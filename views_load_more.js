/**
 * An ajax responder that accepts a packet of JSON data and acts appropriately.
 *
 * The following fields control behavior.
 * - 'display': Display the associated data in the view area.
 */
Drupal.views_load_more = function(target, response) {
  var $view = $(target);

  // Check the 'display' for data.
  if (response.status && response.display) {
    var $newView = $(response.display);
    // We don't want to replace we want to append
    // Also we'll want to strip out the pager data
    $view.find('.item-list').remove();
    $view.append($newView);
    $view = $newView;
    $view.parent().removeClass('views-processed');
    Drupal.attachBehaviors($view.parent());
  }

  if (response.messages) {
    // Show any messages (but first remove old ones, if there are any).
    $view.find('.views-messages').remove().end().prepend(response.messages);
  }
  
};

