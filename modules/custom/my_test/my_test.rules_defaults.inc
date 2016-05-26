<?php
/**
 * @file
 * my_test.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function my_test_default_rules_configuration() {
  $items = array();
  $items['rules_send_mail_after_registering'] = entity_import('rules_config', '{ "rules_send_mail_after_registering" : {
      "LABEL" : "Send mail after registering",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "webform_rules", "rules", "mimemail" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "webform_has_id" : {
            "form_id" : [ "form-id" ],
            "selected_webform" : { "value" : { "webform-client-form-1" : "webform-client-form-1" } }
          }
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "submission_form_[node:vid]",
            "to" : "khanh130895@gmail.com",
            "subject" : "New submission ",
            "body" : "You have a new submission. Here is the details\\r\\n\\r\\nName: [data:name-value]\\r\\nEmail: [data:email-value]\\r\\nMessage: [data:message-value]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_send_mail_after_subscribe'] = entity_import('rules_config', '{ "rules_send_mail_after_subscribe" : {
      "LABEL" : "Send mail after subscribe",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "webform_rules", "rules", "mimemail" ],
      "ON" : { "webform_rules_submit" : [] },
      "IF" : [
        { "webform_has_id" : {
            "form_id" : [ "form_id" ],
            "selected_webform" : { "value" : { "webform-client-form-2" : "webform-client-form-2" } }
          }
        }
      ],
      "DO" : [
        { "mimemail" : {
            "key" : "suscribe",
            "to" : "khanh130895@gmail.com",
            "subject" : "New subscribe",
            "body" : "Here is details \\r\\n[data:email-value]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
