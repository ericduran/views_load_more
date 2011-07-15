<?php

/**
 * The plugin to handle Load More pager.
 *
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_load_more extends views_plugin_pager_full {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'Load more pager, @count item, skip @skip', 'Load more pager, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
      return format_plural($this->options['items_per_page'], 'Load more pager, @count item', 'Load more pager, @count items', array('@count' => $this->options['items_per_page']));
  }
  
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['id']['#default_value'] = 7;
    $form['id']['#access'] = FALSE;
  }
  function render($input) {
    $pager_theme = views_theme_functions('views_load_more_pager', $this->view, $this->display);
    return theme($pager_theme, array(
      'parameters' => $input, 'element' => $this->options['id']));
  }
}

