<section class="container mcc--googleform">

  <form class="wrapper" action="https://docs.google.com/a/dosomething.org/forms/d/1YY2BTXz65IcqyjaTf6GT8FZx0Z2E1251LcSf5LIhc0s/formResponse" method="post" id="ss-form" target="_self" onsubmit="">
    <p class="required">
      <strong>All fields are required.</strong>
    </p>

    <?php // First Name Field ?>
    <div class="ss-form-question errorbox-good -compact -alpha">
      <div dir="ltr" class="ss-item ss-item-required ss-text">
        <div class="ss-form-entry">
          <div class="ss-q-title">
            <label class="ss-q-item-label" for="entry_212037837">First Name <span class="ss-required-asterisk">*</span></label>
          </div>
          <div class="ss-q-help ss-secondary-text" dir="ltr"></div><input type="text" name="entry.212037837" value="" class="ss-q-short" id="entry_212037837" dir="auto" aria-label="First Name" aria-required="true" required="" title="">
          <div class="error-message" id="1205439792_errorMessage"></div>
          <div class="required-message">This is a required question.</div>
        </div>
      </div>
    </div>

    <?php // Last Name Field ?>
    <div class="ss-form-question errorbox-good -compact -beta">
      <div dir="ltr" class="ss-item ss-item-required ss-text">
        <div class="ss-form-entry">
          <div class="ss-q-title">
            <label class="ss-q-item-label" for="entry_2068859039">Last Name <span class="ss-required-asterisk">*</span></label>
          </div>
          <div class="ss-q-help ss-secondary-text" dir="ltr"></div><input type="text" name="entry.2068859039" value="" class="ss-q-short" id="entry_2068859039" dir="auto" aria-label="Last Name" aria-required="true" required="" title="">
          <div class="error-message" id="1427438197_errorMessage"></div>
          <div class="required-message">This is a required question.</div>
        </div>
      </div>
    </div>

    <?php // Email Address Field ?>
    <div class="ss-form-question errorbox-good -compact -alpha">
      <div dir="ltr" class="ss-item ss-item-required ss-text">
        <div class="ss-form-entry">
          <div class="ss-q-title">
            <label class="ss-q-item-label" for="entry_1282358104">Email Address <span class="ss-required-asterisk">*</span></label>
          </div>
          <div class="ss-q-help ss-secondary-text" dir="ltr"></div><input type="text" name="entry.1282358104" value="" class="ss-q-short" id="entry_1282358104" dir="auto" aria-label="Email Address" aria-required="true" required="" title="">
          <div class="error-message" id="970803978_errorMessage"></div>
          <div class="required-message">This is a required question.</div>
        </div>
      </div>
    </div>

    <?php // Cell Number Field ?>
    <div class="ss-form-question errorbox-good -compact -beta">
      <div dir="ltr" class="ss-item ss-item-required ss-text">
        <div class="ss-form-entry">
          <div class="ss-q-title">
            <label class="ss-q-item-label" for="entry_35169248">Cell Number <span class="ss-required-asterisk">*</span></label>
          </div>
          <div class="ss-q-help ss-secondary-text" dir="ltr"></div><input type="text" name="entry.35169248" value="" class="ss-q-short" id="entry_35169248" dir="auto" aria-label="Cell Number" aria-required="true" required="" title="">
          <div class="error-message" id="437089912_errorMessage"></div>
          <div class="required-message">This is a required question.</div>
        </div>
      </div>
    </div>

    <?php // Birthday Field ?>
    <div class="ss-form-question errorbox-good">
      <div dir="ltr" class="ss-item ss-item-required ss-date">
        <div class="ss-form-entry">
          <div class="ss-q-title">
            <label class="ss-q-item-label" for="entry_164235794"><?php print t('Birthday'); ?> <span class="ss-required-asterisk">*</span></label>
          </div>
          <div class="ss-q-help ss-secondary-text" dir="ltr">
            <?php print t('You must be ages 13 to 25 (sorry 26-and-up-year-olds).'); ?>
          </div>

          <div class="ss-datetime-box">
            <select name="entry.164235794_month" class="ss-month-dropdown" id="entry.164235794_month" aria-label="<?php print t('Month'); ?>" aria-required="true">
              <option value=""><?php print t('Month'); ?></option>
              <option value="1"><?php print t('January'); ?></option>
              <option value="2"><?php print t('February'); ?></option>
              <option value="3"><?php print t('March'); ?></option>
              <option value="4"><?php print t('April'); ?></option>
              <option value="5"><?php print t('May'); ?></option>
              <option value="6"><?php print t('June'); ?></option>
              <option value="7"><?php print t('July'); ?></option>
              <option value="8"><?php print t('August'); ?></option>
              <option value="9"><?php print t('September'); ?></option>
              <option value="10"><?php print t('October'); ?></option>
              <option value="11"><?php print t('November'); ?></option>
              <option value="12"><?php print t('December'); ?></option>
            </select>

            <select name="entry.164235794_day" class="ss-day-dropdown" id="entry.164235794_day" aria-label="<?php print t('Day of month'); ?>" aria-required="true">
              <option value=""><?php print t('Day'); ?></option>
              <option value="1">1</option>
              <option value="2">2</option>
              <option value="3">3</option>
              <option value="4">4</option>
              <option value="5">5</option>
              <option value="6">6</option>
              <option value="7">7</option>
              <option value="8">8</option>
              <option value="9">9</option>
              <option value="10">10</option>
              <option value="11">11</option>
              <option value="12">12</option>
              <option value="13">13</option>
              <option value="14">14</option>
              <option value="15">15</option>
              <option value="16">16</option>
              <option value="17">17</option>
              <option value="18">18</option>
              <option value="19">19</option>
              <option value="20">20</option>
              <option value="21">21</option>
              <option value="22">22</option>
              <option value="23">23</option>
              <option value="24">24</option>
              <option value="25">25</option>
              <option value="26">26</option>
              <option value="27">27</option>
              <option value="28">28</option>
              <option value="29">29</option>
              <option value="30">30</option>
              <option value="31">31</option>
            </select>

            <select name="entry.164235794_year" id="entry.164235794_year" aria-label="Year" aria-required="true">
              <option value="">Year</option>
              <option value="1989">1989</option>
              <option value="1990">1990</option>
              <option value="1991">1991</option>
              <option value="1992">1992</option>
              <option value="1993">1993</option>
              <option value="1994">1994</option>
              <option value="1995">1995</option>
              <option value="1996">1996</option>
              <option value="1997">1997</option>
              <option value="1998">1998</option>
              <option value="1999">1999</option>
              <option value="2000">2000</option>
              <option value="2001">2001</option>
            </select>
          </div>

          <div class="required-message">This is a required question.</div>
        </div>
      </div>
    </div>

    <?php // Idea in USA Radio Selection ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-radio">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_1600151592">Can your idea be done by anyone in the United States? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr"></div>
                <ul class="ss-choices" role="radiogroup" aria-label="Can your idea be done by anyone in the United States?">
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.1724618567" value="Yes" id="group_1724618567_1" role="radio" class="ss-q-radio" aria-label="Yes" required="" aria-required="true"></span> <span class="ss-choice-label">Yes</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.1724618567" value="No" id="group_1724618567_2" role="radio" class="ss-q-radio" aria-label="No" required="" aria-required="true"></span> <span class="ss-choice-label">No</span></label>
                    </li>
                </ul>
                <div class="error-message" id="1600151592_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Location Field ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-text">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_429981564">Where are you located? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    Please provide your (valid!) Zip Code.
                </div><input type="text" name="entry.429981564" value="" class="ss-q-short" id="entry_429981564" dir="auto" aria-label="Where are you located? Please provide your (valid!) Zip Code." aria-required="true" required="" title="">
                <div class="error-message" id="1112487280_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Cause Area Radio Selection ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-radio">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_1031662904">What cause area does your idea impact? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    If your idea addresses more than one cause, choose the one you think is most relevant.
                </div>
                <ul class="ss-choices" role="radiogroup" aria-label="What cause area does your idea impact? If your idea addresses more than one cause, choose the one you think is most relevant.">
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Animals" id="group_822732364_1" role="radio" class="ss-q-radio" aria-label="Animals" required="" aria-required="true"></span> <span class="ss-choice-label">Animals</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Bullying &amp; Violence" id="group_822732364_2" role="radio" class="ss-q-radio" aria-label="Bullying &amp; Violence" required="" aria-required="true"></span> <span class="ss-choice-label">Bullying &amp; Violence</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Disasters" id="group_822732364_3" role="radio" class="ss-q-radio" aria-label="Disasters" required="" aria-required="true"></span> <span class="ss-choice-label">Disasters</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Discrimination" id="group_822732364_4" role="radio" class="ss-q-radio" aria-label="Discrimination" required="" aria-required="true"></span> <span class="ss-choice-label">Discrimination</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Education" id="group_822732364_5" role="radio" class="ss-q-radio" aria-label="Education" required="" aria-required="true"></span> <span class="ss-choice-label">Education</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Environment" id="group_822732364_6" role="radio" class="ss-q-radio" aria-label="Environment" required="" aria-required="true"></span> <span class="ss-choice-label">Environment</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Homelessness &amp; Poverty" id="group_822732364_7" role="radio" class="ss-q-radio" aria-label="Homelessness &amp; Poverty" required="" aria-required="true"></span> <span class="ss-choice-label">Homelessness &amp; Poverty</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Physical &amp; Mental Health" id="group_822732364_8" role="radio" class="ss-q-radio" aria-label="Physical &amp; Mental Health" required="" aria-required="true"></span> <span class="ss-choice-label">Physical &amp; Mental Health</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="Sex &amp; Relationships" id="group_822732364_9" role="radio" class="ss-q-radio" aria-label="Sex &amp; Relationships" required="" aria-required="true"></span> <span class="ss-choice-label">Sex &amp; Relationships</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.822732364" value="__other_option__" id="group_822732364_10" role="radio" class="ss-q-radio ss-q-other-toggle" required="" aria-required="true"></span> <span class="ss-choice-label">Other:</span></label> <span class="ss-q-other-container goog-inline-block"><input type="text" name="entry.822732364.other_option_response" value="" class="ss-q-other" id="entry_822732364_other_option_response" dir="auto" aria-label="Other"></span>
                    </li>
                </ul>
                <div class="error-message" id="1031662904_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Type of Action Radio Selection ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-radio">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_223902718">What type of action is your idea? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    If your idea is more than one type of action, choose the one that’s most relevant. Check out our <a href="https://docs.google.com/a/dosomething.org/file/d/0B5fENCbpVZv9R0VnMjh5VWJybFB1QTRyRS05clF3V19VdkFj/edit" target="_blank">descriptions on each type of action</a>.
                </div>
                <ul class="ss-choices" role="radiogroup" aria-label="What type of action is your idea? If your idea is more than one type of action, choose the one that’s most relevant. Check out our descriptions on each type of action.">
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Donate an item" id="group_101412798_1" role="radio" class="ss-q-radio" aria-label="Donate an item" required="" aria-required="true"></span> <span class="ss-choice-label">Donate an item</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Face-to-face interaction" id="group_101412798_2" role="radio" class="ss-q-radio" aria-label="Face-to-face interaction" required="" aria-required="true"></span> <span class="ss-choice-label">Face-to-face interaction</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Host an event" id="group_101412798_3" role="radio" class="ss-q-radio" aria-label="Host an event" required="" aria-required="true"></span> <span class="ss-choice-label">Host an event</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Improve/clean up a (physical) space" id="group_101412798_4" role="radio" class="ss-q-radio" aria-label="Improve/clean up a (physical) space" required="" aria-required="true"></span> <span class="ss-choice-label">Improve/clean up a (physical) space</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Make something&nbsp;" id="group_101412798_5" role="radio" class="ss-q-radio" aria-label="Make something&nbsp;" required="" aria-required="true"></span> <span class="ss-choice-label">Make something&nbsp;</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Share something&nbsp;" id="group_101412798_6" role="radio" class="ss-q-radio" aria-label="Share something&nbsp;" required="" aria-required="true"></span> <span class="ss-choice-label">Share something&nbsp;</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Start something (like a club)" id="group_101412798_7" role="radio" class="ss-q-radio" aria-label="Start something (like a club)" required="" aria-required="true"></span> <span class="ss-choice-label">Start something (like a club)</span></label>
                    </li>
                    <li class="ss-choice-item">
                        <label><span class="ss-choice-item-control goog-inline-block"><input type="radio" name="entry.101412798" value="Take a stand (think protest-y stuff)" id="group_101412798_8" role="radio" class="ss-q-radio" aria-label="Take a stand (think protest-y stuff)" required="" aria-required="true"></span> <span class="ss-choice-label">Take a stand (think protest-y stuff)</span></label>
                    </li>
                </ul>
                <div class="error-message" id="223902718_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // What Problem Addressed Text Area ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-paragraph-text">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_1255883103">What problem are you addressing? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    You MUST include a fact/statistic that proves this problem. e.g. X% of animals end up in shelters after hurricanes. Limit 1-2 sentences.
                </div>
                <textarea name="entry.1255883103" rows="8" cols="0" class="ss-q-long" id="entry_1255883103" dir="auto" aria-label="What problem are you addressing? You MUST include a fact/statistic that proves this problem. e.g. X% of animals end up in shelters after hurricanes. Limit 1-2 sentences." aria-required="true" required=""></textarea>
                <div class="error-message" id="1184451617_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Source Text Area ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-paragraph-text">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_1631970968">Please cite the source(s) of the fact(s) you listed above. <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    Get your research on. Be sure to include: (1) Title of specific study, article, website, or book OR (2) Organization or author that published it OR (3) Link to study or stat. Limit 1-2 sentences.
                </div>
                <textarea name="entry.1631970968" rows="8" cols="0" class="ss-q-long" id="entry_1631970968" dir="auto" aria-label="Please cite the source(s) of the fact(s) you listed above. Get your research on. Be sure to include: (1) Title of specific study, article, website, or book OR (2) Organization or author that published it OR (3) Link to study or stat. Limit 1-2 sentences." aria-required="true" required=""></textarea>
                <div class="error-message" id="2043198594_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Action Description Text Area ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-paragraph-text">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_334582054">Describe the action you want people to take. <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    This should be one clear single action anyone in the U.S. can do. E.g., “Collect gently used towels and deliver them to your local animal shelter.” Limit 1-2 sentences.
                </div>
                <textarea name="entry.334582054" rows="8" cols="0" class="ss-q-long" id="entry_334582054" dir="auto" aria-label="Describe the action you want people to take. This should be one clear single action anyone in the U.S. can do. E.g., “Collect gently used towels and deliver them to your local animal shelter.” Limit 1-2 sentences." aria-required="true" required=""></textarea>
                <div class="error-message" id="711595546_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <?php // Prove Idea Text Area ?>
    <div class="ss-form-question errorbox-good">
        <div dir="ltr" class="ss-item ss-item-required ss-paragraph-text">
            <div class="ss-form-entry">
                <div class="ss-q-title">
                    <label class="ss-q-item-label" for="entry_2116830440">How can you prove your idea is an effective solution to the problem? <span class="ss-required-asterisk">*</span></label>
                </div>
                <div class="ss-q-help ss-secondary-text" dir="ltr">
                    Do this by (1) Sharing results if you’ve done this before (e.g. “I ran this project last Christmas and fed 100 people”) OR (2) Linking to someone that’s successfully done this (e.g. “The Red Cross runs blood drives that save lives”) OR (3) Linking to research that proves your solution is valid (e.g. “The CDC says educating people about vaccines makes them more likely to get vaccinated”). Limit 1-2 sentences.
                </div>
                <textarea name="entry.2116830440" rows="8" cols="0" class="ss-q-long" id="entry_2116830440" dir="auto" aria-label="How can you prove your idea is an effective solution to the problem? Do this by (1) Sharing results if you’ve done this before (e.g. “I ran this project last Christmas and fed 100 people”) OR (2) Linking to someone that’s successfully done this (e.g. “The Red Cross runs blood drives that save lives”) OR (3) Linking to research that proves your solution is valid (e.g. “The CDC says educating people about vaccines makes them more likely to get vaccinated”). Limit 1-2 sentences." aria-required="true" required=""></textarea>
                <div class="error-message" id="1391945183_errorMessage"></div>
                <div class="required-message">This is a required question.</div>
            </div>
        </div>
    </div>

    <input type="hidden" name="draftResponse" value="[,,&quot;-2455914862412393102&quot;] "> <input type="hidden" name="pageHistory" value="0"> <input type="hidden" name="fbzx" value="-2455914862412393102">

    <input type="submit" name="submit" value="<?php print t('Submit'); ?>" id="ss-submit" class="button">
  </form>

</section>

