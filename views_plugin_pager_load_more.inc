<?php

/**
 * The plugin to handle full pager.
 *
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_load_more extends views_plugin_pager_full {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'More pager, @count item, skip @skip', 'More pager, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
      return format_plural($this->options['items_per_page'], 'More pager, @count item', 'More pager, @count items', array('@count' => $this->options['items_per_page']));
  }
  
  // TODO: Add waypoint Support.
  // function option_definition() {
  //   $options = parent::option_definition();
  // 
  //   return $options;
  // }

  // function options_form(&$form, &$form_state) {
  //   $form = parent::options_form($form, $form_state);  
  // }

  function render($input) {
    $pager_theme = views_theme_functions('views_load_more_pager', $this->view, $this->display);
    return theme($pager_theme, $input, $this->options['items_per_page'], $this->options['id']);
  }
}

