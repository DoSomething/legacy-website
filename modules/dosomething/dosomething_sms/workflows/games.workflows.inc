<?php

/**
 * @file
 * ConductorWorkflow definitions for SMS games.
 */

require_once drupal_get_path('module', 'dosomething_sms') . '/sms_flow_game_constants.inc';

/**
 * Handle all random pathing for randoming pathing and WYR-style games under one workflow
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mcommons_random_path';
$workflow->title = 'Handler for path randomizing.';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('mcommons_random_paths');

$activity = $workflow->newActivity('mcommons_random_paths');
$activity->name = 'mcommons_random_paths';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->sets = array(
  // Pregnancy Text WAIT tips
  array(
    'mdata_id'     => 10223,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_WAIT_TIPS,
    'opt_in_paths' => array(153193, 153203, 153213, 153223, 153233, 153243, 153253, 153263, 153273),
    'path_special' => 153183,
    'send_to_special_on' => 3,
  ),
  // Pregnancy Text SAFE tips
  array(
    'mdata_id'     => 10233,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_SAFE_TIPS,
    'opt_in_paths' => array(153283, 153293, 153303, 153313, 153323, 153333, 153343, 153353),
  ),
  // Pregnancy Text PARENT tips
  array(
    'mdata_id'     => 10243,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_PARENT_TIPS,
    'opt_in_paths' => array(153363, 153373, 153383),
  ),
  // Pregnancy Text RIGHTS tips
  array(
    'mdata_id'     => 10253,
    'game_id'      => SmsFlowGameConstants::PREGTEXT_RIGHTS_TIPS,
    'opt_in_paths' => array(153393, 153403, 153413),
  ),
  // Give A Spit 2013 - Random Fact Tips
  array(
    'mdata_id'     => 10923,
    'game_id'      => SmsFlowGameConstants::GIVEASPIT_RANDOM_TIPS,
    'opt_in_paths' => array(161195, 161197, 161199, 161201, 161203, 161205, 161207, 161209, 161211, 161213, 161215, 161217, 161219, 161221, 161223, 161225),
  ),
  // Cell Phones for Survivors 2013 - Random Tips
  array(
    'mdata_id'     => 10931,
    'game_id'      => SmsFlowGameConstants::SURVIVORS_RANDOM_TIPS,
    'opt_in_paths' => array(161399, 161401, 161405, 161407, 161409, 161521),
    'path_special' => 161403,
    'send_to_special_on' => 3,
  ),
  // Fed Up 2013 - Random Tips
  array(
    'mdata_id'     => 10951,
    'game_id'      => SmsFlowGameConstants::FEDUP_RANDOM_TIPS,
    'opt_in_paths' => array(161557, 161559, 161561, 161563, 161565, 161567, 161569, 161571, 161573, 161575),
  ),
  // 50 Cans - MARKT tips
  array(
    'mdata_id'     => 10957,
    'game_id'      => SmsFlowGameConstants::MARKT_50CANS_TIPS,
    'opt_in_paths' => array(161843, 161845, 161847, 161849, 161851, 161853, 161855, 161857, 161859),
  ),
  // 50 Cans - RUN tips
  array(
    'mdata_id'     => 10959,
    'game_id'      => SmsFlowGameConstants::RUN_50CANS_TIPS,
    'opt_in_paths' => array(161819, 161821, 161823, 161825, 161827, 161829, 161831, 161833, 161835, 161837, 161839, 161841),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mcommons_random_paths');

$workflows[$workflow->name] = $workflow;


/**
 * Handles all ordered pathing under one workflow
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mcommons_ordered_paths';
$workflow->title = 'Handler for MCommons Ordered Paths';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('mcommons_ordered_paths');

$activity = $workflow->newActivity('mcommons_ordered_paths');
$activity->name = 'mcommons_ordered_paths';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->sets = array(
  // GUIDE path for I Heart Dad 2013
  array(
    'mdata_id' => 10843,
    'game_id' => SmsFlowGameConstants::IHEARTDAD_GUIDE,
    'opt_in_paths' => array(158861, 158863, 158865, 158869, 158871, 158873),
  ),
  // Birthday Mail 2013 Tips
  array(
    'mdata_id' => 10907,
    'game_id' => SmsFlowGameConstants::BDAYMAIL_TIPS,
    'opt_in_paths' => array(160625, 160627, 160629, 160631, 160633, 160635),
  ),
  // Give A Spit 2013 Idea Tips
  array(
    'mdata_id' => 10921,
    'game_id' => SmsFlowGameConstants::GIVEASPIT_ORDERED_TIPS,
    'opt_in_paths' => array(161183, 161185, 161187, 161189, 161191, 161193),
    'should_loop' => TRUE,
  ),
  // 50 Cans STAT
  array(
    'mdata_id' => 9221,
    'game_id' => SmsFlowGameConstants::STATS_50CANS_TIPS,
    'opt_in_paths' => array(161861, 161863, 161865, 161867),
  ),
  // Grandparents Gone Wired 2013 - EMAIL tips
  array(
    'mdata_id' => 10975,
    'game_id' => SmsFlowGameConstants::GGW_EMAIL_TIPS,
    'opt_in_paths' => array(162747, 162423, 162425, 162427, 162429, 162431, 162433, 162435, 162437, 162439, 162441),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - COMP tips
  array(
    'mdata_id' => 10977,
    'game_id' => SmsFlowGameConstants::GGW_COMP_TIPS,
    'opt_in_paths' => array(162443, 162445, 162447, 162449, 162451, 162453, 162455, 162457, 162459, 162461, 162463, 162465),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - PHONE tips
  array(
    'mdata_id' => 10979,
    'game_id' => SmsFlowGameConstants::GGW_PHONE_TIPS,
    'opt_in_paths' => array(162467, 162469, 162471, 162473, 162475, 162477, 162479, 162481, 162483, 162485, 162487, 162489, 162491, 162493),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - FBOOK tips
  array(
    'mdata_id' => 10981,
    'game_id' => SmsFlowGameConstants::GGW_FBOOK_TIPS,
    'opt_in_paths' => array(162495, 162497, 162499, 162501, 162503, 162505, 162507, 162509, 162511, 162513, 162515, 162517, 162519, 162521),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - TWEET tips
  array(
    'mdata_id' => 10983,
    'game_id' => SmsFlowGameConstants::GGW_TWEET_TIPS,
    'opt_in_paths' => array(162523, 162525, 162527, 162529, 162531, 162533, 162535, 162537),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - VIDCHAT tips
  array(
    'mdata_id' => 10985,
    'game_id' => SmsFlowGameConstants::GGW_VIDCHAT_TIPS,
    'opt_in_paths' => array(162749, 162539, 162541, 162543, 162545, 162547, 162549, 162551),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - INSTA tips
  array(
    'mdata_id' => 10987,
    'game_id' => SmsFlowGameConstants::GGW_INSTA_TIPS,
    'opt_in_paths' => array(162589, 162591, 162593, 162595, 162597, 162599, 162601, 162603, 162605),
    'should_loop' => TRUE,
  ),
  // Grandparents Gone Wired 2013 - TABLET tips
  array(
    'mdata_id' => 10989,
    'game_id' => SmsFlowGameConstants::GGW_TABLET_TIPS,
    'opt_in_paths' => array(162553, 162555, 162557, 162559, 162561, 162563, 162565, 162567, 162569, 162571),
    'should_loop' => TRUE,
  ),
  // Teens for Jeans 2013 - PRIZE guide
  array(
    'mdata_id' => 11001,
    'game_id' => SmsFlowGameConstants::TFJ_PRIZE_GUIDE,
    'opt_in_paths' => array(162865, 162867),
    'should_loop' => TRUE,
  ),
  // Teens for Jeans 2013 - MARKET tips
  array(
    'mdata_id'     => 11007,
    'game_id'      => SmsFlowGameConstants::TFJ_MARKET_TIPS,
    'opt_in_paths' => array(162875, 162877, 162879),
    'should_loop'  => TRUE,
  ),
  // Teens for Jeans 2013 - RUN tips
  array(
    'mdata_id'     => 11009,
    'game_id'      => SmsFlowGameConstants::TFJ_RUN_TIPS,
    'opt_in_paths' => array(162881, 162883, 162885, 162887),
    'should_loop'  => TRUE,
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mcommons_ordered_paths');

$workflows[$workflow->name] = $workflow;

/**
 * Handles all time-based pathing under one workflow
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_mcommons_timed_paths';
$workflow->title = 'Handler for MCommons Timed Paths';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('mcommons_timed_paths');

$activity = $workflow->newActivity('mcommons_timed_paths');
$activity->name = 'mcommons_timed_paths';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->sets = array(
  // Hunt 2013 daily challenges
  array(
    'mdata_id' => 10855,
    'timezone' => 'America/New_York',
    'paths' => array(
      array(
        'time' => '2013-07-16 10:00:00',
        'opt_in_path' => 159319,
      ),
      array(
        'time' => '2013-07-17 10:00:00',
        'opt_in_path' => 159321,
      ),
      array(
        'time' => '2013-07-18 10:00:00',
        'opt_in_path' => 159323,
      ),
      array(
        'time' => '2013-07-19 10:00:00',
        'opt_in_path' => 159325,
      ),
      array(
        'time' => '2013-07-20 10:00:00',
        'opt_in_path' => 159327,
      ),
      array(
        'time' => '2013-07-21 10:00:00',
        'opt_in_path' => 159329,
      ),
      array(
        'time' => '2013-07-22 10:00:00',
        'opt_in_path' => 159331,
      ),
      array(
        'time' => '2013-07-23 10:00:00',
        'opt_in_path' => 159333,
      ),
      array(
        'time' => '2013-07-24 10:00:00',
        'opt_in_path' => 159335,
      ),
      array(
        'time' => '2013-07-25 10:00:00',
        'opt_in_path' => 159337,
      ),
      array(
        'time' => '2013-07-26 10:00:00',
        'opt_in_path' => 159339,
      ),
      // Message for after the campaign ends
      array(
        'time' => '2013-07-27 10:00:00',
        'opt_in_path' => 159381,
      ),
    ),
  ),
  // Hunt 2013 INSTA actions
  array(
    'mdata_id' => 10861,
    'timezone' => 'America/New_York',
    'paths' => array(
      array(
        'time' => '2013-07-16 10:00:00',
        'opt_in_path' => 159397,
      ),
      array(
        'time' => '2013-07-17 10:00:00',
        'opt_in_path' => 159399,
      ),
      array(
        'time' => '2013-07-18 10:00:00',
        'opt_in_path' => 159401,
      ),
      array(
        'time' => '2013-07-19 10:00:00',
        'opt_in_path' => 159403,
      ),
      array(
        'time' => '2013-07-20 10:00:00',
        'opt_in_path' => 159405,
      ),
      array(
        'time' => '2013-07-21 10:00:00',
        'opt_in_path' => 159409,
      ),
      array(
        'time' => '2013-07-22 10:00:00',
        'opt_in_path' => 159411,
      ),
      array(
        'time' => '2013-07-23 10:00:00',
        'opt_in_path' => 159413,
      ),
      array(
        'time' => '2013-07-24 10:00:00',
        'opt_in_path' => 159415,
      ),
      array(
        'time' => '2013-07-25 10:00:00',
        'opt_in_path' => 159417,
      ),
      array(
        'time' => '2013-07-26 10:00:00',
        'opt_in_path' => 159419,
      ),
      // Message for after the campaign ends
      array(
        'time' => '2013-07-27 10:00:00',
        'opt_in_path' => 159381,
      ),
    ),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('mcommons_timed_paths');

$workflows[$workflow->name] = $workflow;

/**
 * Intended to be plugged in at the end of a pregnancy text drip message as an
 * mData. Will respond to any user message that matches a given set.
 */
$workflow = new ConductorWorkflow();
$workflow->wid = 'new';
$workflow->name = 'sms_flow_preg_text_responder';
$workflow->title = 'Pregnancy Text Out-of-Flow Responder';
$workflow->api_version = '1.0';

$activity = $workflow->newActivity('start');
$activity->name = 'start';
$activity->outputs = array('out_of_flow_responder');

$activity = $workflow->newActivity('out_of_flow_responder');
$activity->name = 'out_of_flow_responder';
$activity->inputs = array('start');
$activity->outputs = array('end');
$activity->no_match_responses = array(155123, 155133, 155143, 155153);
$activity->mms_match_responses = array(
  "Now that's a good looking picture",
);
$activity->response_sets = array(
  array(
    'phrase_match' => array('I hate you', 'suck it', 'kill yourself', 'youre the worst', 'shut up'),
    'word_match' => array('die'),
    'response' => array("That's no way to talk to a baby. If you really really want me to go away, text AWAY and I'll be gone."),
  ),
  array(
    'phrase_match' => array('i love you'),
    'AND_match' => array(array('love', 'you')),
    'response' => array("I love you too!"),
  ),
  array(
    'phrase_match' => array('Who is this', 'Who are you', 'Who the hell is this', 'What is this'),
    'response' => array("I'm a phone baby your friend sent from DoSomething.org. I'll only text you today, but if you want me to go away, text AWAY."),
  ),
  array(
    'phrase_match' => array('Im not up', 'Im not awake'),
    'response' => array("You are now!"),
  ),
  array(
    'phrase_match' => array('I will feed you'),
    'AND_match' => array(array('feed', 'you')),
    'response' => array("Thanks!", "Thank you!", "You're the best."),
  ),
  array(
    'phrase_match' => array('Im tired'),
    'response' => array("Me too, being this cute is exhausting"),
  ),
  array(
    'phrase_match' => array('I dont want to bring you breakfast', 'I dont want to bring you breakfast in bed'),
    'response' => array("But I'm hungry!"),
  ),
  array(
    'phrase_match' => array('Feeds baby', 'heres breakfast', 'Im making breakfast'),
    'word_match' => array('Eggs', 'pancakes', 'waffles', 'bagles', 'milk', 'cereal', 'applesauce', 'bottle', 'feed'),
    'response' => array("Yum! I'll totally get you when I learn how to walk", "Nom nom nom"),
  ),
  array(
    'AND_match' => array(array('orange', 'juice')),
    'response' => array("Yum! I'll totally get you when I learn how to walk", "Nom nom nom"),
  ),
  array(
    'phrase_match' => array('good morning'),
    'word_match' => array('Goodmorning', ' morning'),
    'response' => array("Good morning!", "It IS a good morning!"),
  ),
  array(
    'exact_match' => array('youre welcome'),
    'response' => array("Now I know where I get my good manners. Such a good example!", "Such good manners"),
  ),
  array(
    'phrase_match' => array('Youre cute', 'youre adorable'),
    'response' => array("I get my good looks from my parents", "Daww you're making me blush", "You sure know how to make a baby feel good", "Remember you said that next time I poop :)"),
  ),
  array(
    'phrase_match' => array('You get me breakfast'),
    'response' => array("I can't even stand up on my own yet!"),
  ),
  array(
    'exact_match' => array('no'),
    'phrase_match' => array('I dont want to'),
    'response' => array("But I'm the baby, you have to!", "Tough break, you've gotta!"),
  ),
  array(
    'word_match' => array('Gross', 'disgusting', 'fowl', 'foul', 'smelly', 'stinky', '/ew+/'),
    'response' => array("But my cute face balances it out...", "I'm a baby, what do you expect?", "I can't help it, I'm a baby, this is what I do!", "It's a good thing I'm so cute...it makes up for all of the smelly and gross."),
  ),
  array(
    'phrase_match' => array('It smells', 'you smell', 'smelly', 'that smells'),
    'response' => array("What can I say? Babies are stinky.", "I'm a baby, that's sort of my M.O."),
  ),
  array(
    'exact_match' => array('poop', 'fart'),
    'phrase_match' => array('its poop', 'its a poop', 'its a fart', 'it was a poop'),
    'AND_match' => array(array('its', 'poop'), array('its', 'fart')),
    'response' => array("There's no real right answer. You sort of lose either way."),
  ),
  array(
    'phrase_match' => array('Its okay', 'thats okay'),
    'response' => array("Thanks for understanding", "You're so understanding"),
  ),
  array(
    'phrase_match' => array('Ill change my shirt', 'clean shirt'),
    'response' => array("That wasn't my favorite color on you anyway, it does nothing for your eyes"),
  ),
  array(
    'phrase_match' => array('you ruined my shirt'),
    'response' => array("I'm sorry, sometimes these things just happen."),
  ),
  array(
    'phrase_match' => array('im pregnant', 'i am pregnant'),
    'response' => array("I'm not the best person to talk to about that, but if you need more info on that matter, you should try calling his hotline: 800-442-4673"),
  ),
  array(
    'phrase_match' => array('fuck you', 'you suck', 'screw you', 'you bitch', 'blow job', 'butt plug', 'camel toe', 'dumb ass', 'hard on', 'jerk off', 'jungle bunny', 'pissed off', 'porch monkey', 'nut sack', 'sand nigger'),
    'word_match' => array('anus', 'arse', 'arsehole', 'ass', 'asshat', 'assjabber', 'asspirate', 'assbag', 'assbandit', 'assbanger', 'assbite', 'assclown', 'asscock', 'asscracker', 'asses', 'assface', 'assfuck', 'assfucker', 'assgoblin', 'asshat', 'asshead', 'asshole', 'asshopper', 'assjacker', 'asslick', 'asslicker', 'assmonkey', 'assmunch', 'assmuncher', 'asspirate', 'assshit', 'assshole', 'asssucker', 'asswad', 'asswipe', 'axwound', 'bastard', 'beaner', 'bitch', 'bitchass', 'bitches', 'bitchtits', 'bitchy', 'blowjob', 'bollocks', 'bollox', 'boner', 'brotherfucker', 'bullshit', 'bumblefuck', 'buttpirate', 'buttfucka', 'buttfucker', 'carpetmuncher', 'chesticle', 'chinc', 'chink', 'choad', 'chode', 'clit', 'clitface', 'clitfuck', 'clusterfuck', 'cock', 'cockass', 'cockbite', 'cockburger', 'cockface', 'cockfucker', 'cockhead', 'cockjockey', 'cockknoker', 'cockmaster', 'cockmongler', 'cockmongruel', 'cockmonkey', 'cockmuncher', 'cocknose', 'cocknugget', 'cockshit', 'cocksmith', 'cocksmoke', 'cocksmoker', 'cocksniffer', 'cocksucker', 'cockwaffle', 'coochie', 'coochy', 'coon', 'cooter', 'cum', 'cumbubble', 'cumdumpster', 'cumguzzler', 'cumjockey', 'cumslut', 'cumtart', 'cunnie', 'cunnilingus', 'cunt', 'cuntass', 'cuntface', 'cunthole', 'cuntlicker', 'cuntrag', 'cuntslut', 'dago', 'damn', 'deggo', 'dick', 'dicksneeze', 'dickbag', 'dickbeaters', 'dickface', 'dickfuck', 'dickfucker', 'dickhead', 'dickhole', 'dickjuice', 'dickmilk', 'dickmonger', 'dicks', 'dickslap', 'dicksucker', 'dicksucking', 'dicktickler', 'dickwad', 'dickweasel', 'dickweed', 'dickwod', 'dike', 'dildo', 'dipshit', 'doochbag', 'dookie', 'douche', 'douchefag', 'douchebag', 'douchewaffle', 'dumass', 'dumbass', 'dumbfuck', 'dumbshit', 'dumshit', 'dyke', 'fag', 'fagbag', 'fagfucker', 'faggit', 'faggot', 'faggotcock', 'fagtard', 'fatass', 'fellatio', 'feltch', 'flamer', 'fuck', 'fuckass', 'fuckbag', 'fuckboy', 'fuckbrain', 'fuckbutt', 'fuckbutter', 'fucked', 'fucker', 'fuckersucker', 'fuckface', 'fuckhead', 'fuckhole', 'fuckin', 'fucking', 'fucknut', 'fucknutt', 'fuckoff', 'fucks', 'fuckstick', 'fucktard', 'fucktart', 'fuckup', 'fuckwad', 'fuckwit', 'fuckwitt', 'fudgepacker', 'gay', 'gayass', 'gaybob', 'gaydo', 'gayfuck', 'gayfuckist', 'gaylord', 'gaytard', 'gaywad', 'goddamn', 'goddamnit', 'gooch', 'gook', 'gringo', 'guido', 'handjob', 'heeb', 'hell', 'ho', 'hoe', 'homo', 'homodumbshit', 'honkey', 'humping', 'jackass', 'jagoff', 'jap', 'jerkass', 'jigaboo', 'jizz', 'junglebunny', 'kike', 'kooch', 'kootch', 'kraut', 'kunt', 'kyke', 'lameass', 'lardass', 'lesbian', 'lesbo', 'lezzie', 'mcfagget', 'mick', 'minge', 'mothafucka', 'mothafuckin', 'motherfucker', 'motherfucking', 'muff', 'muffdiver', 'munging', 'negro', 'nigaboo', 'nigga', 'nigger', 'niggers', 'niglet', 'nutsack', 'paki', 'panooch', 'pecker', 'peckerhead', 'penis', 'penisbanger', 'penisfucker', 'penispuffer', 'piss', 'pissed', 'pissflaps', 'polesmoker', 'pollock', 'poon', 'poonani', 'poonany', 'poontang', 'porchmonkey', 'prick', 'punanny', 'punta', 'pussies', 'pussy', 'pussylicking', 'puto', 'queef', 'queer', 'queerbait', 'queerhole', 'renob', 'rimjob', 'ruski', 'sandnigger', 'schlong', 'scrote', 'shit', 'shitass', 'shitbag', 'shitbagger', 'shitbrains', 'shitbreath', 'shitcanned', 'shitcunt', 'shitdick', 'shitface', 'shitfaced', 'shithead', 'shithole', 'shithouse', 'shitspitter', 'shitstain', 'shitter', 'shittiest', 'shitting', 'shitty', 'shiz', 'shiznit', 'skank', 'skeet', 'skullfuck', 'slut', 'slutbag', 'smeg', 'snatch', 'spic', 'spick', 'splooge', 'spook', 'suckass', 'tard', 'testicle', 'thundercunt', 'tit', 'titfuck', 'tits', 'tittyfuck', 'twat', 'twatlips', 'twats', 'twatwaffle', 'unclefucker', 'vajj', 'vag', 'vagina', 'vajayjay', 'vjayjay', 'wank', 'wankjob', 'wetback', 'whore', 'whorebag', 'whoreface', 'wop'),
    'word_match_exact' => TRUE,
    'response' => array("That's no way to talk to a baby. If you want me to go away, I will, just text AWAY.", "You kiss your mother with that mouth? If you want me to go away, I will, just text AWAY.", "Woah, that's too much for my baby ears to handle. If you want me to go away, I will, just text AWAY."),
  ),
  array(
    'phrase_match' => array('Calm down'),
    'AND_match' => array(array('calm', 'down')),
    'response' => array("I'm trying, I swear!"),
  ),
  array(
    'exact_match' => array('wait'),
    'response' => array("I don't control these things. "),
  ),
  array(
    'phrase_match' => array('Potty trained', ' potty train', ' use the toilet'),
    'response' => array("I won't be potty trained for at least another year, buckle up!"),
  ),
  array(
    'phrase_match' => array('Shake baby'),
    'response' => array("OW", "I'm not a doll! That hurts!"),
  ),
  array(
    'exact_match' => array('change yourself'),
    'phrase_match' => array('change yourself'),
    'response' => array("I can't hold onto anything bigger than a pinky, how do you expect me to change my own diaper?", "Give me about 2 years and I totally will"),
  ),
  array(
    'phrase_match' => array('Changed your diaper', 'youre all clean', 'Ill change you', 'changing you', 'clean now', 'diaper changed', 'change you', 'smelling good', 'changes diaper'),
    'word_match' => array('change', 'wash', 'clean'),
    'response' => array("So fresh and so clean clean", "Thanks!", "Thanks! When you smell better, you feel better"),
  ),
  array(
    'exact_match' => array('ok', 'okay', 'done'),
    'phrase_match' => array('all done', 'I did it', 'I will', 'I am', 'I did', 'Im done'),
    'response' => array("You're the best!", "Thanks!", "Thank you!", "Phew, so much better"),
  ),
  array(
    'phrase_match' => array('youre the best'),
    'response' => array("No you're the best."),
  ),
  array(
    'phrase_match' => array('I cant right now', 'not now', 'Ill do it later'),
    'response' => array("Mkay, I'll be here waiting.", "Just don't forget about me!"),
  ),
  array(
    'phrase_match' => array('I already changed you'),
    'AND_match' => array(array('change', 'already')),
    'response' => array("Well, I poop a lot.", "Call me Sir Poops A Lot"),
  ),
  array(
    'phrase_match' => array('Are you hungry', 'Do you need food', 'Do you need a bottle', 'Something to eat'),
    'response' => array("Yes please, I'm always hungry", "I could always eat", "A little snack sounds good"),
  ),
  array(
    'phrase_match' => array('Do you need to be changed', 'Diaper change', 'Check diaper', ' change diaper'),
    'response' => array("I pretty much always need my diaper changed", "Yeah, I think there might be a situation downtown"),
  ),
  array(
    'phrase_match' => array('Sit in your soiled clothes', 'sit in your dirty diaper', 'stay dirty'),
    'response' => array("Well that's just gross, imagine it for a second. Go ahead."),
  ),
  array(
    'phrase_match' => array('Are you sleepy', 'Are you tired', 'are you sleep', 'are you asleep'),
    'response' => array("I'm a little sleepy"),
  ),
  array(
    'phrase_match' => array('Im sleeping', 'Im asleep'),
    'response' => array("Not anymore!"),
  ),
  array(
    'phrase_match' => array('Please dont cry'),
    'AND_match' => array(array('dont', 'cry')),
    'response' => array("I'm a baby, it's what I do!"),
  ),
  array(
    'phrase_match' => array('Chill out'),
    'AND_match' => array(array('chill', 'out')),
    'response' => array("This is me chilled out"),
  ),
  array(
    'AND_match' => array(array('stay', 'still'), array('hold', 'still')),
    'response' => array("BUT I. DONT. WANNAAAAAA", "This is about as still as I get."),
  ),
  array(
    'phrase_match' => array('Im coming', 'Im here', 'here I come', 'coming', 'here', 'im home'),
    'response' => array("Can't wait to see you!", "YAY!"),
  ),
  array(
    'phrase_match' => array('on my way'),
    'word_match' => array('omw'),
    'response' => array("Woohoo! See you soon!", "Yay! See you in a little.", "Good :)"),
  ),
  array(
    'phrase_match' => array('Youre ugly', 'youre not cute'),
    'response' => array("Well they tell me I look like my parents...", "Where do you think I get my looks from?", "I'm lookin at you.."),
  ),
  array(
    'exact_match' => array('No it doesnt', 'No youre not'),
    'response' => array("Hey, don't argue with a baby.", "I'm the baby, I'm always right", "There's no arguing with a baby-\"I'm a baby\" is the ultimate trump card."),
  ),
  array(
    'phrase_match' => array('Goo goo gaga', 'goo goo ga ga'),
    'AND_match' => array(array('goo', 'ga'), array('goo', 'gaga')),
    'response' => array("Aw, look at you trying to talk in my language. That's so cute."),
  ),
  array(
    'phrase_match' => array('Im at work', 'Im at school'),
    'response' => array("Okay, I'll try to be quiet til you're done"),
  ),
  array(
    'phrase_match' => array('driving me crazy', 'drive me crazy'),
    'response' => array("But the cuteness makes up for it :)"),
  ),
  array(
    'phrase_match' => array('get adopted', 'putting you up for adoption'),
    'response' => array("You don't mean that. If you really want me to go away though, I will, just text AWAY :("),
  ),
  array(
    'phrase_match' => array('snack time'),
    'response' => array("Nom nom nom nom"),
  ),
  array(
    'phrase_match' => array('There was no school today', 'school is already out', 'school has been out', 'Its the weekend', 'Its Saturday', 'Its Sunday'),
    'response' => array("I'm just a baby, I don't even know what day of the week it is. "),
  ),
  array(
    'phrase_match' => array('Yes I have to study'),
  ),
  array(
    'phrase_match' => array('I dont have to study'),
    'response' => array("Perfect! Then we can play allll night"),
  ),
  array(
    'phrase_match' => array('I dont take algebra', 'I already took algebra'),
    'response' => array("I can't even say my name yet, I don't know the difference between school subjects"),
  ),
  array(
    'phrase_match' => array('I cant sing', 'I dont know any lullabies', 'I dont know a lullaby'),
    'response' => array("I'm sure whatever you sing will be perfect."),
  ),
  array(
    'phrase_match' => array('cant send a photo', 'cant send a picture', 'cant send a pic', 'Do I have to send a picture', 'Do I have to send a photo'),
    'response' => array("You don't have to send me a picture. You just take so many of me, I thought it would be nice to have one of you!"),
  ),
  array(
    'phrase_match' => array('I dont want to sing'),
    'response' => array("But it'll make me go to sleep"),
  ),
  array(
    'phrase_match' => array('You do it'),
    'response' => array("I can't even say my own name yet, how am I supposed to do it?"),
  ),
  array(
    'phrase_match' => array('Whats your name?'),
    'response' => array("That's your job! Just don't go all celeb on me and name me Flamingo or something."),
  ),
  array(
    'phrase_match' => array('Dont go', 'Dont go away', 'Dont leave', 'No dont leave baby'),
    'response' => array("Ok fine I won't go, I would miss you too much anyway."),
  ),
  array(
    'phrase_match' => array('i miss you', 'i missed you'),
    'response' => array("Daww :)"),
  ),
  array(
    'exact_match' => array('boo'),
    'phrase_match' => array('peek a boo'),
    'response' => array("Ah! You scared me."),
  ),
  array(
    'phrase_match' => array('What do you want to play'),
    'response' => array("Peek-a-boo! Duh."),
  ),
  array(
    'phrase_match' => array('passing you off', 'pass you off'),
    'response' => array("You can't just pass me off, I'm here to stay!"),
  ),
  array(
    'exact_match' => array('tell me'),
    'phrase_match' => array('Tell me what you need', 'Tell me what you want'),
    'response' => array("I wish I could!", "I'm trying but I can't!"),
  ),
  array(
    'phrase_match' => array('Try harder', 'Youre not trying'),
    'response' => array("I really am trying. Things will be so much easier when I learn how to talk out loud. "),
  ),
  array(
    'word_match' => array('/\bha[ha]*\b/', 'LOL', 'LMAO'),
    'response' => array("Glad you find me funny :)", "I'm just a regular comedian. ", "I'm glad you think I'm as funny as I do!"),
  ),
  array(
    'word_match' => array('tickle', 'tickling'),
    'response' => array("Hehehe I'm ticklish!", "Heheh!", "Ahh I'm ticklish! I can't breathe I'm laughing so hard!"),
  ),
);

$activity = $workflow->newActivity('end');
$activity->name = 'end';
$activity->inputs = array('out_of_flow_responder');

$workflows[$workflow->name] = $workflow;
