# Cosa è #

L'idea di base è di realizzare una stazione meteo con un raspberry che fornisca info riguardo alla temperatura dell'aria, l'umidità, la pressione (mai implementato). 
Il front end è sviluppato con Drupal, tramite un server LAMP installato direttamente sul raspberry (testato su Raspbian).

# Come funziona #

## Script python ##
Gli script vanno inseriti nella crontab di raspberry, ad un intervallo di tempo a scelta.
Nel file config.yaml sono presenti i parametri di configurazione del database sul quale verranno salvati i dati recuperati ad ogni esecuzione del cron.

i 3 script si occupano di reperire info dal sistema (temperatura e utilizzo cpu), temperatura dell'aria (necessario collegare un sensore al raspberry rispettando il numero del pin presente nello script)
, umidità dell'aria (tramite sensore dht11, anche in questo caso è necessario rispettare il numero dei pin GPIO utilizzati o, in alternativa, modificare lo script).

Se non si hanno a disposizione sensori esterni è possibile utilizzare il solo script per la CPU che aggiornerà la corrispondente tabella mySQL (stazionemeteo_cpuusage e stazionemeteo_cputemp)


## modulo Drupal ##
Stazione_meteo è un modulo sviluppato da zero per Drupal 7 che estende le funzionalità di Drupal Views creando nuove tabelle sulle quali inserire i dati recuperati dagli script.

https://www.drupal.org/project/views

Questi dati possono poi essere utilizzati in una qualsiasi vista drupal e (volendo) mostrati tramite google charts o highcharts (utilizzabili tramite gli appositi moduli di Drupal)

# Bunus pack #

Nella cartella startup sono presenti 2 script per gestire un sensore di rilevamento fiamma e uno 