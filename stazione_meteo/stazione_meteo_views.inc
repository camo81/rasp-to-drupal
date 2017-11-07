<?php

function stazione_meteo_views_api() {
  return array(
    'api' => 3,
  );
}


class views_handler_field_dollars extends views_handler_field_numeric {
  function render($values) {
    $this->options['set_precision'] = TRUE;
    $this->options['precision'] = 2;
    return parent::render($values);
  }
}

function stazione_meteo_views_data() {
  // Basic table information.
	$data['stazionemeteo_temperatura']['table']['group']  = t('Stazione Meteo'); 
  $data['stazionemeteo_cputemp']['table']['group']  = t('Stazione Meteo'); 
  $data['stazionemeteo_cpuusage']['table']['group']  = t('Stazione Meteo'); 
  $data['stazionemeteo_umidita']['table']['group']  = t('Stazione Meteo');


	
  //dichiariazione delle tabelle
  	$data['stazionemeteo_temperatura']['table']['base'] = array(
    'field' => 'idTemperatura',
    'title' => t('Tabella temperatura'),
  ); 

    $data['stazionemeteo_cputemp']['table']['base'] = array(
    'field' => 'idCpuTemp',
    'title' => t('Tabella CPU temperatura'),
  ); 

    $data['stazionemeteo_cpuusage']['table']['base'] = array(
    'field' => 'idCpuUsage',
    'title' => t('Tabella CPU USE'),
  ); 

    $data['stazionemeteo_umidita']['table']['base'] = array(
    'field' => 'idUmidita',
    'title' => t('Tabella Umidità'),
  );     



  //definizione tabella temperatura

    $data['stazionemeteo_temperatura']['idTemperatura'] = array(
    'title' => t('id temperatura'), 
    'help' => t('id temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  ); 

  $data['stazionemeteo_temperatura']['valore'] = array(
    'title' => t('valore temperatura'), 
    'help' => t('valore temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  $data['stazionemeteo_temperatura']['data'] = array(
    'title' => t('data temperatura'), 
    'help' => t('data temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  ); 




  //definizione tabella cputemp
    $data['stazionemeteo_cputemp']['idCpuTemp'] = array(
    'title' => t('id cpu temperatura'), 
    'help' => t('id cpu temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  ); 

    $data['stazionemeteo_cputemp']['valore'] = array(
    'title' => t('valore cpu temperatura'), 
    'help' => t('valore cpu temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
 
    $data['stazionemeteo_cputemp']['data'] = array(
    'title' => t('data cpu temperatura'), 
    'help' => t('data cpu temperatura'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  ); 




  //definizione tabella cpuusage
    $data['stazionemeteo_cpuusage']['idCpuUsage'] = array(
    'title' => t('id cpu use'), 
    'help' => t('id cpu use'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  ); 

    $data['stazionemeteo_cpuusage']['valore'] = array(
    'title' => t('valore cpu use'), 
    'help' => t('valore cpu use'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
 
    $data['stazionemeteo_cpuusage']['data'] = array(
    'title' => t('data cpu use'), 
    'help' => t('data cpu use'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  ); 
    

  //definizione tabella umidità
    $data['stazionemeteo_umidita']['idUmidita'] = array(
    'title' => t('id umidita'), 
    'help' => t('id umidita'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  ); 

    $data['stazionemeteo_umidita']['valore'] = array(
    'title' => t('valore umidita'), 
    'help' => t('valore umidita'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );
 

    $data['stazionemeteo_umidita']['tempDht'] = array(
    'title' => t('valore temperatura DHT'), 
    'help' => t('valore temperatura DHT'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );


    $data['stazionemeteo_umidita']['data'] = array(
    'title' => t('data umidita'), 
    'help' => t('data umidita'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_date',
    ),
  ); 


  return $data;
}