/**
 * An ajax responder that accepts a packet of JSON data and acts appropriately.
 *
 * The following fields control behavior.
 * - 'display': Display the associated data in the view area.
 */
Drupal.viewsLoadMore = function(target, response) {
  var $view = $(target);
  var pager_class = '.pager';
  var view_content_class = '.view-content';
  var view_row_class = '.views-row';

  // Check the 'display' for data.
  if (response.status && response.display) {
    var $newView = $(response.display);
    var $pager = $newView.find(pager_class);
    // Normally views would replace here, but we're going to
    // append instead. At the same time, we want to update
    // the pager to the new pager and re-attached the proper
    // behaviors for the view.
    $view.removeClass('views-processed');
    // Update the Pager with the new pager.
    $view.find(pager_class).html($pager.html());
    // Append the new content to the old view.
    $view.find(view_content_class).append($newView.find(view_row_class));
    Drupal.attachBehaviors($view);
  }

  if (response.messages) {
    // Show any messages (but first remove old ones, if there are any).
    $view.find('.views-messages').remove().end().prepend(response.messages);
  }
  
};

