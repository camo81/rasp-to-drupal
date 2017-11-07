import yaml

with open("config.yaml", 'r') as ymlfile:
    cfg = yaml.load(ymlfile)

    user = cfg['dbconfig']['user']
    password = cfg['dbconfig']['password']
    db_name = cfg['dbconfig']['dbname']
    db_host = cfg['dbconfig']['dbhost']

print user,password,db_name,db_host
