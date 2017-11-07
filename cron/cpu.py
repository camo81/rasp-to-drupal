import subprocess
import os
import psutil
import yaml
import MySQLdb

def db_config():

    with open("config.yaml", 'r') as ymlfile:
        cfg = yaml.load(ymlfile)
    global user
    user = cfg['dbconfig']['user']
    global password
    password = cfg['dbconfig']['password']
    global db_name
    db_name = cfg['dbconfig']['dbname']
    global db_host
    db_host = cfg['dbconfig']['dbhost']


def get_temperature():
    "Returns the temperature in degrees C"
    try:
        s = subprocess.check_output(["/opt/vc/bin/vcgencmd","measure_temp"])
        return float(s.split('=')[1][:-3])
    except:
        return 0

def get_cpu_speed():
    "Returns the current CPU speed"
    f = os.popen('/opt/vc/bin/vcgencmd get_config arm_freq')
    cpu = f.read()
    return cpu


def get_cpu_use():
    return str( psutil.cpu_percent())
    

#recupero i dati richiesti
cputemp = get_temperature()
cpuuse = get_cpu_use()

cputemp = round(cputemp,2)
#cpuuse = round(cpuuse,2)

#insert in db 
db_config()

# Connetto al DB
db = MySQLdb.connect(db_host,user,password,db_name )
cursor = db.cursor()


#Query per inserire i valori
cursor.execute('''INSERT into stazionemeteo_cputemp (valore)
                  values (%s)''',
                  (cputemp))

db.commit()

cursor.execute('''INSERT into stazionemeteo_cpuusage (valore)
                  values (%s)''',
                  (cpuuse))

db.commit()

# disconnetto
db.close()



