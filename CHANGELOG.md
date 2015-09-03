# Change Log

## [v1.1.12](https://github.com/dosomething/phoenix/tree/v1.1.12) (2015-09-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.11...v1.1.12)

**Merged pull requests:**

- Enable the hot module share module. [\#4979](https://github.com/DoSomething/phoenix/pull/4979) ([DFurnes](https://github.com/DFurnes))
- Switches campaigns to nid [\#4978](https://github.com/DoSomething/phoenix/pull/4978) ([deadlybutter](https://github.com/deadlybutter))

## [v1.1.11](https://github.com/dosomething/phoenix/tree/v1.1.11) (2015-08-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.10...v1.1.11)

**Fixed bugs:**

- Last reportback item overrides all the items [\#4908](https://github.com/DoSomething/phoenix/issues/4908)
- Saving from RB review page sets all prior flagged\_reason & promoted\_reason values to NULL [\#4880](https://github.com/DoSomething/phoenix/issues/4880)
- Updating flagged RBItem status does not update the flagged state [\#4879](https://github.com/DoSomething/phoenix/issues/4879)

**Closed issues:**

- Create "region" taxonomy  [\#4826](https://github.com/DoSomething/phoenix/issues/4826)
- enhanced FB/Tumblr share for hot module [\#4643](https://github.com/DoSomething/phoenix/issues/4643)

**Merged pull requests:**

- Hot module share [\#4974](https://github.com/DoSomething/phoenix/pull/4974) ([DFurnes](https://github.com/DFurnes))
- Moves entity save to before review call [\#4971](https://github.com/DoSomething/phoenix/pull/4971) ([deadlybutter](https://github.com/deadlybutter))

## [v1.1.10](https://github.com/dosomething/phoenix/tree/v1.1.10) (2015-08-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.9...v1.1.10)

**Fixed bugs:**

- Time Off on Hot Module Countdown [\#4964](https://github.com/DoSomething/phoenix/issues/4964)

**Closed issues:**

- progress copy override [\#4638](https://github.com/DoSomething/phoenix/issues/4638)

**Merged pull requests:**

- Adds override copy to campaign settings [\#4967](https://github.com/DoSomething/phoenix/pull/4967) ([deadlybutter](https://github.com/deadlybutter))
- Updates review reportback logic to support multiple files [\#4909](https://github.com/DoSomething/phoenix/pull/4909) ([deadlybutter](https://github.com/deadlybutter))

## [v1.1.9](https://github.com/dosomething/phoenix/tree/v1.1.9) (2015-08-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.8...v1.1.9)

**Fixed bugs:**

- some copy from campaign fields were wiped from production in translation deploy [\#4930](https://github.com/DoSomething/phoenix/issues/4930)
- Problem Shares on Hot Module Campaigns Misaligned [\#4918](https://github.com/DoSomething/phoenix/issues/4918)

**Closed issues:**

- PHP Fatal error:  Call to undefined function dosomething\_helplers\_get\_variable\(\) [\#4961](https://github.com/DoSomething/phoenix/issues/4961)
- ds pull stage --db doesn't work [\#4946](https://github.com/DoSomething/phoenix/issues/4946)
- query of campaigns where high season end date is on or after August 31st 2015 [\#4940](https://github.com/DoSomething/phoenix/issues/4940)
- remove reportback crons [\#4905](https://github.com/DoSomething/phoenix/issues/4905)

**Merged pull requests:**

- Fixed typo that caused fatal error on cron. [\#4965](https://github.com/DoSomething/phoenix/pull/4965) ([angaither](https://github.com/angaither))
- Fix hot module share bar [\#4960](https://github.com/DoSomething/phoenix/pull/4960) ([sbsmith86](https://github.com/sbsmith86))
- Remove crons that update flagged/promoted values. [\#4954](https://github.com/DoSomething/phoenix/pull/4954) ([angaither](https://github.com/angaither))
- Updates the hot \(and win\) module timing logic [\#4953](https://github.com/DoSomething/phoenix/pull/4953) ([deadlybutter](https://github.com/deadlybutter))

## [v1.1.8](https://github.com/dosomething/phoenix/tree/v1.1.8) (2015-08-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.7...v1.1.8)

**Fixed bugs:**

- adding win module image borks the win module [\#4941](https://github.com/DoSomething/phoenix/issues/4941)

**Closed issues:**

- add more copy to error message if cc doesn't go through on /donate [\#4938](https://github.com/DoSomething/phoenix/issues/4938)
- Progress Update value not reflected in hot module graph [\#4929](https://github.com/DoSomething/phoenix/issues/4929)
- editors need access to Goal Settings group of custom settings tab on campaign nodes [\#4928](https://github.com/DoSomething/phoenix/issues/4928)

**Merged pull requests:**

- Win module background image updates. Fixes \#4941 [\#4952](https://github.com/DoSomething/phoenix/pull/4952) ([sbsmith86](https://github.com/sbsmith86))
- Adds custom error copy [\#4950](https://github.com/DoSomething/phoenix/pull/4950) ([deadlybutter](https://github.com/deadlybutter))
- Add new permissions for editors and site admins [\#4935](https://github.com/DoSomething/phoenix/pull/4935) ([angaither](https://github.com/angaither))
- Added override to total quantity log sums. [\#4932](https://github.com/DoSomething/phoenix/pull/4932) ([angaither](https://github.com/angaither))

## [v1.1.7](https://github.com/dosomething/phoenix/tree/v1.1.7) (2015-08-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.6...v1.1.7)

**Closed issues:**

- add stripe zip code verification on /donate [\#4937](https://github.com/DoSomething/phoenix/issues/4937)

**Merged pull requests:**

- Adds Stripe zip check verification [\#4947](https://github.com/DoSomething/phoenix/pull/4947) ([deadlybutter](https://github.com/deadlybutter))

## [v1.1.6](https://github.com/dosomething/phoenix/tree/v1.1.6) (2015-08-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.5...v1.1.6)

**Merged pull requests:**

- Fixes fields lost during enabling translation. [\#4943](https://github.com/DoSomething/phoenix/pull/4943) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.5](https://github.com/dosomething/phoenix/tree/v1.1.5) (2015-08-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.4...v1.1.5)

**Fixed bugs:**

- staff pick label missing from homepage [\#4944](https://github.com/DoSomething/phoenix/issues/4944)

**Closed issues:**

- NPM install fails during staging deploys sometimes [\#4920](https://github.com/DoSomething/phoenix/issues/4920)
- Execute ds-global script when after deploying \#4803 to staging and production [\#4869](https://github.com/DoSomething/phoenix/issues/4869)

**Merged pull requests:**

- Fixes staff pick label on homepage. [\#4945](https://github.com/DoSomething/phoenix/pull/4945) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.4](https://github.com/dosomething/phoenix/tree/v1.1.4) (2015-08-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.3...v1.1.4)

**Fixed bugs:**

- Campaign Images Not Appearing on Campaign Collections [\#4931](https://github.com/DoSomething/phoenix/issues/4931)

**Merged pull requests:**

- Fixes images and call to action on campaign term pages. [\#4933](https://github.com/DoSomething/phoenix/pull/4933) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.3](https://github.com/dosomething/phoenix/tree/v1.1.3) (2015-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.2...v1.1.3)

**Fixed bugs:**

- Thor User Profiles Aren't Displaying All Campaign Images [\#4897](https://github.com/DoSomething/phoenix/issues/4897)

**Merged pull requests:**

- Provides temporary solution for API output of translatable fields. [\#4923](https://github.com/DoSomething/phoenix/pull/4923) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.2](https://github.com/dosomething/phoenix/tree/v1.1.2) (2015-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.1...v1.1.2)

**Closed issues:**

- Global: Add Global English language [\#4911](https://github.com/DoSomething/phoenix/issues/4911)

**Merged pull requests:**

- Fixes \#4911: adds "English, Global" language. [\#4921](https://github.com/DoSomething/phoenix/pull/4921) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.1](https://github.com/dosomething/phoenix/tree/v1.1.1) (2015-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.1.0...v1.1.1)

**Fixed bugs:**

- Thor Internal Search Does Not Show Images [\#4894](https://github.com/DoSomething/phoenix/issues/4894)
- Flagged RBs Show NULL and 0 Statuses [\#4829](https://github.com/DoSomething/phoenix/issues/4829)
- approved/excluded/promoted fids have flagged = null status [\#4815](https://github.com/DoSomething/phoenix/issues/4815)

**Closed issues:**

- Remove 'Language-neutral' from campaign lanugages [\#4906](https://github.com/DoSomething/phoenix/issues/4906)
- Make 54 Language-neutral campaigns English [\#4904](https://github.com/DoSomething/phoenix/issues/4904)
- Thor: create Jenkins job to trigger phoenix cron and run it [\#4896](https://github.com/DoSomething/phoenix/issues/4896)
- Cleanup wonky reportback statuiiii [\#4887](https://github.com/DoSomething/phoenix/issues/4887)
- Campaign translation: Make sure translated content displayed properly [\#4834](https://github.com/DoSomething/phoenix/issues/4834)

**Merged pull requests:**

- Fixes \#4894: campaign images on search results. [\#4919](https://github.com/DoSomething/phoenix/pull/4919) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.1.0](https://github.com/dosomething/phoenix/tree/v1.1.0) (2015-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.37...v1.1.0)

**Fixed bugs:**

- Thor Internal Search Doesn't Return Results [\#4893](https://github.com/DoSomething/phoenix/issues/4893)
- Thor Tumblr Problem Share Lags [\#4892](https://github.com/DoSomething/phoenix/issues/4892)
- Thor Facebook Problem Share Post Missing Photo [\#4891](https://github.com/DoSomething/phoenix/issues/4891)
- Thor Share Buttons Appear Vertically \(vs. Horizontally\) [\#4890](https://github.com/DoSomething/phoenix/issues/4890)

**Closed issues:**

- Admin: Move campaing language selection dropdown to the top [\#4907](https://github.com/DoSomething/phoenix/issues/4907)
- Thor "Explore Campaigns" Page Doesn't Populate with Anything [\#4895](https://github.com/DoSomething/phoenix/issues/4895)

**Merged pull requests:**

- Makes campaigns translatable [\#4803](https://github.com/DoSomething/phoenix/pull/4803) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.37](https://github.com/dosomething/phoenix/tree/v1.0.37) (2015-08-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.36...v1.0.37)

**Merged pull requests:**

- Quick form submit logic fix [\#4903](https://github.com/DoSomething/phoenix/pull/4903) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.36](https://github.com/dosomething/phoenix/tree/v1.0.36) (2015-08-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.35...v1.0.36)

**Merged pull requests:**

- Adds new confirmation field & styling to form [\#4898](https://github.com/DoSomething/phoenix/pull/4898) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.35](https://github.com/dosomething/phoenix/tree/v1.0.35) (2015-08-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.34...v1.0.35)

**Fixed bugs:**

- problem share text spacing is off [\#4899](https://github.com/DoSomething/phoenix/issues/4899)

**Merged pull requests:**

- Fix style bug on problem shares [\#4900](https://github.com/DoSomething/phoenix/pull/4900) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.34](https://github.com/dosomething/phoenix/tree/v1.0.34) (2015-08-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.33...v1.0.34)

**Fixed bugs:**

- reportback inbox submission query retrieval issue [\#4797](https://github.com/DoSomething/phoenix/issues/4797)

**Closed issues:**

- Campaign translation: set Session language detection [\#4883](https://github.com/DoSomething/phoenix/issues/4883)
- Login Message Broker requests to Northstar [\#4010](https://github.com/DoSomething/phoenix/issues/4010)

**Merged pull requests:**

- Wrote a query to find flagged/null items. [\#4889](https://github.com/DoSomething/phoenix/pull/4889) ([angaither](https://github.com/angaither))

## [v1.0.33](https://github.com/dosomething/phoenix/tree/v1.0.33) (2015-08-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.32...v1.0.33)

**Closed issues:**

- add Mexican Spanish as language option [\#4881](https://github.com/DoSomething/phoenix/issues/4881)
- Images are missing after enabling ds-global [\#4870](https://github.com/DoSomething/phoenix/issues/4870)
- Campaign translation: Make provided list of fields translatable [\#4835](https://github.com/DoSomething/phoenix/issues/4835)
- Campaign translation: copy original content to translatable fields [\#4832](https://github.com/DoSomething/phoenix/issues/4832)
- Win module shares [\#4811](https://github.com/DoSomething/phoenix/issues/4811)
- Google Analytics: Fender Refactor [\#4793](https://github.com/DoSomething/phoenix/issues/4793)

**Merged pull requests:**

- Add a query string to bust cache on deploys. [\#4888](https://github.com/DoSomething/phoenix/pull/4888) ([DFurnes](https://github.com/DFurnes))
- Google analytics refactor [\#4882](https://github.com/DoSomething/phoenix/pull/4882) ([sbsmith86](https://github.com/sbsmith86))
- Updating win module share language [\#4875](https://github.com/DoSomething/phoenix/pull/4875) ([sbsmith86](https://github.com/sbsmith86))
- Hot module refactor [\#4868](https://github.com/DoSomething/phoenix/pull/4868) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.32](https://github.com/dosomething/phoenix/tree/v1.0.32) (2015-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.31...v1.0.32)

**Fixed bugs:**

- when editors and/or member support roles review reportbacks, flagged status is set to null [\#4871](https://github.com/DoSomething/phoenix/issues/4871)

**Merged pull requests:**

- Allow extra roles to review/edit reportbacks. [\#4872](https://github.com/DoSomething/phoenix/pull/4872) ([angaither](https://github.com/angaither))

## [v1.0.31](https://github.com/dosomething/phoenix/tree/v1.0.31) (2015-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.30...v1.0.31)

**Merged pull requests:**

- Additional reportback cleanup from role issues [\#4878](https://github.com/DoSomething/phoenix/pull/4878) ([angaither](https://github.com/angaither))

## [v1.0.30](https://github.com/dosomething/phoenix/tree/v1.0.30) (2015-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.29...v1.0.30)

**Closed issues:**

- Drupal Core Critical - Multiple Vulnerabilities - SA-CORE-2015-003 [\#4874](https://github.com/DoSomething/phoenix/issues/4874)

**Merged pull requests:**

- Updates Drupal Core to 7.39. [\#4877](https://github.com/DoSomething/phoenix/pull/4877) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.29](https://github.com/dosomething/phoenix/tree/v1.0.29) (2015-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.28...v1.0.29)

**Closed issues:**

- Ctools - Critical - Multiple Vulnerabilities - SA-CONTRIB-2015-141 [\#4873](https://github.com/DoSomething/phoenix/issues/4873)
- Import and Test Production DB dump on Thor RDS [\#4827](https://github.com/DoSomething/phoenix/issues/4827)
- Display reportback [\#4812](https://github.com/DoSomething/phoenix/issues/4812)

**Merged pull requests:**

- Updates Ctools to 1.8. [\#4876](https://github.com/DoSomething/phoenix/pull/4876) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Display and style promoted reportback image [\#4865](https://github.com/DoSomething/phoenix/pull/4865) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.28](https://github.com/dosomething/phoenix/tree/v1.0.28) (2015-08-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.27...v1.0.28)

**Closed issues:**

- don't display problem shares when campaign has win module [\#4857](https://github.com/DoSomething/phoenix/issues/4857)

**Merged pull requests:**

- Give '' as default status. [\#4864](https://github.com/DoSomething/phoenix/pull/4864) ([angaither](https://github.com/angaither))

## [v1.0.27](https://github.com/dosomething/phoenix/tree/v1.0.27) (2015-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.26...v1.0.27)

**Merged pull requests:**

- Hide problem shares when win module is enabled [\#4862](https://github.com/DoSomething/phoenix/pull/4862) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.26](https://github.com/dosomething/phoenix/tree/v1.0.26) (2015-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.25...v1.0.26)

**Closed issues:**

- Pull in a random promoted image  [\#4809](https://github.com/DoSomething/phoenix/issues/4809)

**Merged pull requests:**

- This value was set to approved above, but since that's commented out,… [\#4863](https://github.com/DoSomething/phoenix/pull/4863) ([angaither](https://github.com/angaither))
- Adds random promoted image to win module [\#4859](https://github.com/DoSomething/phoenix/pull/4859) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.25](https://github.com/dosomething/phoenix/tree/v1.0.25) (2015-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.24...v1.0.25)

**Fixed bugs:**

- Tmblr Problem Share Functionality Lagging [\#4837](https://github.com/DoSomething/phoenix/issues/4837)

**Closed issues:**

- Create Solr Server for Thor Environment [\#4824](https://github.com/DoSomething/phoenix/issues/4824)
- Create RDS/MySQL Server for Thor Environment [\#4823](https://github.com/DoSomething/phoenix/issues/4823)
- Create Redis Server for Thor Environment [\#4822](https://github.com/DoSomething/phoenix/issues/4822)
- Setup Thor Environment Webhead [\#4820](https://github.com/DoSomething/phoenix/issues/4820)
- Display author callout under the win header [\#4808](https://github.com/DoSomething/phoenix/issues/4808)
- Display image and progress [\#4807](https://github.com/DoSomething/phoenix/issues/4807)
- Image node reference [\#4804](https://github.com/DoSomething/phoenix/issues/4804)
- Add new OP/column to reportback log [\#4753](https://github.com/DoSomething/phoenix/issues/4753)
- remove feature flag for hot module [\#4656](https://github.com/DoSomething/phoenix/issues/4656)

**Merged pull requests:**

- Moving images to sites/default directory [\#4861](https://github.com/DoSomething/phoenix/pull/4861) ([sbsmith86](https://github.com/sbsmith86))
- Adds install hook to remove feature flag variable [\#4860](https://github.com/DoSomething/phoenix/pull/4860) ([deadlybutter](https://github.com/deadlybutter))
- Improves ds pull stage script. [\#4856](https://github.com/DoSomething/phoenix/pull/4856) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Changes win module background field to image node [\#4854](https://github.com/DoSomething/phoenix/pull/4854) ([deadlybutter](https://github.com/deadlybutter))
- Win module [\#4848](https://github.com/DoSomething/phoenix/pull/4848) ([sbsmith86](https://github.com/sbsmith86))
- Adds promoted/flagged reasons to the reportback view [\#4846](https://github.com/DoSomething/phoenix/pull/4846) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.24](https://github.com/dosomething/phoenix/tree/v1.0.24) (2015-08-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.23...v1.0.24)

**Fixed bugs:**

- two files from same rb \(one flagged one approved\) causes incorrect flagged status [\#4847](https://github.com/DoSomething/phoenix/issues/4847)
- live query was resetting value set by cron, causing quantity displayed to be off [\#4748](https://github.com/DoSomething/phoenix/issues/4748)
- Reportback flagged status [\#4529](https://github.com/DoSomething/phoenix/issues/4529)

**Closed issues:**

- Drush make fails on downloading dependencies from github [\#4853](https://github.com/DoSomething/phoenix/issues/4853)
- Flagging RB Doesn't Always Change Total Approved Quantity [\#4633](https://github.com/DoSomething/phoenix/issues/4633)

**Merged pull requests:**

- Adds review fix [\#4852](https://github.com/DoSomething/phoenix/pull/4852) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.23](https://github.com/dosomething/phoenix/tree/v1.0.23) (2015-08-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.22...v1.0.23)

**Fixed bugs:**

- Win module timing logic is wrong [\#4843](https://github.com/DoSomething/phoenix/issues/4843)
- Undefined properties in reportback in dblog [\#4790](https://github.com/DoSomething/phoenix/issues/4790)

**Merged pull requests:**

- Updates win module timing logic [\#4845](https://github.com/DoSomething/phoenix/pull/4845) ([deadlybutter](https://github.com/deadlybutter))
- Fixes various bug reports in dblog [\#4844](https://github.com/DoSomething/phoenix/pull/4844) ([deadlybutter](https://github.com/deadlybutter))
- Removes hot module feature flag [\#4841](https://github.com/DoSomething/phoenix/pull/4841) ([deadlybutter](https://github.com/deadlybutter))
- Adds progress copy override [\#4840](https://github.com/DoSomething/phoenix/pull/4840) ([deadlybutter](https://github.com/deadlybutter))
- Adds win module background image field [\#4839](https://github.com/DoSomething/phoenix/pull/4839) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.22](https://github.com/dosomething/phoenix/tree/v1.0.22) (2015-08-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.21...v1.0.22)

**Closed issues:**

- Share prompt [\#4806](https://github.com/DoSomething/phoenix/issues/4806)
- Win copy field [\#4805](https://github.com/DoSomething/phoenix/issues/4805)

**Merged pull requests:**

- Adds win copy [\#4833](https://github.com/DoSomething/phoenix/pull/4833) ([deadlybutter](https://github.com/deadlybutter))
- Adds share prompt [\#4831](https://github.com/DoSomething/phoenix/pull/4831) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.21](https://github.com/dosomething/phoenix/tree/v1.0.21) (2015-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.20...v1.0.21)

**Closed issues:**

- Vagrant Troubleshooting with Joe [\#4821](https://github.com/DoSomething/phoenix/issues/4821)
- Win module feature flag [\#4813](https://github.com/DoSomething/phoenix/issues/4813)
- Win module timing [\#4810](https://github.com/DoSomething/phoenix/issues/4810)

**Merged pull requests:**

- Adds win module feature flag and timing [\#4830](https://github.com/DoSomething/phoenix/pull/4830) ([deadlybutter](https://github.com/deadlybutter))
- Removes user drush file created specifically for updating user field [\#4817](https://github.com/DoSomething/phoenix/pull/4817) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.20](https://github.com/dosomething/phoenix/tree/v1.0.20) (2015-08-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.19...v1.0.20)

**Closed issues:**

- Enable UK shipments [\#4732](https://github.com/DoSomething/phoenix/issues/4732)
- Hot Module Launch Checklist [\#4651](https://github.com/DoSomething/phoenix/issues/4651)
- Testing plan [\#4646](https://github.com/DoSomething/phoenix/issues/4646)

**Merged pull requests:**

- Improves UK address form. [\#4816](https://github.com/DoSomething/phoenix/pull/4816) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.19](https://github.com/dosomething/phoenix/tree/v1.0.19) (2015-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.18...v1.0.19)

## [v1.0.18](https://github.com/dosomething/phoenix/tree/v1.0.18) (2015-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.17...v1.0.18)

**Fixed bugs:**

- clean up reportback file flagged status [\#4779](https://github.com/DoSomething/phoenix/issues/4779)

**Closed issues:**

- print rbid into inbox of /rb [\#4795](https://github.com/DoSomething/phoenix/issues/4795)
- add problem shares to SMS games [\#4560](https://github.com/DoSomething/phoenix/issues/4560)

**Merged pull requests:**

- Reportback data cleanup. [\#4814](https://github.com/DoSomething/phoenix/pull/4814) ([angaither](https://github.com/angaither))
- Don't pre-select approved on rb file reviews. [\#4802](https://github.com/DoSomething/phoenix/pull/4802) ([angaither](https://github.com/angaither))
- Reverts features on enabling ds-global. [\#4801](https://github.com/DoSomething/phoenix/pull/4801) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Added new param to files query, can order by asc/desc [\#4800](https://github.com/DoSomething/phoenix/pull/4800) ([angaither](https://github.com/angaither))
- Show problem shares on SMS campaigns [\#4799](https://github.com/DoSomething/phoenix/pull/4799) ([sbsmith86](https://github.com/sbsmith86))
- Added rbid and fid to inbox. [\#4798](https://github.com/DoSomething/phoenix/pull/4798) ([angaither](https://github.com/angaither))

## [v1.0.17](https://github.com/dosomething/phoenix/tree/v1.0.17) (2015-08-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.16...v1.0.17)

**Fixed bugs:**

- SQL error on running database update [\#4792](https://github.com/DoSomething/phoenix/issues/4792)

**Closed issues:**

- new reportbacks are skipping the inbox [\#4775](https://github.com/DoSomething/phoenix/issues/4775)
- add UTM parameters to reportback share URLs [\#4611](https://github.com/DoSomething/phoenix/issues/4611)
- add UTM parameters to problem share URLs [\#4575](https://github.com/DoSomething/phoenix/issues/4575)

**Merged pull requests:**

- Update to fix query to be more inclusive. [\#4796](https://github.com/DoSomething/phoenix/pull/4796) ([weerd](https://github.com/weerd))
- Share Bar [\#4794](https://github.com/DoSomething/phoenix/pull/4794) ([sbsmith86](https://github.com/sbsmith86))
- Adding SEO changes for front page and campaigns pages [\#4778](https://github.com/DoSomething/phoenix/pull/4778) ([blisteringherb](https://github.com/blisteringherb))
- Adding Brazil and Mexico admin roles and perms [\#4776](https://github.com/DoSomething/phoenix/pull/4776) ([blisteringherb](https://github.com/blisteringherb))

## [v1.0.16](https://github.com/dosomething/phoenix/tree/v1.0.16) (2015-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.15...v1.0.16)

**Fixed bugs:**

- Reportback change log isn't displaying [\#4785](https://github.com/DoSomething/phoenix/issues/4785)

**Merged pull requests:**

- Give not null a default, causing sql errors. [\#4791](https://github.com/DoSomething/phoenix/pull/4791) ([angaither](https://github.com/angaither))

## [v1.0.15](https://github.com/dosomething/phoenix/tree/v1.0.15) (2015-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.14...v1.0.15)

**Fixed bugs:**

- tips on action page in do it section aren't displaying [\#4788](https://github.com/DoSomething/phoenix/issues/4788)

**Closed issues:**

- Expose flagged status/file status on admin view [\#4786](https://github.com/DoSomething/phoenix/issues/4786)

**Merged pull requests:**

- Add flagged bool to rb admin view [\#4787](https://github.com/DoSomething/phoenix/pull/4787) ([angaither](https://github.com/angaither))

## [v1.0.14](https://github.com/dosomething/phoenix/tree/v1.0.14) (2015-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.13...v1.0.14)

**Closed issues:**

- SASS Cleanup: Remove scss/helpers [\#4516](https://github.com/DoSomething/phoenix/issues/4516)
- SASS Clean up: Get rid of /campaigns directory in scss/content [\#4515](https://github.com/DoSomething/phoenix/issues/4515)
- Fix scholarship styling on persistent nav [\#4440](https://github.com/DoSomething/phoenix/issues/4440)

**Merged pull requests:**

- Sasslint [\#4783](https://github.com/DoSomething/phoenix/pull/4783) ([DFurnes](https://github.com/DFurnes))
- Update copy for Zendesk errors. [\#4782](https://github.com/DoSomething/phoenix/pull/4782) ([DFurnes](https://github.com/DFurnes))

## [v1.0.13](https://github.com/dosomething/phoenix/tree/v1.0.13) (2015-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.12...v1.0.13)

**Fixed bugs:**

- Zendesk ticket submission errors [\#4780](https://github.com/DoSomething/phoenix/issues/4780)
- Stat card progress [\#4771](https://github.com/DoSomething/phoenix/issues/4771)

**Merged pull requests:**

- Installs translation modules [\#4784](https://github.com/DoSomething/phoenix/pull/4784) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Remove `show\_campaign\_progress` flag [\#4772](https://github.com/DoSomething/phoenix/pull/4772) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.12](https://github.com/dosomething/phoenix/tree/v1.0.12) (2015-08-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.11...v1.0.12)

**Closed issues:**

- custom GA event for hot shares [\#4644](https://github.com/DoSomething/phoenix/issues/4644)

**Merged pull requests:**

- Custom GA events for hot module shares [\#4781](https://github.com/DoSomething/phoenix/pull/4781) ([sbsmith86](https://github.com/sbsmith86))

## [v1.0.11](https://github.com/dosomething/phoenix/tree/v1.0.11) (2015-08-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.10...v1.0.11)

**Fixed bugs:**

- Flagged status should be null by default [\#4756](https://github.com/DoSomething/phoenix/issues/4756)

**Merged pull requests:**

- Fix bug in how drupal reads the schema for RB table. [\#4777](https://github.com/DoSomething/phoenix/pull/4777) ([weerd](https://github.com/weerd))

## [v1.0.10](https://github.com/dosomething/phoenix/tree/v1.0.10) (2015-08-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.9...v1.0.10)

**Merged pull requests:**

- Revert "Enables simple campaign translation for Global project" [\#4774](https://github.com/DoSomething/phoenix/pull/4774) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.9](https://github.com/dosomething/phoenix/tree/v1.0.9) (2015-08-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.8...v1.0.9)

**Closed issues:**

- progress and goal not showing on prod [\#4770](https://github.com/DoSomething/phoenix/issues/4770)

**Merged pull requests:**

- Hot fix for hot module total numbers [\#4773](https://github.com/DoSomething/phoenix/pull/4773) ([angaither](https://github.com/angaither))

## [v1.0.8](https://github.com/dosomething/phoenix/tree/v1.0.8) (2015-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.7...v1.0.8)

**Closed issues:**

- Twitter Permalink Share Shows Jumbled Copy Where Apostrophe Should Be [\#4624](https://github.com/DoSomething/phoenix/issues/4624)
- dosomething\_search\_index view mode causes overridden Features [\#3449](https://github.com/DoSomething/phoenix/issues/3449)

**Merged pull requests:**

- Decode twitter text [\#4769](https://github.com/DoSomething/phoenix/pull/4769) ([sbsmith86](https://github.com/sbsmith86))
- Enables simple campaign translation for Global project [\#4768](https://github.com/DoSomething/phoenix/pull/4768) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.7](https://github.com/dosomething/phoenix/tree/v1.0.7) (2015-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.6...v1.0.7)

**Fixed bugs:**

- Undefined index on page loads [\#4760](https://github.com/DoSomething/phoenix/issues/4760)
- Can't generate reportbacks because of message broker error [\#4758](https://github.com/DoSomething/phoenix/issues/4758)

**Closed issues:**

- Invalid argument supplied for foreach\(\) in Campaign class [\#4763](https://github.com/DoSomething/phoenix/issues/4763)
- v1.0.6 Critical prod error: E\_ERROR: Call to undefined function publish\(\) [\#4761](https://github.com/DoSomething/phoenix/issues/4761)
- Undefined index notice in Campaign class [\#4759](https://github.com/DoSomething/phoenix/issues/4759)
- Check campaign high seasons in the db [\#4724](https://github.com/DoSomething/phoenix/issues/4724)
- Homepage video takeover [\#4706](https://github.com/DoSomething/phoenix/issues/4706)
- admin styling off on staging [\#4639](https://github.com/DoSomething/phoenix/issues/4639)

**Merged pull requests:**

- Fixes overridden status of dosomething\_campaign\_run and dosomething\_fact\_page features [\#4766](https://github.com/DoSomething/phoenix/pull/4766) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixing bug with helper isset function [\#4765](https://github.com/DoSomething/phoenix/pull/4765) ([weerd](https://github.com/weerd))
- fixes invalid argument in foreach block for mobile app date [\#4764](https://github.com/DoSomething/phoenix/pull/4764) ([chloealee](https://github.com/chloealee))
- Fixes undefined index on page load [\#4762](https://github.com/DoSomething/phoenix/pull/4762) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.6](https://github.com/dosomething/phoenix/tree/v1.0.6) (2015-07-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.5...v1.0.6)

**Closed issues:**

- Add date fields to campaign template for mobile app support [\#4723](https://github.com/DoSomething/phoenix/issues/4723)

**Merged pull requests:**

- Updates reportback quantity logic [\#4757](https://github.com/DoSomething/phoenix/pull/4757) ([deadlybutter](https://github.com/deadlybutter))
- creates convertDate helper function and adds field\_mobile\_app\_date to… [\#4754](https://github.com/DoSomething/phoenix/pull/4754) ([chloealee](https://github.com/chloealee))

## [v1.0.5](https://github.com/dosomething/phoenix/tree/v1.0.5) (2015-07-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.4...v1.0.5)

**Fixed bugs:**

- can't submit initial photo for reportback [\#4751](https://github.com/DoSomething/phoenix/issues/4751)
- Display of readable timing goal is off [\#4714](https://github.com/DoSomething/phoenix/issues/4714)
- Graph: Cross Browser Issues [\#4695](https://github.com/DoSomething/phoenix/issues/4695)

**Closed issues:**

- \# of hours left should start at 48 hours for Hot Module [\#4750](https://github.com/DoSomething/phoenix/issues/4750)
- admins can no longer change status of rb [\#4749](https://github.com/DoSomething/phoenix/issues/4749)
- Graph dates not corresponding with rb submission dates [\#4747](https://github.com/DoSomething/phoenix/issues/4747)
- SMS webform \*Know it\* section missing from the Admin View [\#4744](https://github.com/DoSomething/phoenix/issues/4744)
- Include third party opt\_in values in Retrieve a campaign endpoint value [\#4735](https://github.com/DoSomething/phoenix/issues/4735)

**Merged pull requests:**

- Hot module: Add safety checks for null values [\#4755](https://github.com/DoSomething/phoenix/pull/4755) ([sbsmith86](https://github.com/sbsmith86))
- Makes the hot module timing conditional based on hours [\#4752](https://github.com/DoSomething/phoenix/pull/4752) ([deadlybutter](https://github.com/deadlybutter))
- Update to include mobile commons and mailchimp data to campaign response. [\#4746](https://github.com/DoSomething/phoenix/pull/4746) ([weerd](https://github.com/weerd))
- Adds know it to sms view [\#4745](https://github.com/DoSomething/phoenix/pull/4745) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.4](https://github.com/dosomething/phoenix/tree/v1.0.4) (2015-07-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.3...v1.0.4)

## [v1.0.3](https://github.com/dosomething/phoenix/tree/v1.0.3) (2015-07-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.2...v1.0.3)

**Fixed bugs:**

- Hot module tumblr share  [\#4741](https://github.com/DoSomething/phoenix/issues/4741)

**Merged pull requests:**

- Hot module tumblr [\#4743](https://github.com/DoSomething/phoenix/pull/4743) ([sbsmith86](https://github.com/sbsmith86))
- Creates ds-global script. [\#4742](https://github.com/DoSomething/phoenix/pull/4742) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v1.0.2](https://github.com/dosomething/phoenix/tree/v1.0.2) (2015-07-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.1...v1.0.2)

**Fixed bugs:**

- Hot module graph appears empty [\#4739](https://github.com/DoSomething/phoenix/issues/4739)
- bring back previous view of /node/\[nid\]/rb/reviewed [\#4728](https://github.com/DoSomething/phoenix/issues/4728)

**Merged pull requests:**

- Updates graph query to use the new name [\#4740](https://github.com/DoSomething/phoenix/pull/4740) ([deadlybutter](https://github.com/deadlybutter))
- Bump Vagrant box version to 1.0.4. Update box name. [\#4738](https://github.com/DoSomething/phoenix/pull/4738) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- adding all new mobile app fields [\#4737](https://github.com/DoSomething/phoenix/pull/4737) ([chloealee](https://github.com/chloealee))
- Updates reportback view structure [\#4736](https://github.com/DoSomething/phoenix/pull/4736) ([deadlybutter](https://github.com/deadlybutter))

## [v1.0.1](https://github.com/dosomething/phoenix/tree/v1.0.1) (2015-07-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v1.0.0...v1.0.1)

**Fixed bugs:**

- Hot module json not sending correct max [\#4730](https://github.com/DoSomething/phoenix/issues/4730)
- Graph: Goal line leaves chart [\#4727](https://github.com/DoSomething/phoenix/issues/4727)

**Closed issues:**

- Replace getReportbackItems\(\) method [\#4700](https://github.com/DoSomething/phoenix/issues/4700)
- Replace getKudos\(\) method [\#4699](https://github.com/DoSomething/phoenix/issues/4699)

**Merged pull requests:**

- Select the max total from the max timestamp. [\#4734](https://github.com/DoSomething/phoenix/pull/4734) ([angaither](https://github.com/angaither))
- Graph: Scale math [\#4733](https://github.com/DoSomething/phoenix/pull/4733) ([sbsmith86](https://github.com/sbsmith86))
- Fixing small bug when generating URI for single resource and adding URI property to other resources. [\#4725](https://github.com/DoSomething/phoenix/pull/4725) ([weerd](https://github.com/weerd))

## [v1.0.0](https://github.com/dosomething/phoenix/tree/v1.0.0) (2015-07-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.25...v1.0.0)

**Fixed bugs:**

- Graph: graph doesn't scale after passing the goal line [\#4696](https://github.com/DoSomething/phoenix/issues/4696)
- promoted reason/flagged not being saved [\#4658](https://github.com/DoSomething/phoenix/issues/4658)

**Merged pull requests:**

- Renames this project to dosomething/phoenix. [\#4731](https://github.com/DoSomething/phoenix/pull/4731) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Update Neue references to point to Forge. [\#4729](https://github.com/DoSomething/phoenix/pull/4729) ([DFurnes](https://github.com/DFurnes))
- DoSomething Global module. [\#4726](https://github.com/DoSomething/phoenix/pull/4726) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Adds promoted/flagged reasons to the reportback log [\#4722](https://github.com/DoSomething/phoenix/pull/4722) ([deadlybutter](https://github.com/deadlybutter))

## [v0.5.25](https://github.com/dosomething/phoenix/tree/v0.5.25) (2015-07-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.24...v0.5.25)

**Fixed bugs:**

- write a script that retroactively fixes flagging issue [\#4713](https://github.com/DoSomething/phoenix/issues/4713)

**Closed issues:**

- add player names to SMS form for multi-player games [\#4499](https://github.com/DoSomething/phoenix/issues/4499)
- Goal share buttons [\#4447](https://github.com/DoSomething/phoenix/issues/4447)

**Merged pull requests:**

- Fixes old typo that caused user var not to get set. [\#4721](https://github.com/DoSomething/phoenix/pull/4721) ([angaither](https://github.com/angaither))
- Added update query to set flagged status to 1 [\#4719](https://github.com/DoSomething/phoenix/pull/4719) ([angaither](https://github.com/angaither))
- Remove scale steps from graph [\#4718](https://github.com/DoSomething/phoenix/pull/4718) ([sbsmith86](https://github.com/sbsmith86))
- Fixes minor time left bugs [\#4717](https://github.com/DoSomething/phoenix/pull/4717) ([deadlybutter](https://github.com/deadlybutter))
- Hot module cross browser [\#4716](https://github.com/DoSomething/phoenix/pull/4716) ([sbsmith86](https://github.com/sbsmith86))
- Campaign class update [\#4715](https://github.com/DoSomething/phoenix/pull/4715) ([weerd](https://github.com/weerd))
- Form updates for multiplayer SMS games [\#4710](https://github.com/DoSomething/phoenix/pull/4710) ([DFurnes](https://github.com/DFurnes))

## [v0.5.24](https://github.com/dosomething/phoenix/tree/v0.5.24) (2015-07-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.23...v0.5.24)

**Fixed bugs:**

- Hot module displays even when date is set to not now  [\#4707](https://github.com/DoSomething/phoenix/issues/4707)

**Merged pull requests:**

- Hot Module: Social Stuff [\#4712](https://github.com/DoSomething/phoenix/pull/4712) ([sbsmith86](https://github.com/sbsmith86))
- fix date bug [\#4711](https://github.com/DoSomething/phoenix/pull/4711) ([chloealee](https://github.com/chloealee))

## [v0.5.23](https://github.com/dosomething/phoenix/tree/v0.5.23) (2015-07-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.22...v0.5.23)

**Fixed bugs:**

- Array flip error on campaign nodes [\#4689](https://github.com/DoSomething/phoenix/issues/4689)
- API Reportback endpoint returns empty object instead of error message when not valid. [\#4490](https://github.com/DoSomething/phoenix/issues/4490)

**Closed issues:**

- Make all exposed properties without values be NULL [\#4642](https://github.com/DoSomething/phoenix/issues/4642)
- Expose all object properties in resources even if doesn't have a value. [\#4641](https://github.com/DoSomething/phoenix/issues/4641)
- Add register & login custom events [\#4589](https://github.com/DoSomething/phoenix/issues/4589)
- Include kudos info in reportback-items data returned from the API [\#4484](https://github.com/DoSomething/phoenix/issues/4484)

**Merged pull requests:**

- Updates to bring kudos in line with standard class code. [\#4708](https://github.com/DoSomething/phoenix/pull/4708) ([weerd](https://github.com/weerd))
- Adds register & login custom events [\#4705](https://github.com/DoSomething/phoenix/pull/4705) ([deadlybutter](https://github.com/deadlybutter))
- Campaign class bug fix [\#4704](https://github.com/DoSomething/phoenix/pull/4704) ([weerd](https://github.com/weerd))
- Wraps author image load in null check [\#4698](https://github.com/DoSomething/phoenix/pull/4698) ([deadlybutter](https://github.com/deadlybutter))
- Fix linting errors in Donate form code. [\#4697](https://github.com/DoSomething/phoenix/pull/4697) ([DFurnes](https://github.com/DFurnes))
- Update watch task to use ESLint. [\#4694](https://github.com/DoSomething/phoenix/pull/4694) ([DFurnes](https://github.com/DFurnes))
- ESLint [\#4692](https://github.com/DoSomething/phoenix/pull/4692) ([DFurnes](https://github.com/DFurnes))
- Reportback response all the things [\#4675](https://github.com/DoSomething/phoenix/pull/4675) ([weerd](https://github.com/weerd))

## [v0.5.22](https://github.com/dosomething/phoenix/tree/v0.5.22) (2015-07-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.21...v0.5.22)

**Merged pull requests:**

- Fix capitalization. [\#4693](https://github.com/DoSomething/phoenix/pull/4693) ([DFurnes](https://github.com/DFurnes))

## [v0.5.21](https://github.com/dosomething/phoenix/tree/v0.5.21) (2015-07-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.20...v0.5.21)

**Fixed bugs:**

- Not seeing graph on some hot phase campaigns [\#4685](https://github.com/DoSomething/phoenix/issues/4685)
- High season end date not outputting correctly [\#4673](https://github.com/DoSomething/phoenix/issues/4673)
- Campaign Thumbnails Not Appearing on Affiliate /campaigns [\#4630](https://github.com/DoSomething/phoenix/issues/4630)
- admin fields no longer hidden when campaign\_type = SMS game [\#4319](https://github.com/DoSomething/phoenix/issues/4319)

**Closed issues:**

- Ensure hot module is only enabled when the dates are correct [\#4672](https://github.com/DoSomething/phoenix/issues/4672)
- give editors access to Goal Settings group on Custom Settings [\#4653](https://github.com/DoSomething/phoenix/issues/4653)
- Override Feature Input Doesn't Register [\#4652](https://github.com/DoSomething/phoenix/issues/4652)
- Can't Delete Reportbacks [\#4623](https://github.com/DoSomething/phoenix/issues/4623)
- Need JS Event for Action Pageviews Count in Optimizely [\#4617](https://github.com/DoSomething/phoenix/issues/4617)
- update help text on /node/add/fact [\#4612](https://github.com/DoSomething/phoenix/issues/4612)
- Log-in button on campaigns works as a 'Signup' [\#4608](https://github.com/DoSomething/phoenix/issues/4608)
- Graph [\#4606](https://github.com/DoSomething/phoenix/issues/4606)
- update problem fact help text [\#4590](https://github.com/DoSomething/phoenix/issues/4590)
- problem shares only when campaign is "not hot" [\#4478](https://github.com/DoSomething/phoenix/issues/4478)
- Update sum\_rb\_quanity -\> sum\_rb\_quantity [\#4468](https://github.com/DoSomething/phoenix/issues/4468)
- GET requests to https://www.dosomething.org/api/v1/users.json?parameters\[email\]= failing [\#4426](https://github.com/DoSomething/phoenix/issues/4426)
- Should updated quantity mean re-reviewing a reportback? [\#4225](https://github.com/DoSomething/phoenix/issues/4225)
- API password reset link is the wrong request type [\#4140](https://github.com/DoSomething/phoenix/issues/4140)
- Old Person Message Broker [\#3849](https://github.com/DoSomething/phoenix/issues/3849)

**Merged pull requests:**

- Updates campaign form script [\#4691](https://github.com/DoSomething/phoenix/pull/4691) ([deadlybutter](https://github.com/deadlybutter))
- Pull HTML5Shiv from Github because of NPM package issues. [\#4690](https://github.com/DoSomething/phoenix/pull/4690) ([DFurnes](https://github.com/DFurnes))
- Add Dotty to dependencies. [\#4688](https://github.com/DoSomething/phoenix/pull/4688) ([DFurnes](https://github.com/DFurnes))
- Add setting helper. [\#4687](https://github.com/DoSomething/phoenix/pull/4687) ([DFurnes](https://github.com/DFurnes))
- Fixes timing logic [\#4686](https://github.com/DoSomething/phoenix/pull/4686) ([deadlybutter](https://github.com/deadlybutter))
- Fixes quantity spelling error [\#4684](https://github.com/DoSomething/phoenix/pull/4684) ([deadlybutter](https://github.com/deadlybutter))
- Updates problem fact help text [\#4683](https://github.com/DoSomething/phoenix/pull/4683) ([deadlybutter](https://github.com/deadlybutter))
- Tidy up scripts [\#4682](https://github.com/DoSomething/phoenix/pull/4682) ([DFurnes](https://github.com/DFurnes))
- Updates help text on /node/add/fact  [\#4681](https://github.com/DoSomething/phoenix/pull/4681) ([deadlybutter](https://github.com/deadlybutter))
- Updates reportback total to use override [\#4680](https://github.com/DoSomething/phoenix/pull/4680) ([deadlybutter](https://github.com/deadlybutter))
- Add Optimizley custom event when user is signed up for campaign. [\#4679](https://github.com/DoSomething/phoenix/pull/4679) ([DFurnes](https://github.com/DFurnes))
- Add override for reportback delete page. [\#4678](https://github.com/DoSomething/phoenix/pull/4678) ([DFurnes](https://github.com/DFurnes))
- Always sets the status to pending when updated [\#4677](https://github.com/DoSomething/phoenix/pull/4677) ([deadlybutter](https://github.com/deadlybutter))
- hot module enabled when high season is current month [\#4676](https://github.com/DoSomething/phoenix/pull/4676) ([chloealee](https://github.com/chloealee))
- Changes end date to use proper value [\#4674](https://github.com/DoSomething/phoenix/pull/4674) ([deadlybutter](https://github.com/deadlybutter))

## [v0.5.20](https://github.com/dosomething/phoenix/tree/v0.5.20) (2015-07-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.19...v0.5.20)

**Merged pull requests:**

- Hot Module Graph updates [\#4671](https://github.com/DoSomething/phoenix/pull/4671) ([sbsmith86](https://github.com/sbsmith86))

## [v0.5.19](https://github.com/dosomething/phoenix/tree/v0.5.19) (2015-07-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.18...v0.5.19)

**Closed issues:**

- hide problem share prompt + social buttons when a campaign is hot [\#4654](https://github.com/DoSomething/phoenix/issues/4654)
- changing a file's status should change the rb's flagged status [\#4621](https://github.com/DoSomething/phoenix/issues/4621)
- Output campaign author information [\#4602](https://github.com/DoSomething/phoenix/issues/4602)
- Hot phase progress copy [\#4446](https://github.com/DoSomething/phoenix/issues/4446)

**Merged pull requests:**

- Updates Drupal Core from 7.35 to 7.38. [\#4670](https://github.com/DoSomething/phoenix/pull/4670) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Allows editor to change reportback status if they made a mistake [\#4669](https://github.com/DoSomething/phoenix/pull/4669) ([deadlybutter](https://github.com/deadlybutter))
- hide social buttons when hot module is enabled [\#4668](https://github.com/DoSomething/phoenix/pull/4668) ([chloealee](https://github.com/chloealee))
- Hot Module - Display progress copy and author info [\#4667](https://github.com/DoSomething/phoenix/pull/4667) ([sbsmith86](https://github.com/sbsmith86))

## [v0.5.18](https://github.com/dosomething/phoenix/tree/v0.5.18) (2015-07-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.17...v0.5.18)

**Merged pull requests:**

- Bump Vagrant box version to 1.0.3. [\#4666](https://github.com/DoSomething/phoenix/pull/4666) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.5.17](https://github.com/dosomething/phoenix/tree/v0.5.17) (2015-07-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.16...v0.5.17)

**Closed issues:**

- Output quantity JSON to hot phase module [\#4607](https://github.com/DoSomething/phoenix/issues/4607)

**Merged pull requests:**

- Updates to fix bug in response. [\#4665](https://github.com/DoSomething/phoenix/pull/4665) ([weerd](https://github.com/weerd))
- Add jsonified campaign progress [\#4664](https://github.com/DoSomething/phoenix/pull/4664) ([angaither](https://github.com/angaither))

## [v0.5.16](https://github.com/dosomething/phoenix/tree/v0.5.16) (2015-07-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.15...v0.5.16)

**Closed issues:**

- Add a table to record the history of campaign quantity progress [\#4605](https://github.com/DoSomething/phoenix/issues/4605)
- Time left in campaign [\#4444](https://github.com/DoSomething/phoenix/issues/4444)

**Merged pull requests:**

- Updating campaign response to include all properties and null values if property has no value. [\#4663](https://github.com/DoSomething/phoenix/pull/4663) ([weerd](https://github.com/weerd))
- Adds time left for hot module [\#4662](https://github.com/DoSomething/phoenix/pull/4662) ([deadlybutter](https://github.com/deadlybutter))
- Adds saftey net to the goal [\#4661](https://github.com/DoSomething/phoenix/pull/4661) ([deadlybutter](https://github.com/deadlybutter))
- Add progress log data [\#4660](https://github.com/DoSomething/phoenix/pull/4660) ([angaither](https://github.com/angaither))
- Adds hot phase progress copy [\#4659](https://github.com/DoSomething/phoenix/pull/4659) ([deadlybutter](https://github.com/deadlybutter))
- Progress log table [\#4628](https://github.com/DoSomething/phoenix/pull/4628) ([angaither](https://github.com/angaither))

## [v0.5.15](https://github.com/dosomething/phoenix/tree/v0.5.15) (2015-07-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.14...v0.5.15)

**Closed issues:**

- Hot phase share copy [\#4637](https://github.com/DoSomething/phoenix/issues/4637)

**Merged pull requests:**

- Upating response to clean it up and fix a bug. [\#4657](https://github.com/DoSomething/phoenix/pull/4657) ([weerd](https://github.com/weerd))
- Adds hot module share copy [\#4655](https://github.com/DoSomething/phoenix/pull/4655) ([deadlybutter](https://github.com/deadlybutter))
- Hot module stat card [\#4648](https://github.com/DoSomething/phoenix/pull/4648) ([sbsmith86](https://github.com/sbsmith86))

## [v0.5.14](https://github.com/dosomething/phoenix/tree/v0.5.14) (2015-07-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.13...v0.5.14)

**Closed issues:**

- Update Kudos response to group by taxonomy term and add total count [\#4650](https://github.com/DoSomething/phoenix/issues/4650)
- Custom template for hot phase campaigns  [\#4603](https://github.com/DoSomething/phoenix/issues/4603)

**Merged pull requests:**

- Kudos response update [\#4649](https://github.com/DoSomething/phoenix/pull/4649) ([weerd](https://github.com/weerd))

## [v0.5.13](https://github.com/dosomething/phoenix/tree/v0.5.13) (2015-07-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.12...v0.5.13)

**Closed issues:**

- Incorrect entity\_save ? [\#4629](https://github.com/DoSomething/phoenix/issues/4629)

**Merged pull requests:**

- Update entity\_save from reportback\_file to reportback [\#4647](https://github.com/DoSomething/phoenix/pull/4647) ([angaither](https://github.com/angaither))

## [v0.5.12](https://github.com/dosomething/phoenix/tree/v0.5.12) (2015-07-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.11...v0.5.12)

**Closed issues:**

- add action\_kit as a shipment item on the campaign signup data form [\#4634](https://github.com/DoSomething/phoenix/issues/4634)
- Progress Update Does Not Save [\#4632](https://github.com/DoSomething/phoenix/issues/4632)
- Northstar user import [\#4631](https://github.com/DoSomething/phoenix/issues/4631)

**Merged pull requests:**

- Fly away little droops users [\#4640](https://github.com/DoSomething/phoenix/pull/4640) ([angaither](https://github.com/angaither))
- Fix typo that caused override to appear not to save. [\#4635](https://github.com/DoSomething/phoenix/pull/4635) ([angaither](https://github.com/angaither))

## [v0.5.11](https://github.com/dosomething/phoenix/tree/v0.5.11) (2015-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.10...v0.5.11)

**Fixed bugs:**

- Guzzle fails locally [\#4616](https://github.com/DoSomething/phoenix/issues/4616)

**Closed issues:**

- Approving Additional Photo + Quantity on Existing RB does not change total approved quantity [\#4626](https://github.com/DoSomething/phoenix/issues/4626)
- New job title user field [\#4604](https://github.com/DoSomething/phoenix/issues/4604)

**Merged pull requests:**

- Add action kit as an option for shipment [\#4636](https://github.com/DoSomething/phoenix/pull/4636) ([angaither](https://github.com/angaither))
- Hot Module Graph [\#4627](https://github.com/DoSomething/phoenix/pull/4627) ([sbsmith86](https://github.com/sbsmith86))
- Add user job title field [\#4622](https://github.com/DoSomething/phoenix/pull/4622) ([angaither](https://github.com/angaither))
- Wrap northstar user migrations in try/catch [\#4620](https://github.com/DoSomething/phoenix/pull/4620) ([angaither](https://github.com/angaither))

## [v0.5.10](https://github.com/dosomething/phoenix/tree/v0.5.10) (2015-06-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.9...v0.5.10)

**Closed issues:**

- Hot module feature flag [\#4614](https://github.com/DoSomething/phoenix/issues/4614)
- Remove hot module animation fields [\#4601](https://github.com/DoSomething/phoenix/issues/4601)

**Merged pull requests:**

- Update to fix Kudos response object. [\#4619](https://github.com/DoSomething/phoenix/pull/4619) ([weerd](https://github.com/weerd))
- Created feature flag to enable hot module. [\#4615](https://github.com/DoSomething/phoenix/pull/4615) ([angaither](https://github.com/angaither))

## [v0.5.9](https://github.com/dosomething/phoenix/tree/v0.5.9) (2015-06-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.8...v0.5.9)

**Closed issues:**

- members are not being subscribed to new campaign specific groups in MailChimp [\#4595](https://github.com/DoSomething/phoenix/issues/4595)
- Add campaign `high\_season` field to the campaigns endpoint [\#4564](https://github.com/DoSomething/phoenix/issues/4564)

**Merged pull requests:**

- Fixes PHP Fatal error: Class 'Transformer' not found during ds install [\#4613](https://github.com/DoSomething/phoenix/pull/4613) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.5.8](https://github.com/dosomething/phoenix/tree/v0.5.8) (2015-06-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.7...v0.5.8)

**Fixed bugs:**

- Undefined Northstar user attributes  [\#4549](https://github.com/DoSomething/phoenix/issues/4549)

**Closed issues:**

- Forward user updates from Drupal to Northstar [\#4570](https://github.com/DoSomething/phoenix/issues/4570)
- Missing Campaign reportback noun/verb properties at GET campaigns/:id [\#4554](https://github.com/DoSomething/phoenix/issues/4554)
- Set animation file status to 1 when saved [\#4461](https://github.com/DoSomething/phoenix/issues/4461)
- Hot Module - Variation D [\#4451](https://github.com/DoSomething/phoenix/issues/4451)
- Hot Module - Variation C [\#4450](https://github.com/DoSomething/phoenix/issues/4450)
- Hot Module - Variation B [\#4449](https://github.com/DoSomething/phoenix/issues/4449)
- Hot Module - Variation A [\#4448](https://github.com/DoSomething/phoenix/issues/4448)
- Goal animation logic  [\#4445](https://github.com/DoSomething/phoenix/issues/4445)

**Merged pull requests:**

- Campaign api update [\#4609](https://github.com/DoSomething/phoenix/pull/4609) ([weerd](https://github.com/weerd))
- Send user updates to aurora [\#4600](https://github.com/DoSomething/phoenix/pull/4600) ([angaither](https://github.com/angaither))

## [v0.5.7](https://github.com/dosomething/phoenix/tree/v0.5.7) (2015-06-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.6...v0.5.7)

**Closed issues:**

- Allow for CSV signup view to be rendered in admin theme [\#4598](https://github.com/DoSomething/phoenix/issues/4598)
- No SMS Notification Received on US Site [\#4597](https://github.com/DoSomething/phoenix/issues/4597)

**Merged pull requests:**

- Added signupcsv to the admin theme path list. [\#4599](https://github.com/DoSomething/phoenix/pull/4599) ([angaither](https://github.com/angaither))

## [v0.5.6](https://github.com/dosomething/phoenix/tree/v0.5.6) (2015-06-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.5...v0.5.6)

**Closed issues:**

- Load guzzle with composer [\#4411](https://github.com/DoSomething/phoenix/issues/4411)

**Merged pull requests:**

- Installs Guzzle lib with composer. [\#4594](https://github.com/DoSomething/phoenix/pull/4594) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.5.5](https://github.com/dosomething/phoenix/tree/v0.5.5) (2015-06-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.4...v0.5.5)

**Fixed bugs:**

- Comeback Clothes here’s what happened list: wrong HTML entities [\#4591](https://github.com/DoSomething/phoenix/issues/4591)

**Merged pull requests:**

- Fixes HTML entities in repotback caption on closed campaigns. [\#4593](https://github.com/DoSomething/phoenix/pull/4593) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.5.4](https://github.com/dosomething/phoenix/tree/v0.5.4) (2015-06-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.3...v0.5.4)

**Merged pull requests:**

- Bump Vagrant box version to 1.0.2. [\#4592](https://github.com/DoSomething/phoenix/pull/4592) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Improve build speed with shallow clones [\#4344](https://github.com/DoSomething/phoenix/pull/4344) ([cjcodes](https://github.com/cjcodes))

## [v0.5.3](https://github.com/dosomething/phoenix/tree/v0.5.3) (2015-06-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.2...v0.5.3)

**Closed issues:**

- Forgot Password Flow Not Working on International [\#4588](https://github.com/DoSomething/phoenix/issues/4588)
- Campaign finder doesn't work on Canada [\#4585](https://github.com/DoSomething/phoenix/issues/4585)

**Merged pull requests:**

- Fixing quotes in drush-intl [\#4587](https://github.com/DoSomething/phoenix/pull/4587) ([blisteringherb](https://github.com/blisteringherb))

## [v0.5.2](https://github.com/dosomething/phoenix/tree/v0.5.2) (2015-06-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.1...v0.5.2)

**Closed issues:**

- Implement Kudos API [\#4580](https://github.com/DoSomething/phoenix/issues/4580)
- Campaign Header Photos, IE 8 [\#4573](https://github.com/DoSomething/phoenix/issues/4573)
- Campaign Titles on Homepage: IE 8 [\#4572](https://github.com/DoSomething/phoenix/issues/4572)
- Add "Notes" field to Donate form [\#4566](https://github.com/DoSomething/phoenix/issues/4566)

**Merged pull requests:**

- Passing the -l param to drush to fix cron [\#4586](https://github.com/DoSomething/phoenix/pull/4586) ([blisteringherb](https://github.com/blisteringherb))
- Kudos entityification [\#4553](https://github.com/DoSomething/phoenix/pull/4553) ([weerd](https://github.com/weerd))

## [v0.5.1](https://github.com/dosomething/phoenix/tree/v0.5.1) (2015-06-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.5.0...v0.5.1)

**Fixed bugs:**

- Rotating RB Image Doesn't Save in Permalink or Backend [\#4577](https://github.com/DoSomething/phoenix/issues/4577)

**Closed issues:**

- Tumblr Sharing from Permalink on IE 8 [\#4574](https://github.com/DoSomething/phoenix/issues/4574)
- Forward user updates to northstar [\#4569](https://github.com/DoSomething/phoenix/issues/4569)
- Tips Modal Spacing Off on Mobile [\#4517](https://github.com/DoSomething/phoenix/issues/4517)
- Notify Northstar when a kudos is received [\#4472](https://github.com/DoSomething/phoenix/issues/4472)

**Merged pull requests:**

- Fix image\_rotate compatibility issue with php 5.5 [\#4578](https://github.com/DoSomething/phoenix/pull/4578) ([sbsmith86](https://github.com/sbsmith86))
- Update 'Notes' field label [\#4576](https://github.com/DoSomething/phoenix/pull/4576) ([sbsmith86](https://github.com/sbsmith86))
- \#4566: Adds 'Notes' field to Donate form, passes as metadata [\#4567](https://github.com/DoSomething/phoenix/pull/4567) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.5.0](https://github.com/dosomething/phoenix/tree/v0.5.0) (2015-06-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.130...v0.5.0)

## [v0.4.130](https://github.com/dosomething/phoenix/tree/v0.4.130) (2015-06-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.129...v0.4.130)

**Closed issues:**

- Change "item" to "reportback\_item" in API response. [\#4561](https://github.com/DoSomething/phoenix/issues/4561)
- Add problem shares modules to make file [\#4558](https://github.com/DoSomething/phoenix/issues/4558)
- Admin Functionality: Rotate Reportback Photo  [\#4512](https://github.com/DoSomething/phoenix/issues/4512)

**Merged pull requests:**

- Add problem shares to make file/ds.info [\#4563](https://github.com/DoSomething/phoenix/pull/4563) ([angaither](https://github.com/angaither))
- Quick update to property name. [\#4562](https://github.com/DoSomething/phoenix/pull/4562) ([weerd](https://github.com/weerd))
- Allow admins to rotate reportback images [\#4555](https://github.com/DoSomething/phoenix/pull/4555) ([sbsmith86](https://github.com/sbsmith86))
- Fix tip appearance on mobile. [\#4552](https://github.com/DoSomething/phoenix/pull/4552) ([DFurnes](https://github.com/DFurnes))

## [v0.4.129](https://github.com/dosomething/phoenix/tree/v0.4.129) (2015-06-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.128...v0.4.129)

## [v0.4.128](https://github.com/dosomething/phoenix/tree/v0.4.128) (2015-06-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.127...v0.4.128)

**Fixed bugs:**

- Site:member-count-readable $token undefined  [\#4550](https://github.com/DoSomething/phoenix/issues/4550)

**Merged pull requests:**

- Replace member count in title by calling the function to get it. [\#4551](https://github.com/DoSomething/phoenix/pull/4551) ([angaither](https://github.com/angaither))

## [v0.4.127](https://github.com/dosomething/phoenix/tree/v0.4.127) (2015-06-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.126...v0.4.127)

## [v0.4.126](https://github.com/dosomething/phoenix/tree/v0.4.126) (2015-06-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.125...v0.4.126)

**Closed issues:**

- add GA custom events to problem share [\#4544](https://github.com/DoSomething/phoenix/issues/4544)
- Under 13 User Flow [\#4514](https://github.com/DoSomething/phoenix/issues/4514)
- FAQ Title Change on Campaign Template [\#4509](https://github.com/DoSomething/phoenix/issues/4509)
- Sort by flagged/promoted reasons [\#4497](https://github.com/DoSomething/phoenix/issues/4497)

**Merged pull requests:**

- Custom GA even tracking for problem shares [\#4548](https://github.com/DoSomething/phoenix/pull/4548) ([sbsmith86](https://github.com/sbsmith86))
- Adds under 13 check to all opt in signups [\#4547](https://github.com/DoSomething/phoenix/pull/4547) ([deadlybutter](https://github.com/deadlybutter))
- Sort by promoted [\#4546](https://github.com/DoSomething/phoenix/pull/4546) ([angaither](https://github.com/angaither))
- Fix to restore reportbacks admin table. [\#4545](https://github.com/DoSomething/phoenix/pull/4545) ([weerd](https://github.com/weerd))
- Update FAQ callout. [\#4543](https://github.com/DoSomething/phoenix/pull/4543) ([angaither](https://github.com/angaither))

## [v0.4.125](https://github.com/dosomething/phoenix/tree/v0.4.125) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.124...v0.4.125)

## [v0.4.124](https://github.com/dosomething/phoenix/tree/v0.4.124) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.123...v0.4.124)

## [v0.4.123](https://github.com/dosomething/phoenix/tree/v0.4.123) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.122...v0.4.123)

## [v0.4.122](https://github.com/dosomething/phoenix/tree/v0.4.122) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.121...v0.4.122)

## [v0.4.121](https://github.com/dosomething/phoenix/tree/v0.4.121) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.120...v0.4.121)

## [v0.4.120](https://github.com/dosomething/phoenix/tree/v0.4.120) (2015-06-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.119...v0.4.120)

**Closed issues:**

- Replace prior campaign endpoint code to use new Campaign class [\#4541](https://github.com/DoSomething/phoenix/issues/4541)
- Write and update hook to activate campaigns [\#4540](https://github.com/DoSomething/phoenix/issues/4540)
- Expand on access control measures for resource access in API [\#4521](https://github.com/DoSomething/phoenix/issues/4521)
- Conditional Quotation Marks for Scholarship Winner Quotes [\#4507](https://github.com/DoSomething/phoenix/issues/4507)
- Show Output Total on Top of Reportbacks Tab [\#4505](https://github.com/DoSomething/phoenix/issues/4505)
- Promoted options [\#4496](https://github.com/DoSomething/phoenix/issues/4496)

**Merged pull requests:**

- Set campaign status to active [\#4542](https://github.com/DoSomething/phoenix/pull/4542) ([angaither](https://github.com/angaither))
- Feature update to add campaign retrieve single endpoint. [\#4539](https://github.com/DoSomething/phoenix/pull/4539) ([weerd](https://github.com/weerd))
- Add the total rb quantity to reviewed RB count. [\#4538](https://github.com/DoSomething/phoenix/pull/4538) ([angaither](https://github.com/angaither))
- Updates to campaign resource for new index listing. [\#4537](https://github.com/DoSomething/phoenix/pull/4537) ([weerd](https://github.com/weerd))
- Bump Vagrant box version to 1.0.1. [\#4536](https://github.com/DoSomething/phoenix/pull/4536) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Promoted reasons [\#4535](https://github.com/DoSomething/phoenix/pull/4535) ([angaither](https://github.com/angaither))
- Adding initial access control to a few resources. [\#4533](https://github.com/DoSomething/phoenix/pull/4533) ([weerd](https://github.com/weerd))

## [v0.4.119](https://github.com/dosomething/phoenix/tree/v0.4.119) (2015-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.118...v0.4.119)

**Closed issues:**

- Create a redirect url that closes the current window [\#4527](https://github.com/DoSomething/phoenix/issues/4527)
- Discussion - building and maintainence of our Drupal API [\#4284](https://github.com/DoSomething/phoenix/issues/4284)

**Merged pull requests:**

- Share functionality updates [\#4532](https://github.com/DoSomething/phoenix/pull/4532) ([sbsmith86](https://github.com/sbsmith86))
- Added sort by flagged reasons [\#4531](https://github.com/DoSomething/phoenix/pull/4531) ([angaither](https://github.com/angaither))
- Fix for small bug. [\#4530](https://github.com/DoSomething/phoenix/pull/4530) ([weerd](https://github.com/weerd))
- Campaign class transformer docs [\#4528](https://github.com/DoSomething/phoenix/pull/4528) ([weerd](https://github.com/weerd))

## [v0.4.118](https://github.com/dosomething/phoenix/tree/v0.4.118) (2015-05-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.117...v0.4.118)

**Closed issues:**

- compression on problem share image on FB [\#4522](https://github.com/DoSomething/phoenix/issues/4522)
- Campaign API endpoint -- index fields [\#4482](https://github.com/DoSomething/phoenix/issues/4482)

**Merged pull requests:**

- Saving images as png files [\#4525](https://github.com/DoSomething/phoenix/pull/4525) ([sbsmith86](https://github.com/sbsmith86))
- Campaign transformer and class [\#4494](https://github.com/DoSomething/phoenix/pull/4494) ([weerd](https://github.com/weerd))

## [v0.4.117](https://github.com/dosomething/phoenix/tree/v0.4.117) (2015-05-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.116...v0.4.117)

**Merged pull requests:**

- To help debug issues seen around under 13 people [\#4519](https://github.com/DoSomething/phoenix/pull/4519) ([angaither](https://github.com/angaither))

## [v0.4.116](https://github.com/dosomething/phoenix/tree/v0.4.116) (2015-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.115...v0.4.116)

**Merged pull requests:**

- Fixing cron and image script to work in correct directory [\#4518](https://github.com/DoSomething/phoenix/pull/4518) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.115](https://github.com/dosomething/phoenix/tree/v0.4.115) (2015-05-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.114...v0.4.115)

## [v0.4.114](https://github.com/dosomething/phoenix/tree/v0.4.114) (2015-05-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.113...v0.4.114)

**Closed issues:**

- Update imagemagick script to use current site path as parameter [\#4504](https://github.com/DoSomething/phoenix/issues/4504)
- remove unnecessary click on /admin/users [\#4498](https://github.com/DoSomething/phoenix/issues/4498)

**Merged pull requests:**

- Redirect to user profile, after search. [\#4513](https://github.com/DoSomething/phoenix/pull/4513) ([angaither](https://github.com/angaither))
- Updates cron script to run script from the correct directory [\#4511](https://github.com/DoSomething/phoenix/pull/4511) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.113](https://github.com/dosomething/phoenix/tree/v0.4.113) (2015-05-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.112...v0.4.113)

**Closed issues:**

- problem facts on social [\#4476](https://github.com/DoSomething/phoenix/issues/4476)
- sharing problem fact on action page [\#4475](https://github.com/DoSomething/phoenix/issues/4475)

**Merged pull requests:**

- Programatically finding full path to font files [\#4508](https://github.com/DoSomething/phoenix/pull/4508) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.112](https://github.com/dosomething/phoenix/tree/v0.4.112) (2015-05-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.111...v0.4.112)

**Closed issues:**

- Feature flag problem shares on action page [\#4503](https://github.com/DoSomething/phoenix/issues/4503)

**Merged pull requests:**

- Problem sharing functionality on campaign action page [\#4501](https://github.com/DoSomething/phoenix/pull/4501) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.111](https://github.com/dosomething/phoenix/tree/v0.4.111) (2015-05-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.110...v0.4.111)

**Closed issues:**

- Optimizely A/B/C/D tests on pitch page [\#4364](https://github.com/DoSomething/phoenix/issues/4364)

**Merged pull requests:**

- Fixes dosomething\_reportback dependencies. [\#4502](https://github.com/DoSomething/phoenix/pull/4502) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Removes Congo. [\#4500](https://github.com/DoSomething/phoenix/pull/4500) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.110](https://github.com/dosomething/phoenix/tree/v0.4.110) (2015-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.109...v0.4.110)

**Fixed bugs:**

- Action guide modal is wonky [\#4491](https://github.com/DoSomething/phoenix/issues/4491)
- new content issue when paginating through content search [\#4489](https://github.com/DoSomething/phoenix/issues/4489)

**Closed issues:**

- Migrate to the new Staging [\#4483](https://github.com/DoSomething/phoenix/issues/4483)
- ImageMagick experiments for drawing problem fact images [\#4471](https://github.com/DoSomething/phoenix/issues/4471)
- give org friend role access to active tab [\#3822](https://github.com/DoSomething/phoenix/issues/3822)

**Merged pull requests:**

- Kill 'has new content' check box in content search [\#4495](https://github.com/DoSomething/phoenix/pull/4495) ([angaither](https://github.com/angaither))
- Problem share images [\#4493](https://github.com/DoSomething/phoenix/pull/4493) ([angaither](https://github.com/angaither))
- Fix action guide markup. [\#4492](https://github.com/DoSomething/phoenix/pull/4492) ([DFurnes](https://github.com/DFurnes))

## [v0.4.109](https://github.com/dosomething/phoenix/tree/v0.4.109) (2015-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.108...v0.4.109)

**Fixed bugs:**

- Reportback flagging does not set flagged value to 0 [\#4485](https://github.com/DoSomething/phoenix/issues/4485)

**Merged pull requests:**

- Always be flaggin [\#4486](https://github.com/DoSomething/phoenix/pull/4486) ([angaither](https://github.com/angaither))

## [v0.4.108](https://github.com/dosomething/phoenix/tree/v0.4.108) (2015-05-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.107...v0.4.108)

## [v0.4.107](https://github.com/dosomething/phoenix/tree/v0.4.107) (2015-05-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.106...v0.4.107)

**Merged pull requests:**

- Bump Vagrant box version to 1.0.0. [\#4481](https://github.com/DoSomething/phoenix/pull/4481) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.106](https://github.com/dosomething/phoenix/tree/v0.4.106) (2015-05-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.105...v0.4.106)

**Closed issues:**

- Editor config file [\#4479](https://github.com/DoSomething/phoenix/issues/4479)
- Create universal Transformer Class for API on DS app [\#4473](https://github.com/DoSomething/phoenix/issues/4473)
- site name won't read member count token [\#4439](https://github.com/DoSomething/phoenix/issues/4439)

**Merged pull requests:**

- Added editor config file. [\#4480](https://github.com/DoSomething/phoenix/pull/4480) ([angaither](https://github.com/angaither))
- Replace html title with tokens. [\#4477](https://github.com/DoSomething/phoenix/pull/4477) ([angaither](https://github.com/angaither))
- Updates to awesome-ize Reportbacks API structure. [\#4474](https://github.com/DoSomething/phoenix/pull/4474) ([weerd](https://github.com/weerd))

## [v0.4.105](https://github.com/dosomething/phoenix/tree/v0.4.105) (2015-05-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.104...v0.4.105)

**Fixed bugs:**

- Campaigns endpoint returns all campaigns twice [\#4356](https://github.com/DoSomething/phoenix/issues/4356)
- Refactor Campaigns API endpoint [\#4110](https://github.com/DoSomething/phoenix/issues/4110)

**Closed issues:**

- Reportback count override [\#4453](https://github.com/DoSomething/phoenix/issues/4453)
- User registration API endpoint [\#4232](https://github.com/DoSomething/phoenix/issues/4232)
- API Login by email \(not username\) [\#4046](https://github.com/DoSomething/phoenix/issues/4046)

**Merged pull requests:**

- Added time\_left as var on pitch page theme. [\#4470](https://github.com/DoSomething/phoenix/pull/4470) ([angaither](https://github.com/angaither))
- Campaigns query [\#4469](https://github.com/DoSomething/phoenix/pull/4469) ([aaronschachter](https://github.com/aaronschachter))
- Updated reportback quanity to work same as signups [\#4466](https://github.com/DoSomething/phoenix/pull/4466) ([angaither](https://github.com/angaither))

## [v0.4.104](https://github.com/dosomething/phoenix/tree/v0.4.104) (2015-05-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.103...v0.4.104)

**Closed issues:**

- non-owner permalink title if user first name does not exist [\#4455](https://github.com/DoSomething/phoenix/issues/4455)
- Views security update [\#4452](https://github.com/DoSomething/phoenix/issues/4452)
- Add goal animation fields [\#4443](https://github.com/DoSomething/phoenix/issues/4443)
- Add Kudos API resource for full CRUD capabilities [\#4431](https://github.com/DoSomething/phoenix/issues/4431)

**Merged pull requests:**

- Update views module [\#4463](https://github.com/DoSomething/phoenix/pull/4463) ([aaronschachter](https://github.com/aaronschachter))
- Adding goal animation fields to campaign config form [\#4460](https://github.com/DoSomething/phoenix/pull/4460) ([sbsmith86](https://github.com/sbsmith86))
- Update user permalink name to say your friend. [\#4458](https://github.com/DoSomething/phoenix/pull/4458) ([angaither](https://github.com/angaither))
- Kudos resource [\#4432](https://github.com/DoSomething/phoenix/pull/4432) ([weerd](https://github.com/weerd))

## [v0.4.103](https://github.com/dosomething/phoenix/tree/v0.4.103) (2015-05-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.102...v0.4.103)

**Merged pull requests:**

- Removes `codercs` alias. [\#4459](https://github.com/DoSomething/phoenix/pull/4459) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.102](https://github.com/dosomething/phoenix/tree/v0.4.102) (2015-05-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.101...v0.4.102)

**Fixed bugs:**

- Only count non-flagged reportbacks [\#4454](https://github.com/DoSomething/phoenix/issues/4454)

**Closed issues:**

- Update flagged/non-flagged reportbacks [\#4456](https://github.com/DoSomething/phoenix/issues/4456)
- Generate themed Reportback images upon Reportback Form submit [\#4105](https://github.com/DoSomething/phoenix/issues/4105)

**Merged pull requests:**

- Allow for null reportback status. [\#4457](https://github.com/DoSomething/phoenix/pull/4457) ([angaither](https://github.com/angaither))
- Issue4105 reportback image processor [\#4442](https://github.com/DoSomething/phoenix/pull/4442) ([DeeZone](https://github.com/DeeZone))

## [v0.4.101](https://github.com/dosomething/phoenix/tree/v0.4.101) (2015-04-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.100...v0.4.101)

**Closed issues:**

- web signups not automatically updating for \# of ppl doing display [\#4437](https://github.com/DoSomething/phoenix/issues/4437)
- Bullets for lists in modals [\#4435](https://github.com/DoSomething/phoenix/issues/4435)
- Campaign Sign-Up Event for SMS Games in GA [\#4355](https://github.com/DoSomething/phoenix/issues/4355)
- User login events \> northstar [\#4276](https://github.com/DoSomething/phoenix/issues/4276)

**Merged pull requests:**

- Update signup cron count query [\#4438](https://github.com/DoSomething/phoenix/pull/4438) ([angaither](https://github.com/angaither))
- Add list styles to FAQ modal. [\#4436](https://github.com/DoSomething/phoenix/pull/4436) ([DFurnes](https://github.com/DFurnes))
- Send users to northstar [\#4434](https://github.com/DoSomething/phoenix/pull/4434) ([angaither](https://github.com/angaither))

## [v0.4.100](https://github.com/dosomething/phoenix/tree/v0.4.100) (2015-04-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.99...v0.4.100)

## [v0.4.99](https://github.com/dosomething/phoenix/tree/v0.4.99) (2015-04-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.98...v0.4.99)

**Fixed bugs:**

- IE 8 issues on campaigns template [\#4430](https://github.com/DoSomething/phoenix/issues/4430)
- no verification message on password reset flow [\#4429](https://github.com/DoSomething/phoenix/issues/4429)

**Closed issues:**

- Change permalink Twitter share to be the Photo Card type [\#4404](https://github.com/DoSomething/phoenix/issues/4404)

**Merged pull requests:**

- Add ES5 shim for Internet Explorer 8. [\#4433](https://github.com/DoSomething/phoenix/pull/4433) ([DFurnes](https://github.com/DFurnes))
- Update paths for custom Modernizr build. [\#4401](https://github.com/DoSomething/phoenix/pull/4401) ([DFurnes](https://github.com/DFurnes))
- Restful [\#4360](https://github.com/DoSomething/phoenix/pull/4360) ([drewish](https://github.com/drewish))

## [v0.4.98](https://github.com/dosomething/phoenix/tree/v0.4.98) (2015-04-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.97...v0.4.98)

## [v0.4.97](https://github.com/dosomething/phoenix/tree/v0.4.97) (2015-04-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.95...v0.4.97)

**Merged pull requests:**

- Expose validation object for unit tests. [\#4425](https://github.com/DoSomething/phoenix/pull/4425) ([DFurnes](https://github.com/DFurnes))
- Upgrades mocha to 1.14.0. [\#4424](https://github.com/DoSomething/phoenix/pull/4424) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.95](https://github.com/dosomething/phoenix/tree/v0.4.95) (2015-04-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.94...v0.4.95)

**Merged pull requests:**

- Fixes Mocha Unit tests. [\#4423](https://github.com/DoSomething/phoenix/pull/4423) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.94](https://github.com/dosomething/phoenix/tree/v0.4.94) (2015-04-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.93...v0.4.94)

**Closed issues:**

- Add API endpoints for Kudos functionality [\#4420](https://github.com/DoSomething/phoenix/issues/4420)

**Merged pull requests:**

- update twitter image tag [\#4422](https://github.com/DoSomething/phoenix/pull/4422) ([sbsmith86](https://github.com/sbsmith86))
- Adding new targeted action endpoint for Kudos. [\#4421](https://github.com/DoSomething/phoenix/pull/4421) ([weerd](https://github.com/weerd))

## [v0.4.93](https://github.com/dosomething/phoenix/tree/v0.4.93) (2015-04-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.92...v0.4.93)

**Fixed bugs:**

- prompt user after sign up for address collection is not prompting user right after sign up [\#4415](https://github.com/DoSomething/phoenix/issues/4415)
- signup count getting overwritten [\#4394](https://github.com/DoSomething/phoenix/issues/4394)

**Closed issues:**

- User create API: set default country [\#4413](https://github.com/DoSomething/phoenix/issues/4413)

**Merged pull requests:**

- Export Modal API for displaying campaign signup form. [\#4419](https://github.com/DoSomething/phoenix/pull/4419) ([DFurnes](https://github.com/DFurnes))
- Refactors and improves Services member create callback. [\#4418](https://github.com/DoSomething/phoenix/pull/4418) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Mobile signup count [\#4416](https://github.com/DoSomething/phoenix/pull/4416) ([angaither](https://github.com/angaither))

## [v0.4.92](https://github.com/dosomething/phoenix/tree/v0.4.92) (2015-04-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.91...v0.4.92)

**Fixed bugs:**

- 2 column gallery is not displaying properly [\#4363](https://github.com/DoSomething/phoenix/issues/4363)

**Closed issues:**

- Add twitter social share metadata to image cached images [\#4405](https://github.com/DoSomething/phoenix/issues/4405)
- Unable to change admin settings on Affiliate sites. [\#4388](https://github.com/DoSomething/phoenix/issues/4388)
- User UID displayed in password reset one time login web page message [\#4111](https://github.com/DoSomething/phoenix/issues/4111)

**Merged pull requests:**

- Use 'left' Figure modifier for duo galleries. [\#4414](https://github.com/DoSomething/phoenix/pull/4414) ([DFurnes](https://github.com/DFurnes))
- Update twitter meta tags to use photo card [\#4412](https://github.com/DoSomething/phoenix/pull/4412) ([sbsmith86](https://github.com/sbsmith86))
- Disable Drupal core email messages [\#4406](https://github.com/DoSomething/phoenix/pull/4406) ([DeeZone](https://github.com/DeeZone))

## [v0.4.91](https://github.com/dosomething/phoenix/tree/v0.4.91) (2015-04-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.90...v0.4.91)

**Fixed bugs:**

- \# of ppl doing and secondary CTA are both showing at the same time [\#4403](https://github.com/DoSomething/phoenix/issues/4403)
- placeholder DS image is showing as broken on search [\#4398](https://github.com/DoSomething/phoenix/issues/4398)

**Closed issues:**

- Add Kudos taxonomy vocabulary [\#4409](https://github.com/DoSomething/phoenix/issues/4409)
- Add scholarship call out back to the persistent nav [\#4392](https://github.com/DoSomething/phoenix/issues/4392)

**Merged pull requests:**

- Feature for adding new Kudos taxonomy vocabulary. [\#4410](https://github.com/DoSomething/phoenix/pull/4410) ([weerd](https://github.com/weerd))
- Removed cta message scope to account for different mark up [\#4408](https://github.com/DoSomething/phoenix/pull/4408) ([sbsmith86](https://github.com/sbsmith86))
- update default image path [\#4407](https://github.com/DoSomething/phoenix/pull/4407) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.90](https://github.com/dosomething/phoenix/tree/v0.4.90) (2015-04-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.89...v0.4.90)

**Merged pull requests:**

- Remove test class [\#4400](https://github.com/DoSomething/phoenix/pull/4400) ([sbsmith86](https://github.com/sbsmith86))
- Allow `npm link` for dosomething-neue. [\#4353](https://github.com/DoSomething/phoenix/pull/4353) ([DFurnes](https://github.com/DFurnes))

## [v0.4.89](https://github.com/dosomething/phoenix/tree/v0.4.89) (2015-04-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.88...v0.4.89)

**Closed issues:**

- wrap secondary CTA text on persistent nav [\#4390](https://github.com/DoSomething/phoenix/issues/4390)
- need commas for thousands place \(and millions\) when outputting \# of ppl doing on pitch  [\#4389](https://github.com/DoSomething/phoenix/issues/4389)
- Add pager on RB review page [\#4369](https://github.com/DoSomething/phoenix/issues/4369)
- set progress/signup count variables for all campaigns [\#4335](https://github.com/DoSomething/phoenix/issues/4335)
- Progress count updates [\#4326](https://github.com/DoSomething/phoenix/issues/4326)
- Make all of the Tip fields required on the campaign template [\#4147](https://github.com/DoSomething/phoenix/issues/4147)
- Remove the Alt BG File fid field. [\#4026](https://github.com/DoSomething/phoenix/issues/4026)
- Safari photo upload crashes the tab in iOS 8.0.2 [\#3971](https://github.com/DoSomething/phoenix/issues/3971)

**Merged pull requests:**

- Persistent nav updates [\#4399](https://github.com/DoSomething/phoenix/pull/4399) ([sbsmith86](https://github.com/sbsmith86))
- Update reportback totals on cron [\#4396](https://github.com/DoSomething/phoenix/pull/4396) ([angaither](https://github.com/angaither))
- Format progress number. [\#4391](https://github.com/DoSomething/phoenix/pull/4391) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.88](https://github.com/dosomething/phoenix/tree/v0.4.88) (2015-04-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.87...v0.4.88)

**Merged pull requests:**

- Remove Alternate BG FID Field on campaigns [\#4382](https://github.com/DoSomething/phoenix/pull/4382) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.87](https://github.com/dosomething/phoenix/tree/v0.4.87) (2015-04-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.86...v0.4.87)

**Closed issues:**

- FATAL: Cannot redeclare redis\_autoload [\#4385](https://github.com/DoSomething/phoenix/issues/4385)

**Merged pull requests:**

- Services module security update to 3.12. [\#4386](https://github.com/DoSomething/phoenix/pull/4386) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.86](https://github.com/dosomething/phoenix/tree/v0.4.86) (2015-04-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.85...v0.4.86)

## [v0.4.85](https://github.com/dosomething/phoenix/tree/v0.4.85) (2015-04-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.84...v0.4.85)

**Fixed bugs:**

- Shower songs reportbacks are in wrong camapaign [\#4368](https://github.com/DoSomething/phoenix/issues/4368)

**Closed issues:**

- Add pagination for Reportback Items collection endpoint [\#4381](https://github.com/DoSomething/phoenix/issues/4381)
- Disable reportback form submission when image is invalid [\#4054](https://github.com/DoSomething/phoenix/issues/4054)
- Uploading an image in landscape and switching back to portrait distorts the image in the modal [\#3961](https://github.com/DoSomething/phoenix/issues/3961)

**Merged pull requests:**

- Updates to add pagination to reportback-items endpoint. [\#4380](https://github.com/DoSomething/phoenix/pull/4380) ([weerd](https://github.com/weerd))
- Disable reportback form when image is invalid [\#4379](https://github.com/DoSomething/phoenix/pull/4379) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.84](https://github.com/dosomething/phoenix/tree/v0.4.84) (2015-04-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.83...v0.4.84)

**Closed issues:**

- Create `get\_scholarship` helper function [\#4333](https://github.com/DoSomething/phoenix/issues/4333)

**Merged pull requests:**

- Fixes indexing tokens on password reset page. [\#4377](https://github.com/DoSomething/phoenix/pull/4377) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Adding scholarship helper function [\#4376](https://github.com/DoSomething/phoenix/pull/4376) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.83](https://github.com/dosomething/phoenix/tree/v0.4.83) (2015-04-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.82...v0.4.83)

**Closed issues:**

- Debugging locally  [\#4352](https://github.com/DoSomething/phoenix/issues/4352)

**Merged pull requests:**

- Reportback endpoints updates [\#4375](https://github.com/DoSomething/phoenix/pull/4375) ([weerd](https://github.com/weerd))
- Bump Vagrant box version to 1.0.0.rc2. [\#4374](https://github.com/DoSomething/phoenix/pull/4374) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.82](https://github.com/dosomething/phoenix/tree/v0.4.82) (2015-04-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.81...v0.4.82)

**Fixed bugs:**

- Fatal error: PHP 5.5 arrays used [\#4372](https://github.com/DoSomething/phoenix/issues/4372)

**Merged pull requests:**

- Fixes array definition incompatible with PHP 5.3. [\#4373](https://github.com/DoSomething/phoenix/pull/4373) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.81](https://github.com/dosomething/phoenix/tree/v0.4.81) (2015-04-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.80...v0.4.81)

**Closed issues:**

- Add helper variable progress to campaign [\#4282](https://github.com/DoSomething/phoenix/issues/4282)
- Sum variable for Campaign Quantity [\#3899](https://github.com/DoSomething/phoenix/issues/3899)

**Merged pull requests:**

- ds test: changes directory to $BASE\_PATH. [\#4371](https://github.com/DoSomething/phoenix/pull/4371) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Update the DoSomething API features code to incorporate activating new endpoints. [\#4370](https://github.com/DoSomething/phoenix/pull/4370) ([weerd](https://github.com/weerd))
- Set up pitch template for Optimizely testing [\#4367](https://github.com/DoSomething/phoenix/pull/4367) ([sbsmith86](https://github.com/sbsmith86))
- Experimental oop api [\#4366](https://github.com/DoSomething/phoenix/pull/4366) ([weerd](https://github.com/weerd))

## [v0.4.80](https://github.com/dosomething/phoenix/tree/v0.4.80) (2015-04-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.79...v0.4.80)

**Closed issues:**

- Send 26+ email template in user\_register transacitonals [\#4362](https://github.com/DoSomething/phoenix/issues/4362)
- Persistent sign up button on pitch page. [\#4308](https://github.com/DoSomething/phoenix/issues/4308)
- Add signup count to pitch page [\#4288](https://github.com/DoSomething/phoenix/issues/4288)
- Manage MailChimp List IDs [\#3841](https://github.com/DoSomething/phoenix/issues/3841)

**Merged pull requests:**

- Allows overriding 26+ Club Registration email template name. [\#4365](https://github.com/DoSomething/phoenix/pull/4365) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.79](https://github.com/dosomething/phoenix/tree/v0.4.79) (2015-04-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.78...v0.4.79)

**Merged pull requests:**

- Improves dosomething\_signup\_update\_7019\(\). [\#4361](https://github.com/DoSomething/phoenix/pull/4361) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.78](https://github.com/dosomething/phoenix/tree/v0.4.78) (2015-04-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.77...v0.4.78)

**Merged pull requests:**

- Decrease spacing on desktop for the persistent nav [\#4359](https://github.com/DoSomething/phoenix/pull/4359) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.77](https://github.com/dosomething/phoenix/tree/v0.4.77) (2015-04-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.76...v0.4.77)

**Merged pull requests:**

- Style updates to persistent nav [\#4358](https://github.com/DoSomething/phoenix/pull/4358) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.76](https://github.com/dosomething/phoenix/tree/v0.4.76) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.75...v0.4.76)

**Merged pull requests:**

- Lodash template [\#4357](https://github.com/DoSomething/phoenix/pull/4357) ([DFurnes](https://github.com/DFurnes))

## [v0.4.75](https://github.com/dosomething/phoenix/tree/v0.4.75) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.74...v0.4.75)

## [v0.4.74](https://github.com/dosomething/phoenix/tree/v0.4.74) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.73...v0.4.74)

**Merged pull requests:**

- Overrides MailChimp settings for 26+ Club. [\#4270](https://github.com/DoSomething/phoenix/pull/4270) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.73](https://github.com/dosomething/phoenix/tree/v0.4.73) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.72...v0.4.73)

## [v0.4.72](https://github.com/dosomething/phoenix/tree/v0.4.72) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.71...v0.4.72)

**Merged pull requests:**

- Use patched UMD branches for a couple of modules. [\#4354](https://github.com/DoSomething/phoenix/pull/4354) ([DFurnes](https://github.com/DFurnes))

## [v0.4.71](https://github.com/dosomething/phoenix/tree/v0.4.71) (2015-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.69...v0.4.71)

**Fixed bugs:**

- secondary sign up button isn't showing up on pitch for logged in users [\#4349](https://github.com/DoSomething/phoenix/issues/4349)
- facts on taxonomy collections should be bulleted [\#4341](https://github.com/DoSomething/phoenix/issues/4341)
- tumblr dialogue never opens up on permalink [\#4337](https://github.com/DoSomething/phoenix/issues/4337)

**Closed issues:**

- Show sign up button with persistent nav turned off  [\#4336](https://github.com/DoSomething/phoenix/issues/4336)
- Homepage member counter error handling [\#4289](https://github.com/DoSomething/phoenix/issues/4289)
- styling off on Do It Tips in IE 8 [\#4213](https://github.com/DoSomething/phoenix/issues/4213)

**Merged pull requests:**

- Wrap sign up button rendering in conditionals so it only prints onces [\#4351](https://github.com/DoSomething/phoenix/pull/4351) ([sbsmith86](https://github.com/sbsmith86))
- Tumblr bug [\#4348](https://github.com/DoSomething/phoenix/pull/4348) ([sbsmith86](https://github.com/sbsmith86))
- Fixes \#4341. [\#4347](https://github.com/DoSomething/phoenix/pull/4347) ([DFurnes](https://github.com/DFurnes))
- Linting fixes and patched UMD modules [\#4346](https://github.com/DoSomething/phoenix/pull/4346) ([DFurnes](https://github.com/DFurnes))
- Remove check for cta to display sign up button [\#4345](https://github.com/DoSomething/phoenix/pull/4345) ([sbsmith86](https://github.com/sbsmith86))
- Webpack cleanup [\#4343](https://github.com/DoSomething/phoenix/pull/4343) ([DFurnes](https://github.com/DFurnes))

## [v0.4.69](https://github.com/dosomething/phoenix/tree/v0.4.69) (2015-04-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.68...v0.4.69)

**Closed issues:**

- GA custom events are not triggering for Twitter shares on permalink [\#4338](https://github.com/DoSomething/phoenix/issues/4338)

**Merged pull requests:**

- fixed spelling error that blocked ga reporting [\#4342](https://github.com/DoSomething/phoenix/pull/4342) ([angaither](https://github.com/angaither))
- Neue 6.4 [\#4323](https://github.com/DoSomething/phoenix/pull/4323) ([DFurnes](https://github.com/DFurnes))

## [v0.4.68](https://github.com/dosomething/phoenix/tree/v0.4.68) (2015-04-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.67...v0.4.68)

**Closed issues:**

- display numeric progress towards goal [\#4330](https://github.com/DoSomething/phoenix/issues/4330)

**Merged pull requests:**

- Show progress on action page under feature flag [\#4340](https://github.com/DoSomething/phoenix/pull/4340) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.67](https://github.com/dosomething/phoenix/tree/v0.4.67) (2015-04-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.66...v0.4.67)

**Closed issues:**

- update copy of rb question [\#4325](https://github.com/DoSomething/phoenix/issues/4325)

**Merged pull requests:**

- Update copy on reportback participation field [\#4334](https://github.com/DoSomething/phoenix/pull/4334) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.66](https://github.com/dosomething/phoenix/tree/v0.4.66) (2015-04-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.65...v0.4.66)

**Fixed bugs:**

- SMS games are showing $1000 scholarship whether there is a scholarship or not [\#4328](https://github.com/DoSomething/phoenix/issues/4328)

**Merged pull requests:**

- SMS Campaigns: Pull in scholarship amount and display if it exists [\#4332](https://github.com/DoSomething/phoenix/pull/4332) ([sbsmith86](https://github.com/sbsmith86))
- Add sign up count to pitch page [\#4329](https://github.com/DoSomething/phoenix/pull/4329) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.65](https://github.com/dosomething/phoenix/tree/v0.4.65) (2015-04-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.64...v0.4.65)

**Closed issues:**

- Enable hooks/pre-commit in git subsystem using DS script [\#4221](https://github.com/DoSomething/phoenix/issues/4221)

**Merged pull requests:**

- Enables git hooks automatically. [\#4331](https://github.com/DoSomething/phoenix/pull/4331) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Persistent Sign up button on the pitch pages [\#4327](https://github.com/DoSomething/phoenix/pull/4327) ([sbsmith86](https://github.com/sbsmith86))
- Bump Neue version to 6.3.x. [\#4318](https://github.com/DoSomething/phoenix/pull/4318) ([DFurnes](https://github.com/DFurnes))

## [v0.4.64](https://github.com/dosomething/phoenix/tree/v0.4.64) (2015-03-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.63...v0.4.64)

**Fixed bugs:**

- double saving progress values [\#4321](https://github.com/DoSomething/phoenix/issues/4321)

**Closed issues:**

- user\_registration Production settings [\#4313](https://github.com/DoSomething/phoenix/issues/4313)

**Merged pull requests:**

- This was saving `progress` and `sum\_rb\_quantity` [\#4322](https://github.com/DoSomething/phoenix/pull/4322) ([angaither](https://github.com/angaither))
- Signup var and cron [\#4320](https://github.com/DoSomething/phoenix/pull/4320) ([angaither](https://github.com/angaither))
- Cron all the things [\#4317](https://github.com/DoSomething/phoenix/pull/4317) ([angaither](https://github.com/angaither))
- Adds hook\_update to apply changes [\#4316](https://github.com/DoSomething/phoenix/pull/4316) ([DeeZone](https://github.com/DeeZone))
- Adjust queue setting in user\_register production [\#4315](https://github.com/DoSomething/phoenix/pull/4315) ([DeeZone](https://github.com/DeeZone))

## [v0.4.63](https://github.com/dosomething/phoenix/tree/v0.4.63) (2015-03-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.62...v0.4.63)

**Fixed bugs:**

- not enough padding btwn know it image and problem [\#4305](https://github.com/DoSomething/phoenix/issues/4305)
- sign up button too close to copy on small screens [\#4278](https://github.com/DoSomething/phoenix/issues/4278)

**Closed issues:**

- ds script: get rid of bin/ds syntax [\#4299](https://github.com/DoSomething/phoenix/issues/4299)
- StatHat coverage for donations [\#4208](https://github.com/DoSomething/phoenix/issues/4208)

**Merged pull requests:**

- Deprecates bin/ds syntax: makes ds script avaliable from anywhere. [\#4312](https://github.com/DoSomething/phoenix/pull/4312) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Add a dollars amount & track that in stathat. [\#4310](https://github.com/DoSomething/phoenix/pull/4310) ([angaither](https://github.com/angaither))
- Fixes \#4305 by using proper tag for paragraph spacing rule. [\#4309](https://github.com/DoSomething/phoenix/pull/4309) ([DFurnes](https://github.com/DFurnes))
- Bump Vagrant box version to 1.0.0.rc1. [\#4307](https://github.com/DoSomething/phoenix/pull/4307) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.62](https://github.com/dosomething/phoenix/tree/v0.4.62) (2015-03-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.61...v0.4.62)

**Fixed bugs:**

- Stathat from donate page not reporting [\#4298](https://github.com/DoSomething/phoenix/issues/4298)

**Closed issues:**

- add tattoos as a shipment item on the campaign signup data form [\#4303](https://github.com/DoSomething/phoenix/issues/4303)

**Merged pull requests:**

- Add stathat.php to drupal-org.make to allow stats to be logged. [\#4306](https://github.com/DoSomething/phoenix/pull/4306) ([angaither](https://github.com/angaither))
- Let's hand out tattoos. [\#4304](https://github.com/DoSomething/phoenix/pull/4304) ([angaither](https://github.com/angaither))

## [v0.4.61](https://github.com/dosomething/phoenix/tree/v0.4.61) (2015-03-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.60...v0.4.61)

**Fixed bugs:**

- admin page accessible for anonymous users [\#4292](https://github.com/DoSomething/phoenix/issues/4292)

**Closed issues:**

- Test issue from someone not on the DS team! [\#4300](https://github.com/DoSomething/phoenix/issues/4300)
- Invalid argument supplied for foreach\(\) node--campaign.tpl.php:212 [\#4291](https://github.com/DoSomething/phoenix/issues/4291)
- Reindex Solr after ds pull stage [\#4290](https://github.com/DoSomething/phoenix/issues/4290)
- Add helper variable for campaign goal [\#4281](https://github.com/DoSomething/phoenix/issues/4281)
- Add guzzle http library   [\#4279](https://github.com/DoSomething/phoenix/issues/4279)

**Merged pull requests:**

- Set progress as default on campaign variables page [\#4302](https://github.com/DoSomething/phoenix/pull/4302) ([angaither](https://github.com/angaither))
- Added goal/progress vars to the dosomething\_helpers config. [\#4297](https://github.com/DoSomething/phoenix/pull/4297) ([angaither](https://github.com/angaither))
- Reindexes Solr automaticall after ds pull stage. [\#4296](https://github.com/DoSomething/phoenix/pull/4296) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes \#4291. [\#4295](https://github.com/DoSomething/phoenix/pull/4295) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Bump Vagrant box version to 1.0.0.alpha3. [\#4294](https://github.com/DoSomething/phoenix/pull/4294) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Update view permission on admin/content/tax [\#4293](https://github.com/DoSomething/phoenix/pull/4293) ([angaither](https://github.com/angaither))

## [v0.4.60](https://github.com/dosomething/phoenix/tree/v0.4.60) (2015-03-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.59...v0.4.60)

**Fixed bugs:**

- & isn't showing properly in captions [\#4286](https://github.com/DoSomething/phoenix/issues/4286)

**Merged pull requests:**

- Reportback &-persands [\#4287](https://github.com/DoSomething/phoenix/pull/4287) ([angaither](https://github.com/angaither))
- Admin northstar inital setup [\#4285](https://github.com/DoSomething/phoenix/pull/4285) ([angaither](https://github.com/angaither))

## [v0.4.59](https://github.com/dosomething/phoenix/tree/v0.4.59) (2015-03-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.58...v0.4.59)

**Closed issues:**

- Admins should see a link to admin permalink page from gallery [\#4219](https://github.com/DoSomething/phoenix/issues/4219)

**Merged pull requests:**

- Update to enable admin edit links in extended gallery. [\#4280](https://github.com/DoSomething/phoenix/pull/4280) ([weerd](https://github.com/weerd))

## [v0.4.58](https://github.com/dosomething/phoenix/tree/v0.4.58) (2015-03-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.57...v0.4.58)

**Closed issues:**

- persistent nav is breaking to 2 lines on small screens [\#4135](https://github.com/DoSomething/phoenix/issues/4135)
- add beta name fields for SMS game A/B test [\#3568](https://github.com/DoSomething/phoenix/issues/3568)

**Merged pull requests:**

- Update to enabled admins to click on button on Reportbacks to edit their status. [\#4275](https://github.com/DoSomething/phoenix/pull/4275) ([weerd](https://github.com/weerd))
- Add markup/styles for SMS first names Optimizely test. [\#4247](https://github.com/DoSomething/phoenix/pull/4247) ([DFurnes](https://github.com/DFurnes))

## [v0.4.57](https://github.com/dosomething/phoenix/tree/v0.4.57) (2015-03-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.56...v0.4.57)

**Closed issues:**

- logged in users don't get signed up for campaign from permalink [\#4255](https://github.com/DoSomething/phoenix/issues/4255)

**Merged pull requests:**

- Add caching back into permalink. [\#4265](https://github.com/DoSomething/phoenix/pull/4265) ([angaither](https://github.com/angaither))

## [v0.4.56](https://github.com/dosomething/phoenix/tree/v0.4.56) (2015-03-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.55...v0.4.56)

**Closed issues:**

- need to know % of users who share from confirmation page [\#4263](https://github.com/DoSomething/phoenix/issues/4263)
- change cta on non-owner permalink if campaign is closed [\#4261](https://github.com/DoSomething/phoenix/issues/4261)
- Add 480x480 scale and crop image style [\#4256](https://github.com/DoSomething/phoenix/issues/4256)
- URL alias not maintained when registering from permalink [\#4254](https://github.com/DoSomething/phoenix/issues/4254)
- Style header gallery images [\#4188](https://github.com/DoSomething/phoenix/issues/4188)
- Retrieve reportback data for header image gallery. [\#4187](https://github.com/DoSomething/phoenix/issues/4187)
- RB header gallery default to off [\#4186](https://github.com/DoSomething/phoenix/issues/4186)

**Merged pull requests:**

- Add missing require for jQuery. [\#4274](https://github.com/DoSomething/phoenix/pull/4274) ([DFurnes](https://github.com/DFurnes))
- Updates to incorportate mobile styles. [\#4273](https://github.com/DoSomething/phoenix/pull/4273) ([weerd](https://github.com/weerd))
- Header gallery styles [\#4272](https://github.com/DoSomething/phoenix/pull/4272) ([weerd](https://github.com/weerd))
- Stathat [\#4271](https://github.com/DoSomething/phoenix/pull/4271) ([angaither](https://github.com/angaither))
- Clean up Grunt file. [\#4268](https://github.com/DoSomething/phoenix/pull/4268) ([DFurnes](https://github.com/DFurnes))
- Add custom google analytics tracking to shares on permalink page. [\#4267](https://github.com/DoSomething/phoenix/pull/4267) ([angaither](https://github.com/angaither))
- The first slash was blocking the url alias [\#4266](https://github.com/DoSomething/phoenix/pull/4266) ([angaither](https://github.com/angaither))
- Permalink campaign closed [\#4264](https://github.com/DoSomething/phoenix/pull/4264) ([angaither](https://github.com/angaither))
- Remove pattern overrides added to Neue in 6.2.2. [\#4262](https://github.com/DoSomething/phoenix/pull/4262) ([DFurnes](https://github.com/DFurnes))
- Add 480x480 image style [\#4258](https://github.com/DoSomething/phoenix/pull/4258) ([angaither](https://github.com/angaither))
- Header gallery data [\#4248](https://github.com/DoSomething/phoenix/pull/4248) ([weerd](https://github.com/weerd))

## [v0.4.55](https://github.com/dosomething/phoenix/tree/v0.4.55) (2015-03-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.54...v0.4.55)

**Fixed bugs:**

- Signup Reason and Signup Reason Label alignment is off on signup data form [\#4229](https://github.com/DoSomething/phoenix/issues/4229)

**Closed issues:**

- truncate why\_participated text on owner permalink [\#4235](https://github.com/DoSomething/phoenix/issues/4235)

**Merged pull requests:**

- Remove permalink cache temporarily. [\#4257](https://github.com/DoSomething/phoenix/pull/4257) ([angaither](https://github.com/angaither))
- Permalink show more [\#4253](https://github.com/DoSomething/phoenix/pull/4253) ([sbsmith86](https://github.com/sbsmith86))
- Move "Why signed up" field into elements wrapper. Fixes \#4229. [\#4251](https://github.com/DoSomething/phoenix/pull/4251) ([DFurnes](https://github.com/DFurnes))

## [v0.4.54](https://github.com/dosomething/phoenix/tree/v0.4.54) (2015-03-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.53...v0.4.54)

**Closed issues:**

- Permalink cache clear [\#4246](https://github.com/DoSomething/phoenix/issues/4246)

**Merged pull requests:**

- After a user updates reportback, clear permalink cache. [\#4250](https://github.com/DoSomething/phoenix/pull/4250) ([angaither](https://github.com/angaither))

## [v0.4.53](https://github.com/dosomething/phoenix/tree/v0.4.53) (2015-03-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.52...v0.4.53)

**Closed issues:**

- FB window should close after I post [\#4210](https://github.com/DoSomething/phoenix/issues/4210)
- rbid in the reprotbacks tab of campaigns needs to link to the admin view of the permalink [\#4116](https://github.com/DoSomething/phoenix/issues/4116)

**Merged pull requests:**

- Admin reportback links [\#4249](https://github.com/DoSomething/phoenix/pull/4249) ([angaither](https://github.com/angaither))

## [v0.4.52](https://github.com/dosomething/phoenix/tree/v0.4.52) (2015-03-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.51...v0.4.52)

**Closed issues:**

- Signups API endpoint [\#4238](https://github.com/DoSomething/phoenix/issues/4238)

**Merged pull requests:**

- Signup Group endpoints for Inviter app prototype [\#4243](https://github.com/DoSomething/phoenix/pull/4243) ([aaronschachter](https://github.com/aaronschachter))

## [v0.4.51](https://github.com/dosomething/phoenix/tree/v0.4.51) (2015-03-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.50...v0.4.51)

**Closed issues:**

- PHP 5.5 Illegal string offset warnings  [\#4244](https://github.com/DoSomething/phoenix/issues/4244)

**Merged pull requests:**

- Proposed solution for \#4244. [\#4245](https://github.com/DoSomething/phoenix/pull/4245) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.50](https://github.com/dosomething/phoenix/tree/v0.4.50) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.49...v0.4.50)

**Closed issues:**

- anchor buttons to the bottom of the permalink [\#4194](https://github.com/DoSomething/phoenix/issues/4194)

**Merged pull requests:**

- Updates Entity API to 1.6. [\#4242](https://github.com/DoSomething/phoenix/pull/4242) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Move non-owner cta to correct spot in tpl [\#4239](https://github.com/DoSomething/phoenix/pull/4239) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.49](https://github.com/dosomething/phoenix/tree/v0.4.49) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.48...v0.4.49)

**Merged pull requests:**

- Updates CTools to 1.7. [\#4241](https://github.com/DoSomething/phoenix/pull/4241) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.48](https://github.com/dosomething/phoenix/tree/v0.4.48) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.47...v0.4.48)

**Merged pull requests:**

- Updates Drupal core to 7.35. [\#4240](https://github.com/DoSomething/phoenix/pull/4240) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.47](https://github.com/dosomething/phoenix/tree/v0.4.47) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.46...v0.4.47)

**Merged pull requests:**

- Renames dosomething\_mobilecommons\_\* variables. [\#4226](https://github.com/DoSomething/phoenix/pull/4226) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.46](https://github.com/dosomething/phoenix/tree/v0.4.46) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.45...v0.4.46)

**Closed issues:**

- API endpoint to retrieve all User activity [\#4230](https://github.com/DoSomething/phoenix/issues/4230)

**Merged pull requests:**

- Return all User activity in API users/:uid/activity [\#4231](https://github.com/DoSomething/phoenix/pull/4231) ([aaronschachter](https://github.com/aaronschachter))

## [v0.4.45](https://github.com/dosomething/phoenix/tree/v0.4.45) (2015-03-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.44...v0.4.45)

**Fixed bugs:**

- Need to fallback if error loading image. [\#4222](https://github.com/DoSomething/phoenix/pull/4222) ([weerd](https://github.com/weerd))

**Closed issues:**

- remove social header/copy fields from DoSomething campaign config [\#4234](https://github.com/DoSomething/phoenix/issues/4234)
- Access permalink share page from user profile  [\#4218](https://github.com/DoSomething/phoenix/issues/4218)
- Permalink sign up button should also work for un-authenticated users [\#4197](https://github.com/DoSomething/phoenix/issues/4197)
- Can't authenticate with Chrome Postman [\#4145](https://github.com/DoSomething/phoenix/issues/4145)

**Merged pull requests:**

- Remove social header/copy vars [\#4237](https://github.com/DoSomething/phoenix/pull/4237) ([angaither](https://github.com/angaither))
- Add link to permalink from user profile [\#4236](https://github.com/DoSomething/phoenix/pull/4236) ([angaither](https://github.com/angaither))
- Anchor card cta at bottom of the card [\#4233](https://github.com/DoSomething/phoenix/pull/4233) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.44](https://github.com/dosomething/phoenix/tree/v0.4.44) (2015-03-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.43...v0.4.44)

**Closed issues:**

- updates to mobile confirmation page [\#4209](https://github.com/DoSomething/phoenix/issues/4209)
- Redirect to action page after signup [\#4190](https://github.com/DoSomething/phoenix/issues/4190)
- non-owner permalink: button should read "SIGN UP" when it serves as pitch [\#4154](https://github.com/DoSomething/phoenix/issues/4154)
- Beta RB permalink should store the Reportback File fid as Signup Source [\#4115](https://github.com/DoSomething/phoenix/issues/4115)

**Merged pull requests:**

- Updates to permalink page on mobile [\#4212](https://github.com/DoSomething/phoenix/pull/4212) ([sbsmith86](https://github.com/sbsmith86))
- Permalink as pitch page [\#4198](https://github.com/DoSomething/phoenix/pull/4198) ([angaither](https://github.com/angaither))

## [v0.4.43](https://github.com/dosomething/phoenix/tree/v0.4.43) (2015-03-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.42...v0.4.43)

**Merged pull requests:**

- Update markup on signup data form. [\#4228](https://github.com/DoSomething/phoenix/pull/4228) ([DFurnes](https://github.com/DFurnes))
- Open a new window everytime [\#4227](https://github.com/DoSomething/phoenix/pull/4227) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.42](https://github.com/dosomething/phoenix/tree/v0.4.42) (2015-03-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.41...v0.4.42)

**Fixed bugs:**

- With new environment PHP throwing 'illegal string offset' error [\#4214](https://github.com/DoSomething/phoenix/issues/4214)
- Permalink page error in metatag module [\#4203](https://github.com/DoSomething/phoenix/issues/4203)
- signup data form styling is off on campaign template [\#4202](https://github.com/DoSomething/phoenix/issues/4202)

**Closed issues:**

- IE8 share bug [\#4216](https://github.com/DoSomething/phoenix/issues/4216)

**Merged pull requests:**

- Using a different intent link for facebook [\#4224](https://github.com/DoSomething/phoenix/pull/4224) ([sbsmith86](https://github.com/sbsmith86))
- Shipment form styles [\#4220](https://github.com/DoSomething/phoenix/pull/4220) ([DFurnes](https://github.com/DFurnes))
- Changing reserved variable names to unique names [\#4217](https://github.com/DoSomething/phoenix/pull/4217) ([sbsmith86](https://github.com/sbsmith86))
- Updating to allow for property set in plain text. [\#4215](https://github.com/DoSomething/phoenix/pull/4215) ([weerd](https://github.com/weerd))
- Always load fids from a reportback. [\#4211](https://github.com/DoSomething/phoenix/pull/4211) ([angaither](https://github.com/angaither))
- COUPONS [\#4206](https://github.com/DoSomething/phoenix/pull/4206) ([aaronschachter](https://github.com/aaronschachter))

## [v0.4.41](https://github.com/dosomething/phoenix/tree/v0.4.41) (2015-03-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.40...v0.4.41)

**Closed issues:**

- Stripe Form errors [\#4199](https://github.com/DoSomething/phoenix/issues/4199)

**Merged pull requests:**

- Pin Stripe PHP lib to v1.18.0 [\#4205](https://github.com/DoSomething/phoenix/pull/4205) ([aaronschachter](https://github.com/aaronschachter))

## [v0.4.40](https://github.com/dosomething/phoenix/tree/v0.4.40) (2015-03-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.39...v0.4.40)

**Closed issues:**

- Update twitter link on permalink share [\#4204](https://github.com/DoSomething/phoenix/issues/4204)
- share cta region runs over on mobile [\#4196](https://github.com/DoSomething/phoenix/issues/4196)
- add coupons as a shipment item on the campaign signup data form [\#4195](https://github.com/DoSomething/phoenix/issues/4195)

**Merged pull requests:**

- Permalink twitter intent update [\#4207](https://github.com/DoSomething/phoenix/pull/4207) ([sbsmith86](https://github.com/sbsmith86))
- Don't convert to table display until we are tablet. Fixes \#4196 [\#4201](https://github.com/DoSomething/phoenix/pull/4201) ([sbsmith86](https://github.com/sbsmith86))
- Quick fixes for donate form CSS. [\#4200](https://github.com/DoSomething/phoenix/pull/4200) ([DFurnes](https://github.com/DFurnes))

## [v0.4.39](https://github.com/dosomething/phoenix/tree/v0.4.39) (2015-03-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.38...v0.4.39)

**Closed issues:**

- original photo shows on confirmation page if user just updates submission w/o new photo [\#4192](https://github.com/DoSomething/phoenix/issues/4192)
- updates to twitter card [\#4160](https://github.com/DoSomething/phoenix/issues/4160)
- Allow users to share the permalink on the confirmation page.  [\#4143](https://github.com/DoSomething/phoenix/issues/4143)

**Merged pull requests:**

- Get the most recently uploaded rb item by default. [\#4193](https://github.com/DoSomething/phoenix/pull/4193) ([angaither](https://github.com/angaither))
- Bump Vagrant box version to 1.0.0.alpha2. [\#4191](https://github.com/DoSomething/phoenix/pull/4191) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.38](https://github.com/dosomething/phoenix/tree/v0.4.38) (2015-03-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.37...v0.4.38)

**Closed issues:**

- SMS game webform accepts player names [\#4185](https://github.com/DoSomething/phoenix/issues/4185)

**Merged pull requests:**

- Fix XSS found on new reporback page. Sanitize original user input. [\#4189](https://github.com/DoSomething/phoenix/pull/4189) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Vagrant on Ansible. [\#4150](https://github.com/DoSomething/phoenix/pull/4150) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.37](https://github.com/dosomething/phoenix/tree/v0.4.37) (2015-03-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.36...v0.4.37)

**Closed issues:**

- use secondary call to action above Do It button on non-owner permalink page [\#4183](https://github.com/DoSomething/phoenix/issues/4183)
- Token replace social share variable [\#4181](https://github.com/DoSomething/phoenix/issues/4181)
- Remove solution supporting text [\#4178](https://github.com/DoSomething/phoenix/issues/4178)
- Add link to the reportback in the tumblr share text  [\#4177](https://github.com/DoSomething/phoenix/issues/4177)
- Update issue in permlink share copy [\#4176](https://github.com/DoSomething/phoenix/issues/4176)
- Add og:description meta tag [\#4175](https://github.com/DoSomething/phoenix/issues/4175)
- Add bottom border back on social cta module [\#4173](https://github.com/DoSomething/phoenix/issues/4173)
- Handle display of solution fact/statement/supporting statement [\#4153](https://github.com/DoSomething/phoenix/issues/4153)
- Update CTA pattern to work with three social media buttons [\#4142](https://github.com/DoSomething/phoenix/issues/4142)

**Merged pull requests:**

- display secondary cta above cta button [\#4184](https://github.com/DoSomething/phoenix/pull/4184) ([sbsmith86](https://github.com/sbsmith86))
- Token replace social share copy [\#4182](https://github.com/DoSomething/phoenix/pull/4182) ([angaither](https://github.com/angaither))
- Permalink share updates [\#4180](https://github.com/DoSomething/phoenix/pull/4180) ([sbsmith86](https://github.com/sbsmith86))
- Issue copy paster errorz [\#4179](https://github.com/DoSomething/phoenix/pull/4179) ([angaither](https://github.com/angaither))
- non-owner permalink updates [\#4174](https://github.com/DoSomething/phoenix/pull/4174) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.36](https://github.com/dosomething/phoenix/tree/v0.4.36) (2015-03-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.35...v0.4.36)

**Merged pull requests:**

- Add tumblr sharing so we can tumble. [\#4172](https://github.com/DoSomething/phoenix/pull/4172) ([sbsmith86](https://github.com/sbsmith86))
- Adding facebook sharing [\#4171](https://github.com/DoSomething/phoenix/pull/4171) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.35](https://github.com/dosomething/phoenix/tree/v0.4.35) (2015-03-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.34...v0.4.35)

**Merged pull requests:**

- sending share\_enabled to the template [\#4170](https://github.com/DoSomething/phoenix/pull/4170) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.34](https://github.com/dosomething/phoenix/tree/v0.4.34) (2015-03-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.33...v0.4.34)

**Closed issues:**

- add feature flag for share language and CTA on confirmation page [\#4162](https://github.com/DoSomething/phoenix/issues/4162)
- Social share copy [\#4161](https://github.com/DoSomething/phoenix/issues/4161)
- Reportback API must support uploading files [\#4151](https://github.com/DoSomething/phoenix/issues/4151)

**Merged pull requests:**

- Permalink sharing take two [\#4169](https://github.com/DoSomething/phoenix/pull/4169) ([angaither](https://github.com/angaither))
- Removed redirect to old confirmation page. [\#4166](https://github.com/DoSomething/phoenix/pull/4166) ([angaither](https://github.com/angaither))
- Created new variable on settings page for social share copy. [\#4165](https://github.com/DoSomething/phoenix/pull/4165) ([angaither](https://github.com/angaither))

## [v0.4.33](https://github.com/dosomething/phoenix/tree/v0.4.33) (2015-03-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.32...v0.4.33)

**Closed issues:**

- Audit incoming legacy traffic [\#3606](https://github.com/DoSomething/phoenix/issues/3606)
- log of search queries for 404 page [\#3511](https://github.com/DoSomething/phoenix/issues/3511)
- enhance cache warming script to include legacy urls we're killing [\#3463](https://github.com/DoSomething/phoenix/issues/3463)
- Create new redirects from legacy to beta [\#3404](https://github.com/DoSomething/phoenix/issues/3404)

**Merged pull requests:**

- Upload files via Reportback endpoint [\#4164](https://github.com/DoSomething/phoenix/pull/4164) ([aaronschachter](https://github.com/aaronschachter))
- Revert "⚠ Permalink sharing" [\#4163](https://github.com/DoSomething/phoenix/pull/4163) ([angaither](https://github.com/angaither))

## [v0.4.32](https://github.com/dosomething/phoenix/tree/v0.4.32) (2015-03-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.31...v0.4.32)

**Fixed bugs:**

- Error on permalink pages with no FID [\#4157](https://github.com/DoSomething/phoenix/issues/4157)

**Merged pull requests:**

- Get file from reportback entity, if no query string. [\#4159](https://github.com/DoSomething/phoenix/pull/4159) ([angaither](https://github.com/angaither))
- ⚠ Permalink sharing [\#4156](https://github.com/DoSomething/phoenix/pull/4156) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.31](https://github.com/dosomething/phoenix/tree/v0.4.31) (2015-03-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.30...v0.4.31)

**Closed issues:**

- Add caching to reportback permalink [\#4138](https://github.com/DoSomething/phoenix/issues/4138)
- Kill current confirmation page [\#4095](https://github.com/DoSomething/phoenix/issues/4095)

**Merged pull requests:**

- Twitter sharez [\#4155](https://github.com/DoSomething/phoenix/pull/4155) ([angaither](https://github.com/angaither))
- Set permalink as cached content. [\#4149](https://github.com/DoSomething/phoenix/pull/4149) ([angaither](https://github.com/angaither))

## [v0.4.30](https://github.com/dosomething/phoenix/tree/v0.4.30) (2015-03-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.29...v0.4.30)

**Merged pull requests:**

- Fixes the version of vagrant box in code. [\#4146](https://github.com/DoSomething/phoenix/pull/4146) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fix automated test issues [\#4144](https://github.com/DoSomething/phoenix/pull/4144) ([DFurnes](https://github.com/DFurnes))
- Restart func should be grepping for a different message [\#4080](https://github.com/DoSomething/phoenix/pull/4080) ([blisteringherb](https://github.com/blisteringherb))

## [v0.4.29](https://github.com/dosomething/phoenix/tree/v0.4.29) (2015-03-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.28...v0.4.29)

**Closed issues:**

- fatal error on SMS games on staging [\#4139](https://github.com/DoSomething/phoenix/issues/4139)
- image styles errors on pitch page on staging [\#4130](https://github.com/DoSomething/phoenix/issues/4130)
- Remove original Reportback Form code [\#4107](https://github.com/DoSomething/phoenix/issues/4107)

**Merged pull requests:**

- Fixes \#4139. [\#4141](https://github.com/DoSomething/phoenix/pull/4141) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Reportback final cleanup [\#4137](https://github.com/DoSomething/phoenix/pull/4137) ([weerd](https://github.com/weerd))
- Add ImageCache Actions color actions submodule. [\#4136](https://github.com/DoSomething/phoenix/pull/4136) ([DFurnes](https://github.com/DFurnes))

## [v0.4.28](https://github.com/dosomething/phoenix/tree/v0.4.28) (2015-03-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.27...v0.4.28)

**Closed issues:**

- Add 'do it' button to page [\#4131](https://github.com/DoSomething/phoenix/issues/4131)
- Permalink var tokens [\#4106](https://github.com/DoSomething/phoenix/issues/4106)
- Update title on permalink pages [\#4067](https://github.com/DoSomething/phoenix/issues/4067)
- Expose the permalink page to non owners. [\#4066](https://github.com/DoSomething/phoenix/issues/4066)

**Merged pull requests:**

- Fendering non-owner permalink page [\#4134](https://github.com/DoSomething/phoenix/pull/4134) ([sbsmith86](https://github.com/sbsmith86))
- Allow non-owners to see the permalink page. [\#4132](https://github.com/DoSomething/phoenix/pull/4132) ([angaither](https://github.com/angaither))

## [v0.4.27](https://github.com/dosomething/phoenix/tree/v0.4.27) (2015-03-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.26...v0.4.27)

**Closed issues:**

- Don't print name if there's no caption [\#4123](https://github.com/DoSomething/phoenix/issues/4123)
- Add scholarship qualification text [\#4121](https://github.com/DoSomething/phoenix/issues/4121)
- API - Get Signup sid and Reportback rbid for Current User per Campaign [\#4119](https://github.com/DoSomething/phoenix/issues/4119)

**Merged pull requests:**

- Provides users/:uid/activity API endpoint [\#4129](https://github.com/DoSomething/phoenix/pull/4129) ([aaronschachter](https://github.com/aaronschachter))
- Permalink template updates [\#4126](https://github.com/DoSomething/phoenix/pull/4126) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.26](https://github.com/dosomething/phoenix/tree/v0.4.26) (2015-03-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.25...v0.4.26)

**Merged pull requests:**

- Updates Message Broker Producer to 0.2.5. [\#4125](https://github.com/DoSomething/phoenix/pull/4125) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.25](https://github.com/dosomething/phoenix/tree/v0.4.25) (2015-03-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.24...v0.4.25)

**Closed issues:**

- Reportback Permalink page front-end [\#3541](https://github.com/DoSomething/phoenix/issues/3541)

**Merged pull requests:**

- If campaign has a scholarship, print the copy for it. [\#4122](https://github.com/DoSomething/phoenix/pull/4122) ([angaither](https://github.com/angaither))

## [v0.4.24](https://github.com/dosomething/phoenix/tree/v0.4.24) (2015-03-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.23...v0.4.24)

**Merged pull requests:**

- Reportback permissions [\#4120](https://github.com/DoSomething/phoenix/pull/4120) ([angaither](https://github.com/angaither))

## [v0.4.23](https://github.com/dosomething/phoenix/tree/v0.4.23) (2015-03-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.22...v0.4.23)

**Closed issues:**

- Reportback confirmation Error [\#4117](https://github.com/DoSomething/phoenix/issues/4117)

**Merged pull requests:**

- the rbid is not set in the values array on new reportbacks. [\#4118](https://github.com/DoSomething/phoenix/pull/4118) ([angaither](https://github.com/angaither))

## [v0.4.22](https://github.com/dosomething/phoenix/tree/v0.4.22) (2015-03-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.21...v0.4.22)

**Closed issues:**

- Reportback file getImage [\#4112](https://github.com/DoSomething/phoenix/issues/4112)
- /api/v1/users.json?parameters\[email\]=\[email\] returns invalid results [\#4094](https://github.com/DoSomething/phoenix/issues/4094)
- Password Reset Endpoint [\#4062](https://github.com/DoSomething/phoenix/issues/4062)

**Merged pull requests:**

- Reportback Confirmation Page [\#4114](https://github.com/DoSomething/phoenix/pull/4114) ([sbsmith86](https://github.com/sbsmith86))
- Allow an override for the getImage reportback file. [\#4113](https://github.com/DoSomething/phoenix/pull/4113) ([angaither](https://github.com/angaither))
- We care what you said [\#4109](https://github.com/DoSomething/phoenix/pull/4109) ([angaither](https://github.com/angaither))
- Adds get reset url resource to API [\#4108](https://github.com/DoSomething/phoenix/pull/4108) ([deadlybutter](https://github.com/deadlybutter))
- Add Image API rule to ensure images are always compressed JPEGs. [\#4092](https://github.com/DoSomething/phoenix/pull/4092) ([DFurnes](https://github.com/DFurnes))

## [v0.4.21](https://github.com/dosomething/phoenix/tree/v0.4.21) (2015-03-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.20...v0.4.21)

**Merged pull requests:**

- Store scaled minimum in a separate variable [\#4104](https://github.com/DoSomething/phoenix/pull/4104) ([sbsmith86](https://github.com/sbsmith86))

## [v0.4.20](https://github.com/dosomething/phoenix/tree/v0.4.20) (2015-03-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.19...v0.4.20)

**Closed issues:**

- Use default hardcoded placeholder images as fallback. [\#3956](https://github.com/DoSomething/phoenix/issues/3956)

**Merged pull requests:**

- Fixes typo in \#4076. [\#4103](https://github.com/DoSomething/phoenix/pull/4103) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Update to provide fallback placeholders if no placeholders uploaded to site. [\#4100](https://github.com/DoSomething/phoenix/pull/4100) ([weerd](https://github.com/weerd))

## [v0.4.19](https://github.com/dosomething/phoenix/tree/v0.4.19) (2015-03-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.18...v0.4.19)

**Merged pull requests:**

- Provides MailChimp list id in MB registration and signup payloads. [\#4076](https://github.com/DoSomething/phoenix/pull/4076) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.18](https://github.com/dosomething/phoenix/tree/v0.4.18) (2015-03-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.17...v0.4.18)

**Closed issues:**

- Typo in \#4099 [\#4101](https://github.com/DoSomething/phoenix/issues/4101)

**Merged pull requests:**

- Fix typo in \#4099. [\#4102](https://github.com/DoSomething/phoenix/pull/4102) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fix more reportback XSS vulnerabilities. [\#4099](https://github.com/DoSomething/phoenix/pull/4099) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes XSS vulnerability in Reportback image captions. [\#4098](https://github.com/DoSomething/phoenix/pull/4098) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.17](https://github.com/dosomething/phoenix/tree/v0.4.17) (2015-03-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.16...v0.4.17)

**Fixed bugs:**

- Animation on Ajax reportback gallery item reveal is broken. [\#4087](https://github.com/DoSomething/phoenix/issues/4087)
- Static content has inconsistentent \<h\> tags [\#4084](https://github.com/DoSomething/phoenix/issues/4084)
- Reportback caption placeholder bug [\#4081](https://github.com/DoSomething/phoenix/issues/4081)
- some rb images have black band on them [\#4032](https://github.com/DoSomething/phoenix/issues/4032)
- In IE8, the user is unable to change photo. [\#3866](https://github.com/DoSomething/phoenix/issues/3866)

**Closed issues:**

- Copy fields needed for DoSomething Campaign config [\#4085](https://github.com/DoSomething/phoenix/issues/4085)
- Tidy up user profile dropdown UI [\#4071](https://github.com/DoSomething/phoenix/issues/4071)
- Permalink page title [\#4065](https://github.com/DoSomething/phoenix/issues/4065)
- crop box doesn't go to the edge of the image [\#3963](https://github.com/DoSomething/phoenix/issues/3963)
- preview images w/ multiple reportbacks should show most recent first [\#3934](https://github.com/DoSomething/phoenix/issues/3934)
- Smoother cropping selection [\#3790](https://github.com/DoSomething/phoenix/issues/3790)
- Reportback Cropping: image\_gd\_create\(\) error  [\#3712](https://github.com/DoSomething/phoenix/issues/3712)

**Merged pull requests:**

- Reportback request animation frame [\#4097](https://github.com/DoSomething/phoenix/pull/4097) ([sbsmith86](https://github.com/sbsmith86))
- Permalink copy vars [\#4096](https://github.com/DoSomething/phoenix/pull/4096) ([angaither](https://github.com/angaither))
- Update to fix odd IE8 bug with labels and inputs in Reportback fallback. [\#4093](https://github.com/DoSomething/phoenix/pull/4093) ([weerd](https://github.com/weerd))
- Swap header sizes on static content. Fixes \#4084. [\#4091](https://github.com/DoSomething/phoenix/pull/4091) ([DFurnes](https://github.com/DFurnes))
- Updating preview gallery order of items. [\#4090](https://github.com/DoSomething/phoenix/pull/4090) ([weerd](https://github.com/weerd))
- Update navigation markup for Neue 6.1. [\#4089](https://github.com/DoSomething/phoenix/pull/4089) ([DFurnes](https://github.com/DFurnes))
- Update to fix broken animation when unveiling gallery items in Reportback gallery. [\#4088](https://github.com/DoSomething/phoenix/pull/4088) ([weerd](https://github.com/weerd))
- Progress on fixing image upload issue. [\#4086](https://github.com/DoSomething/phoenix/pull/4086) ([weerd](https://github.com/weerd))
- Update to fix slight bug in caption placeholder. [\#4082](https://github.com/DoSomething/phoenix/pull/4082) ([weerd](https://github.com/weerd))

## [v0.4.16](https://github.com/dosomething/phoenix/tree/v0.4.16) (2015-02-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.15...v0.4.16)

**Closed issues:**

- Fatal error introduced in v0.4.15 [\#4078](https://github.com/DoSomething/phoenix/issues/4078)

**Merged pull requests:**

- Removes unintended hook\_user\_load\(\). [\#4079](https://github.com/DoSomething/phoenix/pull/4079) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- More cleanup [\#4073](https://github.com/DoSomething/phoenix/pull/4073) ([DFurnes](https://github.com/DFurnes))

## [v0.4.15](https://github.com/dosomething/phoenix/tree/v0.4.15) (2015-02-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.14...v0.4.15)

**Fixed bugs:**

- Slight bug in Reportback Ajax script if requestSize variable changed. [\#3848](https://github.com/DoSomething/phoenix/issues/3848)

**Closed issues:**

- After reportbacking back, redirect user to RB confirmation [\#4004](https://github.com/DoSomething/phoenix/issues/4004)
- View more link persists when there’s no more images to view [\#3908](https://github.com/DoSomething/phoenix/issues/3908)
- Reportback Permalink page \(bender\) [\#3540](https://github.com/DoSomething/phoenix/issues/3540)

**Merged pull requests:**

- Fix homepage headers on affiliate sites [\#4072](https://github.com/DoSomething/phoenix/pull/4072) ([DFurnes](https://github.com/DFurnes))
- Reportback view more fixes [\#4069](https://github.com/DoSomething/phoenix/pull/4069) ([weerd](https://github.com/weerd))
- Theme that report back back back [\#4063](https://github.com/DoSomething/phoenix/pull/4063) ([angaither](https://github.com/angaither))

## [v0.4.14](https://github.com/dosomething/phoenix/tree/v0.4.14) (2015-02-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.13...v0.4.14)

**Fixed bugs:**

- Submit button animated icon working funky on mobile browsers [\#3968](https://github.com/DoSomething/phoenix/issues/3968)

**Closed issues:**

- Permalink page is only visible to the user who created the reportback [\#4052](https://github.com/DoSomething/phoenix/issues/4052)
- API should not strip characters from Reportback fields [\#4047](https://github.com/DoSomething/phoenix/issues/4047)
- Standalone Subscription Interface [\#3522](https://github.com/DoSomething/phoenix/issues/3522)

**Merged pull requests:**

- Let there be apostrophes  [\#4064](https://github.com/DoSomething/phoenix/pull/4064) ([aaronschachter](https://github.com/aaronschachter))
- Use standard header pattern on homepage, rather than wonky custom one. [\#4060](https://github.com/DoSomething/phoenix/pull/4060) ([DFurnes](https://github.com/DFurnes))
- Use Inline Form Actions pattern on search page. [\#4059](https://github.com/DoSomething/phoenix/pull/4059) ([DFurnes](https://github.com/DFurnes))

## [v0.4.13](https://github.com/dosomething/phoenix/tree/v0.4.13) (2015-02-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.12...v0.4.13)

**Fixed bugs:**

- padding off on triad gallery for closed campaigns [\#4040](https://github.com/DoSomething/phoenix/issues/4040)
- Action guide styling [\#4036](https://github.com/DoSomething/phoenix/issues/4036)
- Handle reportback caption overflow [\#3960](https://github.com/DoSomething/phoenix/issues/3960)

**Closed issues:**

- Staging campaign confirmation page does not appear [\#4057](https://github.com/DoSomething/phoenix/issues/4057)
- Reportback feature flag updates [\#4045](https://github.com/DoSomething/phoenix/issues/4045)
- Remove legacy rb entity file view [\#4044](https://github.com/DoSomething/phoenix/issues/4044)
- API endpoint to retrieve promoted Reportbacks [\#3966](https://github.com/DoSomething/phoenix/issues/3966)
- Reportback ajax loaded images animation failing [\#3847](https://github.com/DoSomething/phoenix/issues/3847)
- Disable / uninstall Flag module [\#3677](https://github.com/DoSomething/phoenix/issues/3677)

**Merged pull requests:**

- Turn off Mobile Commons subscriptions for the 26+ Club [\#4061](https://github.com/DoSomething/phoenix/pull/4061) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes \#4036. [\#4056](https://github.com/DoSomething/phoenix/pull/4056) ([DFurnes](https://github.com/DFurnes))
- Fix spacing on figure gallery on closed campaign. Fixes \#4040. [\#4055](https://github.com/DoSomething/phoenix/pull/4055) ([DFurnes](https://github.com/DFurnes))
- Prevents ds script from overriding local bash environment. [\#4053](https://github.com/DoSomething/phoenix/pull/4053) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Permalink feature flag ✓ [\#4050](https://github.com/DoSomething/phoenix/pull/4050) ([angaither](https://github.com/angaither))
- Updated reportback view url to admin/reportback. [\#4043](https://github.com/DoSomething/phoenix/pull/4043) ([angaither](https://github.com/angaither))

## [v0.4.12](https://github.com/dosomething/phoenix/tree/v0.4.12) (2015-02-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.11...v0.4.12)

**Fixed bugs:**

- Static content/Fact pages aren't linked in SOLR search. [\#4034](https://github.com/DoSomething/phoenix/issues/4034)
- PHP Notice Undefined \#title [\#4029](https://github.com/DoSomething/phoenix/issues/4029)

**Closed issues:**

- Permalink feature flag [\#4037](https://github.com/DoSomething/phoenix/issues/4037)
- First name text in nav should match other nav colors [\#4023](https://github.com/DoSomething/phoenix/issues/4023)
- Add dividing line in Reportback to make sections in interface more apparent. [\#4020](https://github.com/DoSomething/phoenix/issues/4020)
- Enable the use of an alternate background and text color in the Reportback section. [\#4018](https://github.com/DoSomething/phoenix/issues/4018)

**Merged pull requests:**

- Sets the title to empty string [\#4042](https://github.com/DoSomething/phoenix/pull/4042) ([deadlybutter](https://github.com/deadlybutter))
- Adding in reportback divider and soem style updates. [\#4041](https://github.com/DoSomething/phoenix/pull/4041) ([weerd](https://github.com/weerd))
- Permalink feature flag [\#4039](https://github.com/DoSomething/phoenix/pull/4039) ([angaither](https://github.com/angaither))
- Fix theme variable naming for static content & fact search results. [\#4035](https://github.com/DoSomething/phoenix/pull/4035) ([DFurnes](https://github.com/DFurnes))

## [v0.4.11](https://github.com/dosomething/phoenix/tree/v0.4.11) (2015-02-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.10...v0.4.11)

**Closed issues:**

- Update Campaign Custom Settings [\#4017](https://github.com/DoSomething/phoenix/issues/4017)
- Client side error messaging on image file size and dimensions [\#3729](https://github.com/DoSomething/phoenix/issues/3729)

**Merged pull requests:**

- Wrapping up updating both backend and frontend with new custom settings. [\#4031](https://github.com/DoSomething/phoenix/pull/4031) ([weerd](https://github.com/weerd))

## [v0.4.10](https://github.com/dosomething/phoenix/tree/v0.4.10) (2015-02-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.9...v0.4.10)

**Closed issues:**

- Remove transactional\_user\_profile\_update production from dosomething\_mbp installation [\#4025](https://github.com/DoSomething/phoenix/issues/4025)
- client side validation needed for accepted image file types [\#3878](https://github.com/DoSomething/phoenix/issues/3878)
- Move Mobile Commons Signup Submissions to Message Broker [\#3840](https://github.com/DoSomething/phoenix/issues/3840)

**Merged pull requests:**

- Validate all the things. [\#4030](https://github.com/DoSomething/phoenix/pull/4030) ([sbsmith86](https://github.com/sbsmith86))
- Removes transactional\_user\_profile\_update MB production. [\#4028](https://github.com/DoSomething/phoenix/pull/4028) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.4.9](https://github.com/dosomething/phoenix/tree/v0.4.9) (2015-02-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.8...v0.4.9)

**Fixed bugs:**

- GA custom event on action page has stopped triggering [\#4016](https://github.com/DoSomething/phoenix/issues/4016)
- button alignment off again on You're Doing section of profile [\#4011](https://github.com/DoSomething/phoenix/issues/4011)

**Closed issues:**

- updates to birthday field on profile [\#4006](https://github.com/DoSomething/phoenix/issues/4006)
- change caption placeholder text  [\#3952](https://github.com/DoSomething/phoenix/issues/3952)
- character counter for user on caption field [\#3920](https://github.com/DoSomething/phoenix/issues/3920)
- Change photo button should pull up a file input and change the photo in the modal [\#3896](https://github.com/DoSomething/phoenix/issues/3896)
- Remove Reportback feature flags / conditional logic [\#3735](https://github.com/DoSomething/phoenix/issues/3735)
- Remove old Prove It code [\#3636](https://github.com/DoSomething/phoenix/issues/3636)
- Reportback Confirmation page needs to use the RB Permalink view [\#3629](https://github.com/DoSomething/phoenix/issues/3629)
- Reportback Cropping: Save original file [\#3615](https://github.com/DoSomething/phoenix/issues/3615)
- Remove "User Profile Link" theme setting / conditionals  [\#3260](https://github.com/DoSomething/phoenix/issues/3260)

**Merged pull requests:**

- Delegates direct mobilecommons calls on signups to MB queues. [\#4024](https://github.com/DoSomething/phoenix/pull/4024) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Reportback change photo [\#4022](https://github.com/DoSomething/phoenix/pull/4022) ([sbsmith86](https://github.com/sbsmith86))
- Reportback spring cleaning [\#4021](https://github.com/DoSomething/phoenix/pull/4021) ([weerd](https://github.com/weerd))
- Update custom events code to use Universal Analytics. [\#4019](https://github.com/DoSomething/phoenix/pull/4019) ([DFurnes](https://github.com/DFurnes))
- Cleans up birthday field [\#4015](https://github.com/DoSomething/phoenix/pull/4015) ([deadlybutter](https://github.com/deadlybutter))
- Updating placeholder text, errr... text. [\#4014](https://github.com/DoSomething/phoenix/pull/4014) ([weerd](https://github.com/weerd))
- Removes profile link conditional [\#4013](https://github.com/DoSomething/phoenix/pull/4013) ([deadlybutter](https://github.com/deadlybutter))
- Adjusts figure min. body height [\#4012](https://github.com/DoSomething/phoenix/pull/4012) ([deadlybutter](https://github.com/deadlybutter))

## [v0.4.8](https://github.com/dosomething/phoenix/tree/v0.4.8) (2015-02-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.7...v0.4.8)

**Merged pull requests:**

- Quick perf wins [\#4009](https://github.com/DoSomething/phoenix/pull/4009) ([DFurnes](https://github.com/DFurnes))

## [v0.4.7](https://github.com/dosomething/phoenix/tree/v0.4.7) (2015-02-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.6...v0.4.7)

**Fixed bugs:**

- Caption required bug [\#3962](https://github.com/DoSomething/phoenix/issues/3962)

**Closed issues:**

- remove t-shirt offer ever if user has earned but not redeemed the offer [\#4005](https://github.com/DoSomething/phoenix/issues/4005)
- Add total count to content search [\#4001](https://github.com/DoSomething/phoenix/issues/4001)
- let's move "image too small" error message at the top of the form, not the bottom [\#3969](https://github.com/DoSomething/phoenix/issues/3969)
- Fix styling of edit photo button [\#3924](https://github.com/DoSomething/phoenix/issues/3924)

**Merged pull requests:**

- Edit photo button styles [\#4008](https://github.com/DoSomething/phoenix/pull/4008) ([sbsmith86](https://github.com/sbsmith86))
- Caption bug fix [\#4007](https://github.com/DoSomething/phoenix/pull/4007) ([weerd](https://github.com/weerd))
- Reportback error display [\#4003](https://github.com/DoSomething/phoenix/pull/4003) ([sbsmith86](https://github.com/sbsmith86))
- Content search view [\#4002](https://github.com/DoSomething/phoenix/pull/4002) ([angaither](https://github.com/angaither))

## [v0.4.6](https://github.com/dosomething/phoenix/tree/v0.4.6) (2015-02-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.5...v0.4.6)

**Closed issues:**

- crop modal shouldn't close when you mouse-up™ outside the modal [\#3953](https://github.com/DoSomething/phoenix/issues/3953)

**Merged pull requests:**

- Remove flag from DS Profile dependencies [\#4000](https://github.com/DoSomething/phoenix/pull/4000) ([aaronschachter](https://github.com/aaronschachter))
- Using closeButtonOnly option when modal opens [\#3999](https://github.com/DoSomething/phoenix/pull/3999) ([sbsmith86](https://github.com/sbsmith86))
- Update Bower dependencies with final Neue 6.0 release! :tada: [\#3998](https://github.com/DoSomething/phoenix/pull/3998) ([DFurnes](https://github.com/DFurnes))
- Update README with blog post link. [\#3997](https://github.com/DoSomething/phoenix/pull/3997) ([DFurnes](https://github.com/DFurnes))

## [v0.4.5](https://github.com/dosomething/phoenix/tree/v0.4.5) (2015-02-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.4...v0.4.5)

**Fixed bugs:**

- proper neue styles missing for pw reset flow [\#3988](https://github.com/DoSomething/phoenix/issues/3988)

**Closed issues:**

- Switch "Contact Us" and sponsor text in info bar on action page [\#3992](https://github.com/DoSomething/phoenix/issues/3992)

**Merged pull requests:**

- Swap positions of "contact us" and partner text in Info Bar. [\#3993](https://github.com/DoSomething/phoenix/pull/3993) ([DFurnes](https://github.com/DFurnes))
- Add container\_\_block for padding on default pages. [\#3990](https://github.com/DoSomething/phoenix/pull/3990) ([DFurnes](https://github.com/DFurnes))
- Update header markup on reward form. [\#3989](https://github.com/DoSomething/phoenix/pull/3989) ([DFurnes](https://github.com/DFurnes))

## [v0.4.4](https://github.com/dosomething/phoenix/tree/v0.4.4) (2015-02-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.3...v0.4.4)

**Fixed bugs:**

- fix spacing between facts on 11 facts pages [\#3771](https://github.com/DoSomething/phoenix/issues/3771)
- Rotate orientation on image upload [\#3630](https://github.com/DoSomething/phoenix/issues/3630)

**Closed issues:**

- /user/edit updates [\#3987](https://github.com/DoSomething/phoenix/issues/3987)
- Unable to load a PNG, no error messages given [\#3950](https://github.com/DoSomething/phoenix/issues/3950)
- No error when uploading a video [\#3914](https://github.com/DoSomething/phoenix/issues/3914)
- crop button should say "crop", not done [\#3913](https://github.com/DoSomething/phoenix/issues/3913)
- Modal is easy to accidentally close while trying to drag the grab-box™ [\#3912](https://github.com/DoSomething/phoenix/issues/3912)
- Add "Edit" link after photo is cropped and previewed in Reportback interface. [\#3880](https://github.com/DoSomething/phoenix/issues/3880)
- Campaign "Plan It" intro should be full-width [\#3857](https://github.com/DoSomething/phoenix/issues/3857)
- get rid of jump when clicking on "Need help finding your school?" for school finder modal [\#3384](https://github.com/DoSomething/phoenix/issues/3384)

**Merged pull requests:**

- Fixes user edit page [\#3991](https://github.com/DoSomething/phoenix/pull/3991) ([deadlybutter](https://github.com/deadlybutter))
- Fix issues with fact page layout. [\#3986](https://github.com/DoSomething/phoenix/pull/3986) ([DFurnes](https://github.com/DFurnes))
- Fixes \#3857. [\#3984](https://github.com/DoSomething/phoenix/pull/3984) ([DFurnes](https://github.com/DFurnes))
- Fixes \#3384. [\#3983](https://github.com/DoSomething/phoenix/pull/3983) ([DFurnes](https://github.com/DFurnes))

## [v0.4.3](https://github.com/dosomething/phoenix/tree/v0.4.3) (2015-02-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.2...v0.4.3)

**Closed issues:**

- Questions about http://staging.beta.dosomething.org/api/v1/users.json?parameters\[mobile\]=2125550001 [\#3985](https://github.com/DoSomething/phoenix/issues/3985)
- Store user subscription preferences in mb-user DB [\#3456](https://github.com/DoSomething/phoenix/issues/3456)
- Send campaign report back transactional via MB [\#3434](https://github.com/DoSomething/phoenix/issues/3434)
- Send campaign sign transactional via MB [\#3433](https://github.com/DoSomething/phoenix/issues/3433)
- Send password reset transactionals via MB [\#3432](https://github.com/DoSomething/phoenix/issues/3432)
- Send all new user transactionals via MB [\#3430](https://github.com/DoSomething/phoenix/issues/3430)
- User Email Opt-in preferences [\#3365](https://github.com/DoSomething/phoenix/issues/3365)

**Merged pull requests:**

- Update header markup on Confirmation page. [\#3982](https://github.com/DoSomething/phoenix/pull/3982) ([DFurnes](https://github.com/DFurnes))
- Update to selection year options and adding some basic styles. [\#3981](https://github.com/DoSomething/phoenix/pull/3981) ([weerd](https://github.com/weerd))
- Adds dropdown menu to nav [\#3944](https://github.com/DoSomething/phoenix/pull/3944) ([deadlybutter](https://github.com/deadlybutter))

## [v0.4.2](https://github.com/dosomething/phoenix/tree/v0.4.2) (2015-02-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.1...v0.4.2)

**Closed issues:**

- Job Skills taxonomy [\#3925](https://github.com/DoSomething/phoenix/issues/3925)
- Scholarship text not aligned on mobile [\#3795](https://github.com/DoSomething/phoenix/issues/3795)

**Merged pull requests:**

- Fix some display issues with figure on profile page. [\#3980](https://github.com/DoSomething/phoenix/pull/3980) ([DFurnes](https://github.com/DFurnes))
- Update header markup on user profile page. [\#3979](https://github.com/DoSomething/phoenix/pull/3979) ([DFurnes](https://github.com/DFurnes))
- Update for Neue 6.0-RC2. [\#3978](https://github.com/DoSomething/phoenix/pull/3978) ([DFurnes](https://github.com/DFurnes))
- Update header markup on pitch page. [\#3977](https://github.com/DoSomething/phoenix/pull/3977) ([DFurnes](https://github.com/DFurnes))

## [v0.4.1](https://github.com/dosomething/phoenix/tree/v0.4.1) (2015-02-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.4.0...v0.4.1)

**Closed issues:**

- Official Rules needs to show up on SMS games and scholarship handwritten font alignment needs fixing [\#3408](https://github.com/DoSomething/phoenix/issues/3408)

**Merged pull requests:**

- Fix display issue with footnote and markdown source lists. [\#3976](https://github.com/DoSomething/phoenix/pull/3976) ([DFurnes](https://github.com/DFurnes))
- Deletes deprecated Reportback Gallery entity reference field [\#3975](https://github.com/DoSomething/phoenix/pull/3975) ([aaronschachter](https://github.com/aaronschachter))
- Fixes scholarship callout on SMS campaigns. [\#3974](https://github.com/DoSomething/phoenix/pull/3974) ([DFurnes](https://github.com/DFurnes))
- Update taxonomy page header markup. [\#3973](https://github.com/DoSomething/phoenix/pull/3973) ([DFurnes](https://github.com/DFurnes))
- Neue 6.0 RC1 [\#3972](https://github.com/DoSomething/phoenix/pull/3972) ([DFurnes](https://github.com/DFurnes))

## [v0.4.0](https://github.com/dosomething/phoenix/tree/v0.4.0) (2015-02-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.232...v0.4.0)

**Closed issues:**

- User Profile shouldn't link to Campaign Run nodes [\#3947](https://github.com/DoSomething/phoenix/issues/3947)
- remove field\_video\_id from image content type [\#3877](https://github.com/DoSomething/phoenix/issues/3877)
- updates to User Profile Edit form \(/user/uid/edit\) [\#3805](https://github.com/DoSomething/phoenix/issues/3805)
- Hide timezone so users can't change it [\#3150](https://github.com/DoSomething/phoenix/issues/3150)

**Merged pull requests:**

- Adds preprocessing to the User Profile form [\#3970](https://github.com/DoSomething/phoenix/pull/3970) ([aaronschachter](https://github.com/aaronschachter))
- Removes the video ID field [\#3967](https://github.com/DoSomething/phoenix/pull/3967) ([deadlybutter](https://github.com/deadlybutter))
- Displaying Campaign Run reportbacks [\#3959](https://github.com/DoSomething/phoenix/pull/3959) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.232](https://github.com/dosomething/phoenix/tree/v0.3.232) (2015-02-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.231...v0.3.232)

**Merged pull requests:**

- removing debug line [\#3965](https://github.com/DoSomething/phoenix/pull/3965) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.231](https://github.com/dosomething/phoenix/tree/v0.3.231) (2015-02-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.230...v0.3.231)

**Closed issues:**

- User Profile: Your Prizes \(various states\) [\#3388](https://github.com/DoSomething/phoenix/issues/3388)
- User Profile: My Scholarships [\#3377](https://github.com/DoSomething/phoenix/issues/3377)
- User Profile: Campaign Status fender [\#3375](https://github.com/DoSomething/phoenix/issues/3375)
- User Profile: Campaign Status bender [\#3374](https://github.com/DoSomething/phoenix/issues/3374)
- User Profile: Redeem T-Shirt Form [\#3373](https://github.com/DoSomething/phoenix/issues/3373)
- International sites need to be able to customize phone number format placeholder [\#3183](https://github.com/DoSomething/phoenix/issues/3183)

**Merged pull requests:**

- Reportback ie bug [\#3964](https://github.com/DoSomething/phoenix/pull/3964) ([sbsmith86](https://github.com/sbsmith86))
- Footnote fact [\#3958](https://github.com/DoSomething/phoenix/pull/3958) ([DFurnes](https://github.com/DFurnes))
- Update SMS template with new footnote pattern. [\#3957](https://github.com/DoSomething/phoenix/pull/3957) ([DFurnes](https://github.com/DFurnes))
- Prefer square-crop over poster on mobile video tiles. [\#3940](https://github.com/DoSomething/phoenix/pull/3940) ([DFurnes](https://github.com/DFurnes))

## [v0.3.230](https://github.com/dosomething/phoenix/tree/v0.3.230) (2015-02-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.229...v0.3.230)

**Merged pull requests:**

- reset degrees when initiating crop [\#3955](https://github.com/DoSomething/phoenix/pull/3955) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.229](https://github.com/dosomething/phoenix/tree/v0.3.229) (2015-02-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.228...v0.3.229)

**Closed issues:**

- Campaign Run needs to display Reviewed Reportbacks view [\#3946](https://github.com/DoSomething/phoenix/issues/3946)

**Merged pull requests:**

- Display reviewed reportbacks for Campaign Run [\#3954](https://github.com/DoSomething/phoenix/pull/3954) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.228](https://github.com/dosomething/phoenix/tree/v0.3.228) (2015-02-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.227...v0.3.228)

**Fixed bugs:**

- Picture rotates in only 180 degree increments after clicking on Change Photo. [\#3935](https://github.com/DoSomething/phoenix/issues/3935)

**Merged pull requests:**

- Fix of PNG images [\#3951](https://github.com/DoSomething/phoenix/pull/3951) ([sbsmith86](https://github.com/sbsmith86))
- Reportback rotate fix [\#3942](https://github.com/DoSomething/phoenix/pull/3942) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.227](https://github.com/dosomething/phoenix/tree/v0.3.227) (2015-02-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.226...v0.3.227)

**Merged pull requests:**

- unbind the click event right before rebinding it [\#3949](https://github.com/DoSomething/phoenix/pull/3949) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.226](https://github.com/dosomething/phoenix/tree/v0.3.226) (2015-02-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.225...v0.3.226)

**Merged pull requests:**

- unbind click event when modal closes [\#3948](https://github.com/DoSomething/phoenix/pull/3948) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.225](https://github.com/dosomething/phoenix/tree/v0.3.225) (2015-02-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.224...v0.3.225)

**Closed issues:**

- DS MBP PHP Notice: Undefined index: username [\#3921](https://github.com/DoSomething/phoenix/issues/3921)
- keep caption field hidden and update caption under preview image [\#3911](https://github.com/DoSomething/phoenix/issues/3911)
- Reportback Caption character count [\#3527](https://github.com/DoSomething/phoenix/issues/3527)

**Merged pull requests:**

- Reportback caption display [\#3945](https://github.com/DoSomething/phoenix/pull/3945) ([sbsmith86](https://github.com/sbsmith86))
- Reportback caption fix take 2 [\#3943](https://github.com/DoSomething/phoenix/pull/3943) ([weerd](https://github.com/weerd))
- Remove username from password\_reset MBP payload [\#3936](https://github.com/DoSomething/phoenix/pull/3936) ([DeeZone](https://github.com/DeeZone))

## [v0.3.224](https://github.com/dosomething/phoenix/tree/v0.3.224) (2015-02-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.223...v0.3.224)

**Fixed bugs:**

- contact us modal styling is off [\#3933](https://github.com/DoSomething/phoenix/issues/3933)
- "File upload error. Could not move uploaded file." on node 4044 [\#3926](https://github.com/DoSomething/phoenix/issues/3926)
- Squishy preview image on mobile [\#3909](https://github.com/DoSomething/phoenix/issues/3909)

**Closed issues:**

- fake [\#3938](https://github.com/DoSomething/phoenix/issues/3938)

**Merged pull requests:**

- Updates Views contrib module [\#3941](https://github.com/DoSomething/phoenix/pull/3941) ([aaronschachter](https://github.com/aaronschachter))
- Updates Contact Us modal to use new modal blocks. [\#3939](https://github.com/DoSomething/phoenix/pull/3939) ([DFurnes](https://github.com/DFurnes))
- Remove EXIF data from file [\#3937](https://github.com/DoSomething/phoenix/pull/3937) ([sbsmith86](https://github.com/sbsmith86))
- user\_name should be username in MBP params [\#3922](https://github.com/DoSomething/phoenix/pull/3922) ([DeeZone](https://github.com/DeeZone))

## [v0.3.223](https://github.com/dosomething/phoenix/tree/v0.3.223) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.222...v0.3.223)

**Fixed bugs:**

- ZenDesk submission error [\#3931](https://github.com/DoSomething/phoenix/issues/3931)

**Merged pull requests:**

- Zendesk fix - Only update when profile fields not set [\#3932](https://github.com/DoSomething/phoenix/pull/3932) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.222](https://github.com/dosomething/phoenix/tree/v0.3.222) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.221...v0.3.222)

**Closed issues:**

- Calculate Reportback Totals upon insert and update [\#3874](https://github.com/DoSomething/phoenix/issues/3874)

**Merged pull requests:**

- Update Cause term totals [\#3930](https://github.com/DoSomething/phoenix/pull/3930) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.221](https://github.com/dosomething/phoenix/tree/v0.3.221) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.220...v0.3.221)

**Closed issues:**

- Reportback Upload IE Support [\#3699](https://github.com/DoSomething/phoenix/issues/3699)

**Merged pull requests:**

- Reportback Access fix [\#3929](https://github.com/DoSomething/phoenix/pull/3929) ([aaronschachter](https://github.com/aaronschachter))
- Update Campaign RB Totals upon Reportback File Save  [\#3928](https://github.com/DoSomething/phoenix/pull/3928) ([aaronschachter](https://github.com/aaronschachter))
- Adding ds function to restart php5-fpm [\#3863](https://github.com/DoSomething/phoenix/pull/3863) ([blisteringherb](https://github.com/blisteringherb))

## [v0.3.220](https://github.com/dosomething/phoenix/tree/v0.3.220) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.219...v0.3.220)

**Closed issues:**

- Stathat coverage for report back submissions [\#3916](https://github.com/DoSomething/phoenix/issues/3916)
- Ability to edit crop after you see crop preview [\#3915](https://github.com/DoSomething/phoenix/issues/3915)
- A preview image and caption should only be shown if the user clicks done button. [\#3891](https://github.com/DoSomething/phoenix/issues/3891)

**Merged pull requests:**

- Reportback ie behavior [\#3927](https://github.com/DoSomething/phoenix/pull/3927) ([weerd](https://github.com/weerd))

## [v0.3.219](https://github.com/dosomething/phoenix/tree/v0.3.219) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.218...v0.3.219)

## [v0.3.218](https://github.com/dosomething/phoenix/tree/v0.3.218) (2015-02-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.217...v0.3.218)

**Closed issues:**

- Multilingual site prototype [\#3720](https://github.com/DoSomething/phoenix/issues/3720)
- Canada: implement profile synchronization [\#3595](https://github.com/DoSomething/phoenix/issues/3595)

**Merged pull requests:**

- Updated reportback image flow. [\#3923](https://github.com/DoSomething/phoenix/pull/3923) ([sbsmith86](https://github.com/sbsmith86))
- Neue 6.0 beta5 [\#3919](https://github.com/DoSomething/phoenix/pull/3919) ([DFurnes](https://github.com/DFurnes))

## [v0.3.217](https://github.com/dosomething/phoenix/tree/v0.3.217) (2015-02-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.216...v0.3.217)

**Merged pull requests:**

- Temporary fix for video tiles on Mobile Safari. [\#3918](https://github.com/DoSomething/phoenix/pull/3918) ([DFurnes](https://github.com/DFurnes))

## [v0.3.216](https://github.com/dosomething/phoenix/tree/v0.3.216) (2015-02-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.215...v0.3.216)

**Fixed bugs:**

- when user goes to change photo the page refresh isn't properly anchoring to prove it section [\#3910](https://github.com/DoSomething/phoenix/issues/3910)

**Closed issues:**

- preview shows wrong image if user first uploads an image less than 480 x 480 [\#3892](https://github.com/DoSomething/phoenix/issues/3892)
- Add "remove photo" link after photo is cropped and previewed in Reportback interface.  [\#3886](https://github.com/DoSomething/phoenix/issues/3886)
- Upload Gallery placeholder images [\#3702](https://github.com/DoSomething/phoenix/issues/3702)

**Merged pull requests:**

- Updates view\_unpublished contrib module [\#3917](https://github.com/DoSomething/phoenix/pull/3917) ([aaronschachter](https://github.com/aaronschachter))
- Show preview image of correct image file [\#3907](https://github.com/DoSomething/phoenix/pull/3907) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.215](https://github.com/dosomething/phoenix/tree/v0.3.215) (2015-02-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.214...v0.3.215)

**Merged pull requests:**

- Update for a hotfix for testing. [\#3906](https://github.com/DoSomething/phoenix/pull/3906) ([weerd](https://github.com/weerd))

## [v0.3.214](https://github.com/dosomething/phoenix/tree/v0.3.214) (2015-02-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.213...v0.3.214)

**Closed issues:**

- Updates to crop box handle [\#3884](https://github.com/DoSomething/phoenix/issues/3884)
- Content for placeholder image captions. [\#3850](https://github.com/DoSomething/phoenix/issues/3850)

**Merged pull requests:**

- Update to temporarily fixed a bug that was introduced. [\#3905](https://github.com/DoSomething/phoenix/pull/3905) ([weerd](https://github.com/weerd))
- Updating placeholder text with approved langauge. [\#3903](https://github.com/DoSomething/phoenix/pull/3903) ([weerd](https://github.com/weerd))

## [v0.3.213](https://github.com/dosomething/phoenix/tree/v0.3.213) (2015-02-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.212...v0.3.213)

**Closed issues:**

- Make the crop box bigger [\#3864](https://github.com/DoSomething/phoenix/issues/3864)
- change photo should refresh page at the prove it section [\#3831](https://github.com/DoSomething/phoenix/issues/3831)
- Alignment of tri-gallery to grid [\#3547](https://github.com/DoSomething/phoenix/issues/3547)
- Trim 11-facts spacing between intro & first fact [\#3255](https://github.com/DoSomething/phoenix/issues/3255)

**Merged pull requests:**

- Reportback caption validation [\#3902](https://github.com/DoSomething/phoenix/pull/3902) ([weerd](https://github.com/weerd))
- Style updates to the resize handle [\#3901](https://github.com/DoSomething/phoenix/pull/3901) ([sbsmith86](https://github.com/sbsmith86))
- Reportback cropbox size [\#3900](https://github.com/DoSomething/phoenix/pull/3900) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.212](https://github.com/dosomething/phoenix/tree/v0.3.212) (2015-02-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.211...v0.3.212)

**Fixed bugs:**

- Admin reportback permalink not working [\#3897](https://github.com/DoSomething/phoenix/issues/3897)
- PHP Notices for output [\#3890](https://github.com/DoSomething/phoenix/issues/3890)

**Merged pull requests:**

- Reportback Permalink fix [\#3898](https://github.com/DoSomething/phoenix/pull/3898) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.211](https://github.com/dosomething/phoenix/tree/v0.3.211) (2015-02-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.210...v0.3.211)

**Closed issues:**

- closing cropping modal should not result in an image being "submitted" for preview [\#3893](https://github.com/DoSomething/phoenix/issues/3893)
- Remove mc\_opt\_in\_path\_id from affiliate MB requests [\#3889](https://github.com/DoSomething/phoenix/issues/3889)

**Merged pull requests:**

- Reportback change photo button [\#3895](https://github.com/DoSomething/phoenix/pull/3895) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.210](https://github.com/dosomething/phoenix/tree/v0.3.210) (2015-02-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.209...v0.3.210)

**Closed issues:**

- Reportback Totals variables [\#3846](https://github.com/DoSomething/phoenix/issues/3846)

**Merged pull requests:**

- Refresh Campaign Count variables [\#3888](https://github.com/DoSomething/phoenix/pull/3888) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.209](https://github.com/dosomething/phoenix/tree/v0.3.209) (2015-02-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.208...v0.3.209)

**Closed issues:**

- add javascript to preview newly cropped image for multiple uploads [\#3829](https://github.com/DoSomething/phoenix/issues/3829)
- Reportback Cropping: Resize area too large on desktop [\#3774](https://github.com/DoSomething/phoenix/issues/3774)

**Merged pull requests:**

- Refactor dosomething\_helpers\_set\_variable [\#3887](https://github.com/DoSomething/phoenix/pull/3887) ([aaronschachter](https://github.com/aaronschachter))
- Adds dosomething\_campaign\_get\_campaigns function [\#3885](https://github.com/DoSomething/phoenix/pull/3885) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.208](https://github.com/dosomething/phoenix/tree/v0.3.208) (2015-02-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.207...v0.3.208)

**Fixed bugs:**

- Bug: Active page not visible to administrators [\#3867](https://github.com/DoSomething/phoenix/issues/3867)

**Closed issues:**

- org friend needs access to closed paged callback [\#3870](https://github.com/DoSomething/phoenix/issues/3870)

**Merged pull requests:**

- Campaign Preview access [\#3883](https://github.com/DoSomething/phoenix/pull/3883) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Count totals [\#3876](https://github.com/DoSomething/phoenix/pull/3876) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.207](https://github.com/dosomething/phoenix/tree/v0.3.207) (2015-02-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.206...v0.3.207)

**Fixed bugs:**

- styling borked on caption field [\#3879](https://github.com/DoSomething/phoenix/issues/3879)

**Merged pull requests:**

- Fix text field class name. [\#3882](https://github.com/DoSomething/phoenix/pull/3882) ([DFurnes](https://github.com/DFurnes))
- Delegates direct mobilecommons calls on registrations to MB queues. [\#3881](https://github.com/DoSomething/phoenix/pull/3881) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Bind move event to the document. [\#3875](https://github.com/DoSomething/phoenix/pull/3875) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.206](https://github.com/dosomething/phoenix/tree/v0.3.206) (2015-02-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.205...v0.3.206)

**Merged pull requests:**

- Reportback Count variables [\#3873](https://github.com/DoSomething/phoenix/pull/3873) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.205](https://github.com/dosomething/phoenix/tree/v0.3.205) (2015-02-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.204...v0.3.205)

**Fixed bugs:**

- spacing of title/cta is off on pitch page if there is a date [\#3844](https://github.com/DoSomething/phoenix/issues/3844)

**Closed issues:**

- Fix spacing of triad gallery pics and descriptions [\#3793](https://github.com/DoSomething/phoenix/issues/3793)

**Merged pull requests:**

- Add Neue v6.0.0-beta4 form classes to crop modal. [\#3872](https://github.com/DoSomething/phoenix/pull/3872) ([DFurnes](https://github.com/DFurnes))
- Reportback caption fallbacks [\#3871](https://github.com/DoSomething/phoenix/pull/3871) ([weerd](https://github.com/weerd))

## [v0.3.204](https://github.com/dosomething/phoenix/tree/v0.3.204) (2015-02-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.203...v0.3.204)

**Merged pull requests:**

- Neue 6.0 beta4 [\#3859](https://github.com/DoSomething/phoenix/pull/3859) ([DFurnes](https://github.com/DFurnes))

## [v0.3.203](https://github.com/dosomething/phoenix/tree/v0.3.203) (2015-02-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.202...v0.3.203)

**Closed issues:**

- Broken Campaigns on beta3 [\#3865](https://github.com/DoSomething/phoenix/issues/3865)
- Convey to the user that they have to crop the image [\#3827](https://github.com/DoSomething/phoenix/issues/3827)
- image rotation only saves after crop frame is also moved [\#3824](https://github.com/DoSomething/phoenix/issues/3824)

**Merged pull requests:**

- Gets rid of the last PHP short tag. [\#3869](https://github.com/DoSomething/phoenix/pull/3869) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Replaces PHP short-tag in Action Guide template which caused E\_PARSE on PHP 5.9 [\#3868](https://github.com/DoSomething/phoenix/pull/3868) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.202](https://github.com/dosomething/phoenix/tree/v0.3.202) (2015-02-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.201...v0.3.202)

**Fixed bugs:**

- users' names not showing up on closed campaign What You Did gallery for logged out users [\#3851](https://github.com/DoSomething/phoenix/issues/3851)
- need more space between paragraph text and inline buttons [\#3764](https://github.com/DoSomething/phoenix/issues/3764)

**Closed issues:**

- Cannot upload image of exactly 480 x 480 [\#3825](https://github.com/DoSomething/phoenix/issues/3825)
- display cropped image preview + caption on form [\#3750](https://github.com/DoSomething/phoenix/issues/3750)

**Merged pull requests:**

- Reportback preview image [\#3862](https://github.com/DoSomething/phoenix/pull/3862) ([sbsmith86](https://github.com/sbsmith86))
- Reportback updates part 1 [\#3861](https://github.com/DoSomething/phoenix/pull/3861) ([weerd](https://github.com/weerd))
- Closed Gallery fix [\#3860](https://github.com/DoSomething/phoenix/pull/3860) ([aaronschachter](https://github.com/aaronschachter))
- Grants org friend access to the active page callback [\#3858](https://github.com/DoSomething/phoenix/pull/3858) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.201](https://github.com/dosomething/phoenix/tree/v0.3.201) (2015-02-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.200...v0.3.201)

**Fixed bugs:**

- Password reset not working on DS Canada site [\#3632](https://github.com/DoSomething/phoenix/issues/3632)

**Closed issues:**

- Add timezone to date values in MB payload [\#3855](https://github.com/DoSomething/phoenix/issues/3855)
- change closed campaign notification message [\#3853](https://github.com/DoSomething/phoenix/issues/3853)
- Neue issues on canada.dosomething.org [\#3834](https://github.com/DoSomething/phoenix/issues/3834)
- Canada: Sync pre-SSO registered users via API [\#3792](https://github.com/DoSomething/phoenix/issues/3792)

**Merged pull requests:**

- Reportback form: Query by Primary Cause [\#3856](https://github.com/DoSomething/phoenix/pull/3856) ([aaronschachter](https://github.com/aaronschachter))
- Closed campaign copy [\#3854](https://github.com/DoSomething/phoenix/pull/3854) ([aaronschachter](https://github.com/aaronschachter))
- Canada: remove post-missing-tig-users drush task. [\#3852](https://github.com/DoSomething/phoenix/pull/3852) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Remove unused images from theme. [\#3843](https://github.com/DoSomething/phoenix/pull/3843) ([DFurnes](https://github.com/DFurnes))

## [v0.3.200](https://github.com/dosomething/phoenix/tree/v0.3.200) (2015-01-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.199...v0.3.200)

**Fixed bugs:**

- Invalid SMS Campaign Reportback CAMPAIGN\_TITLE merge\_var value [\#3835](https://github.com/DoSomething/phoenix/issues/3835)

**Closed issues:**

- Theme Gallery placeholders [\#3664](https://github.com/DoSomething/phoenix/issues/3664)
- outstanding redirects needed [\#3647](https://github.com/DoSomething/phoenix/issues/3647)

**Merged pull requests:**

- Reportback placeholders [\#3842](https://github.com/DoSomething/phoenix/pull/3842) ([weerd](https://github.com/weerd))

## [v0.3.199](https://github.com/dosomething/phoenix/tree/v0.3.199) (2015-01-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.198...v0.3.199)

**Merged pull requests:**

- Creates a drush job to post missing TIG users to the remote user API. [\#3839](https://github.com/DoSomething/phoenix/pull/3839) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.198](https://github.com/dosomething/phoenix/tree/v0.3.198) (2015-01-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.197...v0.3.198)

**Fixed bugs:**

- not enough padding between text separator and copy on closed campaigns [\#3766](https://github.com/DoSomething/phoenix/issues/3766)

**Merged pull requests:**

- Quick fix for container collapsing issue with floated content. [\#3838](https://github.com/DoSomething/phoenix/pull/3838) ([DFurnes](https://github.com/DFurnes))

## [v0.3.197](https://github.com/dosomething/phoenix/tree/v0.3.197) (2015-01-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.196...v0.3.197)

**Fixed bugs:**

- Official rules link visual bug [\#3819](https://github.com/DoSomething/phoenix/issues/3819)

**Merged pull requests:**

- Fix display issue where carousel was breaking out of grid. [\#3837](https://github.com/DoSomething/phoenix/pull/3837) ([DFurnes](https://github.com/DFurnes))
- Fix official rules display issue. [\#3830](https://github.com/DoSomething/phoenix/pull/3830) ([DFurnes](https://github.com/DFurnes))

## [v0.3.196](https://github.com/dosomething/phoenix/tree/v0.3.196) (2015-01-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.195...v0.3.196)

**Closed issues:**

- set default status of reportbacks in inbox to approved [\#3823](https://github.com/DoSomething/phoenix/issues/3823)

**Merged pull requests:**

- Approved as default status on RB Form [\#3833](https://github.com/DoSomething/phoenix/pull/3833) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.195](https://github.com/dosomething/phoenix/tree/v0.3.195) (2015-01-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.194...v0.3.195)

**Closed issues:**

- Reportback Flags cleanup [\#3689](https://github.com/DoSomething/phoenix/issues/3689)
- video tiles on homepage [\#3627](https://github.com/DoSomething/phoenix/issues/3627)
- Reportback cropping: Crop box sometimes breaks out of image container [\#3591](https://github.com/DoSomething/phoenix/issues/3591)
- pull in link to user profile and uid into Zendesk [\#3565](https://github.com/DoSomething/phoenix/issues/3565)
- Multiple images reportback flow [\#3287](https://github.com/DoSomething/phoenix/issues/3287)
- Remove Pitch Page optimizely templates [\#3251](https://github.com/DoSomething/phoenix/issues/3251)

**Merged pull requests:**

- Kills flagged\_reportback Flag and related fields [\#3832](https://github.com/DoSomething/phoenix/pull/3832) ([aaronschachter](https://github.com/aaronschachter))
- Wreck it fix it [\#3828](https://github.com/DoSomething/phoenix/pull/3828) ([DFurnes](https://github.com/DFurnes))
- Video tile [\#3826](https://github.com/DoSomething/phoenix/pull/3826) ([DFurnes](https://github.com/DFurnes))
- Adds profile link and UID to Zendesk users [\#3821](https://github.com/DoSomething/phoenix/pull/3821) ([deadlybutter](https://github.com/deadlybutter))
- Remove old Optimizely code snippets. [\#3802](https://github.com/DoSomething/phoenix/pull/3802) ([DFurnes](https://github.com/DFurnes))

## [v0.3.194](https://github.com/dosomething/phoenix/tree/v0.3.194) (2015-01-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.193...v0.3.194)

**Closed issues:**

- Canada: forgot password flow error [\#3814](https://github.com/DoSomething/phoenix/issues/3814)
- Uninstall and remove deprecated SMS Reportback modules [\#3529](https://github.com/DoSomething/phoenix/issues/3529)

**Merged pull requests:**

- Cleanup SMS Reportback functionality modules. [\#3820](https://github.com/DoSomething/phoenix/pull/3820) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.193](https://github.com/dosomething/phoenix/tree/v0.3.193) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.192...v0.3.193)

**Merged pull requests:**

- DS Terms API: Inbox count [\#3818](https://github.com/DoSomething/phoenix/pull/3818) ([aaronschachter](https://github.com/aaronschachter))
- Updates to grab full reportback data, such as captions and limiting number of prior reportbacks to show [\#3817](https://github.com/DoSomething/phoenix/pull/3817) ([weerd](https://github.com/weerd))

## [v0.3.192](https://github.com/dosomething/phoenix/tree/v0.3.192) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.191...v0.3.192)

**Fixed bugs:**

- Canada forgot password: check if local user exists before creating it from remote [\#3815](https://github.com/DoSomething/phoenix/issues/3815)

**Merged pull requests:**

- Canada Forgot Password: Create only missing local accounts. [\#3816](https://github.com/DoSomething/phoenix/pull/3816) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.191](https://github.com/dosomething/phoenix/tree/v0.3.191) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.190...v0.3.191)

**Closed issues:**

- Canada forgot password for remote TIG accounts [\#3749](https://github.com/DoSomething/phoenix/issues/3749)

**Merged pull requests:**

- Happy new 2015! [\#3813](https://github.com/DoSomething/phoenix/pull/3813) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Implements ExternalAuthUserPassController on UK and Canada. [\#3812](https://github.com/DoSomething/phoenix/pull/3812) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.190](https://github.com/dosomething/phoenix/tree/v0.3.190) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.189...v0.3.190)

**Fixed bugs:**

- Prove It button placement should be independent of detail height [\#3806](https://github.com/DoSomething/phoenix/issues/3806)
- getting weird "blank" result in search - no image, title, or description [\#3510](https://github.com/DoSomething/phoenix/issues/3510)

**Closed issues:**

- Markup & logic for prior reportback submissions in Prove It form. [\#3808](https://github.com/DoSomething/phoenix/issues/3808)

**Merged pull requests:**

- Adjusts figure description height [\#3811](https://github.com/DoSomething/phoenix/pull/3811) ([deadlybutter](https://github.com/deadlybutter))
- Reportback fixes part 3a [\#3809](https://github.com/DoSomething/phoenix/pull/3809) ([weerd](https://github.com/weerd))

## [v0.3.189](https://github.com/dosomething/phoenix/tree/v0.3.189) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.188...v0.3.189)

**Merged pull requests:**

- Fixing scoping issue, adding semicolon after function declaration. [\#3810](https://github.com/DoSomething/phoenix/pull/3810) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.188](https://github.com/dosomething/phoenix/tree/v0.3.188) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.187...v0.3.188)

**Fixed bugs:**

- All iPhone pics that I uploaded triggered the "too small" error message [\#3803](https://github.com/DoSomething/phoenix/issues/3803)

**Merged pull requests:**

- waiting for image to load for mobile. fixes \#3803 [\#3807](https://github.com/DoSomething/phoenix/pull/3807) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.187](https://github.com/dosomething/phoenix/tree/v0.3.187) (2015-01-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.186...v0.3.187)

**Merged pull requests:**

- Removed caption logic to reportback js [\#3797](https://github.com/DoSomething/phoenix/pull/3797) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.186](https://github.com/dosomething/phoenix/tree/v0.3.186) (2015-01-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.185...v0.3.186)

**Merged pull requests:**

- Provides additional settings and debug messages to DS MBP installation. [\#3804](https://github.com/DoSomething/phoenix/pull/3804) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Harmonize local user creation from remote SSO. [\#3801](https://github.com/DoSomething/phoenix/pull/3801) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.185](https://github.com/dosomething/phoenix/tree/v0.3.185) (2015-01-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.184...v0.3.185)

**Merged pull requests:**

- Neue 6.0.0 beta3 [\#3798](https://github.com/DoSomething/phoenix/pull/3798) ([DFurnes](https://github.com/DFurnes))

## [v0.3.184](https://github.com/dosomething/phoenix/tree/v0.3.184) (2015-01-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.183...v0.3.184)

**Merged pull requests:**

- Fix typo in dosomething\_mbp uninstall function name. [\#3796](https://github.com/DoSomething/phoenix/pull/3796) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.183](https://github.com/dosomething/phoenix/tree/v0.3.183) (2015-01-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.182...v0.3.183)

**Fixed bugs:**

- close button off-center on modal [\#3770](https://github.com/DoSomething/phoenix/issues/3770)
- modal header not rendering properly on image manipulation modal [\#3762](https://github.com/DoSomething/phoenix/issues/3762)
- DS install broken: Drush terminated due to New Relic PHP Library missing [\#3718](https://github.com/DoSomething/phoenix/issues/3718)

**Closed issues:**

- Reportback Cropping: Do not let users crop an image too small [\#3590](https://github.com/DoSomething/phoenix/issues/3590)
- Transaction settings in dosomething\_mbp [\#3523](https://github.com/DoSomething/phoenix/issues/3523)

**Merged pull requests:**

- Enables dosomething message broker globally. [\#3794](https://github.com/DoSomething/phoenix/pull/3794) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Client side validation of image size [\#3791](https://github.com/DoSomething/phoenix/pull/3791) ([sbsmith86](https://github.com/sbsmith86))
- Issue3523 mbp international settings v2 [\#3763](https://github.com/DoSomething/phoenix/pull/3763) ([DeeZone](https://github.com/DeeZone))

## [v0.3.182](https://github.com/dosomething/phoenix/tree/v0.3.182) (2015-01-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.181...v0.3.182)

**Fixed bugs:**

- links in campaign footer should be white [\#3760](https://github.com/DoSomething/phoenix/issues/3760)

**Merged pull requests:**

- restrict cropbox to never be smaller than 480px [\#3789](https://github.com/DoSomething/phoenix/pull/3789) ([sbsmith86](https://github.com/sbsmith86))
- Reportback fixes part 2 [\#3788](https://github.com/DoSomething/phoenix/pull/3788) ([weerd](https://github.com/weerd))
- Reportback Image Rotation [\#3767](https://github.com/DoSomething/phoenix/pull/3767) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.181](https://github.com/dosomething/phoenix/tree/v0.3.181) (2015-01-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.180...v0.3.181)

**Fixed bugs:**

- 2 column layout on SMS Games Step 2 is off [\#3768](https://github.com/DoSomething/phoenix/issues/3768)
- scholarship winner and grant winner text should be capitalized in closed state [\#3765](https://github.com/DoSomething/phoenix/issues/3765)

**Closed issues:**

- Display Flagged reason in Reportback File teaser [\#3784](https://github.com/DoSomething/phoenix/issues/3784)

**Merged pull requests:**

- Display flagged\_reason in Reportback view [\#3787](https://github.com/DoSomething/phoenix/pull/3787) ([aaronschachter](https://github.com/aaronschachter))
- File upload support for IE8/9 [\#3785](https://github.com/DoSomething/phoenix/pull/3785) ([aaronschachter](https://github.com/aaronschachter))
- Capitalize scholarship/grant winner text server-side. [\#3782](https://github.com/DoSomething/phoenix/pull/3782) ([DFurnes](https://github.com/DFurnes))
- Update SMS form for Neue 6.0. [\#3781](https://github.com/DoSomething/phoenix/pull/3781) ([DFurnes](https://github.com/DFurnes))
- Update to spacing for extended gallery. [\#3780](https://github.com/DoSomething/phoenix/pull/3780) ([weerd](https://github.com/weerd))

## [v0.3.180](https://github.com/dosomething/phoenix/tree/v0.3.180) (2015-01-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.179...v0.3.180)

**Fixed bugs:**

- persistent nav missing on mobile [\#3769](https://github.com/DoSomething/phoenix/issues/3769)
- duo gallery should be 150 x 150 [\#3758](https://github.com/DoSomething/phoenix/issues/3758)
- Scholarship text doesn't need to show up on desktop widths [\#3727](https://github.com/DoSomething/phoenix/issues/3727)

**Closed issues:**

- Remove unused image styles in CMS. [\#3775](https://github.com/DoSomething/phoenix/issues/3775)
- Facts page should use compacted list [\#3772](https://github.com/DoSomething/phoenix/issues/3772)

**Merged pull requests:**

- Add a class to target banner on action pages. [\#3779](https://github.com/DoSomething/phoenix/pull/3779) ([DFurnes](https://github.com/DFurnes))
- Image sizes [\#3778](https://github.com/DoSomething/phoenix/pull/3778) ([DFurnes](https://github.com/DFurnes))
- Update to restore the page nav after it was removed for testing on IE. [\#3777](https://github.com/DoSomething/phoenix/pull/3777) ([weerd](https://github.com/weerd))
- IE8 fix for reportback gallery extended gallery layout on desktop. [\#3776](https://github.com/DoSomething/phoenix/pull/3776) ([weerd](https://github.com/weerd))
- Use compacted lists on fact index page. [\#3773](https://github.com/DoSomething/phoenix/pull/3773) ([DFurnes](https://github.com/DFurnes))
- Fix display issue with secondary navigation on mobile. [\#3761](https://github.com/DoSomething/phoenix/pull/3761) ([DFurnes](https://github.com/DFurnes))
- Add proper success/error logging to Sass task. [\#3757](https://github.com/DoSomething/phoenix/pull/3757) ([DFurnes](https://github.com/DFurnes))
- \#3647: Slight mod to previous script for legacy redirects [\#3753](https://github.com/DoSomething/phoenix/pull/3753) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.3.179](https://github.com/dosomething/phoenix/tree/v0.3.179) (2015-01-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.178...v0.3.179)

**Merged pull requests:**

- Fixes issue with social icons on mobile dropping below subfooter. [\#3756](https://github.com/DoSomething/phoenix/pull/3756) ([DFurnes](https://github.com/DFurnes))
- Update heading in Zendesk modal for Neue 6.0. [\#3755](https://github.com/DoSomething/phoenix/pull/3755) ([DFurnes](https://github.com/DFurnes))
- Reportback cleanup [\#3754](https://github.com/DoSomething/phoenix/pull/3754) ([weerd](https://github.com/weerd))
- Updated affiliate footer markup for Neue 6.0. [\#3752](https://github.com/DoSomething/phoenix/pull/3752) ([DFurnes](https://github.com/DFurnes))
- Grunt cleanup [\#3751](https://github.com/DoSomething/phoenix/pull/3751) ([DFurnes](https://github.com/DFurnes))
- Clean up sources on taxonomy page. [\#3748](https://github.com/DoSomething/phoenix/pull/3748) ([DFurnes](https://github.com/DFurnes))
- A few fixes to layout on 404 and search pages. [\#3747](https://github.com/DoSomething/phoenix/pull/3747) ([DFurnes](https://github.com/DFurnes))
- Confirmation pages [\#3746](https://github.com/DoSomething/phoenix/pull/3746) ([DFurnes](https://github.com/DFurnes))

## [v0.3.178](https://github.com/dosomething/phoenix/tree/v0.3.178) (2015-01-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.177...v0.3.178)

**Fixed bugs:**

- Staff Gallery layout breaks for some rows [\#3731](https://github.com/DoSomething/phoenix/issues/3731)
- Misaligned campaigns and campaign labels in /campaigns. [\#3728](https://github.com/DoSomething/phoenix/issues/3728)
- Taxonomy term page css is broken [\#3726](https://github.com/DoSomething/phoenix/issues/3726)

**Closed issues:**

- JSHint errors in paraneue-dosomething theme [\#3610](https://github.com/DoSomething/phoenix/issues/3610)

**Merged pull requests:**

- No source mappy [\#3745](https://github.com/DoSomething/phoenix/pull/3745) ([DFurnes](https://github.com/DFurnes))
- Clean up 'explore campaigns' view a bit. [\#3744](https://github.com/DoSomething/phoenix/pull/3744) ([DFurnes](https://github.com/DFurnes))
- Update campaign group template for Neue 6.0. [\#3743](https://github.com/DoSomething/phoenix/pull/3743) ([DFurnes](https://github.com/DFurnes))
- Neue 6.0 beta2 [\#3742](https://github.com/DoSomething/phoenix/pull/3742) ([DFurnes](https://github.com/DFurnes))
- Fixes alignment of polaroid on action page. [\#3741](https://github.com/DoSomething/phoenix/pull/3741) ([DFurnes](https://github.com/DFurnes))
- Updates pitch page tagline for Neue 6.0. [\#3740](https://github.com/DoSomething/phoenix/pull/3740) ([DFurnes](https://github.com/DFurnes))
- Fix display issues on 404 page. [\#3739](https://github.com/DoSomething/phoenix/pull/3739) ([DFurnes](https://github.com/DFurnes))
- Fix display issue with staff pick flag in Finder. [\#3738](https://github.com/DoSomething/phoenix/pull/3738) ([DFurnes](https://github.com/DFurnes))
- Fix linting errors. [\#3612](https://github.com/DoSomething/phoenix/pull/3612) ([DFurnes](https://github.com/DFurnes))

## [v0.3.177](https://github.com/dosomething/phoenix/tree/v0.3.177) (2015-01-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.176...v0.3.177)

**Fixed bugs:**

- User Profile - "You Did" gallery css is broken [\#3730](https://github.com/DoSomething/phoenix/issues/3730)
- Local menu tab is missing [\#3723](https://github.com/DoSomething/phoenix/issues/3723)

**Closed issues:**

- User Profile "Prove it" button alignment [\#3662](https://github.com/DoSomething/phoenix/issues/3662)
- User Profile: admin view [\#3563](https://github.com/DoSomething/phoenix/issues/3563)

**Merged pull requests:**

- Fix page template so admin bar is rendered. [\#3737](https://github.com/DoSomething/phoenix/pull/3737) ([DFurnes](https://github.com/DFurnes))
- Use latest Neue 6.0 beta, and restores mosaic gallery views. [\#3736](https://github.com/DoSomething/phoenix/pull/3736) ([DFurnes](https://github.com/DFurnes))
- Making title 1em [\#3734](https://github.com/DoSomething/phoenix/pull/3734) ([deadlybutter](https://github.com/deadlybutter))
- Aligns prove it buttons on User profile [\#3733](https://github.com/DoSomething/phoenix/pull/3733) ([deadlybutter](https://github.com/deadlybutter))
- Media fixes [\#3732](https://github.com/DoSomething/phoenix/pull/3732) ([DFurnes](https://github.com/DFurnes))

## [v0.3.176](https://github.com/dosomething/phoenix/tree/v0.3.176) (2015-01-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.175...v0.3.176)

**Merged pull requests:**

- Finder neue 6.0 [\#3725](https://github.com/DoSomething/phoenix/pull/3725) ([DFurnes](https://github.com/DFurnes))
- Update taxonomy term markup for Neue 6.0. [\#3724](https://github.com/DoSomething/phoenix/pull/3724) ([DFurnes](https://github.com/DFurnes))

## [v0.3.175](https://github.com/dosomething/phoenix/tree/v0.3.175) (2015-01-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.174...v0.3.175)

**Closed issues:**

- Migrate Signups and Reportbacks to Campaign Run nid [\#3707](https://github.com/DoSomething/phoenix/issues/3707)
- Reportback Modal: Doesn't work on IE8 [\#3676](https://github.com/DoSomething/phoenix/issues/3676)
- Paraneue Gallery: "Show more" functionality [\#3372](https://github.com/DoSomething/phoenix/issues/3372)

**Merged pull requests:**

- Libsassy [\#3722](https://github.com/DoSomething/phoenix/pull/3722) ([DFurnes](https://github.com/DFurnes))
- Archive Activity form [\#3721](https://github.com/DoSomething/phoenix/pull/3721) ([aaronschachter](https://github.com/aaronschachter))
- Neue 6.x [\#3708](https://github.com/DoSomething/phoenix/pull/3708) ([DFurnes](https://github.com/DFurnes))
- Adds show more functionality to gallery [\#3691](https://github.com/DoSomething/phoenix/pull/3691) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.174](https://github.com/dosomething/phoenix/tree/v0.3.174) (2015-01-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.173...v0.3.174)

**Closed issues:**

- Refactor Flagged Reportbacks [\#3652](https://github.com/DoSomething/phoenix/issues/3652)
- Refactor Promoted Reportback files [\#3562](https://github.com/DoSomething/phoenix/issues/3562)

**Merged pull requests:**

- Flagged Reason migrate fix [\#3717](https://github.com/DoSomething/phoenix/pull/3717) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.173](https://github.com/dosomething/phoenix/tree/v0.3.173) (2015-01-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.172...v0.3.173)

**Fixed bugs:**

- Reportback Form: Special characters weirdness [\#3704](https://github.com/DoSomething/phoenix/issues/3704)
- Terms API - numeric id's [\#3700](https://github.com/DoSomething/phoenix/issues/3700)

**Closed issues:**

- Return quantity label in Reportback Files API [\#3703](https://github.com/DoSomething/phoenix/issues/3703)
- Prove it gallery total count [\#3663](https://github.com/DoSomething/phoenix/issues/3663)
- Display promoted and approved Reportbacks in Campaign template [\#3633](https://github.com/DoSomething/phoenix/issues/3633)
- Prove It theming [\#3288](https://github.com/DoSomething/phoenix/issues/3288)

**Merged pull requests:**

- Don't encode Reportback / RB File user input on entity load [\#3716](https://github.com/DoSomething/phoenix/pull/3716) ([aaronschachter](https://github.com/aaronschachter))
- Adds quantity\_label to Reportback review API [\#3715](https://github.com/DoSomething/phoenix/pull/3715) ([aaronschachter](https://github.com/aaronschachter))
- API - Numeric Term id's [\#3714](https://github.com/DoSomething/phoenix/pull/3714) ([aaronschachter](https://github.com/aaronschachter))
- Reportback script [\#3698](https://github.com/DoSomething/phoenix/pull/3698) ([weerd](https://github.com/weerd))
- Uses flagged property to filter out flagged reportbacks [\#3692](https://github.com/DoSomething/phoenix/pull/3692) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.172](https://github.com/dosomething/phoenix/tree/v0.3.172) (2015-01-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.171...v0.3.172)

**Merged pull requests:**

- Deletes Promoted flag for real [\#3713](https://github.com/DoSomething/phoenix/pull/3713) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.171](https://github.com/dosomething/phoenix/tree/v0.3.171) (2015-01-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.170...v0.3.171)

**Closed issues:**

- anonymous users shouldn't have access to reviewed/unreviewed Reportbacks view [\#3710](https://github.com/DoSomething/phoenix/issues/3710)

**Merged pull requests:**

- RB View permissions fix [\#3711](https://github.com/DoSomething/phoenix/pull/3711) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.170](https://github.com/dosomething/phoenix/tree/v0.3.170) (2015-01-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.169...v0.3.170)

**Fixed bugs:**

- Reportback Flagging is deleting images no matter what [\#3705](https://github.com/DoSomething/phoenix/issues/3705)

**Merged pull requests:**

- Fixes Flagged bug [\#3709](https://github.com/DoSomething/phoenix/pull/3709) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.169](https://github.com/dosomething/phoenix/tree/v0.3.169) (2015-01-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.168...v0.3.169)

**Fixed bugs:**

- API Gallery: PHP Notice [\#3697](https://github.com/DoSomething/phoenix/issues/3697)

**Closed issues:**

- Autoflagging subsequent images [\#3654](https://github.com/DoSomething/phoenix/issues/3654)

**Merged pull requests:**

- Automatically flag Images for flagged Reportbacks [\#3706](https://github.com/DoSomething/phoenix/pull/3706) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.168](https://github.com/dosomething/phoenix/tree/v0.3.168) (2015-01-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.167...v0.3.168)

**Closed issues:**

- Variable to store Placeholder Image fid's [\#3694](https://github.com/DoSomething/phoenix/issues/3694)
- SMS Reportback Caption [\#3484](https://github.com/DoSomething/phoenix/issues/3484)

**Merged pull requests:**

- Gallery File fid's variable [\#3701](https://github.com/DoSomething/phoenix/pull/3701) ([aaronschachter](https://github.com/aaronschachter))
- Enables application/x-www-form-urlencoded request parsing [\#3696](https://github.com/DoSomething/phoenix/pull/3696) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.167](https://github.com/dosomething/phoenix/tree/v0.3.167) (2015-01-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.166...v0.3.167)

**Closed issues:**

- Reportback modal styles [\#3667](https://github.com/DoSomething/phoenix/issues/3667)

**Merged pull requests:**

- Deletes promoted flag [\#3695](https://github.com/DoSomething/phoenix/pull/3695) ([aaronschachter](https://github.com/aaronschachter))
- Terms API endpoint [\#3693](https://github.com/DoSomething/phoenix/pull/3693) ([aaronschachter](https://github.com/aaronschachter))
- Update flagged Reportbacks [\#3690](https://github.com/DoSomething/phoenix/pull/3690) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.166](https://github.com/dosomething/phoenix/tree/v0.3.166) (2015-01-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.165...v0.3.166)

**Merged pull requests:**

- Canada SSO profile sync. [\#3658](https://github.com/DoSomething/phoenix/pull/3658) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.165](https://github.com/dosomething/phoenix/tree/v0.3.165) (2015-01-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.164...v0.3.165)

**Merged pull requests:**

- Reportback cropping fixes [\#3685](https://github.com/DoSomething/phoenix/pull/3685) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.164](https://github.com/dosomething/phoenix/tree/v0.3.164) (2015-01-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.163...v0.3.164)

**Fixed bugs:**

- PHP Warnings in Closed Campaign [\#3686](https://github.com/DoSomething/phoenix/issues/3686)

**Closed issues:**

- Make campaign run notification message editable [\#3682](https://github.com/DoSomething/phoenix/issues/3682)

**Merged pull requests:**

- Copy change, fixes \#3682 [\#3688](https://github.com/DoSomething/phoenix/pull/3688) ([aaronschachter](https://github.com/aaronschachter))
- Closed Gallery fix [\#3687](https://github.com/DoSomething/phoenix/pull/3687) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.163](https://github.com/dosomething/phoenix/tree/v0.3.163) (2015-01-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.162...v0.3.163)

**Fixed bugs:**

- Conditional info in Reportback Files index [\#3675](https://github.com/DoSomething/phoenix/issues/3675)

**Merged pull requests:**

- Gallery api [\#3684](https://github.com/DoSomething/phoenix/pull/3684) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.162](https://github.com/dosomething/phoenix/tree/v0.3.162) (2015-01-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.161...v0.3.162)

**Merged pull requests:**

- Install Security Kit. [\#3683](https://github.com/DoSomething/phoenix/pull/3683) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.161](https://github.com/dosomething/phoenix/tree/v0.3.161) (2015-01-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.160...v0.3.161)

**Fixed bugs:**

- Fixes User Enumeration vulnerability on Forgot Password. [\#3681](https://github.com/DoSomething/phoenix/pull/3681) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.160](https://github.com/dosomething/phoenix/tree/v0.3.160) (2015-01-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.159...v0.3.160)

**Merged pull requests:**

- Closed Reportback Gallery [\#3680](https://github.com/DoSomething/phoenix/pull/3680) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.159](https://github.com/dosomething/phoenix/tree/v0.3.159) (2015-01-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.158...v0.3.159)

**Fixed bugs:**

- Broken Reportback Reviewed form [\#3674](https://github.com/DoSomething/phoenix/issues/3674)
- New reportback admin view: Performance issues [\#3589](https://github.com/DoSomething/phoenix/issues/3589)
- Field Collection revision bug [\#2872](https://github.com/DoSomething/phoenix/issues/2872)
- Fixes XSS vulnerabilities on User Profile. [\#3678](https://github.com/DoSomething/phoenix/pull/3678) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

**Closed issues:**

- A minimum image size should be enforced when cropping [\#3631](https://github.com/DoSomething/phoenix/issues/3631)
- DS API: Reportback Files PUT endpoint [\#3598](https://github.com/DoSomething/phoenix/issues/3598)
- Rollback International Affilates Databases [\#3546](https://github.com/DoSomething/phoenix/issues/3546)

**Merged pull requests:**

- Reportback modal cropping [\#3673](https://github.com/DoSomething/phoenix/pull/3673) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.158](https://github.com/dosomething/phoenix/tree/v0.3.158) (2014-12-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.157...v0.3.158)

**Merged pull requests:**

- \#1635: Installs New Relic module [\#3672](https://github.com/DoSomething/phoenix/pull/3672) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.3.157](https://github.com/dosomething/phoenix/tree/v0.3.157) (2014-12-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.156...v0.3.157)

**Merged pull requests:**

- Reportback File tweaks [\#3671](https://github.com/DoSomething/phoenix/pull/3671) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.156](https://github.com/dosomething/phoenix/tree/v0.3.156) (2014-12-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.155...v0.3.156)

**Merged pull requests:**

- Switching class placed on upload field based on theme setting [\#3670](https://github.com/DoSomething/phoenix/pull/3670) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.155](https://github.com/dosomething/phoenix/tree/v0.3.155) (2014-12-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.154...v0.3.155)

**Merged pull requests:**

- Fixes bug in Reportback Files review endpoint [\#3669](https://github.com/DoSomething/phoenix/pull/3669) ([aaronschachter](https://github.com/aaronschachter))
- Reportback modal [\#3661](https://github.com/DoSomething/phoenix/pull/3661) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.154](https://github.com/dosomething/phoenix/tree/v0.3.154) (2014-12-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.153...v0.3.154)

**Closed issues:**

- Reportback View - additional link to raw file [\#3666](https://github.com/DoSomething/phoenix/issues/3666)
- display total count on reportbacks inbox [\#3655](https://github.com/DoSomething/phoenix/issues/3655)

**Merged pull requests:**

- Reportback File - link to original upload [\#3668](https://github.com/DoSomething/phoenix/pull/3668) ([aaronschachter](https://github.com/aaronschachter))
- Display Reportback Inbox total [\#3665](https://github.com/DoSomething/phoenix/pull/3665) ([aaronschachter](https://github.com/aaronschachter))
- User Profile - Reportback permalinks [\#3660](https://github.com/DoSomething/phoenix/pull/3660) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.153](https://github.com/dosomething/phoenix/tree/v0.3.153) (2014-12-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.152...v0.3.153)

**Closed issues:**

- Reportback admin view: Status form [\#3566](https://github.com/DoSomething/phoenix/issues/3566)

**Merged pull requests:**

- Edit Reportback Review [\#3659](https://github.com/DoSomething/phoenix/pull/3659) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.152](https://github.com/dosomething/phoenix/tree/v0.3.152) (2014-12-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.151...v0.3.152)

**Closed issues:**

- Reportback Flag form [\#3564](https://github.com/DoSomething/phoenix/issues/3564)
- User Profile: I'm Doing buttons [\#3376](https://github.com/DoSomething/phoenix/issues/3376)

**Merged pull requests:**

- Fixes UK SSO registration. [\#3657](https://github.com/DoSomething/phoenix/pull/3657) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Reportback File teaser view mode [\#3656](https://github.com/DoSomething/phoenix/pull/3656) ([aaronschachter](https://github.com/aaronschachter))
- Adds prove it buttons to the figure template [\#3649](https://github.com/DoSomething/phoenix/pull/3649) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.151](https://github.com/dosomething/phoenix/tree/v0.3.151) (2014-12-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.150...v0.3.151)

**Closed issues:**

- Delete Reportback Files on entity delete [\#3646](https://github.com/DoSomething/phoenix/issues/3646)
- warning on reportback deletion [\#3644](https://github.com/DoSomething/phoenix/issues/3644)

**Merged pull requests:**

- Delete Reportback Images [\#3653](https://github.com/DoSomething/phoenix/pull/3653) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.150](https://github.com/dosomething/phoenix/tree/v0.3.150) (2014-12-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.149...v0.3.150)

**Closed issues:**

- Reportback View - reviewed tab [\#3611](https://github.com/DoSomething/phoenix/issues/3611)

**Merged pull requests:**

- Flagged and flagged\_reason columns [\#3651](https://github.com/DoSomething/phoenix/pull/3651) ([aaronschachter](https://github.com/aaronschachter))
- Change RB Reviewed filter [\#3648](https://github.com/DoSomething/phoenix/pull/3648) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.149](https://github.com/dosomething/phoenix/tree/v0.3.149) (2014-12-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.148...v0.3.149)

**Merged pull requests:**

- Reviewed Reportbacks view [\#3645](https://github.com/DoSomething/phoenix/pull/3645) ([aaronschachter](https://github.com/aaronschachter))
- Removed second video poster print [\#3643](https://github.com/DoSomething/phoenix/pull/3643) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.148](https://github.com/dosomething/phoenix/tree/v0.3.148) (2014-12-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.147...v0.3.148)

**Fixed bugs:**

- can't submit "not affiliated with school" on mobile [\#3617](https://github.com/DoSomething/phoenix/issues/3617)

**Closed issues:**

- Dummy reportback generator [\#3634](https://github.com/DoSomething/phoenix/issues/3634)

**Merged pull requests:**

- Generate Reportback form [\#3641](https://github.com/DoSomething/phoenix/pull/3641) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#3617. [\#3639](https://github.com/DoSomething/phoenix/pull/3639) ([DFurnes](https://github.com/DFurnes))
- Reportback script [\#3638](https://github.com/DoSomething/phoenix/pull/3638) ([weerd](https://github.com/weerd))
- Setting up initial JS for Reportbacks [\#3637](https://github.com/DoSomething/phoenix/pull/3637) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.147](https://github.com/dosomething/phoenix/tree/v0.3.147) (2014-12-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.146...v0.3.147)

**Fixed bugs:**

- PHP Notice in Notfound tpl [\#3559](https://github.com/DoSomething/phoenix/issues/3559)

**Closed issues:**

- Geolocation for Patients Playbook \(for Dec 12th\) [\#3579](https://github.com/DoSomething/phoenix/issues/3579)
- Send transactional contents by template area [\#3431](https://github.com/DoSomething/phoenix/issues/3431)

**Merged pull requests:**

- Dynamic Reportback File gallery [\#3635](https://github.com/DoSomething/phoenix/pull/3635) ([aaronschachter](https://github.com/aaronschachter))
- Introduce common interface for DosomethingUserRemote creation. [\#3628](https://github.com/DoSomething/phoenix/pull/3628) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Added check to 404 video poster [\#3625](https://github.com/DoSomething/phoenix/pull/3625) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.146](https://github.com/dosomething/phoenix/tree/v0.3.146) (2014-12-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.145...v0.3.146)

**Closed issues:**

- 404 Search results repeating words [\#3594](https://github.com/DoSomething/phoenix/issues/3594)

**Merged pull requests:**

- Upgrade Google Analytics contrib module [\#3626](https://github.com/DoSomething/phoenix/pull/3626) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#3594 [\#3624](https://github.com/DoSomething/phoenix/pull/3624) ([deadlybutter](https://github.com/deadlybutter))
- Reportback initial markup [\#3621](https://github.com/DoSomething/phoenix/pull/3621) ([weerd](https://github.com/weerd))

## [v0.3.145](https://github.com/dosomething/phoenix/tree/v0.3.145) (2014-12-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.144...v0.3.145)

**Fixed bugs:**

- BUG: Styling on 404 headers broken on node pages. [\#3536](https://github.com/DoSomething/phoenix/issues/3536)

**Closed issues:**

- DS API: Retrieve User uid by mobile [\#3603](https://github.com/DoSomething/phoenix/issues/3603)
- Reportback Files: Add uid\_reviewer and reviewed timestamp [\#3597](https://github.com/DoSomething/phoenix/issues/3597)

**Merged pull requests:**

- Reportback File Reviewer [\#3623](https://github.com/DoSomething/phoenix/pull/3623) ([aaronschachter](https://github.com/aaronschachter))
- Reportback cropping updates [\#3622](https://github.com/DoSomething/phoenix/pull/3622) ([sbsmith86](https://github.com/sbsmith86))
- Rescoping header CSS on not found pages [\#3587](https://github.com/DoSomething/phoenix/pull/3587) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.144](https://github.com/dosomething/phoenix/tree/v0.3.144) (2014-12-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.143...v0.3.144)

**Merged pull requests:**

- Member index [\#3620](https://github.com/DoSomething/phoenix/pull/3620) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.143](https://github.com/dosomething/phoenix/tree/v0.3.143) (2014-12-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.142...v0.3.143)

**Closed issues:**

- DS API: Add mobile field value in Users create endpoint  [\#3613](https://github.com/DoSomething/phoenix/issues/3613)

**Merged pull requests:**

- Set User field\_mobile value in DS API [\#3616](https://github.com/DoSomething/phoenix/pull/3616) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.142](https://github.com/dosomething/phoenix/tree/v0.3.142) (2014-12-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.141...v0.3.142)

**Closed issues:**

- Admin interface to set message template values [\#3464](https://github.com/DoSomething/phoenix/issues/3464)

**Merged pull requests:**

- Reportback Flag form - front end [\#3614](https://github.com/DoSomething/phoenix/pull/3614) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.141](https://github.com/dosomething/phoenix/tree/v0.3.141) (2014-12-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.140...v0.3.141)

**Fixed bugs:**

- taxonomy collections show blank in partnership with for logged in users [\#3607](https://github.com/DoSomething/phoenix/issues/3607)

**Merged pull requests:**

- Partners footer bug fix [\#3609](https://github.com/DoSomething/phoenix/pull/3609) ([aaronschachter](https://github.com/aaronschachter))
- ReportbackFile Entity [\#3608](https://github.com/DoSomething/phoenix/pull/3608) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.140](https://github.com/dosomething/phoenix/tree/v0.3.140) (2014-12-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.139...v0.3.140)

**Closed issues:**

- Rerun US users cleanup script [\#3552](https://github.com/DoSomething/phoenix/issues/3552)
- Import existing Legacy redirects into Beta [\#3409](https://github.com/DoSomething/phoenix/issues/3409)
- Approved Reportback File flag + Bulk Approval [\#3389](https://github.com/DoSomething/phoenix/issues/3389)
- Reportback Gallery View [\#3285](https://github.com/DoSomething/phoenix/issues/3285)

**Merged pull requests:**

- Reportback Review page filters [\#3604](https://github.com/DoSomething/phoenix/pull/3604) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#3409: Redirect import script [\#3602](https://github.com/DoSomething/phoenix/pull/3602) ([mshmsh5000](https://github.com/mshmsh5000))
- Updates 3404 script to use beta aliases as 301 targets [\#3601](https://github.com/DoSomething/phoenix/pull/3601) ([mshmsh5000](https://github.com/mshmsh5000))
- Removes cancel-us-users drush job. [\#3600](https://github.com/DoSomething/phoenix/pull/3600) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Introduces DosomethingCanadaSsoUser class. [\#3596](https://github.com/DoSomething/phoenix/pull/3596) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.139](https://github.com/dosomething/phoenix/tree/v0.3.139) (2014-12-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.138...v0.3.139)

**Fixed bugs:**

- search results display for campaign groups [\#3584](https://github.com/DoSomething/phoenix/issues/3584)

**Closed issues:**

- Expand Canada Redirect for Teens for Jeans from Domain to US Campaign Page [\#3557](https://github.com/DoSomething/phoenix/issues/3557)
- add paragraph spacing below bulleted list [\#3542](https://github.com/DoSomething/phoenix/issues/3542)
- Reportback Form cropping [\#3286](https://github.com/DoSomething/phoenix/issues/3286)
- featured campaign on collections is super pixelated [\#3267](https://github.com/DoSomething/phoenix/issues/3267)

**Merged pull requests:**

- Canada: Provides integration test for the phone field. [\#3593](https://github.com/DoSomething/phoenix/pull/3593) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Wrapping up image swapping script for high res feature tile images. [\#3592](https://github.com/DoSomething/phoenix/pull/3592) ([weerd](https://github.com/weerd))
- Get variables for campaign groups in search [\#3588](https://github.com/DoSomething/phoenix/pull/3588) ([sbsmith86](https://github.com/sbsmith86))
- Introduces common DosomethingUserRemote abstract class. [\#3582](https://github.com/DoSomething/phoenix/pull/3582) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.138](https://github.com/dosomething/phoenix/tree/v0.3.138) (2014-12-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.137...v0.3.138)

**Closed issues:**

- Images on the recommended campaigns block on 404 page and no search results aren't clickable [\#3580](https://github.com/DoSomething/phoenix/issues/3580)

**Merged pull requests:**

- Link images to content in recommended campaign galleries. [\#3586](https://github.com/DoSomething/phoenix/pull/3586) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.137](https://github.com/dosomething/phoenix/tree/v0.3.137) (2014-12-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.136...v0.3.137)

**Closed issues:**

- don't display campaigns on taxonomy collections if status=closed [\#3583](https://github.com/DoSomething/phoenix/issues/3583)

**Merged pull requests:**

- Taxonomy Term campaigns view sort [\#3585](https://github.com/DoSomething/phoenix/pull/3585) ([aaronschachter](https://github.com/aaronschachter))
- UK: Provides integration test for the phone field. [\#3581](https://github.com/DoSomething/phoenix/pull/3581) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Renames CanadaSSOClient.php to dosomething\_canada\_sso\_client.inc. [\#3578](https://github.com/DoSomething/phoenix/pull/3578) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.136](https://github.com/dosomething/phoenix/tree/v0.3.136) (2014-12-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.135...v0.3.136)

**Fixed bugs:**

- Bug in Profile Doing links [\#3574](https://github.com/DoSomething/phoenix/issues/3574)
- Reportback API: Uid restrictions [\#3572](https://github.com/DoSomething/phoenix/issues/3572)
- Scrolling disabled when cropping is turned on  [\#3571](https://github.com/DoSomething/phoenix/issues/3571)

**Closed issues:**

- Ability to specify Signup uid in API endpoint [\#3530](https://github.com/DoSomething/phoenix/issues/3530)

**Merged pull requests:**

- Signup API endpoint [\#3577](https://github.com/DoSomething/phoenix/pull/3577) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#3574 [\#3576](https://github.com/DoSomething/phoenix/pull/3576) ([aaronschachter](https://github.com/aaronschachter))
- Check Reportback uid and permissions upon save [\#3575](https://github.com/DoSomething/phoenix/pull/3575) ([aaronschachter](https://github.com/aaronschachter))
- Binding touch events to image not document [\#3573](https://github.com/DoSomething/phoenix/pull/3573) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.135](https://github.com/dosomething/phoenix/tree/v0.3.135) (2014-12-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.134...v0.3.135)

**Closed issues:**

- Remove deprecated dosomething\_reportback\_set\_field\_values functions [\#3567](https://github.com/DoSomething/phoenix/issues/3567)
- Enable Reportback API endpoint [\#3528](https://github.com/DoSomething/phoenix/issues/3528)

**Merged pull requests:**

- Enables Reportback endpoint [\#3570](https://github.com/DoSomething/phoenix/pull/3570) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.134](https://github.com/dosomething/phoenix/tree/v0.3.134) (2014-12-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.133...v0.3.134)

**Closed issues:**

- Cropping when updating a submission is broken [\#3554](https://github.com/DoSomething/phoenix/issues/3554)

**Merged pull requests:**

- Reportback form cropping [\#3561](https://github.com/DoSomething/phoenix/pull/3561) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.133](https://github.com/dosomething/phoenix/tree/v0.3.133) (2014-12-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.132...v0.3.133)

**Fixed bugs:**

- User Profile Reportback Gallery bug: missing Titles [\#3550](https://github.com/DoSomething/phoenix/issues/3550)

**Closed issues:**

- Change DS Canada log in modal header [\#3545](https://github.com/DoSomething/phoenix/issues/3545)
- Site Administrator role [\#3472](https://github.com/DoSomething/phoenix/issues/3472)

**Merged pull requests:**

- Fixes \#3550 [\#3560](https://github.com/DoSomething/phoenix/pull/3560) ([aaronschachter](https://github.com/aaronschachter))
- Reportback File status [\#3558](https://github.com/DoSomething/phoenix/pull/3558) ([aaronschachter](https://github.com/aaronschachter))
- Site admin role to administer redirects, homepage [\#3556](https://github.com/DoSomething/phoenix/pull/3556) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.132](https://github.com/dosomething/phoenix/tree/v0.3.132) (2014-11-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.131...v0.3.132)

**Merged pull requests:**

- Canada: allow response code 302. [\#3555](https://github.com/DoSomething/phoenix/pull/3555) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes \#3404: Parses CSV of redirects and creates Drupal redirects [\#3538](https://github.com/DoSomething/phoenix/pull/3538) ([mshmsh5000](https://github.com/mshmsh5000))
- Fixes \#3414: Script to populate Legacy/Beta alias/canonical path matrix [\#3537](https://github.com/DoSomething/phoenix/pull/3537) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.3.131](https://github.com/dosomething/phoenix/tree/v0.3.131) (2014-11-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.130...v0.3.131)

**Closed issues:**

- markdown needed for field\_transactional\_email\_copy on campaign collections [\#3549](https://github.com/DoSomething/phoenix/issues/3549)
- need to remove redirects from beta to legacy [\#3509](https://github.com/DoSomething/phoenix/issues/3509)
- no search results found on site search should match copy and design of 404 no search results found [\#3497](https://github.com/DoSomething/phoenix/issues/3497)
- load test 404 page w/ search [\#3461](https://github.com/DoSomething/phoenix/issues/3461)

**Merged pull requests:**

- Stringoverrides [\#3553](https://github.com/DoSomething/phoenix/pull/3553) ([aaronschachter](https://github.com/aaronschachter))
- Adds Markdown support to Transactional Email copy for Campaign Group [\#3551](https://github.com/DoSomething/phoenix/pull/3551) ([aaronschachter](https://github.com/aaronschachter))
- Restores and fixes `cancel-us-users` drush task [\#3548](https://github.com/DoSomething/phoenix/pull/3548) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Theming the search page when no results found. [\#3544](https://github.com/DoSomething/phoenix/pull/3544) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.130](https://github.com/dosomething/phoenix/tree/v0.3.130) (2014-11-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.129...v0.3.130)

**Closed issues:**

- Stop users cleanup cron and cleanup the code [\#3524](https://github.com/DoSomething/phoenix/issues/3524)
- Canada: Handle user validation errors  [\#3480](https://github.com/DoSomething/phoenix/issues/3480)
- need script that retrieves url aliases from machine paths and vice versa [\#3414](https://github.com/DoSomething/phoenix/issues/3414)

**Merged pull requests:**

- Canada: process custom HTTP response errors. [\#3543](https://github.com/DoSomething/phoenix/pull/3543) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Removes `cancel-us-users` drush task. [\#3539](https://github.com/DoSomething/phoenix/pull/3539) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Canada refactor sso client [\#3534](https://github.com/DoSomething/phoenix/pull/3534) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.129](https://github.com/dosomething/phoenix/tree/v0.3.129) (2014-11-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.128...v0.3.129)

**Fixed bugs:**

- some campaigns are showing up multiple times in search [\#3468](https://github.com/DoSomething/phoenix/issues/3468)

**Merged pull requests:**

- Kill video poster [\#3535](https://github.com/DoSomething/phoenix/pull/3535) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.128](https://github.com/dosomething/phoenix/tree/v0.3.128) (2014-11-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.127...v0.3.128)

**Fixed bugs:**

- Donate Page CVV bug [\#3526](https://github.com/DoSomething/phoenix/issues/3526)
- Reportback Gallery view does not update [\#3519](https://github.com/DoSomething/phoenix/issues/3519)

**Closed issues:**

- need the ability to add reportbacks without associating them to a real user/First Name [\#3514](https://github.com/DoSomething/phoenix/issues/3514)
- 404 page video needs a poster image [\#3424](https://github.com/DoSomething/phoenix/issues/3424)

**Merged pull requests:**

- Video poster [\#3533](https://github.com/DoSomething/phoenix/pull/3533) ([deadlybutter](https://github.com/deadlybutter))
- fixed regex to allow four digits [\#3532](https://github.com/DoSomething/phoenix/pull/3532) ([tjrosario](https://github.com/tjrosario))
- Dup search results bug [\#3531](https://github.com/DoSomething/phoenix/pull/3531) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.127](https://github.com/dosomething/phoenix/tree/v0.3.127) (2014-11-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.126...v0.3.127)

**Fixed bugs:**

- Campaign transactional email missing additional tags [\#3507](https://github.com/DoSomething/phoenix/issues/3507)

**Closed issues:**

- update display of campaigns on taxonomy collections [\#3265](https://github.com/DoSomething/phoenix/issues/3265)

**Merged pull requests:**

- Allow admins to create dummy reportbacks for Close Gallery [\#3525](https://github.com/DoSomething/phoenix/pull/3525) ([aaronschachter](https://github.com/aaronschachter))
- Update to remove styles now placed in Neue. [\#3521](https://github.com/DoSomething/phoenix/pull/3521) ([weerd](https://github.com/weerd))
- Update to allow stepwise show more functionality. [\#3520](https://github.com/DoSomething/phoenix/pull/3520) ([weerd](https://github.com/weerd))
- Add tag as array [\#3508](https://github.com/DoSomething/phoenix/pull/3508) ([DeeZone](https://github.com/DeeZone))

## [v0.3.126](https://github.com/dosomething/phoenix/tree/v0.3.126) (2014-11-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.125...v0.3.126)

**Closed issues:**

- Setup cron to run drush command to cleanup US users on affiliates [\#3339](https://github.com/DoSomething/phoenix/issues/3339)

**Merged pull requests:**

- Fixes non-working reportback cache clear [\#3518](https://github.com/DoSomething/phoenix/pull/3518) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.125](https://github.com/dosomething/phoenix/tree/v0.3.125) (2014-11-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.124...v0.3.125)

**Merged pull requests:**

- Campaign Gallery PHP Warning fix [\#3516](https://github.com/DoSomething/phoenix/pull/3516) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.124](https://github.com/dosomething/phoenix/tree/v0.3.124) (2014-11-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.123...v0.3.124)

**Closed issues:**

- PHP Warning in Paraneue Gallery [\#3515](https://github.com/DoSomething/phoenix/issues/3515)

**Merged pull requests:**

- Fixes paraneue namespace for search results [\#3517](https://github.com/DoSomething/phoenix/pull/3517) ([aaronschachter](https://github.com/aaronschachter))
- Taxonomy tweaks [\#3513](https://github.com/DoSomething/phoenix/pull/3513) ([tjrosario](https://github.com/tjrosario))

## [v0.3.123](https://github.com/dosomething/phoenix/tree/v0.3.123) (2014-11-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.122...v0.3.123)

**Closed issues:**

- Responsive featured mosaic image \(reasons you won't believe\) [\#3474](https://github.com/DoSomething/phoenix/issues/3474)
- Donate Page: New UI Requirements [\#3312](https://github.com/DoSomething/phoenix/issues/3312)
- update results not found copy on search [\#3304](https://github.com/DoSomething/phoenix/issues/3304)

**Merged pull requests:**

- Remove campaign gallery tpl [\#3512](https://github.com/DoSomething/phoenix/pull/3512) ([aaronschachter](https://github.com/aaronschachter))
- Use mosaic gallery tpl for Campaign Group [\#3504](https://github.com/DoSomething/phoenix/pull/3504) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.122](https://github.com/dosomething/phoenix/tree/v0.3.122) (2014-11-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.121...v0.3.122)

**Closed issues:**

- add call to action to taxonomy collections [\#3383](https://github.com/DoSomething/phoenix/issues/3383)

**Merged pull requests:**

- Fixed CTA location [\#3506](https://github.com/DoSomething/phoenix/pull/3506) ([deadlybutter](https://github.com/deadlybutter))
- Taxonomy gallery show more [\#3505](https://github.com/DoSomething/phoenix/pull/3505) ([weerd](https://github.com/weerd))

## [v0.3.121](https://github.com/dosomething/phoenix/tree/v0.3.121) (2014-11-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.120...v0.3.121)

**Closed issues:**

- path specific copy on 404 page should not be bold [\#3487](https://github.com/DoSomething/phoenix/issues/3487)
- all paragraph/bulleted list text should be 3/4 length [\#3370](https://github.com/DoSomething/phoenix/issues/3370)

**Merged pull requests:**

- Adds call to action into preprocessing & template [\#3503](https://github.com/DoSomething/phoenix/pull/3503) ([deadlybutter](https://github.com/deadlybutter))
- Taxonomy content [\#3500](https://github.com/DoSomething/phoenix/pull/3500) ([tjrosario](https://github.com/tjrosario))

## [v0.3.120](https://github.com/dosomething/phoenix/tree/v0.3.120) (2014-11-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.119...v0.3.120)

**Closed issues:**

- pull in query string into the search bar on 404 page with no results [\#3496](https://github.com/DoSomething/phoenix/issues/3496)
- remove recommended campaigns header copy for 404 page [\#3486](https://github.com/DoSomething/phoenix/issues/3486)
- Fix Canada User Registration [\#3221](https://github.com/DoSomething/phoenix/issues/3221)

**Merged pull requests:**

- 404 style updates and bug fix [\#3502](https://github.com/DoSomething/phoenix/pull/3502) ([sbsmith86](https://github.com/sbsmith86))
- Campaign Tile image: data-src-large attribute [\#3499](https://github.com/DoSomething/phoenix/pull/3499) ([aaronschachter](https://github.com/aaronschachter))
- Adds missing Campaigns container [\#3498](https://github.com/DoSomething/phoenix/pull/3498) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.119](https://github.com/dosomething/phoenix/tree/v0.3.119) (2014-11-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.118...v0.3.119)

**Closed issues:**

- Blog image header - create admin ability to edit image [\#3491](https://github.com/DoSomething/phoenix/issues/3491)
- Donate Form logging [\#3489](https://github.com/DoSomething/phoenix/issues/3489)
- Drupal core security upgrade [\#3488](https://github.com/DoSomething/phoenix/issues/3488)

**Merged pull requests:**

- Adds Stripe logging [\#3494](https://github.com/DoSomething/phoenix/pull/3494) ([aaronschachter](https://github.com/aaronschachter))
- Stripe form double bind [\#3492](https://github.com/DoSomething/phoenix/pull/3492) ([tjrosario](https://github.com/tjrosario))
- Drupal core security update [\#3490](https://github.com/DoSomething/phoenix/pull/3490) ([aaronschachter](https://github.com/aaronschachter))
- Paraneue Tile pattern template [\#3485](https://github.com/DoSomething/phoenix/pull/3485) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.118](https://github.com/dosomething/phoenix/tree/v0.3.118) (2014-11-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.117...v0.3.118)

**Closed issues:**

- add facts header field to taxonomy collections [\#3381](https://github.com/DoSomething/phoenix/issues/3381)
- add title field to taxonomy collections [\#3380](https://github.com/DoSomething/phoenix/issues/3380)
- sources treatment on collections should match other places on the site [\#3241](https://github.com/DoSomething/phoenix/issues/3241)

**Merged pull requests:**

- Canada: Fixes PHP notices, handles form unknown errors. [\#3483](https://github.com/DoSomething/phoenix/pull/3483) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Exported call to action in taxonomy [\#3482](https://github.com/DoSomething/phoenix/pull/3482) ([deadlybutter](https://github.com/deadlybutter))
- fixed spacing between sources and headlines on collections [\#3481](https://github.com/DoSomething/phoenix/pull/3481) ([tjrosario](https://github.com/tjrosario))
- Added facts header in preprocessing [\#3479](https://github.com/DoSomething/phoenix/pull/3479) ([deadlybutter](https://github.com/deadlybutter))
- Facts header field  [\#3478](https://github.com/DoSomething/phoenix/pull/3478) ([deadlybutter](https://github.com/deadlybutter))
- Added title preprocessing [\#3477](https://github.com/DoSomething/phoenix/pull/3477) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.117](https://github.com/dosomething/phoenix/tree/v0.3.117) (2014-11-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.116...v0.3.117)

**Closed issues:**

- Create variables to manage copy on 404 page [\#3470](https://github.com/DoSomething/phoenix/issues/3470)

**Merged pull requests:**

- Added title field to taxonomy [\#3476](https://github.com/DoSomething/phoenix/pull/3476) ([deadlybutter](https://github.com/deadlybutter))
- 404 copy variables [\#3471](https://github.com/DoSomething/phoenix/pull/3471) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.116](https://github.com/dosomething/phoenix/tree/v0.3.116) (2014-11-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.115...v0.3.116)

**Fixed bugs:**

- Donate Form JS is telling me my CC number is invalid [\#3460](https://github.com/DoSomething/phoenix/issues/3460)

**Closed issues:**

- no search results found on 404 page [\#3428](https://github.com/DoSomething/phoenix/issues/3428)
- Stop users cleanup cron task and cleanup code [\#3347](https://github.com/DoSomething/phoenix/issues/3347)
- search results on 404 page [\#3318](https://github.com/DoSomething/phoenix/issues/3318)
- change variables that are displayed on search results [\#3207](https://github.com/DoSomething/phoenix/issues/3207)

**Merged pull requests:**

- Adds DS Reportback admin config form [\#3469](https://github.com/DoSomething/phoenix/pull/3469) ([aaronschachter](https://github.com/aaronschachter))
- Reportback Files API endpoint [\#3467](https://github.com/DoSomething/phoenix/pull/3467) ([aaronschachter](https://github.com/aaronschachter))
- fixed cc number validator and added card type to success msg [\#3466](https://github.com/DoSomething/phoenix/pull/3466) ([tjrosario](https://github.com/tjrosario))
- Adding a no results state to 404 pages [\#3465](https://github.com/DoSomething/phoenix/pull/3465) ([sbsmith86](https://github.com/sbsmith86))
- Removes the code with the manual user addresses fix. [\#3462](https://github.com/DoSomething/phoenix/pull/3462) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Added filtering to notfound search [\#3458](https://github.com/DoSomething/phoenix/pull/3458) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.115](https://github.com/dosomething/phoenix/tree/v0.3.115) (2014-11-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.114...v0.3.115)

**Closed issues:**

- Reportback Caption JS visibility [\#3453](https://github.com/DoSomething/phoenix/issues/3453)
- Create general template [\#3429](https://github.com/DoSomething/phoenix/issues/3429)

**Merged pull requests:**

- Updates to hide or show caption field in reportback. [\#3459](https://github.com/DoSomething/phoenix/pull/3459) ([weerd](https://github.com/weerd))

## [v0.3.114](https://github.com/dosomething/phoenix/tree/v0.3.114) (2014-11-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.113...v0.3.114)

**Fixed bugs:**

- Donate Form: Expiration month error [\#3438](https://github.com/DoSomething/phoenix/issues/3438)

**Closed issues:**

- Expose multiplayer SMS game IDs in views for A/B testing [\#3423](https://github.com/DoSomething/phoenix/issues/3423)
- New Reportback File properties: Options and fid\_processed [\#3398](https://github.com/DoSomething/phoenix/issues/3398)

**Merged pull requests:**

- Expose hidden SMS Game signup form fields [\#3457](https://github.com/DoSomething/phoenix/pull/3457) ([aaronschachter](https://github.com/aaronschachter))
- force a leading zero on exp month if value is less than 10 [\#3455](https://github.com/DoSomething/phoenix/pull/3455) ([tjrosario](https://github.com/tjrosario))

## [v0.3.113](https://github.com/dosomething/phoenix/tree/v0.3.113) (2014-11-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.112...v0.3.113)

**Closed issues:**

- Add Reportback Caption field [\#3284](https://github.com/DoSomething/phoenix/issues/3284)

**Merged pull requests:**

- Reportback Image caption [\#3454](https://github.com/DoSomething/phoenix/pull/3454) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.112](https://github.com/dosomething/phoenix/tree/v0.3.112) (2014-11-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.111...v0.3.112)

**Fixed bugs:**

- thumbnails are pixelated in search results [\#3447](https://github.com/DoSomething/phoenix/issues/3447)

**Closed issues:**

- Set up Feature Flag for new Reportback User Interface \(Step 4\) [\#3445](https://github.com/DoSomething/phoenix/issues/3445)
- Handle Stripe errors [\#3437](https://github.com/DoSomething/phoenix/issues/3437)
- path specific copy should be 3/4 length [\#3427](https://github.com/DoSomething/phoenix/issues/3427)
- 404 page header size reduction [\#3421](https://github.com/DoSomething/phoenix/issues/3421)
- need code for optimizely test for padding in tiled campaigns view [\#3392](https://github.com/DoSomething/phoenix/issues/3392)

**Merged pull requests:**

- Using a larger image style for thumbnails [\#3452](https://github.com/DoSomething/phoenix/pull/3452) ([sbsmith86](https://github.com/sbsmith86))
- Fixes Static Content PHP Notice [\#3451](https://github.com/DoSomething/phoenix/pull/3451) ([aaronschachter](https://github.com/aaronschachter))
- Stripe Errors [\#3450](https://github.com/DoSomething/phoenix/pull/3450) ([aaronschachter](https://github.com/aaronschachter))
- 404 path copy size [\#3448](https://github.com/DoSomething/phoenix/pull/3448) ([sbsmith86](https://github.com/sbsmith86))
- Adding new Reportback feature flag and setting it up. [\#3446](https://github.com/DoSomething/phoenix/pull/3446) ([weerd](https://github.com/weerd))
- Search update mergefix [\#3444](https://github.com/DoSomething/phoenix/pull/3444) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.111](https://github.com/dosomething/phoenix/tree/v0.3.111) (2014-11-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.110...v0.3.111)

**Closed issues:**

- Tests fails with "TypeError: callback provided to sync glob" [\#3440](https://github.com/DoSomething/phoenix/issues/3440)
- display the text of the search query in the search bar on the 404 page [\#3426](https://github.com/DoSomething/phoenix/issues/3426)

**Merged pull requests:**

- Adding query string to search form [\#3439](https://github.com/DoSomething/phoenix/pull/3439) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.110](https://github.com/dosomething/phoenix/tree/v0.3.110) (2014-11-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.109...v0.3.110)

**Merged pull requests:**

- Downgrade node-glob dependency in DS test suite due to \#3440. [\#3441](https://github.com/DoSomething/phoenix/pull/3441) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.109](https://github.com/dosomething/phoenix/tree/v0.3.109) (2014-11-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.108...v0.3.109)

**Merged pull requests:**

- Core + contrib updates [\#3425](https://github.com/DoSomething/phoenix/pull/3425) ([aaronschachter](https://github.com/aaronschachter))
- Fixes race condition in UK and Canada integration tests. [\#3419](https://github.com/DoSomething/phoenix/pull/3419) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.108](https://github.com/dosomething/phoenix/tree/v0.3.108) (2014-11-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.107...v0.3.108)

**Closed issues:**

- change display of search results [\#3319](https://github.com/DoSomething/phoenix/issues/3319)

**Merged pull requests:**

- Donate Form: Allows Stripe CVC check to pass [\#3436](https://github.com/DoSomething/phoenix/pull/3436) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.107](https://github.com/dosomething/phoenix/tree/v0.3.107) (2014-11-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.106...v0.3.107)

**Fixed bugs:**

- Homepage images are broken [\#3422](https://github.com/DoSomething/phoenix/issues/3422)

**Closed issues:**

- Donate Form confirmation message [\#3410](https://github.com/DoSomething/phoenix/issues/3410)

**Merged pull requests:**

- Fixes JS error [\#3435](https://github.com/DoSomething/phoenix/pull/3435) ([aaronschachter](https://github.com/aaronschachter))
- Donate Form: Display confirmation within block content [\#3420](https://github.com/DoSomething/phoenix/pull/3420) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.106](https://github.com/dosomething/phoenix/tree/v0.3.106) (2014-11-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.105...v0.3.106)

**Closed issues:**

- Donate Form: Variable for Stripe Publish Key  [\#3413](https://github.com/DoSomething/phoenix/issues/3413)

**Merged pull requests:**

- Stripe Publish API key variable [\#3418](https://github.com/DoSomething/phoenix/pull/3418) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.105](https://github.com/dosomething/phoenix/tree/v0.3.105) (2014-11-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.104...v0.3.105)

**Merged pull requests:**

- Runs UK and Canada tests on international subdomain. [\#3417](https://github.com/DoSomething/phoenix/pull/3417) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fix Stripe Customer / Charge requests  [\#3416](https://github.com/DoSomething/phoenix/pull/3416) ([aaronschachter](https://github.com/aaronschachter))
- Search appearance [\#3405](https://github.com/DoSomething/phoenix/pull/3405) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.104](https://github.com/dosomething/phoenix/tree/v0.3.104) (2014-11-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.103...v0.3.104)

**Fixed bugs:**

- Vagrant international build: affiliate sites use wrong database settings. [\#3269](https://github.com/DoSomething/phoenix/issues/3269)

**Closed issues:**

- 404 Path Copy variables need to display as Markdown [\#3403](https://github.com/DoSomething/phoenix/issues/3403)

**Merged pull requests:**

- Donate page [\#3412](https://github.com/DoSomething/phoenix/pull/3412) ([tjrosario](https://github.com/tjrosario))
- Fixes various 404 page bugs [\#3411](https://github.com/DoSomething/phoenix/pull/3411) ([deadlybutter](https://github.com/deadlybutter))
- Stripe customer [\#3407](https://github.com/DoSomething/phoenix/pull/3407) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.103](https://github.com/dosomething/phoenix/tree/v0.3.103) (2014-11-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.102...v0.3.103)

**Closed issues:**

- Path-specific 404 page suggestions [\#3317](https://github.com/DoSomething/phoenix/issues/3317)
- Add member\_count merge\_var [\#3177](https://github.com/DoSomething/phoenix/issues/3177)
- Redirects from legacy to beta [\#3148](https://github.com/DoSomething/phoenix/issues/3148)

**Merged pull requests:**

- Donate Form block [\#3401](https://github.com/DoSomething/phoenix/pull/3401) ([aaronschachter](https://github.com/aaronschachter))
- Added specific path option to the 404 page [\#3400](https://github.com/DoSomething/phoenix/pull/3400) ([deadlybutter](https://github.com/deadlybutter))
- DoSomething Payment module + Stripe integration [\#3397](https://github.com/DoSomething/phoenix/pull/3397) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.102](https://github.com/dosomething/phoenix/tree/v0.3.102) (2014-11-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.101...v0.3.102)

**Fixed bugs:**

- US states are shown on users profile page on Canada [\#3328](https://github.com/DoSomething/phoenix/issues/3328)

**Closed issues:**

- Fix UK and Canada tests due to a change in profile Page [\#3393](https://github.com/DoSomething/phoenix/issues/3393)
- Create permanent solution that fixes users country [\#3341](https://github.com/DoSomething/phoenix/issues/3341)

**Merged pull requests:**

- Cleans up users adderssfield country [\#3396](https://github.com/DoSomething/phoenix/pull/3396) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Changes the way country is tested in UK and Canada. [\#3395](https://github.com/DoSomething/phoenix/pull/3395) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.101](https://github.com/dosomething/phoenix/tree/v0.3.101) (2014-11-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.100...v0.3.101)

**Closed issues:**

- Adjust tag values in mbp payload [\#3386](https://github.com/DoSomething/phoenix/issues/3386)
- facts, action guides, campaign runs, and the homepage shouldn't show up in search results [\#3206](https://github.com/DoSomething/phoenix/issues/3206)

**Merged pull requests:**

- Integrates preliminary 404 search functionality [\#3394](https://github.com/DoSomething/phoenix/pull/3394) ([deadlybutter](https://github.com/deadlybutter))
- Adjusts tag values in payload [\#3387](https://github.com/DoSomething/phoenix/pull/3387) ([DeeZone](https://github.com/DeeZone))
- Issue3177 add member count [\#3385](https://github.com/DoSomething/phoenix/pull/3385) ([DeeZone](https://github.com/DeeZone))

## [v0.3.100](https://github.com/dosomething/phoenix/tree/v0.3.100) (2014-11-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.99...v0.3.100)

**Closed issues:**

- Render Image video in header if Image video field exists [\#3333](https://github.com/DoSomething/phoenix/issues/3333)

**Merged pull requests:**

- Added Video hero [\#3391](https://github.com/DoSomething/phoenix/pull/3391) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.99](https://github.com/dosomething/phoenix/tree/v0.3.99) (2014-11-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.98...v0.3.99)

**Fixed bugs:**

- Fix Signup page access [\#3382](https://github.com/DoSomething/phoenix/issues/3382)
- PHP Warning in Paraneue Gallery [\#3378](https://github.com/DoSomething/phoenix/issues/3378)

**Closed issues:**

- Profile template v1.0 [\#3261](https://github.com/DoSomething/phoenix/issues/3261)

**Merged pull requests:**

- Fix Signup page view permissions [\#3390](https://github.com/DoSomething/phoenix/pull/3390) ([aaronschachter](https://github.com/aaronschachter))
- Fixes PHP Warning [\#3379](https://github.com/DoSomething/phoenix/pull/3379) ([aaronschachter](https://github.com/aaronschachter))
- Issue3365 add production [\#3369](https://github.com/DoSomething/phoenix/pull/3369) ([DeeZone](https://github.com/DeeZone))

## [v0.3.98](https://github.com/dosomething/phoenix/tree/v0.3.98) (2014-11-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.97...v0.3.98)

**Closed issues:**

- Zendesk admin form tweaks [\#3330](https://github.com/DoSomething/phoenix/issues/3330)
- User Profile: Theme "I'm Doing" items as different tile [\#3299](https://github.com/DoSomething/phoenix/issues/3299)

**Merged pull requests:**

- Gallery template refactor / User Profile triads [\#3371](https://github.com/DoSomething/phoenix/pull/3371) ([aaronschachter](https://github.com/aaronschachter))
- Grant member support access to Zendesk config [\#3368](https://github.com/DoSomething/phoenix/pull/3368) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.97](https://github.com/dosomething/phoenix/tree/v0.3.97) (2014-11-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.96...v0.3.97)

**Closed issues:**

- Allow staff to reset a user's Signup Data Form submission [\#3337](https://github.com/DoSomething/phoenix/issues/3337)
- Update "still having issues?" language on school finder [\#3321](https://github.com/DoSomething/phoenix/issues/3321)
- Paraneue Gallery theme functions [\#3283](https://github.com/DoSomething/phoenix/issues/3283)

**Merged pull requests:**

- School Finder State/Province label [\#3367](https://github.com/DoSomething/phoenix/pull/3367) ([aaronschachter](https://github.com/aaronschachter))
- Allow Signup Data Form reset [\#3366](https://github.com/DoSomething/phoenix/pull/3366) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.96](https://github.com/dosomething/phoenix/tree/v0.3.96) (2014-11-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.95...v0.3.96)

**Merged pull requests:**

- Wee little school finder bugs [\#3363](https://github.com/DoSomething/phoenix/pull/3363) ([DFurnes](https://github.com/DFurnes))
- Use module names as menu titles [\#3362](https://github.com/DoSomething/phoenix/pull/3362) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.95](https://github.com/dosomething/phoenix/tree/v0.3.95) (2014-11-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.94...v0.3.95)

**Closed issues:**

- turn off address validation on canadian site [\#3344](https://github.com/DoSomething/phoenix/issues/3344)

**Merged pull requests:**

- Address validation switch [\#3361](https://github.com/DoSomething/phoenix/pull/3361) ([aaronschachter](https://github.com/aaronschachter))
- Fix gallery index [\#3359](https://github.com/DoSomething/phoenix/pull/3359) ([blisteringherb](https://github.com/blisteringherb))

## [v0.3.94](https://github.com/dosomething/phoenix/tree/v0.3.94) (2014-11-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.93...v0.3.94)

**Closed issues:**

- Track Action Page views vs Pitch Page views [\#3308](https://github.com/DoSomething/phoenix/issues/3308)

**Merged pull requests:**

- Fires custom event on action page. Fixes \#3308. [\#3360](https://github.com/DoSomething/phoenix/pull/3360) ([DFurnes](https://github.com/DFurnes))

## [v0.3.93](https://github.com/dosomething/phoenix/tree/v0.3.93) (2014-11-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.92...v0.3.93)

**Fixed bugs:**

- school finder doesn't work on ie8/ie9 operating system windows 7 [\#3354](https://github.com/DoSomething/phoenix/issues/3354)

**Closed issues:**

- Setup a cron job to update users address country [\#3340](https://github.com/DoSomething/phoenix/issues/3340)
- remove data-validate='zip' attribute on address collection for international sites [\#3329](https://github.com/DoSomething/phoenix/issues/3329)
- get Zendesk set up on Canada [\#3322](https://github.com/DoSomething/phoenix/issues/3322)
- Add "Image Video" field to Image content type  [\#3228](https://github.com/DoSomething/phoenix/issues/3228)
- improvements to search results [\#3209](https://github.com/DoSomething/phoenix/issues/3209)

**Merged pull requests:**

- Fixes IE8 and IE9 CORS issues with School Finder. [\#3358](https://github.com/DoSomething/phoenix/pull/3358) ([DFurnes](https://github.com/DFurnes))
- Fixes image uploader thumbnail not showing. [\#3356](https://github.com/DoSomething/phoenix/pull/3356) ([DFurnes](https://github.com/DFurnes))
- Added video field to image feature [\#3355](https://github.com/DoSomething/phoenix/pull/3355) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.92](https://github.com/dosomething/phoenix/tree/v0.3.92) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.91...v0.3.92)

**Merged pull requests:**

- Paraneue gallery theme functions [\#3348](https://github.com/DoSomething/phoenix/pull/3348) ([sbsmith86](https://github.com/sbsmith86))

## [v0.3.91](https://github.com/dosomething/phoenix/tree/v0.3.91) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.90...v0.3.91)

**Merged pull requests:**

- Fixes lock being set on premature returns. [\#3357](https://github.com/DoSomething/phoenix/pull/3357) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixed css to apply style to the header instead of div [\#3350](https://github.com/DoSomething/phoenix/pull/3350) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.90](https://github.com/dosomething/phoenix/tree/v0.3.90) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.89...v0.3.90)

**Closed issues:**

- Create bin script to run drush commands at every affiliate [\#3349](https://github.com/DoSomething/phoenix/issues/3349)

**Merged pull requests:**

- Provides bin script that runs drush on each affiliate. [\#3352](https://github.com/DoSomething/phoenix/pull/3352) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Enables affiliate access to Zendesk [\#3351](https://github.com/DoSomething/phoenix/pull/3351) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.89](https://github.com/dosomething/phoenix/tree/v0.3.89) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.88...v0.3.89)

**Merged pull requests:**

- Fixing user country with drush: update only users register after intl release. [\#3346](https://github.com/DoSomething/phoenix/pull/3346) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Provides an option to bypass JS validation of user's postcode. [\#3345](https://github.com/DoSomething/phoenix/pull/3345) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.88](https://github.com/dosomething/phoenix/tree/v0.3.88) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.87...v0.3.88)

**Closed issues:**

- Add "Show More" results button to School Finder [\#3326](https://github.com/DoSomething/phoenix/issues/3326)
- Update Canada User addresses [\#3242](https://github.com/DoSomething/phoenix/issues/3242)

**Merged pull requests:**

- Add drush task to fix users address country. [\#3338](https://github.com/DoSomething/phoenix/pull/3338) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Add "show more" link to the school finder. [\#3336](https://github.com/DoSomething/phoenix/pull/3336) ([DFurnes](https://github.com/DFurnes))
- Ensuring that disallowed types do not show up in search results [\#3327](https://github.com/DoSomething/phoenix/pull/3327) ([blisteringherb](https://github.com/blisteringherb))

## [v0.3.87](https://github.com/dosomething/phoenix/tree/v0.3.87) (2014-11-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.86...v0.3.87)

**Closed issues:**

- change select state label on canadian school finder to select province [\#3320](https://github.com/DoSomething/phoenix/issues/3320)

**Merged pull requests:**

- Cancel temporary user accounts at the affiliate sites. [\#3095](https://github.com/DoSomething/phoenix/pull/3095) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.86](https://github.com/dosomething/phoenix/tree/v0.3.86) (2014-11-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.85...v0.3.86)

**Fixed bugs:**

- Notfound module needs to include features [\#3334](https://github.com/DoSomething/phoenix/issues/3334)

**Closed issues:**

- 404 page callback [\#3289](https://github.com/DoSomething/phoenix/issues/3289)
- Notfound content type / template [\#3229](https://github.com/DoSomething/phoenix/issues/3229)

**Merged pull requests:**

- Fixes \#3334 [\#3335](https://github.com/DoSomething/phoenix/pull/3335) ([deadlybutter](https://github.com/deadlybutter))

## [v0.3.85](https://github.com/dosomething/phoenix/tree/v0.3.85) (2014-11-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.84...v0.3.85)

**Fixed bugs:**

- MBP 7002 update never completes [\#3323](https://github.com/DoSomething/phoenix/issues/3323)
- can't select a state in the school finder [\#3316](https://github.com/DoSomething/phoenix/issues/3316)
- Canada Users are still created with US address [\#3307](https://github.com/DoSomething/phoenix/issues/3307)

**Closed issues:**

- remove I \<3 null from state field [\#3315](https://github.com/DoSomething/phoenix/issues/3315)
- Message Broker / DS MBP errors [\#3303](https://github.com/DoSomething/phoenix/issues/3303)
- ds pull does not wipe local db [\#3132](https://github.com/DoSomething/phoenix/issues/3132)

**Merged pull requests:**

- Check yourself before you wreck the drush updb [\#3332](https://github.com/DoSomething/phoenix/pull/3332) ([aaronschachter](https://github.com/aaronschachter))
- 404page [\#3331](https://github.com/DoSomething/phoenix/pull/3331) ([deadlybutter](https://github.com/deadlybutter))
- Lint fix [\#3325](https://github.com/DoSomething/phoenix/pull/3325) ([DFurnes](https://github.com/DFurnes))
- Drop local database before pulling stage DB [\#3324](https://github.com/DoSomething/phoenix/pull/3324) ([aaronschachter](https://github.com/aaronschachter))
- Adding gallery field to solr index [\#3313](https://github.com/DoSomething/phoenix/pull/3313) ([blisteringherb](https://github.com/blisteringherb))

## [v0.3.84](https://github.com/dosomething/phoenix/tree/v0.3.84) (2014-11-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.83...v0.3.84)

**Fixed bugs:**

- DS Build is broken [\#3311](https://github.com/DoSomething/phoenix/issues/3311)

**Merged pull requests:**

- Restores peace and happiness to DS build [\#3314](https://github.com/DoSomething/phoenix/pull/3314) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.83](https://github.com/dosomething/phoenix/tree/v0.3.83) (2014-11-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.82...v0.3.83)

## [v0.3.82](https://github.com/dosomething/phoenix/tree/v0.3.82) (2014-11-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.81...v0.3.82)

**Closed issues:**

- Admin reportback create/edit form [\#3293](https://github.com/DoSomething/phoenix/issues/3293)

**Merged pull requests:**

- Bug fix to resolve sending transactional requests to MB [\#3309](https://github.com/DoSomething/phoenix/pull/3309) ([DeeZone](https://github.com/DeeZone))

## [v0.3.81](https://github.com/dosomething/phoenix/tree/v0.3.81) (2014-11-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.80...v0.3.81)

**Merged pull requests:**

- Fact Page intro variable [\#3306](https://github.com/DoSomething/phoenix/pull/3306) ([aaronschachter](https://github.com/aaronschachter))
- Displays actual User data on profile [\#3302](https://github.com/DoSomething/phoenix/pull/3302) ([aaronschachter](https://github.com/aaronschachter))
- User reportbacks [\#3301](https://github.com/DoSomething/phoenix/pull/3301) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.80](https://github.com/dosomething/phoenix/tree/v0.3.80) (2014-11-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.79...v0.3.80)

**Fixed bugs:**

- User Profile displays logged in user info for all profiles [\#3300](https://github.com/DoSomething/phoenix/issues/3300)

**Closed issues:**

- add copy as intro to all 11 facts pages [\#3297](https://github.com/DoSomething/phoenix/issues/3297)
- Canada State label [\#3248](https://github.com/DoSomething/phoenix/issues/3248)

**Merged pull requests:**

- Fixes race hook\_update bug with message\_broker\_producer update [\#3305](https://github.com/DoSomething/phoenix/pull/3305) ([DeeZone](https://github.com/DeeZone))
- Adds Title to Administrative Area options variable [\#3298](https://github.com/DoSomething/phoenix/pull/3298) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.79](https://github.com/dosomething/phoenix/tree/v0.3.79) (2014-10-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.78...v0.3.79)

**Closed issues:**

- Integrate message\_broker\_producer update [\#3239](https://github.com/DoSomething/phoenix/issues/3239)

**Merged pull requests:**

- Update message\_broker\_producer module [\#3240](https://github.com/DoSomething/phoenix/pull/3240) ([DeeZone](https://github.com/DeeZone))

## [v0.3.78](https://github.com/dosomething/phoenix/tree/v0.3.78) (2014-10-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.77...v0.3.78)

**Closed issues:**

- Don't need Submit Button Label field on shipment form [\#3165](https://github.com/DoSomething/phoenix/issues/3165)

**Merged pull requests:**

- Don't build US on international deploys. [\#3296](https://github.com/DoSomething/phoenix/pull/3296) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Adding proximity boost to enable search phrases [\#3295](https://github.com/DoSomething/phoenix/pull/3295) ([blisteringherb](https://github.com/blisteringherb))

## [v0.3.77](https://github.com/dosomething/phoenix/tree/v0.3.77) (2014-10-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.76...v0.3.77)

**Merged pull requests:**

- DS Build: echo debug line with drush working directory [\#3294](https://github.com/DoSomething/phoenix/pull/3294) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.76](https://github.com/dosomething/phoenix/tree/v0.3.76) (2014-10-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.75...v0.3.76)

**Closed issues:**

- action guide list margin cleanup [\#3282](https://github.com/DoSomething/phoenix/issues/3282)

**Merged pull requests:**

- DS build: Add drush status. [\#3292](https://github.com/DoSomething/phoenix/pull/3292) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Pull in Neue 5.2.x. [\#3291](https://github.com/DoSomething/phoenix/pull/3291) ([DFurnes](https://github.com/DFurnes))

## [v0.3.75](https://github.com/dosomething/phoenix/tree/v0.3.75) (2014-10-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.74...v0.3.75)

**Fixed bugs:**

- user never gets logged in on firefox on staging [\#3279](https://github.com/DoSomething/phoenix/issues/3279)

**Merged pull requests:**

- DS build: Revert only overridden features. [\#3290](https://github.com/DoSomething/phoenix/pull/3290) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.74](https://github.com/dosomething/phoenix/tree/v0.3.74) (2014-10-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.73...v0.3.74)

**Closed issues:**

- International build - features not reverting [\#3211](https://github.com/DoSomething/phoenix/issues/3211)

**Merged pull requests:**

- Deployments: flush the Redis cache before running drush. [\#3272](https://github.com/DoSomething/phoenix/pull/3272) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.73](https://github.com/dosomething/phoenix/tree/v0.3.73) (2014-10-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.72...v0.3.73)

**Fixed bugs:**

- Campaign Confirmation page links don't work [\#3280](https://github.com/DoSomething/phoenix/issues/3280)

**Closed issues:**

- need field\_intro\_image added to taxonomy collections [\#3266](https://github.com/DoSomething/phoenix/issues/3266)

**Merged pull requests:**

- Fixes Confirmation Page links [\#3281](https://github.com/DoSomething/phoenix/pull/3281) ([aaronschachter](https://github.com/aaronschachter))
- Term intro image [\#3278](https://github.com/DoSomething/phoenix/pull/3278) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.72](https://github.com/dosomething/phoenix/tree/v0.3.72) (2014-10-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.71...v0.3.72)

**Fixed bugs:**

- editors and admins should see action page on campaign pages even if not signed up [\#3273](https://github.com/DoSomething/phoenix/issues/3273)
- Broken page layout for User Password Reset [\#3270](https://github.com/DoSomething/phoenix/issues/3270)

**Merged pull requests:**

- User Profile: You Did [\#3277](https://github.com/DoSomething/phoenix/pull/3277) ([aaronschachter](https://github.com/aaronschachter))
- Fixes User Reset layout [\#3276](https://github.com/DoSomething/phoenix/pull/3276) ([aaronschachter](https://github.com/aaronschachter))
- Let staff bypass pitch page [\#3274](https://github.com/DoSomething/phoenix/pull/3274) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.71](https://github.com/dosomething/phoenix/tree/v0.3.71) (2014-10-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.70...v0.3.71)

**Merged pull requests:**

- Fixes \#3270 - only check for full width if multiple suggestions [\#3271](https://github.com/DoSomething/phoenix/pull/3271) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.70](https://github.com/dosomething/phoenix/tree/v0.3.70) (2014-10-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.69...v0.3.70)

**Closed issues:**

- remove "Did you mean" suggestions on search [\#3204](https://github.com/DoSomething/phoenix/issues/3204)

**Merged pull requests:**

- User Profile: I'm Doing [\#3268](https://github.com/DoSomething/phoenix/pull/3268) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.69](https://github.com/dosomething/phoenix/tree/v0.3.69) (2014-10-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.68...v0.3.69)

**Fixed bugs:**

- autocomplete on school finder doesn't work on production [\#3259](https://github.com/DoSomething/phoenix/issues/3259)

**Closed issues:**

- Hide User Profile tabs from non-staff [\#3252](https://github.com/DoSomething/phoenix/issues/3252)
- need config variable for "Need help locating your school" copy [\#3250](https://github.com/DoSomething/phoenix/issues/3250)

**Merged pull requests:**

- School Help Text variable [\#3263](https://github.com/DoSomething/phoenix/pull/3263) ([aaronschachter](https://github.com/aaronschachter))
- Profile cleanup [\#3262](https://github.com/DoSomething/phoenix/pull/3262) ([aaronschachter](https://github.com/aaronschachter))
- Brings back missed UK to the affiliates list. [\#3254](https://github.com/DoSomething/phoenix/pull/3254) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.68](https://github.com/dosomething/phoenix/tree/v0.3.68) (2014-10-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.67...v0.3.68)

**Merged pull requests:**

- Provide the affiliate code to country code mapping. [\#3249](https://github.com/DoSomething/phoenix/pull/3249) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.67](https://github.com/dosomething/phoenix/tree/v0.3.67) (2014-10-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.66...v0.3.67)

**Closed issues:**

- Wipe User activity upon User delete [\#3245](https://github.com/DoSomething/phoenix/issues/3245)
- School Finder can show submission errors multiple times  [\#3243](https://github.com/DoSomething/phoenix/issues/3243)

**Merged pull requests:**

- Provides a common way to determine current affiliate. [\#3247](https://github.com/DoSomething/phoenix/pull/3247) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Delete all user data upon user delete [\#3246](https://github.com/DoSomething/phoenix/pull/3246) ([aaronschachter](https://github.com/aaronschachter))
- Only show maximum of one form validation error at once. [\#3244](https://github.com/DoSomething/phoenix/pull/3244) ([DFurnes](https://github.com/DFurnes))

## [v0.3.66](https://github.com/dosomething/phoenix/tree/v0.3.66) (2014-10-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.65...v0.3.66)

**Closed issues:**

- \[submitted\] token doesn't work on shipment form [\#3222](https://github.com/DoSomething/phoenix/issues/3222)

**Merged pull requests:**

- Adds isset checks to avoid PHP Notice undefined index [\#3238](https://github.com/DoSomething/phoenix/pull/3238) ([aaronschachter](https://github.com/aaronschachter))
- Support \[submitted\] token in Shipment Form submitted copy [\#3237](https://github.com/DoSomething/phoenix/pull/3237) ([aaronschachter](https://github.com/aaronschachter))
- Canada SSO: improve intergration tests. [\#3236](https://github.com/DoSomething/phoenix/pull/3236) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.65](https://github.com/dosomething/phoenix/tree/v0.3.65) (2014-10-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.64...v0.3.65)

**Merged pull requests:**

- Taxonomy Term Zendesk Form [\#3218](https://github.com/DoSomething/phoenix/pull/3218) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.64](https://github.com/dosomething/phoenix/tree/v0.3.64) (2014-10-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.63...v0.3.64)

**Fixed bugs:**

- Campaign Group not outputting Source query string [\#3231](https://github.com/DoSomething/phoenix/issues/3231)

**Closed issues:**

- need pitch tab to show active state pitch page for closed campaigns, not the closed campaign view [\#3220](https://github.com/DoSomething/phoenix/issues/3220)
- Save CA as address country for DS Canada User Registration [\#3217](https://github.com/DoSomething/phoenix/issues/3217)

**Merged pull requests:**

- Update Features contrib module [\#3235](https://github.com/DoSomething/phoenix/pull/3235) ([aaronschachter](https://github.com/aaronschachter))
- UK SSO: refactor integration tests. [\#3234](https://github.com/DoSomething/phoenix/pull/3234) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes Pitch Page view bug [\#3233](https://github.com/DoSomething/phoenix/pull/3233) ([aaronschachter](https://github.com/aaronschachter))
- Adds missing Signup Source to Campaign Group gallery [\#3232](https://github.com/DoSomething/phoenix/pull/3232) ([aaronschachter](https://github.com/aaronschachter))
- Canada SSO: fixes users address country. [\#3230](https://github.com/DoSomething/phoenix/pull/3230) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.63](https://github.com/dosomething/phoenix/tree/v0.3.63) (2014-10-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.62...v0.3.63)

**Fixed bugs:**

- Footer expands outside of container on campaign group page [\#3225](https://github.com/DoSomething/phoenix/issues/3225)
- UK SSO: newly registered users has wrong country [\#3223](https://github.com/DoSomething/phoenix/issues/3223)

**Closed issues:**

- Taxonomy Term view: Zendesk form [\#3194](https://github.com/DoSomething/phoenix/issues/3194)
- Vocabulary fields [\#3162](https://github.com/DoSomething/phoenix/issues/3162)
- 3M logo needs to be added to the homepage [\#3157](https://github.com/DoSomething/phoenix/issues/3157)

**Merged pull requests:**

- HTML For Dummies [\#3227](https://github.com/DoSomething/phoenix/pull/3227) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#3223. [\#3226](https://github.com/DoSomething/phoenix/pull/3226) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- UK SSO: Add country field integration test. [\#3224](https://github.com/DoSomething/phoenix/pull/3224) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- SSO Canada: registration [\#3205](https://github.com/DoSomething/phoenix/pull/3205) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.62](https://github.com/dosomething/phoenix/tree/v0.3.62) (2014-10-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.61...v0.3.62)

**Closed issues:**

- Grant communications team view unpublished access [\#3214](https://github.com/DoSomething/phoenix/issues/3214)
- Address Form API form element needs dynamic country code [\#3212](https://github.com/DoSomething/phoenix/issues/3212)

**Merged pull requests:**

- Communications team - view unpublished access [\#3216](https://github.com/DoSomething/phoenix/pull/3216) ([aaronschachter](https://github.com/aaronschachter))
- Taxonomy Term: Intro title field [\#3215](https://github.com/DoSomething/phoenix/pull/3215) ([aaronschachter](https://github.com/aaronschachter))
- Variable for dosomething\_user\_address\_country [\#3213](https://github.com/DoSomething/phoenix/pull/3213) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.61](https://github.com/dosomething/phoenix/tree/v0.3.61) (2014-10-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.60...v0.3.61)

**Merged pull requests:**

- Check for field existance before preprocessing homepage. [\#3210](https://github.com/DoSomething/phoenix/pull/3210) ([DFurnes](https://github.com/DFurnes))

## [v0.3.60](https://github.com/dosomething/phoenix/tree/v0.3.60) (2014-10-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.59...v0.3.60)

**Closed issues:**

- New vocabularies [\#3161](https://github.com/DoSomething/phoenix/issues/3161)

**Merged pull requests:**

- Taxonomy Term Facts [\#3208](https://github.com/DoSomething/phoenix/pull/3208) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.59](https://github.com/dosomething/phoenix/tree/v0.3.59) (2014-10-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.58...v0.3.59)

## [v0.3.58](https://github.com/dosomething/phoenix/tree/v0.3.58) (2014-10-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.57...v0.3.58)

**Closed issues:**

- Staff view of campaign as active while closed [\#3199](https://github.com/DoSomething/phoenix/issues/3199)

**Merged pull requests:**

- Active Campaign preview page [\#3203](https://github.com/DoSomething/phoenix/pull/3203) ([aaronschachter](https://github.com/aaronschachter))
- Homepage sponsor admin [\#3202](https://github.com/DoSomething/phoenix/pull/3202) ([DFurnes](https://github.com/DFurnes))

## [v0.3.57](https://github.com/dosomething/phoenix/tree/v0.3.57) (2014-10-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.56...v0.3.57)

**Closed issues:**

- Enable DS Shipments module for TFJ Canada [\#3156](https://github.com/DoSomething/phoenix/issues/3156)

**Merged pull requests:**

- Taxonomy Term partners [\#3201](https://github.com/DoSomething/phoenix/pull/3201) ([aaronschachter](https://github.com/aaronschachter))
- Enable DS Shipment for Canada [\#3198](https://github.com/DoSomething/phoenix/pull/3198) ([aaronschachter](https://github.com/aaronschachter))
- Canada SSO: adapt login to common flow provided in external\_auth. [\#3176](https://github.com/DoSomething/phoenix/pull/3176) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.56](https://github.com/dosomething/phoenix/tree/v0.3.56) (2014-10-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.55...v0.3.56)

**Closed issues:**

- Admin Term table view [\#3191](https://github.com/DoSomething/phoenix/issues/3191)
- Taxonomy term template [\#3159](https://github.com/DoSomething/phoenix/issues/3159)

**Merged pull requests:**

- Term video [\#3196](https://github.com/DoSomething/phoenix/pull/3196) ([aaronschachter](https://github.com/aaronschachter))
- Taxonomy Terms admin list [\#3195](https://github.com/DoSomething/phoenix/pull/3195) ([aaronschachter](https://github.com/aaronschachter))
- Refs \#3189 - staff need access too [\#3192](https://github.com/DoSomething/phoenix/pull/3192) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.55](https://github.com/dosomething/phoenix/tree/v0.3.55) (2014-10-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.54...v0.3.55)

**Closed issues:**

- Taxonomy Term access [\#3189](https://github.com/DoSomething/phoenix/issues/3189)
- Taxonomy feature UUID conflict [\#3187](https://github.com/DoSomething/phoenix/issues/3187)

**Merged pull requests:**

- Term Page access [\#3190](https://github.com/DoSomething/phoenix/pull/3190) ([aaronschachter](https://github.com/aaronschachter))
- No more exporting terms [\#3188](https://github.com/DoSomething/phoenix/pull/3188) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.54](https://github.com/dosomething/phoenix/tree/v0.3.54) (2014-10-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.53...v0.3.54)

**Closed issues:**

- Video tile A/B test [\#3170](https://github.com/DoSomething/phoenix/issues/3170)
- Term view: General copy variables [\#3168](https://github.com/DoSomething/phoenix/issues/3168)
- Taxonomy term URL pattern [\#3163](https://github.com/DoSomething/phoenix/issues/3163)

**Merged pull requests:**

- Taxonomy Term URL pattern [\#3186](https://github.com/DoSomething/phoenix/pull/3186) ([aaronschachter](https://github.com/aaronschachter))
- Global copy variables [\#3185](https://github.com/DoSomething/phoenix/pull/3185) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.53](https://github.com/dosomething/phoenix/tree/v0.3.53) (2014-10-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.52...v0.3.53)

**Merged pull requests:**

- Adds secondary page tpl to DRY [\#3184](https://github.com/DoSomething/phoenix/pull/3184) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.52](https://github.com/dosomething/phoenix/tree/v0.3.52) (2014-10-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.51...v0.3.52)

**Merged pull requests:**

- Fix release v0.3.51. [\#3182](https://github.com/DoSomething/phoenix/pull/3182) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.51](https://github.com/dosomething/phoenix/tree/v0.3.51) (2014-10-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.50...v0.3.51)

**Closed issues:**

- \[shipments\] - need to add configuration to prevent old ppl from submitting the form [\#3166](https://github.com/DoSomething/phoenix/issues/3166)

**Merged pull requests:**

- Taxonomy term template [\#3181](https://github.com/DoSomething/phoenix/pull/3181) ([aaronschachter](https://github.com/aaronschachter))
- Taxonomy fields: Subtitle and Cover Image [\#3180](https://github.com/DoSomething/phoenix/pull/3180) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Group cleanup [\#3179](https://github.com/DoSomething/phoenix/pull/3179) ([aaronschachter](https://github.com/aaronschachter))
- Campaign gallery [\#3178](https://github.com/DoSomething/phoenix/pull/3178) ([aaronschachter](https://github.com/aaronschachter))
- Canada SSO: simple integration tests. [\#3175](https://github.com/DoSomething/phoenix/pull/3175) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Shipment Form - Conditionally prevent Old People from submitting [\#3167](https://github.com/DoSomething/phoenix/pull/3167) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.50](https://github.com/dosomething/phoenix/tree/v0.3.50) (2014-10-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.49...v0.3.50)

**Merged pull requests:**

- UK SSO: adapt login/signup to common flow provided in external\_auth. [\#3174](https://github.com/DoSomething/phoenix/pull/3174) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.49](https://github.com/dosomething/phoenix/tree/v0.3.49) (2014-10-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.48...v0.3.49)

**Merged pull requests:**

- Appends source query string to /campaigns [\#3173](https://github.com/DoSomething/phoenix/pull/3173) ([aaronschachter](https://github.com/aaronschachter))
- Custom taxonomy term page [\#3172](https://github.com/DoSomething/phoenix/pull/3172) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.48](https://github.com/dosomething/phoenix/tree/v0.3.48) (2014-10-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.47...v0.3.48)

**Closed issues:**

- Upgrade Drupal core to 7.32 [\#3169](https://github.com/DoSomething/phoenix/issues/3169)
- Canada School API sending incorrect headers [\#3160](https://github.com/DoSomething/phoenix/issues/3160)
- School Finder endpoint CORS issue [\#3133](https://github.com/DoSomething/phoenix/issues/3133)

**Merged pull requests:**

- Critical Dries update [\#3171](https://github.com/DoSomething/phoenix/pull/3171) ([aaronschachter](https://github.com/aaronschachter))
- Only preprocess campaign\_group if full view mode [\#3164](https://github.com/DoSomething/phoenix/pull/3164) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.47](https://github.com/dosomething/phoenix/tree/v0.3.47) (2014-10-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.46...v0.3.47)

**Merged pull requests:**

- Closed Campaign: Only display Winners section if Scholarship [\#3158](https://github.com/DoSomething/phoenix/pull/3158) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.46](https://github.com/dosomething/phoenix/tree/v0.3.46) (2014-10-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.45...v0.3.46)

**Merged pull requests:**

- Updates for Neue 5.1 [\#3155](https://github.com/DoSomething/phoenix/pull/3155) ([DFurnes](https://github.com/DFurnes))

## [v0.3.45](https://github.com/dosomething/phoenix/tree/v0.3.45) (2014-10-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.44...v0.3.45)

**Merged pull requests:**

- COMPUTER SCIENCE [\#3154](https://github.com/DoSomething/phoenix/pull/3154) ([aaronschachter](https://github.com/aaronschachter))
- Zendesk documentation [\#3152](https://github.com/DoSomething/phoenix/pull/3152) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.44](https://github.com/dosomething/phoenix/tree/v0.3.44) (2014-10-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.43...v0.3.44)

**Merged pull requests:**

- Fact Page fixes [\#3151](https://github.com/DoSomething/phoenix/pull/3151) ([aaronschachter](https://github.com/aaronschachter))
- UK SSO: Multiple code style and documentation improvements. [\#3147](https://github.com/DoSomething/phoenix/pull/3147) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.43](https://github.com/dosomething/phoenix/tree/v0.3.43) (2014-10-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.42...v0.3.43)

**Merged pull requests:**

- DS API: Get Member Count [\#3149](https://github.com/DoSomething/phoenix/pull/3149) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.42](https://github.com/dosomething/phoenix/tree/v0.3.42) (2014-10-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.41...v0.3.42)

**Closed issues:**

- \[collections\] - users who sign up for a campaign collection are not receiving an email or being subscribed to mailchimp [\#3144](https://github.com/DoSomething/phoenix/issues/3144)

**Merged pull requests:**

- DS-460 Always round down human readable count [\#3146](https://github.com/DoSomething/phoenix/pull/3146) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.41](https://github.com/dosomething/phoenix/tree/v0.3.41) (2014-10-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.40...v0.3.41)

**Merged pull requests:**

- Readable Member Count [\#3145](https://github.com/DoSomething/phoenix/pull/3145) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.40](https://github.com/dosomething/phoenix/tree/v0.3.40) (2014-10-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.39...v0.3.40)

**Merged pull requests:**

- Member Count Variable / Token [\#3143](https://github.com/DoSomething/phoenix/pull/3143) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.39](https://github.com/dosomething/phoenix/tree/v0.3.39) (2014-10-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.38...v0.3.39)

**Merged pull requests:**

- Remove metatag exports [\#3142](https://github.com/DoSomething/phoenix/pull/3142) ([aaronschachter](https://github.com/aaronschachter))
- School finder front end [\#3135](https://github.com/DoSomething/phoenix/pull/3135) ([DFurnes](https://github.com/DFurnes))

## [v0.3.38](https://github.com/dosomething/phoenix/tree/v0.3.38) (2014-10-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.37...v0.3.38)

**Closed issues:**

- Grant communications team clear cache access [\#3140](https://github.com/DoSomething/phoenix/issues/3140)
- Add revision setting to .make for message\_broker\_producer [\#3126](https://github.com/DoSomething/phoenix/issues/3126)

**Merged pull requests:**

- Clear cache perms to Communication Team [\#3141](https://github.com/DoSomething/phoenix/pull/3141) ([aaronschachter](https://github.com/aaronschachter))
- Enable System set\_variable resource in DS API [\#3139](https://github.com/DoSomething/phoenix/pull/3139) ([aaronschachter](https://github.com/aaronschachter))
- Member count [\#3138](https://github.com/DoSomething/phoenix/pull/3138) ([aaronschachter](https://github.com/aaronschachter))
- UK SSO: Store Postal Code in local database. [\#3137](https://github.com/DoSomething/phoenix/pull/3137) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Add an option to use NFS for Vagrant rather than SSHFS. [\#3136](https://github.com/DoSomething/phoenix/pull/3136) ([DFurnes](https://github.com/DFurnes))

## [v0.3.37](https://github.com/dosomething/phoenix/tree/v0.3.37) (2014-10-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.36...v0.3.37)

**Merged pull requests:**

- Address Administrative Area options variable [\#3134](https://github.com/DoSomething/phoenix/pull/3134) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.36](https://github.com/dosomething/phoenix/tree/v0.3.36) (2014-10-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.35...v0.3.36)

**Merged pull requests:**

- Adds revision setting for message\_broker\_producer [\#3130](https://github.com/DoSomething/phoenix/pull/3130) ([DeeZone](https://github.com/DeeZone))

## [v0.3.35](https://github.com/dosomething/phoenix/tree/v0.3.35) (2014-10-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.34...v0.3.35)

**Merged pull requests:**

- Fix bugs in the redux tests. [\#3131](https://github.com/DoSomething/phoenix/pull/3131) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.34](https://github.com/dosomething/phoenix/tree/v0.3.34) (2014-10-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.33...v0.3.34)

**Closed issues:**

- Testing adding new issues to a Milestone [\#3127](https://github.com/DoSomething/phoenix/issues/3127)

**Merged pull requests:**

- UK SSO: Improve module installation. [\#3129](https://github.com/DoSomething/phoenix/pull/3129) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Campaign Shipment Form [\#3128](https://github.com/DoSomething/phoenix/pull/3128) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.33](https://github.com/dosomething/phoenix/tree/v0.3.33) (2014-10-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.32...v0.3.33)

**Fixed bugs:**

- Search Bug: HTML encoding not recognized in search results [\#3000](https://github.com/DoSomething/phoenix/issues/3000)

**Merged pull requests:**

- UK SSO: Implement administration form. [\#3125](https://github.com/DoSomething/phoenix/pull/3125) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- School Not Affiliated variable [\#3124](https://github.com/DoSomething/phoenix/pull/3124) ([aaronschachter](https://github.com/aaronschachter))
- DS-441 Fixes PHP notices [\#3123](https://github.com/DoSomething/phoenix/pull/3123) ([aaronschachter](https://github.com/aaronschachter))
- Fixes bug in User Profile form [\#3121](https://github.com/DoSomething/phoenix/pull/3121) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.32](https://github.com/dosomething/phoenix/tree/v0.3.32) (2014-09-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.31...v0.3.32)

**Merged pull requests:**

- School dropdown [\#3122](https://github.com/DoSomething/phoenix/pull/3122) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.31](https://github.com/dosomething/phoenix/tree/v0.3.31) (2014-09-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.30...v0.3.31)

**Merged pull requests:**

- Views Data Export [\#3120](https://github.com/DoSomething/phoenix/pull/3120) ([aaronschachter](https://github.com/aaronschachter))
- Fixes sporadic timing-related test failures. [\#3119](https://github.com/DoSomething/phoenix/pull/3119) ([DFurnes](https://github.com/DFurnes))

## [v0.3.30](https://github.com/dosomething/phoenix/tree/v0.3.30) (2014-09-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.29...v0.3.30)

**Closed issues:**

- Include messagebroker-config in site build [\#3102](https://github.com/DoSomething/phoenix/issues/3102)

**Merged pull requests:**

- Fixes Signup Form PHP Notice [\#3118](https://github.com/DoSomething/phoenix/pull/3118) ([aaronschachter](https://github.com/aaronschachter))
- Updates Services contrib module [\#3117](https://github.com/DoSomething/phoenix/pull/3117) ([aaronschachter](https://github.com/aaronschachter))
- Variable for School API endpoint [\#3116](https://github.com/DoSomething/phoenix/pull/3116) ([aaronschachter](https://github.com/aaronschachter))
- Signup Data Form: Collect school [\#3115](https://github.com/DoSomething/phoenix/pull/3115) ([aaronschachter](https://github.com/aaronschachter))
- Adds messagebroker-config to make file [\#3107](https://github.com/DoSomething/phoenix/pull/3107) ([DeeZone](https://github.com/DeeZone))

## [v0.3.29](https://github.com/dosomething/phoenix/tree/v0.3.29) (2014-09-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.28...v0.3.29)

**Merged pull requests:**

- Adds School ID to User [\#3114](https://github.com/DoSomething/phoenix/pull/3114) ([aaronschachter](https://github.com/aaronschachter))
- Bug fix in Signup Data Form for T-shirts [\#3113](https://github.com/DoSomething/phoenix/pull/3113) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.28](https://github.com/dosomething/phoenix/tree/v0.3.28) (2014-09-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.27...v0.3.28)

**Merged pull requests:**

- Campaign Group: Second CTA [\#3112](https://github.com/DoSomething/phoenix/pull/3112) ([aaronschachter](https://github.com/aaronschachter))
- Update failing logged-in signup test based on \#3109 changes. [\#3110](https://github.com/DoSomething/phoenix/pull/3110) ([DFurnes](https://github.com/DFurnes))

## [v0.3.27](https://github.com/dosomething/phoenix/tree/v0.3.27) (2014-09-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.26...v0.3.27)

**Merged pull requests:**

- DS-384 - Drops data column from dosomething\_signup table [\#3105](https://github.com/DoSomething/phoenix/pull/3105) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.26](https://github.com/dosomething/phoenix/tree/v0.3.26) (2014-09-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.25...v0.3.26)

**Merged pull requests:**

- Pitch Page updates [\#3109](https://github.com/DoSomething/phoenix/pull/3109) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.25](https://github.com/dosomething/phoenix/tree/v0.3.25) (2014-09-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.24...v0.3.25)

**Merged pull requests:**

- Test docs and phantomcss bug [\#3108](https://github.com/DoSomething/phoenix/pull/3108) ([DFurnes](https://github.com/DFurnes))
- DS User: Remove mobilecommons permission and dependency [\#3103](https://github.com/DoSomething/phoenix/pull/3103) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.24](https://github.com/dosomething/phoenix/tree/v0.3.24) (2014-09-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.23...v0.3.24)

**Merged pull requests:**

- Make sure to wait for confirmation page to appear. [\#3106](https://github.com/DoSomething/phoenix/pull/3106) ([DFurnes](https://github.com/DFurnes))

## [v0.3.23](https://github.com/dosomething/phoenix/tree/v0.3.23) (2014-09-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.22...v0.3.23)

**Merged pull requests:**

- Fix failing tests [\#3104](https://github.com/DoSomething/phoenix/pull/3104) ([DFurnes](https://github.com/DFurnes))
- User delete quiet [\#3101](https://github.com/DoSomething/phoenix/pull/3101) ([DFurnes](https://github.com/DFurnes))

## [v0.3.22](https://github.com/dosomething/phoenix/tree/v0.3.22) (2014-09-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.21...v0.3.22)

**Merged pull requests:**

- Casper fail screenshots [\#3100](https://github.com/DoSomething/phoenix/pull/3100) ([DFurnes](https://github.com/DFurnes))

## [v0.3.21](https://github.com/dosomething/phoenix/tree/v0.3.21) (2014-09-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.20...v0.3.21)

**Merged pull requests:**

- Fixes CasperJS XUnit output parameter. [\#3099](https://github.com/DoSomething/phoenix/pull/3099) ([DFurnes](https://github.com/DFurnes))

## [v0.3.20](https://github.com/dosomething/phoenix/tree/v0.3.20) (2014-09-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.19...v0.3.20)

**Merged pull requests:**

- Fixes passing override arguments to the test runner. [\#3098](https://github.com/DoSomething/phoenix/pull/3098) ([DFurnes](https://github.com/DFurnes))

## [v0.3.19](https://github.com/dosomething/phoenix/tree/v0.3.19) (2014-09-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.18...v0.3.19)

## [v0.3.18](https://github.com/dosomething/phoenix/tree/v0.3.18) (2014-09-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.17...v0.3.18)

**Merged pull requests:**

- narrowed msg callout width [\#3097](https://github.com/DoSomething/phoenix/pull/3097) ([tjrosario](https://github.com/tjrosario))
- Test redux [\#3096](https://github.com/DoSomething/phoenix/pull/3096) ([DFurnes](https://github.com/DFurnes))
- Provide UK-specific integration tests. [\#3093](https://github.com/DoSomething/phoenix/pull/3093) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Override logo based on dev/staging environment. [\#3092](https://github.com/DoSomething/phoenix/pull/3092) ([DFurnes](https://github.com/DFurnes))

## [v0.3.17](https://github.com/dosomething/phoenix/tree/v0.3.17) (2014-09-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.16...v0.3.17)

**Merged pull requests:**

- Uk form order [\#3091](https://github.com/DoSomething/phoenix/pull/3091) ([DFurnes](https://github.com/DFurnes))
- removing kik api script [\#3090](https://github.com/DoSomething/phoenix/pull/3090) ([tjrosario](https://github.com/tjrosario))

## [v0.3.16](https://github.com/dosomething/phoenix/tree/v0.3.16) (2014-09-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.15...v0.3.16)

**Merged pull requests:**

- Setup the User's Birthday field to accept input in local format. [\#3086](https://github.com/DoSomething/phoenix/pull/3086) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.15](https://github.com/dosomething/phoenix/tree/v0.3.15) (2014-09-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.14...v0.3.15)

**Closed issues:**

- An awesome new readme for this repository [\#3075](https://github.com/DoSomething/phoenix/issues/3075)

**Merged pull requests:**

- Prettier readme. [\#3089](https://github.com/DoSomething/phoenix/pull/3089) ([DFurnes](https://github.com/DFurnes))
- Revert "Revert "Add 'uk\_birthday' validator that accepts DD/MM/YYYY form... [\#3088](https://github.com/DoSomething/phoenix/pull/3088) ([DFurnes](https://github.com/DFurnes))
- Fix app.css compilation by improving bower function in ds script. [\#3087](https://github.com/DoSomething/phoenix/pull/3087) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.14](https://github.com/dosomething/phoenix/tree/v0.3.14) (2014-09-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.13...v0.3.14)

## [v0.3.13](https://github.com/dosomething/phoenix/tree/v0.3.13) (2014-09-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.12...v0.3.13)

## [v0.3.12](https://github.com/dosomething/phoenix/tree/v0.3.12) (2014-09-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.11...v0.3.12)

**Merged pull requests:**

- Revert "Add 'uk\_birthday' validator that accepts DD/MM/YYYY format." [\#3085](https://github.com/DoSomething/phoenix/pull/3085) ([DFurnes](https://github.com/DFurnes))
- Add 'uk\_birthday' validator that accepts DD/MM/YYYY format. [\#3084](https://github.com/DoSomething/phoenix/pull/3084) ([DFurnes](https://github.com/DFurnes))
- Fix Mocha XUnit test output. [\#3079](https://github.com/DoSomething/phoenix/pull/3079) ([DFurnes](https://github.com/DFurnes))

## [v0.3.11](https://github.com/dosomething/phoenix/tree/v0.3.11) (2014-09-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.10...v0.3.11)

**Merged pull requests:**

- DS-401: CrowdCurity [\#3083](https://github.com/DoSomething/phoenix/pull/3083) ([mshmsh5000](https://github.com/mshmsh5000))
- Redis Client: Use builtin class loader. [\#3082](https://github.com/DoSomething/phoenix/pull/3082) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fixes automatic signups from pitch page. [\#3081](https://github.com/DoSomething/phoenix/pull/3081) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Fix Predis libraries autoload. [\#3080](https://github.com/DoSomething/phoenix/pull/3080) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.3.10](https://github.com/dosomething/phoenix/tree/v0.3.10) (2014-09-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.9...v0.3.10)

**Merged pull requests:**

- DS-389 Adds signup source to reportback confirmation links [\#3078](https://github.com/DoSomething/phoenix/pull/3078) ([aaronschachter](https://github.com/aaronschachter))
- Adds MIT license [\#3074](https://github.com/DoSomething/phoenix/pull/3074) ([mshmsh5000](https://github.com/mshmsh5000))
- Neue 5.x [\#3072](https://github.com/DoSomething/phoenix/pull/3072) ([DFurnes](https://github.com/DFurnes))

## [v0.3.9](https://github.com/dosomething/phoenix/tree/v0.3.9) (2014-09-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.8...v0.3.9)

**Merged pull requests:**

- Adds Source to signups view [\#3077](https://github.com/DoSomething/phoenix/pull/3077) ([aaronschachter](https://github.com/aaronschachter))
- Signup source [\#3076](https://github.com/DoSomething/phoenix/pull/3076) ([aaronschachter](https://github.com/aaronschachter))
- DS-71: Removes all Salt provisioning code [\#3067](https://github.com/DoSomething/phoenix/pull/3067) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.3.8](https://github.com/dosomething/phoenix/tree/v0.3.8) (2014-09-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.7...v0.3.8)

**Merged pull requests:**

- DS-386 Apply register\_form alters to user\_register\_form only [\#3073](https://github.com/DoSomething/phoenix/pull/3073) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.7](https://github.com/dosomething/phoenix/tree/v0.3.7) (2014-09-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.6...v0.3.7)

**Merged pull requests:**

- User registration signup hotfix [\#3070](https://github.com/DoSomething/phoenix/pull/3070) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.6](https://github.com/dosomething/phoenix/tree/v0.3.6) (2014-09-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.5...v0.3.6)

**Merged pull requests:**

- Campaign Group cleanup [\#3069](https://github.com/DoSomething/phoenix/pull/3069) ([aaronschachter](https://github.com/aaronschachter))
- DS-360 Use site logo as metatag default for non-campaign pages [\#3068](https://github.com/DoSomething/phoenix/pull/3068) ([aaronschachter](https://github.com/aaronschachter))

## [v0.3.5](https://github.com/dosomething/phoenix/tree/v0.3.5) (2014-09-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.4...v0.3.5)

**Merged pull requests:**

- UK SSO: Map SSO `phone\_number` field to the local `phone\_number`. [\#3066](https://github.com/DoSomething/phoenix/pull/3066) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Campaign Collection: Dynamic parent signup [\#3065](https://github.com/DoSomething/phoenix/pull/3065) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Collections [\#3064](https://github.com/DoSomething/phoenix/pull/3064) ([aaronschachter](https://github.com/aaronschachter))
- adds kik meta data for campaign pages [\#3063](https://github.com/DoSomething/phoenix/pull/3063) ([tjrosario](https://github.com/tjrosario))
- DS-329 Output profile subtitle [\#3062](https://github.com/DoSomething/phoenix/pull/3062) ([aaronschachter](https://github.com/aaronschachter))
- Profile variables [\#3061](https://github.com/DoSomething/phoenix/pull/3061) ([aaronschachter](https://github.com/aaronschachter))
- UK SSO: Remove hardcoded postcode, populate SSO with real user value. [\#3060](https://github.com/DoSomething/phoenix/pull/3060) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- UK SSO: Map SSO `contactable` field to the local `field\_opt\_in\_email`. [\#3059](https://github.com/DoSomething/phoenix/pull/3059) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Style cleanup [\#3058](https://github.com/DoSomething/phoenix/pull/3058) ([DFurnes](https://github.com/DFurnes))
- Registration Form: Display Postal Code config [\#3057](https://github.com/DoSomething/phoenix/pull/3057) ([aaronschachter](https://github.com/aaronschachter))
- Last Name Registration Form  \(UK\) [\#3056](https://github.com/DoSomething/phoenix/pull/3056) ([aaronschachter](https://github.com/aaronschachter))
- Version banner [\#3055](https://github.com/DoSomething/phoenix/pull/3055) ([DFurnes](https://github.com/DFurnes))

## [v0.3.4](https://github.com/dosomething/phoenix/tree/v0.3.4) (2014-09-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.3...v0.3.4)

**Merged pull requests:**

- User Opt In Fields [\#3054](https://github.com/DoSomething/phoenix/pull/3054) ([aaronschachter](https://github.com/aaronschachter))
- DS-354 Login subheader styles [\#3053](https://github.com/DoSomething/phoenix/pull/3053) ([DFurnes](https://github.com/DFurnes))

## [v0.3.3](https://github.com/dosomething/phoenix/tree/v0.3.3) (2014-09-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.2...v0.3.3)

**Merged pull requests:**

- UK Login Form copy [\#3052](https://github.com/DoSomething/phoenix/pull/3052) ([aaronschachter](https://github.com/aaronschachter))
- User Login: Display Forgot Password variable [\#3051](https://github.com/DoSomething/phoenix/pull/3051) ([aaronschachter](https://github.com/aaronschachter))
- Neue 4.5 [\#3049](https://github.com/DoSomething/phoenix/pull/3049) ([DFurnes](https://github.com/DFurnes))

## [v0.3.2](https://github.com/dosomething/phoenix/tree/v0.3.2) (2014-09-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.1...v0.3.2)

**Merged pull requests:**

- Login Form copy variable [\#3050](https://github.com/DoSomething/phoenix/pull/3050) ([aaronschachter](https://github.com/aaronschachter))
- DRY for Terms/Privacy variable links [\#3048](https://github.com/DoSomething/phoenix/pull/3048) ([aaronschachter](https://github.com/aaronschachter))
- Add Privacy Policy link to Registration legal copy [\#3047](https://github.com/DoSomething/phoenix/pull/3047) ([aaronschachter](https://github.com/aaronschachter))
- showing h1 at all breakpoints and hiding h2 at mobile breakpoint on home... [\#3046](https://github.com/DoSomething/phoenix/pull/3046) ([tjrosario](https://github.com/tjrosario))

## [v0.3.1](https://github.com/dosomething/phoenix/tree/v0.3.1) (2014-09-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.3.0...v0.3.1)

**Merged pull requests:**

- Register form translations [\#3045](https://github.com/DoSomething/phoenix/pull/3045) ([aaronschachter](https://github.com/aaronschachter))
- Remove Grunt test task \(now handled by ds utility\). [\#3044](https://github.com/DoSomething/phoenix/pull/3044) ([DFurnes](https://github.com/DFurnes))

## [v0.3.0](https://github.com/dosomething/phoenix/tree/v0.3.0) (2014-09-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.237...v0.3.0)

**Merged pull requests:**

- API updates \(Signup and Reportback\) [\#3035](https://github.com/DoSomething/phoenix/pull/3035) ([aaronschachter](https://github.com/aaronschachter))
- Fix @self alias. [\#3021](https://github.com/DoSomething/phoenix/pull/3021) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.237](https://github.com/dosomething/phoenix/tree/v0.2.237) (2014-09-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.236...v0.2.237)

**Merged pull requests:**

- Ds 327 canada user register hook [\#3043](https://github.com/DoSomething/phoenix/pull/3043) ([mshmsh5000](https://github.com/mshmsh5000))
- DS-326: Fixes bad Exception instantiation [\#3042](https://github.com/DoSomething/phoenix/pull/3042) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.2.236](https://github.com/dosomething/phoenix/tree/v0.2.236) (2014-09-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.235...v0.2.236)

**Merged pull requests:**

- Clear Asset Path theme setting after pulling from stage. [\#3041](https://github.com/DoSomething/phoenix/pull/3041) ([DFurnes](https://github.com/DFurnes))
- added feature modifier to the mosiac galleries in campaign grouped template [\#3039](https://github.com/DoSomething/phoenix/pull/3039) ([tjrosario](https://github.com/tjrosario))

## [v0.2.235](https://github.com/dosomething/phoenix/tree/v0.2.235) (2014-09-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.234...v0.2.235)

**Merged pull requests:**

- United Kingdom: Push new user registrations to vInspired SSO. [\#3040](https://github.com/DoSomething/phoenix/pull/3040) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- DS-303 Update validation to accept any country code & spacing. [\#3037](https://github.com/DoSomething/phoenix/pull/3037) ([DFurnes](https://github.com/DFurnes))
- Users endpoint - Check for existing email [\#3034](https://github.com/DoSomething/phoenix/pull/3034) ([aaronschachter](https://github.com/aaronschachter))
- DS-291 Canada user API integration [\#3032](https://github.com/DoSomething/phoenix/pull/3032) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.2.234](https://github.com/dosomething/phoenix/tree/v0.2.234) (2014-09-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.233...v0.2.234)

**Merged pull requests:**

- Remove Message Broker modules from Dosomething.info [\#3038](https://github.com/DoSomething/phoenix/pull/3038) ([aaronschachter](https://github.com/aaronschachter))
- Add some better logging for Drush actions. [\#3036](https://github.com/DoSomething/phoenix/pull/3036) ([DFurnes](https://github.com/DFurnes))
- Drush helpers for CasperJS [\#3033](https://github.com/DoSomething/phoenix/pull/3033) ([DFurnes](https://github.com/DFurnes))

## [v0.2.233](https://github.com/dosomething/phoenix/tree/v0.2.233) (2014-08-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.232...v0.2.233)

**Merged pull requests:**

- United Kingdom: Authenticate users with vInspired SSO. [\#3031](https://github.com/DoSomething/phoenix/pull/3031) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Adds client-side unit testing to DS utility. [\#3028](https://github.com/DoSomething/phoenix/pull/3028) ([DFurnes](https://github.com/DFurnes))

## [v0.2.232](https://github.com/dosomething/phoenix/tree/v0.2.232) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.231...v0.2.232)

**Merged pull requests:**

- changed preset to 300x300 [\#3030](https://github.com/DoSomething/phoenix/pull/3030) ([tjrosario](https://github.com/tjrosario))

## [v0.2.231](https://github.com/dosomething/phoenix/tree/v0.2.231) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.230...v0.2.231)

**Merged pull requests:**

- design qa [\#3029](https://github.com/DoSomething/phoenix/pull/3029) ([tjrosario](https://github.com/tjrosario))

## [v0.2.230](https://github.com/dosomething/phoenix/tree/v0.2.230) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.229...v0.2.230)

**Merged pull requests:**

- Removes campaign cache data collection for MB [\#3014](https://github.com/DoSomething/phoenix/pull/3014) ([DeeZone](https://github.com/DeeZone))

## [v0.2.229](https://github.com/dosomething/phoenix/tree/v0.2.229) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.228...v0.2.229)

**Merged pull requests:**

- Removing capistrano deployment files [\#2984](https://github.com/DoSomething/phoenix/pull/2984) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.228](https://github.com/dosomething/phoenix/tree/v0.2.228) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.227...v0.2.228)

**Merged pull requests:**

- Remove unused SMS Game code [\#3023](https://github.com/DoSomething/phoenix/pull/3023) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.227](https://github.com/dosomething/phoenix/tree/v0.2.227) (2014-08-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.226...v0.2.227)

**Merged pull requests:**

- Don't recommend closed campaigns [\#3027](https://github.com/DoSomething/phoenix/pull/3027) ([aaronschachter](https://github.com/aaronschachter))
- Makes paraneue login.inc file translatable [\#3026](https://github.com/DoSomething/phoenix/pull/3026) ([aaronschachter](https://github.com/aaronschachter))
- Fixes bug in Signup Data Form Shirt collector [\#3025](https://github.com/DoSomething/phoenix/pull/3025) ([aaronschachter](https://github.com/aaronschachter))
- Increase visual test failure threshold to 2% difference. [\#3019](https://github.com/DoSomething/phoenix/pull/3019) ([DFurnes](https://github.com/DFurnes))

## [v0.2.226](https://github.com/dosomething/phoenix/tree/v0.2.226) (2014-08-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.225...v0.2.226)

**Merged pull requests:**

- Shirt size variable [\#3024](https://github.com/DoSomething/phoenix/pull/3024) ([aaronschachter](https://github.com/aaronschachter))
- Moves DS Campaign documentation to GH wiki [\#3022](https://github.com/DoSomething/phoenix/pull/3022) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.225](https://github.com/dosomething/phoenix/tree/v0.2.225) (2014-08-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.224...v0.2.225)

**Merged pull requests:**

- Fix ds pull stage: force "yes". [\#3020](https://github.com/DoSomething/phoenix/pull/3020) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Confirmation Page path change [\#3018](https://github.com/DoSomething/phoenix/pull/3018) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.224](https://github.com/dosomething/phoenix/tree/v0.2.224) (2014-08-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.223...v0.2.224)

**Merged pull requests:**

- Tshirt style mods [\#3017](https://github.com/DoSomething/phoenix/pull/3017) ([tjrosario](https://github.com/tjrosario))

## [v0.2.223](https://github.com/dosomething/phoenix/tree/v0.2.223) (2014-08-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.222...v0.2.223)

**Merged pull requests:**

- New campaign fields [\#3016](https://github.com/DoSomething/phoenix/pull/3016) ([aaronschachter](https://github.com/aaronschachter))
- added support for IE8 for shirt style options [\#3015](https://github.com/DoSomething/phoenix/pull/3015) ([tjrosario](https://github.com/tjrosario))

## [v0.2.222](https://github.com/dosomething/phoenix/tree/v0.2.222) (2014-08-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.221...v0.2.222)

**Merged pull requests:**

- added support to select any default checked radios [\#3013](https://github.com/DoSomething/phoenix/pull/3013) ([tjrosario](https://github.com/tjrosario))
- Refactoring ds build script for multisite deployments [\#2809](https://github.com/DoSomething/phoenix/pull/2809) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.221](https://github.com/dosomething/phoenix/tree/v0.2.221) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.220...v0.2.221)

**Merged pull requests:**

- Adds contrib POTX module [\#3012](https://github.com/DoSomething/phoenix/pull/3012) ([aaronschachter](https://github.com/aaronschachter))
- Set Dope shirt as default [\#3011](https://github.com/DoSomething/phoenix/pull/3011) ([aaronschachter](https://github.com/aaronschachter))
- removed clear on every 3rd gallery item [\#3010](https://github.com/DoSomething/phoenix/pull/3010) ([tjrosario](https://github.com/tjrosario))

## [v0.2.220](https://github.com/dosomething/phoenix/tree/v0.2.220) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.219...v0.2.220)

**Merged pull requests:**

- DS-265 Fix issue where form validation was not showing up on T-Shirt form. [\#3009](https://github.com/DoSomething/phoenix/pull/3009) ([DFurnes](https://github.com/DFurnes))
- updated selected state to 4px border radius [\#3008](https://github.com/DoSomething/phoenix/pull/3008) ([tjrosario](https://github.com/tjrosario))
- Pass those tests! [\#3005](https://github.com/DoSomething/phoenix/pull/3005) ([DFurnes](https://github.com/DFurnes))
- Create shipment on Signup Data Form submit [\#2997](https://github.com/DoSomething/phoenix/pull/2997) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.219](https://github.com/dosomething/phoenix/tree/v0.2.219) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.218...v0.2.219)

**Merged pull requests:**

- Redeem Page: Allow blank variables for subtitle and page header [\#3007](https://github.com/DoSomething/phoenix/pull/3007) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.218](https://github.com/dosomething/phoenix/tree/v0.2.218) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.217...v0.2.218)

**Merged pull requests:**

- fixed landscape dimensions [\#3006](https://github.com/DoSomething/phoenix/pull/3006) ([tjrosario](https://github.com/tjrosario))
- updated subtitle var [\#3004](https://github.com/DoSomething/phoenix/pull/3004) ([tjrosario](https://github.com/tjrosario))

## [v0.2.217](https://github.com/dosomething/phoenix/tree/v0.2.217) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.216...v0.2.217)

**Merged pull requests:**

- form validation for shirt fields [\#3003](https://github.com/DoSomething/phoenix/pull/3003) ([tjrosario](https://github.com/tjrosario))

## [v0.2.216](https://github.com/dosomething/phoenix/tree/v0.2.216) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.215...v0.2.216)

**Merged pull requests:**

- new branch commit for tshirt redeem [\#3002](https://github.com/DoSomething/phoenix/pull/3002) ([tjrosario](https://github.com/tjrosario))

## [v0.2.215](https://github.com/dosomething/phoenix/tree/v0.2.215) (2014-08-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.214...v0.2.215)

**Merged pull requests:**

- DS-262 Allow repeating fives in phone numbers. [\#2999](https://github.com/DoSomething/phoenix/pull/2999) ([DFurnes](https://github.com/DFurnes))
- Remove Reportback Field tables and code [\#2998](https://github.com/DoSomething/phoenix/pull/2998) ([aaronschachter](https://github.com/aaronschachter))
- Signup Data Form - Shipment Item [\#2995](https://github.com/DoSomething/phoenix/pull/2995) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.214](https://github.com/dosomething/phoenix/tree/v0.2.214) (2014-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.213...v0.2.214)

**Merged pull requests:**

- Reward Edit form [\#2993](https://github.com/DoSomething/phoenix/pull/2993) ([aaronschachter](https://github.com/aaronschachter))
- Clears QA IP address from flood table before running tests. [\#2992](https://github.com/DoSomething/phoenix/pull/2992) ([DFurnes](https://github.com/DFurnes))

## [v0.2.213](https://github.com/dosomething/phoenix/tree/v0.2.213) (2014-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.212...v0.2.213)

**Merged pull requests:**

- Fixes PHP notices [\#2991](https://github.com/DoSomething/phoenix/pull/2991) ([aaronschachter](https://github.com/aaronschachter))
- Move Signup documentation to the wiki [\#2990](https://github.com/DoSomething/phoenix/pull/2990) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.212](https://github.com/dosomething/phoenix/tree/v0.2.212) (2014-08-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.211...v0.2.212)

**Merged pull requests:**

- Clean Slate form [\#2989](https://github.com/DoSomething/phoenix/pull/2989) ([aaronschachter](https://github.com/aaronschachter))
- Test tweaks [\#2988](https://github.com/DoSomething/phoenix/pull/2988) ([DFurnes](https://github.com/DFurnes))
- Re-organize test directory. [\#2987](https://github.com/DoSomething/phoenix/pull/2987) ([DFurnes](https://github.com/DFurnes))

## [v0.2.211](https://github.com/dosomething/phoenix/tree/v0.2.211) (2014-08-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.210...v0.2.211)

**Merged pull requests:**

- Fixes Reward Form address validation [\#2986](https://github.com/DoSomething/phoenix/pull/2986) ([aaronschachter](https://github.com/aaronschachter))
- Fix errors on Reportback Delete form. [\#2985](https://github.com/DoSomething/phoenix/pull/2985) ([aaronschachter](https://github.com/aaronschachter))
- Use campaign fixture for automated tests. [\#2982](https://github.com/DoSomething/phoenix/pull/2982) ([DFurnes](https://github.com/DFurnes))

## [v0.2.210](https://github.com/dosomething/phoenix/tree/v0.2.210) (2014-08-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.209...v0.2.210)

**Merged pull requests:**

- Reward page / form template [\#2983](https://github.com/DoSomething/phoenix/pull/2983) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.209](https://github.com/dosomething/phoenix/tree/v0.2.209) (2014-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.208...v0.2.209)

**Merged pull requests:**

- Updated image style for 3col galleries. [\#2980](https://github.com/DoSomething/phoenix/pull/2980) ([angaither](https://github.com/angaither))
- Added cache for dosomething\_reportback table. [\#2979](https://github.com/DoSomething/phoenix/pull/2979) ([angaither](https://github.com/angaither))

## [v0.2.208](https://github.com/dosomething/phoenix/tree/v0.2.208) (2014-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.207...v0.2.208)

## [v0.2.207](https://github.com/dosomething/phoenix/tree/v0.2.207) (2014-08-18)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.206...v0.2.207)

**Merged pull requests:**

- Grant rights to Administrator and Editor to the translation interface. [\#2981](https://github.com/DoSomething/phoenix/pull/2981) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.206](https://github.com/dosomething/phoenix/tree/v0.2.206) (2014-08-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.205...v0.2.206)

**Merged pull requests:**

- updated gallery markup to match new pattern [\#2978](https://github.com/DoSomething/phoenix/pull/2978) ([tjrosario](https://github.com/tjrosario))
- Added an index to the nid table on dosomething-signup [\#2977](https://github.com/DoSomething/phoenix/pull/2977) ([angaither](https://github.com/angaither))

## [v0.2.205](https://github.com/dosomething/phoenix/tree/v0.2.205) (2014-08-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.204...v0.2.205)

**Merged pull requests:**

- Exports campaigns resource [\#2975](https://github.com/DoSomething/phoenix/pull/2975) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.204](https://github.com/dosomething/phoenix/tree/v0.2.204) (2014-08-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.203...v0.2.204)

**Merged pull requests:**

- Campaigns index endpoint [\#2974](https://github.com/DoSomething/phoenix/pull/2974) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.203](https://github.com/dosomething/phoenix/tree/v0.2.203) (2014-08-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.202...v0.2.203)

**Merged pull requests:**

- DoSomething API [\#2973](https://github.com/DoSomething/phoenix/pull/2973) ([aaronschachter](https://github.com/aaronschachter))
- moved duo gallery to be global [\#2972](https://github.com/DoSomething/phoenix/pull/2972) ([tjrosario](https://github.com/tjrosario))

## [v0.2.202](https://github.com/dosomething/phoenix/tree/v0.2.202) (2014-08-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.201...v0.2.202)

**Merged pull requests:**

- Shipment item and additional\_item properties [\#2971](https://github.com/DoSomething/phoenix/pull/2971) ([aaronschachter](https://github.com/aaronschachter))
- Added indicies to reportback tables for faster views. [\#2970](https://github.com/DoSomething/phoenix/pull/2970) ([angaither](https://github.com/angaither))
- Test cleanup [\#2957](https://github.com/DoSomething/phoenix/pull/2957) ([DFurnes](https://github.com/DFurnes))
- Using protocol-relative url for solr finder [\#2953](https://github.com/DoSomething/phoenix/pull/2953) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.201](https://github.com/dosomething/phoenix/tree/v0.2.201) (2014-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.200...v0.2.201)

**Merged pull requests:**

- Multi-player SMS Game signup [\#2969](https://github.com/DoSomething/phoenix/pull/2969) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.200](https://github.com/dosomething/phoenix/tree/v0.2.200) (2014-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.199...v0.2.200)

**Merged pull requests:**

- Use the slave server for reportback view queries. [\#2968](https://github.com/DoSomething/phoenix/pull/2968) ([angaither](https://github.com/angaither))
- Fixed 'to-do' item in birthday validation [\#2967](https://github.com/DoSomething/phoenix/pull/2967) ([deadlybutter](https://github.com/deadlybutter))

## [v0.2.199](https://github.com/dosomething/phoenix/tree/v0.2.199) (2014-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.198...v0.2.199)

**Merged pull requests:**

- Fixed weird bug with Plan It section when action guides are added. It wa... [\#2966](https://github.com/DoSomething/phoenix/pull/2966) ([weerd](https://github.com/weerd))

## [v0.2.198](https://github.com/dosomething/phoenix/tree/v0.2.198) (2014-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.197...v0.2.198)

**Merged pull requests:**

- Removing the  var from campaign thumbnail template since we don't use it... [\#2965](https://github.com/DoSomething/phoenix/pull/2965) ([weerd](https://github.com/weerd))

## [v0.2.197](https://github.com/dosomething/phoenix/tree/v0.2.197) (2014-08-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.196...v0.2.197)

**Merged pull requests:**

- Fixing translation error on SMS link that happened during global site tr... [\#2964](https://github.com/DoSomething/phoenix/pull/2964) ([weerd](https://github.com/weerd))
- New SMS Game variables [\#2963](https://github.com/DoSomething/phoenix/pull/2963) ([aaronschachter](https://github.com/aaronschachter))
- Reward logging [\#2962](https://github.com/DoSomething/phoenix/pull/2962) ([aaronschachter](https://github.com/aaronschachter))
- Fix ds pull stage: force "yes" on files override dialog. [\#2961](https://github.com/DoSomething/phoenix/pull/2961) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Remove user email vars from exported variables. [\#2960](https://github.com/DoSomething/phoenix/pull/2960) ([angaither](https://github.com/angaither))

## [v0.2.196](https://github.com/dosomething/phoenix/tree/v0.2.196) (2014-08-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.195...v0.2.196)

**Merged pull requests:**

- Reward Delete form [\#2959](https://github.com/DoSomething/phoenix/pull/2959) ([aaronschachter](https://github.com/aaronschachter))
- DS User Address Form element [\#2958](https://github.com/DoSomething/phoenix/pull/2958) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.195](https://github.com/dosomething/phoenix/tree/v0.2.195) (2014-08-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.194...v0.2.195)

**Merged pull requests:**

- DoSomething Shipment [\#2956](https://github.com/DoSomething/phoenix/pull/2956) ([aaronschachter](https://github.com/aaronschachter))
- Reward Redeem Form [\#2955](https://github.com/DoSomething/phoenix/pull/2955) ([aaronschachter](https://github.com/aaronschachter))
- Rewards admin view [\#2954](https://github.com/DoSomething/phoenix/pull/2954) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.194](https://github.com/dosomething/phoenix/tree/v0.2.194) (2014-08-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.193...v0.2.194)

**Merged pull requests:**

- Reportback Count Reward [\#2947](https://github.com/DoSomething/phoenix/pull/2947) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.193](https://github.com/dosomething/phoenix/tree/v0.2.193) (2014-08-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.192...v0.2.193)

**Merged pull requests:**

- Adds CDN contrib module to installation profile [\#2952](https://github.com/DoSomething/phoenix/pull/2952) ([aaronschachter](https://github.com/aaronschachter))
- Added reportback and signup global header view totals [\#2951](https://github.com/DoSomething/phoenix/pull/2951) ([angaither](https://github.com/angaither))

## [v0.2.192](https://github.com/dosomething/phoenix/tree/v0.2.192) (2014-08-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.191...v0.2.192)

**Closed issues:**

- \[Critical\] Drupal core vulnerability — Access bypass, Cross-site scripting [\#2839](https://github.com/DoSomething/phoenix/issues/2839)

**Merged pull requests:**

- Contrib security updates [\#2950](https://github.com/DoSomething/phoenix/pull/2950) ([aaronschachter](https://github.com/aaronschachter))
- Fix PHP notice for Undefined num\_participants property  [\#2949](https://github.com/DoSomething/phoenix/pull/2949) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.191](https://github.com/dosomething/phoenix/tree/v0.2.191) (2014-08-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.190...v0.2.191)

**Merged pull requests:**

- Core upgrade [\#2948](https://github.com/DoSomething/phoenix/pull/2948) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.190](https://github.com/dosomething/phoenix/tree/v0.2.190) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.189...v0.2.190)

## [v0.2.189](https://github.com/dosomething/phoenix/tree/v0.2.189) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.188...v0.2.189)

**Merged pull requests:**

- RequireJS bundles [\#2942](https://github.com/DoSomething/phoenix/pull/2942) ([DFurnes](https://github.com/DFurnes))

## [v0.2.188](https://github.com/dosomething/phoenix/tree/v0.2.188) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.187...v0.2.188)

**Merged pull requests:**

- Dosomething Reward module [\#2946](https://github.com/DoSomething/phoenix/pull/2946) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.187](https://github.com/dosomething/phoenix/tree/v0.2.187) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.186...v0.2.187)

**Merged pull requests:**

- Adds Latest News Copy field into Campaign class [\#2945](https://github.com/DoSomething/phoenix/pull/2945) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.186](https://github.com/dosomething/phoenix/tree/v0.2.186) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.185...v0.2.186)

**Merged pull requests:**

- New campaign field for Latest News [\#2944](https://github.com/DoSomething/phoenix/pull/2944) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.185](https://github.com/dosomething/phoenix/tree/v0.2.185) (2014-08-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.184...v0.2.185)

**Merged pull requests:**

- Reportback form: Number of participants variable [\#2943](https://github.com/DoSomething/phoenix/pull/2943) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.184](https://github.com/dosomething/phoenix/tree/v0.2.184) (2014-08-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.183...v0.2.184)

**Merged pull requests:**

- show gallery description regardless of title being set [\#2941](https://github.com/DoSomething/phoenix/pull/2941) ([tjrosario](https://github.com/tjrosario))

## [v0.2.183](https://github.com/dosomething/phoenix/tree/v0.2.183) (2014-08-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.182...v0.2.183)

**Merged pull requests:**

- Only load campaign stats for API requests [\#2940](https://github.com/DoSomething/phoenix/pull/2940) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.182](https://github.com/dosomething/phoenix/tree/v0.2.182) (2014-08-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.181...v0.2.182)

**Merged pull requests:**

- File proxy update [\#2939](https://github.com/DoSomething/phoenix/pull/2939) ([aaronschachter](https://github.com/aaronschachter))
- DoSomething modules i18n: wrap hardcoded strings into t\(\). [\#2938](https://github.com/DoSomething/phoenix/pull/2938) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Vagrant solr [\#2895](https://github.com/DoSomething/phoenix/pull/2895) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.181](https://github.com/dosomething/phoenix/tree/v0.2.181) (2014-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.180...v0.2.181)

**Merged pull requests:**

- Removing comma in array [\#2937](https://github.com/DoSomething/phoenix/pull/2937) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.180](https://github.com/dosomething/phoenix/tree/v0.2.180) (2014-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.179...v0.2.180)

**Merged pull requests:**

- Adding beta web2 server to prod deployment [\#2936](https://github.com/DoSomething/phoenix/pull/2936) ([blisteringherb](https://github.com/blisteringherb))
- Adding active hours as an indexed field for campaigns [\#2931](https://github.com/DoSomething/phoenix/pull/2931) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.179](https://github.com/dosomething/phoenix/tree/v0.2.179) (2014-08-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.178...v0.2.179)

**Closed issues:**

- Technical Debt: refactor logo overriding. [\#2827](https://github.com/DoSomething/phoenix/issues/2827)

**Merged pull requests:**

- Drupalize the logo-override. Add in default logo. [\#2926](https://github.com/DoSomething/phoenix/pull/2926) ([angaither](https://github.com/angaither))

## [v0.2.178](https://github.com/dosomething/phoenix/tree/v0.2.178) (2014-08-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.177...v0.2.178)

**Merged pull requests:**

- Fixes DOS-147: Latest version of Predis library missing 'lib' directory [\#2935](https://github.com/DoSomething/phoenix/pull/2935) ([mshmsh5000](https://github.com/mshmsh5000))

## [v0.2.177](https://github.com/dosomething/phoenix/tree/v0.2.177) (2014-08-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.176...v0.2.177)

**Merged pull requests:**

- Parent opt in [\#2933](https://github.com/DoSomething/phoenix/pull/2933) ([aaronschachter](https://github.com/aaronschachter))
- Updating number validation in reportbacks to not allow 0. [\#2932](https://github.com/DoSomething/phoenix/pull/2932) ([weerd](https://github.com/weerd))
- Adding action description  link. [\#2929](https://github.com/DoSomething/phoenix/pull/2929) ([weerd](https://github.com/weerd))
- DoSomething js i18n: wrap hardcoded strings into Drupal.t\(\). [\#2928](https://github.com/DoSomething/phoenix/pull/2928) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.176](https://github.com/dosomething/phoenix/tree/v0.2.176) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.175...v0.2.176)

**Merged pull requests:**

- Joining bubble query with AND [\#2927](https://github.com/DoSomething/phoenix/pull/2927) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.175](https://github.com/dosomething/phoenix/tree/v0.2.175) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.174...v0.2.175)

**Merged pull requests:**

- Fixing bubble query to respect queried field in filter [\#2924](https://github.com/DoSomething/phoenix/pull/2924) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.174](https://github.com/dosomething/phoenix/tree/v0.2.174) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.173...v0.2.174)

**Merged pull requests:**

- Mcc  form update [\#2925](https://github.com/DoSomething/phoenix/pull/2925) ([weerd](https://github.com/weerd))

## [v0.2.173](https://github.com/dosomething/phoenix/tree/v0.2.173) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.172...v0.2.173)

**Merged pull requests:**

- Reportback form: Number of participants [\#2923](https://github.com/DoSomething/phoenix/pull/2923) ([aaronschachter](https://github.com/aaronschachter))
- Set the title of unpublished campaigns in a group to 'Stay Tuned' [\#2922](https://github.com/DoSomething/phoenix/pull/2922) ([angaither](https://github.com/angaither))
- Include app.js using Drupal API so it supports Drupal.t\(\). [\#2918](https://github.com/DoSomething/phoenix/pull/2918) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.172](https://github.com/dosomething/phoenix/tree/v0.2.172) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.171...v0.2.172)

**Merged pull requests:**

- Remove non-features-exported hook\_ctools\_plugin\_api [\#2921](https://github.com/DoSomething/phoenix/pull/2921) ([aaronschachter](https://github.com/aaronschachter))
- Temporary fix for JS issues on staging. [\#2920](https://github.com/DoSomething/phoenix/pull/2920) ([DFurnes](https://github.com/DFurnes))
- Communications team permissions [\#2919](https://github.com/DoSomething/phoenix/pull/2919) ([aaronschachter](https://github.com/aaronschachter))
- Updates to tweak some layout issues with the new promotions approach in ... [\#2914](https://github.com/DoSomething/phoenix/pull/2914) ([weerd](https://github.com/weerd))
- Added 'explore campaigns' to editable menu text. [\#2913](https://github.com/DoSomething/phoenix/pull/2913) ([angaither](https://github.com/angaither))

## [v0.2.171](https://github.com/dosomething/phoenix/tree/v0.2.171) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.170...v0.2.171)

**Merged pull requests:**

- Adds num\_participants field to Reportback table [\#2917](https://github.com/DoSomething/phoenix/pull/2917) ([aaronschachter](https://github.com/aaronschachter))
- Workflow Form [\#2916](https://github.com/DoSomething/phoenix/pull/2916) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.170](https://github.com/dosomething/phoenix/tree/v0.2.170) (2014-07-31)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.169...v0.2.170)

**Merged pull requests:**

- Adding a new bubble factor field and improving Finder results [\#2909](https://github.com/DoSomething/phoenix/pull/2909) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.169](https://github.com/dosomething/phoenix/tree/v0.2.169) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.168...v0.2.169)

**Merged pull requests:**

- SMS Worfklow debugging [\#2915](https://github.com/DoSomething/phoenix/pull/2915) ([aaronschachter](https://github.com/aaronschachter))
- More form fixing [\#2912](https://github.com/DoSomething/phoenix/pull/2912) ([aaronschachter](https://github.com/aaronschachter))
- Only display zenddesk form on ds.org, not on affiliate sites. [\#2911](https://github.com/DoSomething/phoenix/pull/2911) ([angaither](https://github.com/angaither))
- SMS Workflow form cleanup [\#2910](https://github.com/DoSomething/phoenix/pull/2910) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.168](https://github.com/dosomething/phoenix/tree/v0.2.168) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.167...v0.2.168)

**Merged pull requests:**

- Dynamic workflow [\#2908](https://github.com/DoSomething/phoenix/pull/2908) ([aaronschachter](https://github.com/aaronschachter))
- Add field collections via campaign JSON. [\#2907](https://github.com/DoSomething/phoenix/pull/2907) ([DFurnes](https://github.com/DFurnes))

## [v0.2.167](https://github.com/dosomething/phoenix/tree/v0.2.167) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.166...v0.2.167)

**Merged pull requests:**

- Sms Workflow entity [\#2906](https://github.com/DoSomething/phoenix/pull/2906) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.166](https://github.com/dosomething/phoenix/tree/v0.2.166) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.165...v0.2.166)

**Merged pull requests:**

- Updated report back opt in IDs [\#2905](https://github.com/DoSomething/phoenix/pull/2905) ([DeeZone](https://github.com/DeeZone))

## [v0.2.165](https://github.com/dosomething/phoenix/tree/v0.2.165) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.164...v0.2.165)

## [v0.2.164](https://github.com/dosomething/phoenix/tree/v0.2.164) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.163...v0.2.164)

**Merged pull requests:**

- Adding some style defaults for the creator modal. [\#2904](https://github.com/DoSomething/phoenix/pull/2904) ([weerd](https://github.com/weerd))

## [v0.2.163](https://github.com/dosomething/phoenix/tree/v0.2.163) (2014-07-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.162...v0.2.163)

**Merged pull requests:**

- bithday vs birthday [\#2903](https://github.com/DoSomething/phoenix/pull/2903) ([DeeZone](https://github.com/DeeZone))
- Campaign fixture images [\#2901](https://github.com/DoSomething/phoenix/pull/2901) ([DFurnes](https://github.com/DFurnes))
- Indexed fields [\#2898](https://github.com/DoSomething/phoenix/pull/2898) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.162](https://github.com/dosomething/phoenix/tree/v0.2.162) (2014-07-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.161...v0.2.162)

**Merged pull requests:**

- Campaign  faming updates [\#2902](https://github.com/DoSomething/phoenix/pull/2902) ([weerd](https://github.com/weerd))

## [v0.2.161](https://github.com/dosomething/phoenix/tree/v0.2.161) (2014-07-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.160...v0.2.161)

**Merged pull requests:**

- Campaign  member faming [\#2900](https://github.com/DoSomething/phoenix/pull/2900) ([weerd](https://github.com/weerd))
- Campaign Downloads field [\#2899](https://github.com/DoSomething/phoenix/pull/2899) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.160](https://github.com/dosomething/phoenix/tree/v0.2.160) (2014-07-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.159...v0.2.160)

**Closed issues:**

- More config SMS adjustments for Birthday Mail 2014 [\#2896](https://github.com/DoSomething/phoenix/issues/2896)

**Merged pull requests:**

- ID updates [\#2897](https://github.com/DoSomething/phoenix/pull/2897) ([DeeZone](https://github.com/DeeZone))

## [v0.2.159](https://github.com/dosomething/phoenix/tree/v0.2.159) (2014-07-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.158...v0.2.159)

**Closed issues:**

- User creation via Drupal Service [\#2888](https://github.com/DoSomething/phoenix/issues/2888)

**Merged pull requests:**

- Drupal API - Custom User create endpoint [\#2894](https://github.com/DoSomething/phoenix/pull/2894) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.158](https://github.com/dosomething/phoenix/tree/v0.2.158) (2014-07-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.157...v0.2.158)

**Merged pull requests:**

- User Profile variables [\#2893](https://github.com/DoSomething/phoenix/pull/2893) ([aaronschachter](https://github.com/aaronschachter))
- Campaign fixtures taxonomy [\#2892](https://github.com/DoSomething/phoenix/pull/2892) ([DFurnes](https://github.com/DFurnes))

## [v0.2.157](https://github.com/dosomething/phoenix/tree/v0.2.157) (2014-07-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.156...v0.2.157)

**Merged pull requests:**

- User Registration Source field [\#2891](https://github.com/DoSomething/phoenix/pull/2891) ([aaronschachter](https://github.com/aaronschachter))
- Campaign fixture [\#2890](https://github.com/DoSomething/phoenix/pull/2890) ([DFurnes](https://github.com/DFurnes))
- Switch back to using production campaign node ID [\#2889](https://github.com/DoSomething/phoenix/pull/2889) ([DeeZone](https://github.com/DeeZone))

## [v0.2.156](https://github.com/dosomething/phoenix/tree/v0.2.156) (2014-07-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.155...v0.2.156)

**Closed issues:**

- Adjust BirthdayMail2014 workflow for testing [\#2886](https://github.com/DoSomething/phoenix/issues/2886)
- Add BirthdayMail2014 Prove Config [\#2879](https://github.com/DoSomething/phoenix/issues/2879)

**Merged pull requests:**

- Adjusts Drupal nid assignment for BirthdayMail 2014 [\#2887](https://github.com/DoSomething/phoenix/pull/2887) ([DeeZone](https://github.com/DeeZone))
- Issue2879 birthday mail2014 keyworks flow config [\#2881](https://github.com/DoSomething/phoenix/pull/2881) ([DeeZone](https://github.com/DeeZone))

## [v0.2.155](https://github.com/dosomething/phoenix/tree/v0.2.155) (2014-07-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.154...v0.2.155)

**Merged pull requests:**

- Campaign template fixes [\#2885](https://github.com/DoSomething/phoenix/pull/2885) ([aaronschachter](https://github.com/aaronschachter))
- Updating solr settings to use default hostname and standard port [\#2884](https://github.com/DoSomething/phoenix/pull/2884) ([blisteringherb](https://github.com/blisteringherb))
- Removing git commit symlink from build. [\#2883](https://github.com/DoSomething/phoenix/pull/2883) ([angaither](https://github.com/angaither))

## [v0.2.154](https://github.com/dosomething/phoenix/tree/v0.2.154) (2014-07-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.153...v0.2.154)

**Merged pull requests:**

- Campaign finder  bug [\#2880](https://github.com/DoSomething/phoenix/pull/2880) ([weerd](https://github.com/weerd))

## [v0.2.153](https://github.com/dosomething/phoenix/tree/v0.2.153) (2014-07-25)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.152...v0.2.153)

**Merged pull requests:**

- Hotfix for DOS-103 [\#2882](https://github.com/DoSomething/phoenix/pull/2882) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.152](https://github.com/dosomething/phoenix/tree/v0.2.152) (2014-07-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.151...v0.2.152)

**Merged pull requests:**

- DoSomething templates i18n: wrap PHP templates text into t\(\). [\#2878](https://github.com/DoSomething/phoenix/pull/2878) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.151](https://github.com/dosomething/phoenix/tree/v0.2.151) (2014-07-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.150...v0.2.151)

**Merged pull requests:**

- Fixes bug in \#2875 [\#2876](https://github.com/DoSomething/phoenix/pull/2876) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.150](https://github.com/dosomething/phoenix/tree/v0.2.150) (2014-07-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.149...v0.2.150)

**Merged pull requests:**

- Static Content Gallery -- Use Thumbnail field when Gallery Style != default [\#2875](https://github.com/DoSomething/phoenix/pull/2875) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.149](https://github.com/dosomething/phoenix/tree/v0.2.149) (2014-07-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.148...v0.2.149)

**Fixed bugs:**

- PHP Notice: Paraneue DS Preprocess page [\#2858](https://github.com/DoSomething/phoenix/issues/2858)

**Merged pull requests:**

- Sponsor logos template [\#2873](https://github.com/DoSomething/phoenix/pull/2873) ([aaronschachter](https://github.com/aaronschachter))
- Remove old MCC notification code. [\#2871](https://github.com/DoSomething/phoenix/pull/2871) ([DFurnes](https://github.com/DFurnes))
- Campaign visual tests [\#2865](https://github.com/DoSomething/phoenix/pull/2865) ([DFurnes](https://github.com/DFurnes))
- Remove bower copy task that was causing trouble with old configs. [\#2856](https://github.com/DoSomething/phoenix/pull/2856) ([DFurnes](https://github.com/DFurnes))

## [v0.2.148](https://github.com/dosomething/phoenix/tree/v0.2.148) (2014-07-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.147...v0.2.148)

**Closed issues:**

- Campaign API: Signups, hi-res cover image [\#2863](https://github.com/DoSomething/phoenix/issues/2863)

**Merged pull requests:**

- Content API: Campaign stats + hi res Cover Image [\#2869](https://github.com/DoSomething/phoenix/pull/2869) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.147](https://github.com/dosomething/phoenix/tree/v0.2.147) (2014-07-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.146...v0.2.147)

**Merged pull requests:**

- DS Build: Force revert all Features [\#2866](https://github.com/DoSomething/phoenix/pull/2866) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Scholarship theme function [\#2862](https://github.com/DoSomething/phoenix/pull/2862) ([aaronschachter](https://github.com/aaronschachter))
- Added a pre-commit hook to check for common mistakes. [\#2861](https://github.com/DoSomething/phoenix/pull/2861) ([angaither](https://github.com/angaither))

## [v0.2.146](https://github.com/dosomething/phoenix/tree/v0.2.146) (2014-07-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.145...v0.2.146)

**Merged pull requests:**

- Enables user register resource [\#2864](https://github.com/DoSomething/phoenix/pull/2864) ([aaronschachter](https://github.com/aaronschachter))
- Campaign headings template [\#2860](https://github.com/DoSomething/phoenix/pull/2860) ([aaronschachter](https://github.com/aaronschachter))
- Intl footer social links [\#2859](https://github.com/DoSomething/phoenix/pull/2859) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.145](https://github.com/dosomething/phoenix/tree/v0.2.145) (2014-07-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.144...v0.2.145)

**Merged pull requests:**

- Member Faming modal [\#2857](https://github.com/DoSomething/phoenix/pull/2857) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.144](https://github.com/dosomething/phoenix/tree/v0.2.144) (2014-07-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.143...v0.2.144)

**Fixed bugs:**

- \[Campaign Finder\] Update to fix missing links on default homepage finder tiles [\#2850](https://github.com/DoSomething/phoenix/issues/2850)
- PHP Undefined index in Preprocess Klout Gallery [\#2815](https://github.com/DoSomething/phoenix/issues/2815)

**Merged pull requests:**

- Fix order and nesting in paraneue\_dosomething theme footer settings. [\#2855](https://github.com/DoSomething/phoenix/pull/2855) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Campaign seo  adding content [\#2853](https://github.com/DoSomething/phoenix/pull/2853) ([weerd](https://github.com/weerd))
- Add internationalization tools. [\#2852](https://github.com/DoSomething/phoenix/pull/2852) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Campaign finder  link fix and cleanup [\#2851](https://github.com/DoSomething/phoenix/pull/2851) ([weerd](https://github.com/weerd))
- Fix Undefined index errors on campaign run. [\#2849](https://github.com/DoSomething/phoenix/pull/2849) ([angaither](https://github.com/angaither))
- Pulls image lazy-loading for tiles out of the campaign finder. [\#2848](https://github.com/DoSomething/phoenix/pull/2848) ([DFurnes](https://github.com/DFurnes))
- hide sponsor logos for affiliates [\#2847](https://github.com/DoSomething/phoenix/pull/2847) ([tjrosario](https://github.com/tjrosario))

## [v0.2.143](https://github.com/dosomething/phoenix/tree/v0.2.143) (2014-07-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.142...v0.2.143)

## [v0.2.142](https://github.com/dosomething/phoenix/tree/v0.2.142) (2014-07-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.141...v0.2.142)

**Closed issues:**

- \[Campaign Finder\] Refactor campaign tiles to use the new establish Neue patterns. [\#2817](https://github.com/DoSomething/phoenix/issues/2817)

**Merged pull requests:**

- added affiliate conditional to main page template to show subtitles for affiliate sites [\#2846](https://github.com/DoSomething/phoenix/pull/2846) ([tjrosario](https://github.com/tjrosario))
- Affiliate branding in the footer [\#2845](https://github.com/DoSomething/phoenix/pull/2845) ([tjrosario](https://github.com/tjrosario))
- Campaign finder  refactoring [\#2843](https://github.com/DoSomething/phoenix/pull/2843) ([weerd](https://github.com/weerd))

## [v0.2.141](https://github.com/dosomething/phoenix/tree/v0.2.141) (2014-07-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.140...v0.2.141)

**Fixed bugs:**

- Reportback mbp image markup missing [\#2838](https://github.com/DoSomething/phoenix/issues/2838)

**Merged pull requests:**

- Reportback API endpoint [\#2844](https://github.com/DoSomething/phoenix/pull/2844) ([aaronschachter](https://github.com/aaronschachter))
- Create a function to determine if current site is an international affiliate. [\#2842](https://github.com/DoSomething/phoenix/pull/2842) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Services: User authentication [\#2841](https://github.com/DoSomething/phoenix/pull/2841) ([aaronschachter](https://github.com/aaronschachter))
- Adds reportback image markup to payload [\#2840](https://github.com/DoSomething/phoenix/pull/2840) ([DeeZone](https://github.com/DeeZone))
- Adding some additional checks for tables and fields [\#2837](https://github.com/DoSomething/phoenix/pull/2837) ([blisteringherb](https://github.com/blisteringherb))
- Campaign created fields [\#2836](https://github.com/DoSomething/phoenix/pull/2836) ([aaronschachter](https://github.com/aaronschachter))
- Drush command to create campaigns from JSON [\#2835](https://github.com/DoSomething/phoenix/pull/2835) ([aaronschachter](https://github.com/aaronschachter))
- Intl: Add footer affiliate logo. [\#2831](https://github.com/DoSomething/phoenix/pull/2831) ([sergii-tkachenko](https://github.com/sergii-tkachenko))

## [v0.2.140](https://github.com/dosomething/phoenix/tree/v0.2.140) (2014-07-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.139...v0.2.140)

**Closed issues:**

- Pinterest metatag [\#2822](https://github.com/DoSomething/phoenix/issues/2822)

**Merged pull requests:**

- Metatag tweaks [\#2834](https://github.com/DoSomething/phoenix/pull/2834) ([aaronschachter](https://github.com/aaronschachter))
- Campaign tests [\#2833](https://github.com/DoSomething/phoenix/pull/2833) ([DFurnes](https://github.com/DFurnes))
- Editor user edit [\#2832](https://github.com/DoSomething/phoenix/pull/2832) ([aaronschachter](https://github.com/aaronschachter))
- added gallery style helper to work with current gallery patterns [\#2830](https://github.com/DoSomething/phoenix/pull/2830) ([tjrosario](https://github.com/tjrosario))
- Campaign  pitch seo update [\#2828](https://github.com/DoSomething/phoenix/pull/2828) ([weerd](https://github.com/weerd))
- Intl: Allow overriding header logo. [\#2824](https://github.com/DoSomething/phoenix/pull/2824) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Metatag defaults for abstract/description [\#2823](https://github.com/DoSomething/phoenix/pull/2823) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.139](https://github.com/dosomething/phoenix/tree/v0.2.139) (2014-07-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.138...v0.2.139)

**Merged pull requests:**

- Twitter Image [\#2821](https://github.com/DoSomething/phoenix/pull/2821) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.138](https://github.com/dosomething/phoenix/tree/v0.2.138) (2014-07-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.137...v0.2.138)

**Fixed bugs:**

- PHP Undefined index in paraneue\_dosomething\_preprocess\_node [\#2816](https://github.com/DoSomething/phoenix/issues/2816)

**Merged pull requests:**

- I18N: add nid autocomplete to about us page link setting. [\#2820](https://github.com/DoSomething/phoenix/pull/2820) ([sergii-tkachenko](https://github.com/sergii-tkachenko))
- Remove SMS Game required check on Signup Admin Config Form [\#2819](https://github.com/DoSomething/phoenix/pull/2819) ([aaronschachter](https://github.com/aaronschachter))
- Zendesk Form variables [\#2818](https://github.com/DoSomething/phoenix/pull/2818) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.137](https://github.com/dosomething/phoenix/tree/v0.2.137) (2014-07-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.136...v0.2.137)

**Merged pull requests:**

- Updating markup for new Neue modal syntax. [\#2812](https://github.com/DoSomething/phoenix/pull/2812) ([DFurnes](https://github.com/DFurnes))

## [v0.2.136](https://github.com/dosomething/phoenix/tree/v0.2.136) (2014-07-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.135...v0.2.136)

**Closed issues:**

- \[Global\] Cleanup variables [\#2810](https://github.com/DoSomething/phoenix/issues/2810)

**Merged pull requests:**

- Updates to cleanup variables and fix a Zendesk bug introduced in previou... [\#2811](https://github.com/DoSomething/phoenix/pull/2811) ([weerd](https://github.com/weerd))

## [v0.2.135](https://github.com/dosomething/phoenix/tree/v0.2.135) (2014-07-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.134...v0.2.135)

## [v0.2.134](https://github.com/dosomething/phoenix/tree/v0.2.134) (2014-07-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.133...v0.2.134)

## [v0.2.133](https://github.com/dosomething/phoenix/tree/v0.2.133) (2014-07-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.132...v0.2.133)

## [v0.2.132](https://github.com/dosomething/phoenix/tree/v0.2.132) (2014-07-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.131...v0.2.132)

## [v0.2.131](https://github.com/dosomething/phoenix/tree/v0.2.131) (2014-07-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.130...v0.2.131)

## [v0.2.130](https://github.com/dosomething/phoenix/tree/v0.2.130) (2014-07-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.129...v0.2.130)

## [v0.2.129](https://github.com/dosomething/phoenix/tree/v0.2.129) (2014-07-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.128...v0.2.129)

## [v0.2.128](https://github.com/dosomething/phoenix/tree/v0.2.128) (2014-07-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.127...v0.2.128)

## [v0.2.127](https://github.com/dosomething/phoenix/tree/v0.2.127) (2014-07-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.126...v0.2.127)

## [v0.2.126](https://github.com/dosomething/phoenix/tree/v0.2.126) (2014-07-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.125...v0.2.126)

## [v0.2.125](https://github.com/dosomething/phoenix/tree/v0.2.125) (2014-07-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.124...v0.2.125)

## [v0.2.124](https://github.com/dosomething/phoenix/tree/v0.2.124) (2014-07-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.123...v0.2.124)

## [v0.2.123](https://github.com/dosomething/phoenix/tree/v0.2.123) (2014-07-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.122...v0.2.123)

## [v0.2.122](https://github.com/dosomething/phoenix/tree/v0.2.122) (2014-07-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.121...v0.2.122)

## [v0.2.121](https://github.com/dosomething/phoenix/tree/v0.2.121) (2014-07-01)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.120...v0.2.121)

## [v0.2.120](https://github.com/dosomething/phoenix/tree/v0.2.120) (2014-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.119...v0.2.120)

## [v0.2.119](https://github.com/dosomething/phoenix/tree/v0.2.119) (2014-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.118...v0.2.119)

## [v0.2.118](https://github.com/dosomething/phoenix/tree/v0.2.118) (2014-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.117...v0.2.118)

## [v0.2.117](https://github.com/dosomething/phoenix/tree/v0.2.117) (2014-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.116...v0.2.117)

## [v0.2.116](https://github.com/dosomething/phoenix/tree/v0.2.116) (2014-06-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.115...v0.2.116)

## [v0.2.115](https://github.com/dosomething/phoenix/tree/v0.2.115) (2014-06-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.114...v0.2.115)

## [v0.2.114](https://github.com/dosomething/phoenix/tree/v0.2.114) (2014-06-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.113...v0.2.114)

## [v0.2.113](https://github.com/dosomething/phoenix/tree/v0.2.113) (2014-06-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.112...v0.2.113)

## [v0.2.112](https://github.com/dosomething/phoenix/tree/v0.2.112) (2014-06-26)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.111...v0.2.112)

## [v0.2.111](https://github.com/dosomething/phoenix/tree/v0.2.111) (2014-06-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.110...v0.2.111)

## [v0.2.110](https://github.com/dosomething/phoenix/tree/v0.2.110) (2014-06-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.109...v0.2.110)

## [v0.2.109](https://github.com/dosomething/phoenix/tree/v0.2.109) (2014-06-24)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.108...v0.2.109)

## [v0.2.108](https://github.com/dosomething/phoenix/tree/v0.2.108) (2014-06-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.107...v0.2.108)

## [v0.2.107](https://github.com/dosomething/phoenix/tree/v0.2.107) (2014-06-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.106...v0.2.107)

## [v0.2.106](https://github.com/dosomething/phoenix/tree/v0.2.106) (2014-06-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.105...v0.2.106)

## [v0.2.105](https://github.com/dosomething/phoenix/tree/v0.2.105) (2014-06-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.104...v0.2.105)

## [v0.2.104](https://github.com/dosomething/phoenix/tree/v0.2.104) (2014-06-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.103...v0.2.104)

## [v0.2.103](https://github.com/dosomething/phoenix/tree/v0.2.103) (2014-06-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.102...v0.2.103)

## [v0.2.102](https://github.com/dosomething/phoenix/tree/v0.2.102) (2014-06-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.101...v0.2.102)

## [v0.2.101](https://github.com/dosomething/phoenix/tree/v0.2.101) (2014-06-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.100...v0.2.101)

## [v0.2.100](https://github.com/dosomething/phoenix/tree/v0.2.100) (2014-06-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.99...v0.2.100)

## [v0.2.99](https://github.com/dosomething/phoenix/tree/v0.2.99) (2014-06-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.98...v0.2.99)

## [v0.2.98](https://github.com/dosomething/phoenix/tree/v0.2.98) (2014-06-17)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.97...v0.2.98)

## [v0.2.97](https://github.com/dosomething/phoenix/tree/v0.2.97) (2014-06-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.96...v0.2.97)

## [v0.2.96](https://github.com/dosomething/phoenix/tree/v0.2.96) (2014-06-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.95...v0.2.96)

## [v0.2.95](https://github.com/dosomething/phoenix/tree/v0.2.95) (2014-06-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.94...v0.2.95)

## [v0.2.94](https://github.com/dosomething/phoenix/tree/v0.2.94) (2014-06-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.93...v0.2.94)

## [v0.2.93](https://github.com/dosomething/phoenix/tree/v0.2.93) (2014-06-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v.0.2.92...v0.2.93)

## [v.0.2.92](https://github.com/dosomething/phoenix/tree/v.0.2.92) (2014-06-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.91...v.0.2.92)

## [v0.2.91](https://github.com/dosomething/phoenix/tree/v0.2.91) (2014-06-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.90...v0.2.91)

## [v0.2.90](https://github.com/dosomething/phoenix/tree/v0.2.90) (2014-06-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.89...v0.2.90)

## [v0.2.89](https://github.com/dosomething/phoenix/tree/v0.2.89) (2014-06-11)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.88...v0.2.89)

## [v0.2.88](https://github.com/dosomething/phoenix/tree/v0.2.88) (2014-06-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.87...v0.2.88)

## [v0.2.87](https://github.com/dosomething/phoenix/tree/v0.2.87) (2014-06-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.86...v0.2.87)

## [v0.2.86](https://github.com/dosomething/phoenix/tree/v0.2.86) (2014-06-10)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.85...v0.2.86)

## [v0.2.85](https://github.com/dosomething/phoenix/tree/v0.2.85) (2014-06-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.84...v0.2.85)

## [v0.2.84](https://github.com/dosomething/phoenix/tree/v0.2.84) (2014-06-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.83...v0.2.84)

## [v0.2.83](https://github.com/dosomething/phoenix/tree/v0.2.83) (2014-06-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.82...v0.2.83)

## [v0.2.82](https://github.com/dosomething/phoenix/tree/v0.2.82) (2014-06-05)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.81...v0.2.82)

## [v0.2.81](https://github.com/dosomething/phoenix/tree/v0.2.81) (2014-06-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.80...v0.2.81)

## [v0.2.80](https://github.com/dosomething/phoenix/tree/v0.2.80) (2014-06-04)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.79...v0.2.80)

## [v0.2.79](https://github.com/dosomething/phoenix/tree/v0.2.79) (2014-06-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.78...v0.2.79)

## [v0.2.78](https://github.com/dosomething/phoenix/tree/v0.2.78) (2014-06-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.77...v0.2.78)

## [v0.2.77](https://github.com/dosomething/phoenix/tree/v0.2.77) (2014-06-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.76...v0.2.77)

## [v0.2.76](https://github.com/dosomething/phoenix/tree/v0.2.76) (2014-06-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.75...v0.2.76)

## [v0.2.75](https://github.com/dosomething/phoenix/tree/v0.2.75) (2014-06-03)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.74...v0.2.75)

## [v0.2.74](https://github.com/dosomething/phoenix/tree/v0.2.74) (2014-06-02)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.73...v0.2.74)

## [v0.2.73](https://github.com/dosomething/phoenix/tree/v0.2.73) (2014-05-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.72...v0.2.73)

## [v0.2.72](https://github.com/dosomething/phoenix/tree/v0.2.72) (2014-05-30)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.71...v0.2.72)

## [v0.2.71](https://github.com/dosomething/phoenix/tree/v0.2.71) (2014-05-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.70...v0.2.71)

## [v0.2.70](https://github.com/dosomething/phoenix/tree/v0.2.70) (2014-05-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.69...v0.2.70)

## [v0.2.69](https://github.com/dosomething/phoenix/tree/v0.2.69) (2014-05-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.68...v0.2.69)

## [v0.2.68](https://github.com/dosomething/phoenix/tree/v0.2.68) (2014-05-29)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.67...v0.2.68)

## [v0.2.67](https://github.com/dosomething/phoenix/tree/v0.2.67) (2014-05-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.66...v0.2.67)

## [v0.2.66](https://github.com/dosomething/phoenix/tree/v0.2.66) (2014-05-28)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.65...v0.2.66)

## [v0.2.65](https://github.com/dosomething/phoenix/tree/v0.2.65) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.64...v0.2.65)

## [v0.2.64](https://github.com/dosomething/phoenix/tree/v0.2.64) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.63...v0.2.64)

## [v0.2.63](https://github.com/dosomething/phoenix/tree/v0.2.63) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.62...v0.2.63)

## [v0.2.62](https://github.com/dosomething/phoenix/tree/v0.2.62) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.61...v0.2.62)

## [v0.2.61](https://github.com/dosomething/phoenix/tree/v0.2.61) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.60...v0.2.61)

## [v0.2.60](https://github.com/dosomething/phoenix/tree/v0.2.60) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.59...v0.2.60)

## [v0.2.59](https://github.com/dosomething/phoenix/tree/v0.2.59) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.58...v0.2.59)

## [v0.2.58](https://github.com/dosomething/phoenix/tree/v0.2.58) (2014-05-27)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.57...v0.2.58)

## [v0.2.57](https://github.com/dosomething/phoenix/tree/v0.2.57) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.56...v0.2.57)

## [v0.2.56](https://github.com/dosomething/phoenix/tree/v0.2.56) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.55...v0.2.56)

## [v0.2.55](https://github.com/dosomething/phoenix/tree/v0.2.55) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.54...v0.2.55)

## [v0.2.54](https://github.com/dosomething/phoenix/tree/v0.2.54) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.53...v0.2.54)

## [v0.2.53](https://github.com/dosomething/phoenix/tree/v0.2.53) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.52...v0.2.53)

## [v0.2.52](https://github.com/dosomething/phoenix/tree/v0.2.52) (2014-05-23)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.51...v0.2.52)

## [v0.2.51](https://github.com/dosomething/phoenix/tree/v0.2.51) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.50...v0.2.51)

## [v0.2.50](https://github.com/dosomething/phoenix/tree/v0.2.50) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.49...v0.2.50)

## [v0.2.49](https://github.com/dosomething/phoenix/tree/v0.2.49) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.48...v0.2.49)

## [v0.2.48](https://github.com/dosomething/phoenix/tree/v0.2.48) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.47...v0.2.48)

## [v0.2.47](https://github.com/dosomething/phoenix/tree/v0.2.47) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.46...v0.2.47)

## [v0.2.46](https://github.com/dosomething/phoenix/tree/v0.2.46) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.45...v0.2.46)

## [v0.2.45](https://github.com/dosomething/phoenix/tree/v0.2.45) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.44...v0.2.45)

## [v0.2.44](https://github.com/dosomething/phoenix/tree/v0.2.44) (2014-05-22)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.43...v0.2.44)

## [v0.2.43](https://github.com/dosomething/phoenix/tree/v0.2.43) (2014-05-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.42...v0.2.43)

## [v0.2.42](https://github.com/dosomething/phoenix/tree/v0.2.42) (2014-05-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.41...v0.2.42)

## [v0.2.41](https://github.com/dosomething/phoenix/tree/v0.2.41) (2014-05-21)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.40...v0.2.41)

## [v0.2.40](https://github.com/dosomething/phoenix/tree/v0.2.40) (2014-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.39...v0.2.40)

## [v0.2.39](https://github.com/dosomething/phoenix/tree/v0.2.39) (2014-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.38...v0.2.39)

## [v0.2.38](https://github.com/dosomething/phoenix/tree/v0.2.38) (2014-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.37...v0.2.38)

## [v0.2.37](https://github.com/dosomething/phoenix/tree/v0.2.37) (2014-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.36...v0.2.37)

## [v0.2.36](https://github.com/dosomething/phoenix/tree/v0.2.36) (2014-05-20)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.35...v0.2.36)

## [v0.2.35](https://github.com/dosomething/phoenix/tree/v0.2.35) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.34...v0.2.35)

## [v0.2.34](https://github.com/dosomething/phoenix/tree/v0.2.34) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.33...v0.2.34)

## [v0.2.33](https://github.com/dosomething/phoenix/tree/v0.2.33) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.32...v0.2.33)

## [v0.2.32](https://github.com/dosomething/phoenix/tree/v0.2.32) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.31...v0.2.32)

## [v0.2.31](https://github.com/dosomething/phoenix/tree/v0.2.31) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.30...v0.2.31)

## [v0.2.30](https://github.com/dosomething/phoenix/tree/v0.2.30) (2014-05-19)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.29...v0.2.30)

## [v0.2.29](https://github.com/dosomething/phoenix/tree/v0.2.29) (2014-05-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.28...v0.2.29)

## [v0.2.28](https://github.com/dosomething/phoenix/tree/v0.2.28) (2014-05-16)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.27...v0.2.28)

## [v0.2.27](https://github.com/dosomething/phoenix/tree/v0.2.27) (2014-05-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.26...v0.2.27)

## [v0.2.26](https://github.com/dosomething/phoenix/tree/v0.2.26) (2014-05-15)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.25...v0.2.26)

## [v0.2.25](https://github.com/dosomething/phoenix/tree/v0.2.25) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.24...v0.2.25)

## [v0.2.24](https://github.com/dosomething/phoenix/tree/v0.2.24) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.23...v0.2.24)

## [v0.2.23](https://github.com/dosomething/phoenix/tree/v0.2.23) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.22...v0.2.23)

## [v0.2.22](https://github.com/dosomething/phoenix/tree/v0.2.22) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.21...v0.2.22)

## [v0.2.21](https://github.com/dosomething/phoenix/tree/v0.2.21) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.20...v0.2.21)

## [v0.2.20](https://github.com/dosomething/phoenix/tree/v0.2.20) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.19...v0.2.20)

## [v0.2.19](https://github.com/dosomething/phoenix/tree/v0.2.19) (2014-05-14)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.18...v0.2.19)

## [v0.2.18](https://github.com/dosomething/phoenix/tree/v0.2.18) (2014-05-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.17...v0.2.18)

## [v0.2.17](https://github.com/dosomething/phoenix/tree/v0.2.17) (2014-05-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.16...v0.2.17)

## [v0.2.16](https://github.com/dosomething/phoenix/tree/v0.2.16) (2014-05-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.15...v0.2.16)

# Change Log

## [v0.2.15](https://github.com/dosomething/phoenix/tree/v0.2.15) (2014-05-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.14...v0.2.15)

## [v0.2.14](https://github.com/dosomething/phoenix/tree/v0.2.14) (2014-05-13)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.13...v0.2.14)

**Fixed bugs:**

- \[Campaign Template\] - 404'd when submit report back on "new" campaigns [\#2084](https://github.com/DoSomething/phoenix/issues/2084)
- \[QA\] Varnish not getting cleared properly? [\#2072](https://github.com/DoSomething/phoenix/issues/2072)
- \[Grouped Campaigns\] Change intro title so it defaults to plain text. [\#2025](https://github.com/DoSomething/phoenix/issues/2025)
- \[Signup Data Form\] weird spacing at top of modal [\#1952](https://github.com/DoSomething/phoenix/issues/1952)

**Closed issues:**

- Staging homepage redirect [\#2089](https://github.com/DoSomething/phoenix/issues/2089)
- Set up AJAX validation for fields/field sets [\#2017](https://github.com/DoSomething/phoenix/issues/2017)
- Field set validation [\#2016](https://github.com/DoSomething/phoenix/issues/2016)
- \[Signup Data Form\] positive confirmation message [\#1948](https://github.com/DoSomething/phoenix/issues/1948)
- \[Signup Data Form\] button placement [\#1947](https://github.com/DoSomething/phoenix/issues/1947)
- \[Signup Data Form\] Style the Skip form [\#1937](https://github.com/DoSomething/phoenix/issues/1937)
- Signup Data Form: Old people messaging [\#1921](https://github.com/DoSomething/phoenix/issues/1921)
- Campaign: Pitch page label [\#1915](https://github.com/DoSomething/phoenix/issues/1915)

**Merged pull requests:**

- Remove front\_page variable from features [\#2098](https://github.com/DoSomething/phoenix/pull/2098) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Group Text formats [\#2090](https://github.com/DoSomething/phoenix/pull/2090) ([aaronschachter](https://github.com/aaronschachter))
- Signup Button label override [\#2087](https://github.com/DoSomething/phoenix/pull/2087) ([aaronschachter](https://github.com/aaronschachter))
- Go home, grandpa [\#2086](https://github.com/DoSomething/phoenix/pull/2086) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.13](https://github.com/dosomething/phoenix/tree/v0.2.13) (2014-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.12...v0.2.13)

**Fixed bugs:**

- \[Signup Data Form\] - fatal error [\#2082](https://github.com/DoSomething/phoenix/issues/2082)

**Merged pull requests:**

- Fixes issue with signup data form submission. [\#2083](https://github.com/DoSomething/phoenix/pull/2083) ([DFurnes](https://github.com/DFurnes))
- Moves analytics code into DS app. [\#2078](https://github.com/DoSomething/phoenix/pull/2078) ([DFurnes](https://github.com/DFurnes))

## [v0.2.12](https://github.com/dosomething/phoenix/tree/v0.2.12) (2014-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.11...v0.2.12)

**Merged pull requests:**

- Fieldset address [\#2060](https://github.com/DoSomething/phoenix/pull/2060) ([DFurnes](https://github.com/DFurnes))

## [v0.2.11](https://github.com/dosomething/phoenix/tree/v0.2.11) (2014-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.10...v0.2.11)

**Closed issues:**

- Preparations for Thumb Wars walkthrough [\#2070](https://github.com/DoSomething/phoenix/issues/2070)
- \[Grouped Campaigns\] Initial pass on markup. [\#2026](https://github.com/DoSomething/phoenix/issues/2026)

**Merged pull requests:**

- Wrapping up all the header refactoring and updating the affected templat... [\#2077](https://github.com/DoSomething/phoenix/pull/2077) ([weerd](https://github.com/weerd))
- Remove hacks from signup data flow. [\#2073](https://github.com/DoSomething/phoenix/pull/2073) ([DFurnes](https://github.com/DFurnes))

## [v0.2.10](https://github.com/dosomething/phoenix/tree/v0.2.10) (2014-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.9...v0.2.10)

**Fixed bugs:**

- Can't request new password due to default styles [\#2075](https://github.com/DoSomething/phoenix/issues/2075)

**Merged pull requests:**

- Temporary fix for Forgot Password page. [\#2079](https://github.com/DoSomething/phoenix/pull/2079) ([DFurnes](https://github.com/DFurnes))
- Fixes tests to run with AMD modules. [\#2076](https://github.com/DoSomething/phoenix/pull/2076) ([DFurnes](https://github.com/DFurnes))

## [v0.2.9](https://github.com/dosomething/phoenix/tree/v0.2.9) (2014-05-12)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.8...v0.2.9)

**Closed issues:**

- \[Grouped Campaigns\] tags field needed [\#2068](https://github.com/DoSomething/phoenix/issues/2068)
- Zendesk form not submitting tickets [\#2064](https://github.com/DoSomething/phoenix/issues/2064)
- Group Campaign -\> dosomething\_mbp request [\#1984](https://github.com/DoSomething/phoenix/issues/1984)

**Merged pull requests:**

- Restores Zendesk tickets [\#2074](https://github.com/DoSomething/phoenix/pull/2074) ([aaronschachter](https://github.com/aaronschachter))
- Adding 'tags' terms [\#2069](https://github.com/DoSomething/phoenix/pull/2069) ([blisteringherb](https://github.com/blisteringherb))
- First draft of adding mbp support for group\_campaign signups [\#2052](https://github.com/DoSomething/phoenix/pull/2052) ([DeeZone](https://github.com/DeeZone))

## [v0.2.8](https://github.com/dosomething/phoenix/tree/v0.2.8) (2014-05-09)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.7...v0.2.8)

**Fixed bugs:**

- \[Campaign Template\] - More Facts About not showing up on action page [\#2036](https://github.com/DoSomething/phoenix/issues/2036)
- \[user profile\] Use l function for link to user profile [\#2019](https://github.com/DoSomething/phoenix/issues/2019)
- \[Signup Data Form\] Form submitted copy not displaying [\#1940](https://github.com/DoSomething/phoenix/issues/1940)

**Closed issues:**

- Modal template documentation [\#2054](https://github.com/DoSomething/phoenix/issues/2054)
- \[Grouped Campaigns\] timing fields needed [\#2040](https://github.com/DoSomething/phoenix/issues/2040)
- \[Campaign Group\] Add taxonomy/finder fields [\#2024](https://github.com/DoSomething/phoenix/issues/2024)
- \[Campaign Group\] Logic for displaying Pre-Live fields vs field\_campaigns [\#1993](https://github.com/DoSomething/phoenix/issues/1993)
- \[Campaign Group\] Display post-signup fields based on signup status [\#1992](https://github.com/DoSomething/phoenix/issues/1992)
- Signup Data Form: Prompt user after signup [\#1913](https://github.com/DoSomething/phoenix/issues/1913)
- Campaign Group: "Teaser" display of unpublished child campaigns [\#1897](https://github.com/DoSomething/phoenix/issues/1897)
- \[Finder\] Higher resolution images [\#1709](https://github.com/DoSomething/phoenix/issues/1709)

**Merged pull requests:**

- Fixes modal popup code. [\#2065](https://github.com/DoSomething/phoenix/pull/2065) ([DFurnes](https://github.com/DFurnes))
- Adding add'l larger images to search and updating relevant code [\#2063](https://github.com/DoSomething/phoenix/pull/2063) ([blisteringherb](https://github.com/blisteringherb))
- Making images clickable for published campaigns [\#2062](https://github.com/DoSomething/phoenix/pull/2062) ([blisteringherb](https://github.com/blisteringherb))
- Adding pitch page label to campaign and campaign group custom settings [\#2061](https://github.com/DoSomething/phoenix/pull/2061) ([blisteringherb](https://github.com/blisteringherb))
- Modal link documentation [\#2059](https://github.com/DoSomething/phoenix/pull/2059) ([blisteringherb](https://github.com/blisteringherb))
- Add DS\_Store to gitignore. [\#2058](https://github.com/DoSomething/phoenix/pull/2058) ([angaither](https://github.com/angaither))
- Return ups results in menu hook differntly. [\#2057](https://github.com/DoSomething/phoenix/pull/2057) ([angaither](https://github.com/angaither))
- Checking for signup status to display button and fields [\#2056](https://github.com/DoSomething/phoenix/pull/2056) ([blisteringherb](https://github.com/blisteringherb))
- Modal theme function was called twice, more\_facts was overridden [\#2053](https://github.com/DoSomething/phoenix/pull/2053) ([blisteringherb](https://github.com/blisteringherb))
- Adding logic for displaying campaigns and pre-live fields [\#2050](https://github.com/DoSomething/phoenix/pull/2050) ([blisteringherb](https://github.com/blisteringherb))
- Quick fix. [\#2049](https://github.com/DoSomething/phoenix/pull/2049) ([weerd](https://github.com/weerd))
- Couldn't solve weird issue, but added some useful variable comments. [\#2048](https://github.com/DoSomething/phoenix/pull/2048) ([weerd](https://github.com/weerd))
- Adding taxonomy and categorization fields [\#2047](https://github.com/DoSomething/phoenix/pull/2047) ([blisteringherb](https://github.com/blisteringherb))
- Refactoring and adding color settings field to campaign [\#2046](https://github.com/DoSomething/phoenix/pull/2046) ([blisteringherb](https://github.com/blisteringherb))
- Adding timing group and timing fields [\#2045](https://github.com/DoSomething/phoenix/pull/2045) ([blisteringherb](https://github.com/blisteringherb))
- Updating user profile link to use standard Drupal link function. [\#2037](https://github.com/DoSomething/phoenix/pull/2037) ([weerd](https://github.com/weerd))

## [v0.2.7](https://github.com/dosomething/phoenix/tree/v0.2.7) (2014-05-08)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.6...v0.2.7)

**Fixed bugs:**

- Campaign confirmation links bug [\#1873](https://github.com/DoSomething/phoenix/issues/1873)

**Closed issues:**

- \[Campaign Group\] Intro image logic [\#2023](https://github.com/DoSomething/phoenix/issues/2023)
- \[Campaign Group\] Include scholarship field [\#2022](https://github.com/DoSomething/phoenix/issues/2022)
- \[Campaign Group\] Rename pre-signup fields [\#2021](https://github.com/DoSomething/phoenix/issues/2021)
- \[Campaign Group\] Move Call to action field up [\#2020](https://github.com/DoSomething/phoenix/issues/2020)
- \[Campaign Group\] Use a new field for the signup form [\#2007](https://github.com/DoSomething/phoenix/issues/2007)
- \[Campaign Group\] Add Cover Image field [\#2002](https://github.com/DoSomething/phoenix/issues/2002)
- \[Campaign Group\] Partner info does not appear in modal [\#2001](https://github.com/DoSomething/phoenix/issues/2001)
- \[Campaign Group\] Node form: Signup Form fields, groups [\#1987](https://github.com/DoSomething/phoenix/issues/1987)
- \[Grouped campaign\] Zendesk forms [\#1898](https://github.com/DoSomething/phoenix/issues/1898)

**Merged pull requests:**

- Turning off Markdown for all textfields [\#2044](https://github.com/DoSomething/phoenix/pull/2044) ([blisteringherb](https://github.com/blisteringherb))
- Updating recommended campaign paths for image link on report back confir... [\#2042](https://github.com/DoSomething/phoenix/pull/2042) ([weerd](https://github.com/weerd))
- Intro image field and logic [\#2039](https://github.com/DoSomething/phoenix/pull/2039) ([blisteringherb](https://github.com/blisteringherb))
- Adding scholarship amount field [\#2038](https://github.com/DoSomething/phoenix/pull/2038) ([blisteringherb](https://github.com/blisteringherb))
- Renaming pre signup fields and adding logic to display when campaigns are published [\#2035](https://github.com/DoSomething/phoenix/pull/2035) ([blisteringherb](https://github.com/blisteringherb))
- Zendesk form for Grouped Campaigns [\#2033](https://github.com/DoSomething/phoenix/pull/2033) ([aaronschachter](https://github.com/aaronschachter))
- Removing field\_subtitle and moving field\_call\_to\_action [\#2032](https://github.com/DoSomething/phoenix/pull/2032) ([blisteringherb](https://github.com/blisteringherb))
- Grouped campaigns [\#2031](https://github.com/DoSomething/phoenix/pull/2031) ([aaronschachter](https://github.com/aaronschachter))
- Add permission to edit home page content. [\#2030](https://github.com/DoSomething/phoenix/pull/2030) ([angaither](https://github.com/angaither))
- Adding cover image field and supporting preprocess functions [\#2029](https://github.com/DoSomething/phoenix/pull/2029) ([blisteringherb](https://github.com/blisteringherb))
- First pass at markup for grouped campaigns. [\#2027](https://github.com/DoSomething/phoenix/pull/2027) ([weerd](https://github.com/weerd))
- Replacing CTA link with text field and adding removing CTA link field [\#2009](https://github.com/DoSomething/phoenix/pull/2009) ([blisteringherb](https://github.com/blisteringherb))

## [v0.2.6](https://github.com/dosomething/phoenix/tree/v0.2.6) (2014-05-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.5...v0.2.6)

**Closed issues:**

- Image Search [\#799](https://github.com/DoSomething/phoenix/issues/799)

**Merged pull requests:**

- Updates to remove the profile link from the nav for now. [\#2018](https://github.com/DoSomething/phoenix/pull/2018) ([weerd](https://github.com/weerd))
- Partner footer links [\#2013](https://github.com/DoSomething/phoenix/pull/2013) ([aaronschachter](https://github.com/aaronschachter))
- Add version numbers to features. [\#2010](https://github.com/DoSomething/phoenix/pull/2010) ([angaither](https://github.com/angaither))

## [v0.2.5](https://github.com/dosomething/phoenix/tree/v0.2.5) (2014-05-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.4...v0.2.5)

**Closed issues:**

- \[Campaign Group\] FAQ content does not appear in modal [\#2000](https://github.com/DoSomething/phoenix/issues/2000)
- \[campaign template\] - need ability to link to partner sites in "In partnership with" [\#1959](https://github.com/DoSomething/phoenix/issues/1959)

**Merged pull requests:**

- Refactoring faq, partner and more facts modals to use a common tpl [\#2015](https://github.com/DoSomething/phoenix/pull/2015) ([blisteringherb](https://github.com/blisteringherb))
- Backup plan for when there are no homepage nodes programmed. [\#2014](https://github.com/DoSomething/phoenix/pull/2014) ([angaither](https://github.com/angaither))
- Adding account link in navigation. [\#2011](https://github.com/DoSomething/phoenix/pull/2011) ([weerd](https://github.com/weerd))

## [v0.2.4](https://github.com/dosomething/phoenix/tree/v0.2.4) (2014-05-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.3...v0.2.4)

**Closed issues:**

- Home entityreference \(homepage\) [\#1996](https://github.com/DoSomething/phoenix/issues/1996)

**Merged pull requests:**

- Makes the homepage nodes editable in a UI. [\#2008](https://github.com/DoSomething/phoenix/pull/2008) ([angaither](https://github.com/angaither))
- Partners in static content [\#2006](https://github.com/DoSomething/phoenix/pull/2006) ([aaronschachter](https://github.com/aaronschachter))
- Falls back to normal image upload field on IE8. [\#2005](https://github.com/DoSomething/phoenix/pull/2005) ([DFurnes](https://github.com/DFurnes))
- Renaming CTA group to Signup Form and moving display checkbox [\#2003](https://github.com/DoSomething/phoenix/pull/2003) ([blisteringherb](https://github.com/blisteringherb))
- Campaign Groups: Signup upon login/register [\#1998](https://github.com/DoSomething/phoenix/pull/1998) ([aaronschachter](https://github.com/aaronschachter))

## [v0.2.3](https://github.com/dosomething/phoenix/tree/v0.2.3) (2014-05-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.2...v0.2.3)

**Closed issues:**

- \[Signup Data Form\] closing notification closes modal as well [\#1953](https://github.com/DoSomething/phoenix/issues/1953)

**Merged pull requests:**

- Adds branch argument to enable passing of tags to capistrano [\#1999](https://github.com/DoSomething/phoenix/pull/1999) ([desmondmorris](https://github.com/desmondmorris))

## [v0.2.2](https://github.com/dosomething/phoenix/tree/v0.2.2) (2014-05-06)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.1...v0.2.2)

**Fixed bugs:**

- \[User Profile\] Fix issue w/ empty state not showing up past 4 signup campaigns [\#1976](https://github.com/DoSomething/phoenix/issues/1976)
- \[Signup Data Form\] invalid address worked [\#1950](https://github.com/DoSomething/phoenix/issues/1950)
- \[Signup Data Form\] Bug in the \[submitted\] token [\#1941](https://github.com/DoSomething/phoenix/issues/1941)
- Campaign Group: Make file copy/paste errors [\#1926](https://github.com/DoSomething/phoenix/issues/1926)
- Campaign Group: Remove view\_unpublished from dependencies [\#1925](https://github.com/DoSomething/phoenix/issues/1925)
- User registration link goes to 'access denied' [\#1900](https://github.com/DoSomething/phoenix/issues/1900)
- \[User Profile\] User email is showing up as logged in user and not account user [\#1899](https://github.com/DoSomething/phoenix/issues/1899)
- Font color on report back file upload is a usability concern.  [\#1890](https://github.com/DoSomething/phoenix/issues/1890)
- campaign \(form\) - can't remove official rules pdf [\#1869](https://github.com/DoSomething/phoenix/issues/1869)
- international - error when report back [\#1850](https://github.com/DoSomething/phoenix/issues/1850)
- international - error if logged in and sign up for campaign [\#1849](https://github.com/DoSomething/phoenix/issues/1849)
- international - taken to blank page after register [\#1848](https://github.com/DoSomething/phoenix/issues/1848)
- address collection - required when editing a user's profile [\#1845](https://github.com/DoSomething/phoenix/issues/1845)
- address collection - some invalid addresses are accepted as valid [\#1836](https://github.com/DoSomething/phoenix/issues/1836)
- address collection - enter wrong address, enter right address, still get error [\#1825](https://github.com/DoSomething/phoenix/issues/1825)
- Address field is only validating if user has an address [\#1815](https://github.com/DoSomething/phoenix/issues/1815)
- Campaign Finder - Mind On My Money shows up twice in results [\#1792](https://github.com/DoSomething/phoenix/issues/1792)
- Search results background swap to white [\#1775](https://github.com/DoSomething/phoenix/issues/1775)
- Campaign Finder - can't switch between choices within a category after second category selected [\#1765](https://github.com/DoSomething/phoenix/issues/1765)
- Campaign Finder - when I change a selection, grayed out options don't reset [\#1764](https://github.com/DoSomething/phoenix/issues/1764)
- campaign finder - inconsistency of ordering filters [\#1762](https://github.com/DoSomething/phoenix/issues/1762)
- campaign finder - filter disabling behaving incorrectly [\#1760](https://github.com/DoSomething/phoenix/issues/1760)
- Campaign Finder - filters not responsive on IE8/XP [\#1758](https://github.com/DoSomething/phoenix/issues/1758)
- Reportback field bug: Doesn't save on first submit [\#1750](https://github.com/DoSomething/phoenix/issues/1750)
- Fatal error: Call to a member function publishMessage\(\) [\#1749](https://github.com/DoSomething/phoenix/issues/1749)
- Campaign Action Guide PHP Strict Warning [\#1724](https://github.com/DoSomething/phoenix/issues/1724)
- Reportback PHP Notice: Undefined property $field [\#1721](https://github.com/DoSomething/phoenix/issues/1721)
- Signup Data Form: PHP Warning for Last Name [\#1720](https://github.com/DoSomething/phoenix/issues/1720)
- User registration: PHP Notice undefined index for mobile [\#1719](https://github.com/DoSomething/phoenix/issues/1719)
- Reportback Field: PHP Notice Undefined property [\#1718](https://github.com/DoSomething/phoenix/issues/1718)
- Signup Form: PHP notice undefined variable [\#1717](https://github.com/DoSomething/phoenix/issues/1717)
- Zendesk admin form: Strict warnings [\#1715](https://github.com/DoSomething/phoenix/issues/1715)
- Message Broker write warning upon reportback [\#1702](https://github.com/DoSomething/phoenix/issues/1702)
- Finder: Multiple Select Issue [\#1695](https://github.com/DoSomething/phoenix/issues/1695)
- Reportback Form: Radio styles [\#1693](https://github.com/DoSomething/phoenix/issues/1693)
- Logout and search breaks to new line between 768px & 783px [\#1579](https://github.com/DoSomething/phoenix/issues/1579)
- hyperlinked text - strange characters should appear normally [\#1438](https://github.com/DoSomething/phoenix/issues/1438)
- /campaigns - all characters not being pulled in properly [\#1357](https://github.com/DoSomething/phoenix/issues/1357)
- Message Broker - Password Reset NULL email [\#1248](https://github.com/DoSomething/phoenix/issues/1248)
- Campaign delete: PHP Warning [\#1211](https://github.com/DoSomething/phoenix/issues/1211)
- Reportback delete form error [\#1073](https://github.com/DoSomething/phoenix/issues/1073)
- @cjcodes fixed a multi-select issue [\#1696](https://github.com/DoSomething/phoenix/pull/1696) ([blisteringherb](https://github.com/blisteringherb))

**Closed issues:**

- \[Campaign Group\] Display confirmation message after signup [\#1991](https://github.com/DoSomething/phoenix/issues/1991)
- \[Campaign Group\] Remove duplicate CTA section from template [\#1989](https://github.com/DoSomething/phoenix/issues/1989)
- \[Campaign Group\] Signup Button preprocess function [\#1988](https://github.com/DoSomething/phoenix/issues/1988)
- \[Grouped Campaigns\] transactional email copy field [\#1973](https://github.com/DoSomething/phoenix/issues/1973)
- \[User Lookup\] - add ability to search by first/last name on /admin/users [\#1972](https://github.com/DoSomething/phoenix/issues/1972)
- \[Admin report back view\] - ability to look up report backs via email address [\#1969](https://github.com/DoSomething/phoenix/issues/1969)
- Campaign Group: Display Signup Form [\#1961](https://github.com/DoSomething/phoenix/issues/1961)
- \[Campaign Group\] Remove unnecessary fields and rearrange [\#1954](https://github.com/DoSomething/phoenix/issues/1954)
- \[Signup Data Form\] font of state field [\#1951](https://github.com/DoSomething/phoenix/issues/1951)
- \[Signup Data Form\] remove "Back to main page" on form [\#1946](https://github.com/DoSomething/phoenix/issues/1946)
- Campaign Group: Add additional fields [\#1943](https://github.com/DoSomething/phoenix/issues/1943)
- \[Campaign Group\] Helper function to determine child campaigns are published [\#1933](https://github.com/DoSomething/phoenix/issues/1933)
- \[Campaign Group\] 3rd party subscription variables [\#1932](https://github.com/DoSomething/phoenix/issues/1932)
- \[Campaign Group\] Modify \_dosomething\_user\_add\_campaign\_data [\#1931](https://github.com/DoSomething/phoenix/issues/1931)
- \[User Profile\] Style cta for when no signups showing. [\#1929](https://github.com/DoSomething/phoenix/issues/1929)
- Signups: Data Form Response column [\#1924](https://github.com/DoSomething/phoenix/issues/1924)
- Signup Data Form: Need ability to skip form [\#1920](https://github.com/DoSomething/phoenix/issues/1920)
- \[User Profile\] Style the profile edit form with some basic styles. [\#1918](https://github.com/DoSomething/phoenix/issues/1918)
- Signup Data Form: Collect/display why\_signed up from user [\#1912](https://github.com/DoSomething/phoenix/issues/1912)
- \[User Profile\] Move `.tile` styles over to Neue as a new pattern. [\#1908](https://github.com/DoSomething/phoenix/issues/1908)
- Signup Data Form config: Add "required" checkbox [\#1904](https://github.com/DoSomething/phoenix/issues/1904)
- Signup Data Form config: Collect why signed up, label [\#1903](https://github.com/DoSomething/phoenix/issues/1903)
- Campaign Group: Child signup should also signup for Group [\#1896](https://github.com/DoSomething/phoenix/issues/1896)
- Campaign Group Signup Form [\#1895](https://github.com/DoSomething/phoenix/issues/1895)
- Campaign Group template [\#1894](https://github.com/DoSomething/phoenix/issues/1894)
- Campaign Group: Module and content type [\#1893](https://github.com/DoSomething/phoenix/issues/1893)
- Remove XML Sitemap perms from Editors [\#1885](https://github.com/DoSomething/phoenix/issues/1885)
- \[User Profile\] Style the user profile page. [\#1881](https://github.com/DoSomething/phoenix/issues/1881)
- \[User Profile\] Create new campaign block template partial [\#1872](https://github.com/DoSomething/phoenix/issues/1872)
- \[User Profile\] Collect data for campaign signups from view instead of markup [\#1870](https://github.com/DoSomething/phoenix/issues/1870)
- Change top nav second line to lowercase + uppercase [\#1860](https://github.com/DoSomething/phoenix/issues/1860)
- Show form validation errors within modal [\#1855](https://github.com/DoSomething/phoenix/issues/1855)
- Message Broker add "campaign\_create" and "campaign\_update" [\#1844](https://github.com/DoSomething/phoenix/issues/1844)
- Modal should be open when user reloads page [\#1843](https://github.com/DoSomething/phoenix/issues/1843)
- EntityMetadataWrapper errors [\#1840](https://github.com/DoSomething/phoenix/issues/1840)
- New square photo styles [\#1829](https://github.com/DoSomething/phoenix/issues/1829)
- On profile edits, make sure to validate address [\#1818](https://github.com/DoSomething/phoenix/issues/1818)
- Address field validation errors needed [\#1817](https://github.com/DoSomething/phoenix/issues/1817)
- Address save to user object [\#1816](https://github.com/DoSomething/phoenix/issues/1816)
- Signup refactor: Entity functions [\#1811](https://github.com/DoSomething/phoenix/issues/1811)
- Signup as Entity [\#1808](https://github.com/DoSomething/phoenix/issues/1808)
- User Profile - cleanup options in the state field [\#1807](https://github.com/DoSomething/phoenix/issues/1807)
- action page \(address collection\) - post-form-submission state [\#1806](https://github.com/DoSomething/phoenix/issues/1806)
- campaign status page - show character limit violators [\#1802](https://github.com/DoSomething/phoenix/issues/1802)
- Campaign Finder - Copy for mobile/desktop homepage views [\#1800](https://github.com/DoSomething/phoenix/issues/1800)
- Campaign Finder - Open all 3 filters when any 1 is clicked [\#1798](https://github.com/DoSomething/phoenix/issues/1798)
- Campaign Finder - Bigger tap areas on filters  [\#1797](https://github.com/DoSomething/phoenix/issues/1797)
- Mail System Module removal - part II [\#1794](https://github.com/DoSomething/phoenix/issues/1794)
- Campaign Finder \(mobile\) - cause should be single select [\#1793](https://github.com/DoSomething/phoenix/issues/1793)
- Remove image cache actions [\#1780](https://github.com/DoSomething/phoenix/issues/1780)
- Campaign Finder \(mobile\) - Remove type and time from mobile [\#1779](https://github.com/DoSomething/phoenix/issues/1779)
- Campaign Finder - when I make a selection within a category, all other options should be unselectable [\#1777](https://github.com/DoSomething/phoenix/issues/1777)
- Finder: Improve Performance [\#1773](https://github.com/DoSomething/phoenix/issues/1773)
- Remove "nipple" from tips that only have one listed [\#1771](https://github.com/DoSomething/phoenix/issues/1771)
- Remove mailsystem from profile and make [\#1759](https://github.com/DoSomething/phoenix/issues/1759)
- Add custom report back field to Comeback Clothes SMS report back submission [\#1751](https://github.com/DoSomething/phoenix/issues/1751)
- Move Message Broker functionality to its own DS module [\#1748](https://github.com/DoSomething/phoenix/issues/1748)
- \[Campaign\] Tweak scholarship callout on pitch page. [\#1742](https://github.com/DoSomething/phoenix/issues/1742)
- Campaign Finder - Mobile filters front-end pass [\#1733](https://github.com/DoSomething/phoenix/issues/1733)
- Campaign Finder - Mobile gallery view front-end pass [\#1732](https://github.com/DoSomething/phoenix/issues/1732)
- Campaign Finder - Network connectivity error state [\#1731](https://github.com/DoSomething/phoenix/issues/1731)
- Campaign Finder - Empty state [\#1730](https://github.com/DoSomething/phoenix/issues/1730)
- Campaign Finder - "show more" pagination [\#1729](https://github.com/DoSomething/phoenix/issues/1729)
- Campaign Finder - Update Time filters [\#1728](https://github.com/DoSomething/phoenix/issues/1728)
- Campaign Finder - Selecting a Type filter clears inactive filters in Type [\#1727](https://github.com/DoSomething/phoenix/issues/1727)
- Campaign Finder - Filter items in Cause not being deactivated correctly  [\#1723](https://github.com/DoSomething/phoenix/issues/1723)
- Campaign Finder - Single select filters [\#1722](https://github.com/DoSomething/phoenix/issues/1722)
- action page \(plan it\) - space above location finder [\#1707](https://github.com/DoSomething/phoenix/issues/1707)
- Reportback view: Display custom field, values [\#1705](https://github.com/DoSomething/phoenix/issues/1705)
- Reportback Field documentation [\#1700](https://github.com/DoSomething/phoenix/issues/1700)
- Production: Remove temp tables [\#1692](https://github.com/DoSomething/phoenix/issues/1692)
- action page \(sources\) - copy running over and off screen when shrink to mobile [\#1691](https://github.com/DoSomething/phoenix/issues/1691)
- Make filters single select on Finder [\#1689](https://github.com/DoSomething/phoenix/issues/1689)
- Finder: Use public IP Address [\#1685](https://github.com/DoSomething/phoenix/issues/1685)
- Add big box to the homepage [\#1683](https://github.com/DoSomething/phoenix/issues/1683)
- Add additional line of four campaign boxes on the homepage [\#1682](https://github.com/DoSomething/phoenix/issues/1682)
- Remove gray box behind finder, add purple + gradient [\#1681](https://github.com/DoSomething/phoenix/issues/1681)
- Finder filter respsonsive bug  [\#1680](https://github.com/DoSomething/phoenix/issues/1680)
- \[Finder\] Pagination [\#1679](https://github.com/DoSomething/phoenix/issues/1679)
- Help tickets not going into ZenDesk for 6 days [\#1674](https://github.com/DoSomething/phoenix/issues/1674)
- action page \(action guides\) -copy running over modal [\#1665](https://github.com/DoSomething/phoenix/issues/1665)
- neue – update handwritten font to COVERED BY YOUR GRACE [\#1658](https://github.com/DoSomething/phoenix/issues/1658)
- \[User Profile\] Style internal content components of profile view. [\#1657](https://github.com/DoSomething/phoenix/issues/1657)
- \[User Profile\] Establish styling/structure to follow site grid. [\#1656](https://github.com/DoSomething/phoenix/issues/1656)
- \[User Profile\] Generate markup for user profile page. [\#1655](https://github.com/DoSomething/phoenix/issues/1655)
- campaign listings \(staging\) - ability to view listings based on changes to campaigns in staging [\#1648](https://github.com/DoSomething/phoenix/issues/1648)
- campaigns - additional report back question [\#1647](https://github.com/DoSomething/phoenix/issues/1647)
- CTIA messaging [\#1617](https://github.com/DoSomething/phoenix/issues/1617)
- action page \(prove it\) – add handwritten scholarship callout [\#1592](https://github.com/DoSomething/phoenix/issues/1592)
- action page \(address collection\) - style modal [\#1539](https://github.com/DoSomething/phoenix/issues/1539)
- Increase PHP memory limit and max children in PHP-FPM [\#1518](https://github.com/DoSomething/phoenix/issues/1518)
- Mailchimp vars cleanup: group\_id [\#1476](https://github.com/DoSomething/phoenix/issues/1476)
- action page \(partners\) - comma and "and" logic with multiple partners [\#1457](https://github.com/DoSomething/phoenix/issues/1457)
- Update Bower version [\#1426](https://github.com/DoSomething/phoenix/issues/1426)
- Import: Update node authors  [\#1417](https://github.com/DoSomething/phoenix/issues/1417)
- Add birthday to user\_register MBP call [\#1323](https://github.com/DoSomething/phoenix/issues/1323)
- action page \(contact\) - need contact us on mobile [\#1202](https://github.com/DoSomething/phoenix/issues/1202)
- action \(header\) – add scholarship call out [\#1184](https://github.com/DoSomething/phoenix/issues/1184)
- Modals - close modals if you click on the page background [\#1128](https://github.com/DoSomething/phoenix/issues/1128)
- auth - error shake only occurs first time I make a mistake per field [\#1080](https://github.com/DoSomething/phoenix/issues/1080)
- campaigns form - add another item ajax error [\#1019](https://github.com/DoSomething/phoenix/issues/1019)
- action page \(prove it\) – report back modal styles [\#1015](https://github.com/DoSomething/phoenix/issues/1015)
- action page \(prove it\) – report back modal markup [\#1014](https://github.com/DoSomething/phoenix/issues/1014)
- partners - make partners page dynamic not static content [\#1001](https://github.com/DoSomething/phoenix/issues/1001)
- Dynamic login message - Welcome Back / You've Signed Up [\#980](https://github.com/DoSomething/phoenix/issues/980)
- Upgrade entity contrib module [\#956](https://github.com/DoSomething/phoenix/issues/956)
- all pages – js taking too long to execute on vagrant boxes [\#815](https://github.com/DoSomething/phoenix/issues/815)
- Campaign Run field [\#500](https://github.com/DoSomething/phoenix/issues/500)
- Signup: Security / hidden nid [\#480](https://github.com/DoSomething/phoenix/issues/480)
- Signup: Devel function [\#466](https://github.com/DoSomething/phoenix/issues/466)
- Reportback: Devel function [\#465](https://github.com/DoSomething/phoenix/issues/465)

**Merged pull requests:**

- Neue 3.8 [\#1997](https://github.com/DoSomething/phoenix/pull/1997) ([DFurnes](https://github.com/DFurnes))
- Refactoring  using new neue patterns [\#1995](https://github.com/DoSomething/phoenix/pull/1995) ([weerd](https://github.com/weerd))
- Switch "Bye Bye Bullies" and "Momm-o-grams" on homepage. [\#1994](https://github.com/DoSomething/phoenix/pull/1994) ([DFurnes](https://github.com/DFurnes))
- Campaign Group: Signup form [\#1990](https://github.com/DoSomething/phoenix/pull/1990) ([aaronschachter](https://github.com/aaronschachter))
- User search: First/last name filters [\#1983](https://github.com/DoSomething/phoenix/pull/1983) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Group: Child signups [\#1981](https://github.com/DoSomething/phoenix/pull/1981) ([aaronschachter](https://github.com/aaronschachter))
- Adding transactional email copy field [\#1979](https://github.com/DoSomething/phoenix/pull/1979) ([blisteringherb](https://github.com/blisteringherb))
- Adding campaign group tpl and refactoring to reuse campaign code [\#1978](https://github.com/DoSomething/phoenix/pull/1978) ([blisteringherb](https://github.com/blisteringherb))
- Fixes for some bugs in User Profile. [\#1977](https://github.com/DoSomething/phoenix/pull/1977) ([weerd](https://github.com/weerd))
- Adding a field to determine whether the signup form is displayed [\#1974](https://github.com/DoSomething/phoenix/pull/1974) ([blisteringherb](https://github.com/blisteringherb))
- Reportback view: Expose email as a filter [\#1971](https://github.com/DoSomething/phoenix/pull/1971) ([aaronschachter](https://github.com/aaronschachter))
- Updates after moving some styles over to Neue [\#1970](https://github.com/DoSomething/phoenix/pull/1970) ([weerd](https://github.com/weerd))
- Properly capitalize path in require. [\#1968](https://github.com/DoSomething/phoenix/pull/1968) ([DFurnes](https://github.com/DFurnes))
- Updated homepage.  [\#1966](https://github.com/DoSomething/phoenix/pull/1966) ([DFurnes](https://github.com/DFurnes))
- Dependency man [\#1965](https://github.com/DoSomething/phoenix/pull/1965) ([DFurnes](https://github.com/DFurnes))
- dosomething\_signup\_create [\#1964](https://github.com/DoSomething/phoenix/pull/1964) ([aaronschachter](https://github.com/aaronschachter))
- Removing view\_unpublished from dependencies [\#1963](https://github.com/DoSomething/phoenix/pull/1963) ([blisteringherb](https://github.com/blisteringherb))
- Fixing copy/paste errors [\#1962](https://github.com/DoSomething/phoenix/pull/1962) ([blisteringherb](https://github.com/blisteringherb))
- User profile  design updates [\#1958](https://github.com/DoSomething/phoenix/pull/1958) ([weerd](https://github.com/weerd))
- Removing unnecessary fields and grouping for better usability [\#1955](https://github.com/DoSomething/phoenix/pull/1955) ([blisteringherb](https://github.com/blisteringherb))
- Prompt signup data form [\#1945](https://github.com/DoSomething/phoenix/pull/1945) ([aaronschachter](https://github.com/aaronschachter))
- Adding addtional fields for campaign group pre and post sign up [\#1944](https://github.com/DoSomething/phoenix/pull/1944) ([blisteringherb](https://github.com/blisteringherb))
- Signup data form fix. [\#1942](https://github.com/DoSomething/phoenix/pull/1942) ([aaronschachter](https://github.com/aaronschachter))
- Signup: Response data [\#1934](https://github.com/DoSomething/phoenix/pull/1934) ([aaronschachter](https://github.com/aaronschachter))
- Better image upload [\#1928](https://github.com/DoSomething/phoenix/pull/1928) ([DFurnes](https://github.com/DFurnes))
- Fix for the black background issue on search results page. [\#1923](https://github.com/DoSomething/phoenix/pull/1923) ([weerd](https://github.com/weerd))
- Some initial very basic styles for the User Profile edit form. [\#1922](https://github.com/DoSomething/phoenix/pull/1922) ([weerd](https://github.com/weerd))
- Collect and save why a user signs up [\#1919](https://github.com/DoSomething/phoenix/pull/1919) ([aaronschachter](https://github.com/aaronschachter))
- Signup Data Form configuration: required + why\_signedup [\#1914](https://github.com/DoSomething/phoenix/pull/1914) ([aaronschachter](https://github.com/aaronschachter))
- Fixed registration link fallback URL. [\#1911](https://github.com/DoSomething/phoenix/pull/1911) ([DFurnes](https://github.com/DFurnes))
- Defining the Campaign Group content type [\#1910](https://github.com/DoSomething/phoenix/pull/1910) ([blisteringherb](https://github.com/blisteringherb))
- User profile  stylez [\#1909](https://github.com/DoSomething/phoenix/pull/1909) ([weerd](https://github.com/weerd))
- Fixed issue with reportback form validation. [\#1906](https://github.com/DoSomething/phoenix/pull/1906) ([DFurnes](https://github.com/DFurnes))
- Restores IE8 polyfills. [\#1905](https://github.com/DoSomething/phoenix/pull/1905) ([DFurnes](https://github.com/DFurnes))
- Remove environment\_indicator module from profile [\#1892](https://github.com/DoSomething/phoenix/pull/1892) ([aaronschachter](https://github.com/aaronschachter))
- Uses AMD Neue interface from Neue 3.5. [\#1888](https://github.com/DoSomething/phoenix/pull/1888) ([DFurnes](https://github.com/DFurnes))
- Always be linting [\#1886](https://github.com/DoSomething/phoenix/pull/1886) ([DFurnes](https://github.com/DFurnes))
- New pull request to get around crazy merge [\#1883](https://github.com/DoSomething/phoenix/pull/1883) ([DeeZone](https://github.com/DeeZone))
- User profile  markup [\#1880](https://github.com/DoSomething/phoenix/pull/1880) ([weerd](https://github.com/weerd))
- Remove extra states [\#1879](https://github.com/DoSomething/phoenix/pull/1879) ([angaither](https://github.com/angaither))
- Drupal.js [\#1878](https://github.com/DoSomething/phoenix/pull/1878) ([DFurnes](https://github.com/DFurnes))
- Adds international core deploy step [\#1877](https://github.com/DoSomething/phoenix/pull/1877) ([desmondmorris](https://github.com/desmondmorris))
- Campaign block template [\#1874](https://github.com/DoSomething/phoenix/pull/1874) ([aaronschachter](https://github.com/aaronschachter))
- Signup Data Form: Already submitted [\#1871](https://github.com/DoSomething/phoenix/pull/1871) ([aaronschachter](https://github.com/aaronschachter))
- Uses same arrow as footer in campaign finder. [\#1865](https://github.com/DoSomething/phoenix/pull/1865) ([DFurnes](https://github.com/DFurnes))
- Recompile dev JS build if config files change. [\#1864](https://github.com/DoSomething/phoenix/pull/1864) ([DFurnes](https://github.com/DFurnes))
- Makes sure to redirect with modal open \(but doesn't lose form state\). [\#1863](https://github.com/DoSomething/phoenix/pull/1863) ([DFurnes](https://github.com/DFurnes))
- Redirect with modal open on form error. [\#1858](https://github.com/DoSomething/phoenix/pull/1858) ([DFurnes](https://github.com/DFurnes))
- Fix all the things [\#1857](https://github.com/DoSomething/phoenix/pull/1857) ([angaither](https://github.com/angaither))
- Updates to campaign finder filter tap targets, styles, and othe misc fix... [\#1852](https://github.com/DoSomething/phoenix/pull/1852) ([weerd](https://github.com/weerd))
- Don't validate null string addresses. [\#1846](https://github.com/DoSomething/phoenix/pull/1846) ([angaither](https://github.com/angaither))
- Made reportback form look prettier. [\#1842](https://github.com/DoSomething/phoenix/pull/1842) ([DFurnes](https://github.com/DFurnes))
- Issue1748-Create\_dosomething\_mbp-v2 [\#1838](https://github.com/DoSomething/phoenix/pull/1838) ([DeeZone](https://github.com/DeeZone))
- Changing finder to use search.ds.org [\#1837](https://github.com/DoSomething/phoenix/pull/1837) ([blisteringherb](https://github.com/blisteringherb))
- Fixing the block that doesn't clear stuff. [\#1835](https://github.com/DoSomething/phoenix/pull/1835) ([weerd](https://github.com/weerd))
- Fixes link not working. [\#1834](https://github.com/DoSomething/phoenix/pull/1834) ([DFurnes](https://github.com/DFurnes))
- Adds missing array quotes. [\#1833](https://github.com/DoSomething/phoenix/pull/1833) ([DFurnes](https://github.com/DFurnes))
- Updaing the copy and styling of copy for home page finder. [\#1832](https://github.com/DoSomething/phoenix/pull/1832) ([weerd](https://github.com/weerd))
- Add some square image styles for @dfurnes [\#1831](https://github.com/DoSomething/phoenix/pull/1831) ([angaither](https://github.com/angaither))
- Generate homepage from an array of NIDs. [\#1830](https://github.com/DoSomething/phoenix/pull/1830) ([DFurnes](https://github.com/DFurnes))
- Switching finder URL to prod [\#1828](https://github.com/DoSomething/phoenix/pull/1828) ([blisteringherb](https://github.com/blisteringherb))
- Campaign finder  no results [\#1827](https://github.com/DoSomething/phoenix/pull/1827) ([weerd](https://github.com/weerd))
- Signup Data Form: Display submitted copy [\#1826](https://github.com/DoSomething/phoenix/pull/1826) ([aaronschachter](https://github.com/aaronschachter))
- Update address validation errors [\#1823](https://github.com/DoSomething/phoenix/pull/1823) ([angaither](https://github.com/angaither))
- Add address validation to user/edit page. [\#1821](https://github.com/DoSomething/phoenix/pull/1821) ([angaither](https://github.com/angaither))
- UPS Error response counts as a bad address. [\#1819](https://github.com/DoSomething/phoenix/pull/1819) ([angaither](https://github.com/angaither))
- Pagination time [\#1813](https://github.com/DoSomething/phoenix/pull/1813) ([DFurnes](https://github.com/DFurnes))
- Validate address on form [\#1812](https://github.com/DoSomething/phoenix/pull/1812) ([angaither](https://github.com/angaither))
- Signup entity [\#1810](https://github.com/DoSomething/phoenix/pull/1810) ([aaronschachter](https://github.com/aaronschachter))
- Campaign finder  error messages [\#1805](https://github.com/DoSomething/phoenix/pull/1805) ([weerd](https://github.com/weerd))
- Admin campaign status page [\#1804](https://github.com/DoSomething/phoenix/pull/1804) ([aaronschachter](https://github.com/aaronschachter))
- Removed imagecache from info & make file. [\#1796](https://github.com/DoSomething/phoenix/pull/1796) ([angaither](https://github.com/angaither))
- Last step in removing the Mail System module [\#1795](https://github.com/DoSomething/phoenix/pull/1795) ([DeeZone](https://github.com/DeeZone))
- Disable those fields [\#1785](https://github.com/DoSomething/phoenix/pull/1785) ([DFurnes](https://github.com/DFurnes))
- Remove image cache presets that used image cache actions [\#1782](https://github.com/DoSomething/phoenix/pull/1782) ([angaither](https://github.com/angaither))
- Fixing IE8 filter bug and updating markup, styles for all browsers. Huzzah! [\#1781](https://github.com/DoSomething/phoenix/pull/1781) ([weerd](https://github.com/weerd))
- Removes mailsystem [\#1778](https://github.com/DoSomething/phoenix/pull/1778) ([DeeZone](https://github.com/DeeZone))
- Improve performance by reducing solr obj size and enabling caching [\#1774](https://github.com/DoSomething/phoenix/pull/1774) ([blisteringherb](https://github.com/blisteringherb))
- Implementing clear function when everything is unchecked [\#1772](https://github.com/DoSomething/phoenix/pull/1772) ([blisteringherb](https://github.com/blisteringherb))
- Validate address [\#1768](https://github.com/DoSomething/phoenix/pull/1768) ([angaither](https://github.com/angaither))
- Campaign finder  mobile style updates [\#1767](https://github.com/DoSomething/phoenix/pull/1767) ([weerd](https://github.com/weerd))
- Fixing inconsistency when filters are selected in different orders [\#1763](https://github.com/DoSomething/phoenix/pull/1763) ([blisteringherb](https://github.com/blisteringherb))
- Added dropoff question to Comeback Clothes SMS report back. [\#1761](https://github.com/DoSomething/phoenix/pull/1761) ([jonuy](https://github.com/jonuy))
- Rough proof of concept of a scholarship page. [\#1757](https://github.com/DoSomething/phoenix/pull/1757) ([angaither](https://github.com/angaither))
- Fixes reportback field submit error [\#1754](https://github.com/DoSomething/phoenix/pull/1754) ([aaronschachter](https://github.com/aaronschachter))
- Fixed up some linting errors. [\#1747](https://github.com/DoSomething/phoenix/pull/1747) ([DFurnes](https://github.com/DFurnes))
- Fix to radio button inputs on report back modal on campaigns. [\#1745](https://github.com/DoSomething/phoenix/pull/1745) ([weerd](https://github.com/weerd))
- Fixing incorrect deactivation of choices when Time or Type selected. [\#1744](https://github.com/DoSomething/phoenix/pull/1744) ([DFurnes](https://github.com/DFurnes))
- Quick update to adjust scholarship callout on pitch page to not fall on ... [\#1743](https://github.com/DoSomething/phoenix/pull/1743) ([weerd](https://github.com/weerd))
- Returns to blank slate if all fields are unchecked. [\#1741](https://github.com/DoSomething/phoenix/pull/1741) ([DFurnes](https://github.com/DFurnes))
- Quick update to allow text-wrapping in long link sources in, well, the s... [\#1740](https://github.com/DoSomething/phoenix/pull/1740) ([weerd](https://github.com/weerd))
- Fix php undefined index errors. [\#1738](https://github.com/DoSomething/phoenix/pull/1738) ([angaither](https://github.com/angaither))
- Reportback field display [\#1737](https://github.com/DoSomething/phoenix/pull/1737) ([aaronschachter](https://github.com/aaronschachter))
- Form refactor [\#1736](https://github.com/DoSomething/phoenix/pull/1736) ([DFurnes](https://github.com/DFurnes))
- Update to adjust spacing on 'Find a Location' section on tablet view. [\#1734](https://github.com/DoSomething/phoenix/pull/1734) ([weerd](https://github.com/weerd))
- Moar fixie [\#1726](https://github.com/DoSomething/phoenix/pull/1726) ([aaronschachter](https://github.com/aaronschachter))
- Single-select on Campaign Finder [\#1725](https://github.com/DoSomething/phoenix/pull/1725) ([DFurnes](https://github.com/DFurnes))
- Fixes PHP warnings [\#1716](https://github.com/DoSomething/phoenix/pull/1716) ([aaronschachter](https://github.com/aaronschachter))
- Refactors Solr logic into separate adapter class. [\#1714](https://github.com/DoSomething/phoenix/pull/1714) ([DFurnes](https://github.com/DFurnes))
- Fixes IE8 style bugs. [\#1713](https://github.com/DoSomething/phoenix/pull/1713) ([DFurnes](https://github.com/DFurnes))
- More campaign finder cleanup [\#1712](https://github.com/DoSomething/phoenix/pull/1712) ([DFurnes](https://github.com/DFurnes))
- Campaign finder initial state [\#1708](https://github.com/DoSomething/phoenix/pull/1708) ([DFurnes](https://github.com/DFurnes))
- Add commas and ands to in partnership with list. [\#1704](https://github.com/DoSomething/phoenix/pull/1704) ([angaither](https://github.com/angaither))
- Action pages  font updates [\#1703](https://github.com/DoSomething/phoenix/pull/1703) ([weerd](https://github.com/weerd))
- Update node authors script. [\#1699](https://github.com/DoSomething/phoenix/pull/1699) ([angaither](https://github.com/angaither))
- Reportback form: Custom field [\#1698](https://github.com/DoSomething/phoenix/pull/1698) ([aaronschachter](https://github.com/aaronschachter))
- Campaign finder lazy load [\#1697](https://github.com/DoSomething/phoenix/pull/1697) ([DFurnes](https://github.com/DFurnes))
- Fixes all special chars on '/campaings' [\#1694](https://github.com/DoSomething/phoenix/pull/1694) ([angaither](https://github.com/angaither))
- Reportback field schema [\#1690](https://github.com/DoSomething/phoenix/pull/1690) ([aaronschachter](https://github.com/aaronschachter))
- Address finder style [\#1687](https://github.com/DoSomething/phoenix/pull/1687) ([DFurnes](https://github.com/DFurnes))
- Using public IP for solr [\#1686](https://github.com/DoSomething/phoenix/pull/1686) ([blisteringherb](https://github.com/blisteringherb))
- Design fixes, simplifies tile rendering. [\#1684](https://github.com/DoSomething/phoenix/pull/1684) ([DFurnes](https://github.com/DFurnes))
- Campaign finder feature flag [\#1677](https://github.com/DoSomething/phoenix/pull/1677) ([DFurnes](https://github.com/DFurnes))
- Updates to the action pages for the modal and the Prove It footer. [\#1676](https://github.com/DoSomething/phoenix/pull/1676) ([weerd](https://github.com/weerd))
- Removing textarea.js file that Drupal adds since it was breaking the JS ... [\#1672](https://github.com/DoSomething/phoenix/pull/1672) ([weerd](https://github.com/weerd))
- Campaign signup security. [\#1671](https://github.com/DoSomething/phoenix/pull/1671) ([angaither](https://github.com/angaither))
- Updated CTIA. Fixes \#1617. [\#1670](https://github.com/DoSomething/phoenix/pull/1670) ([DFurnes](https://github.com/DFurnes))

## [v0.2.1](https://github.com/dosomething/phoenix/tree/v0.2.1) (2014-04-07)
[Full Changelog](https://github.com/dosomething/phoenix/compare/v0.2.0...v0.2.1)

**Fixed bugs:**

- Log out relative path [\#1646](https://github.com/DoSomething/phoenix/issues/1646)
- modal banner – default styles from Neue overridden [\#1644](https://github.com/DoSomething/phoenix/issues/1644)
- Fix WatchDog issue reporting undefined variables [\#1641](https://github.com/DoSomething/phoenix/issues/1641)
- Reportback log records with uid 0 [\#1628](https://github.com/DoSomething/phoenix/issues/1628)
- Campaign pitch metatag images [\#1620](https://github.com/DoSomething/phoenix/issues/1620)
- 11 Facts - error on production \(beta\) [\#1571](https://github.com/DoSomething/phoenix/issues/1571)
- Drush features-revert error: Drush command terminated abnormally due to an unrecoverable error. [\#1568](https://github.com/DoSomething/phoenix/issues/1568)
- Static content: Drop field\_cta\_button\_text [\#1563](https://github.com/DoSomething/phoenix/issues/1563)
- Reportback file extensions [\#1526](https://github.com/DoSomething/phoenix/issues/1526)
- Devel module doesnt fully enable via drush [\#1523](https://github.com/DoSomething/phoenix/issues/1523)
- Log-in form is now requesting address [\#1521](https://github.com/DoSomething/phoenix/issues/1521)
- Aaron Schachter takeover [\#1508](https://github.com/DoSomething/phoenix/issues/1508)
- Undefined variable: bottom\_region [\#1491](https://github.com/DoSomething/phoenix/issues/1491)
- action page \(prove it\) - report back modal background is transparent [\#1490](https://github.com/DoSomething/phoenix/issues/1490)
- EntityMetadataWrapperException: Unknown data property field\_video. [\#1489](https://github.com/DoSomething/phoenix/issues/1489)
- action page \(all\) - Step 1, 2, etc. bands [\#1464](https://github.com/DoSomething/phoenix/issues/1464)
- action page \(sponsor modal\) - on mobile image isn't getting resized [\#1437](https://github.com/DoSomething/phoenix/issues/1437)
- campaign \(form\) - AJAX error on entity reference fields [\#1436](https://github.com/DoSomething/phoenix/issues/1436)
- Paypal donate button - not working [\#1404](https://github.com/DoSomething/phoenix/issues/1404)
- campaign / static content – button text underlined [\#1400](https://github.com/DoSomething/phoenix/issues/1400)
- campaigns – updated image mask not always loading [\#1399](https://github.com/DoSomething/phoenix/issues/1399)
- /user/login styles broken [\#1395](https://github.com/DoSomething/phoenix/issues/1395)
- registration - error after entering 6 character password [\#1394](https://github.com/DoSomething/phoenix/issues/1394)
- Mind On My Money - getting incorrect under 13 flag [\#1390](https://github.com/DoSomething/phoenix/issues/1390)
- zendesk error on second submission [\#1388](https://github.com/DoSomething/phoenix/issues/1388)
- /about page cannot be found [\#1373](https://github.com/DoSomething/phoenix/issues/1373)
- action page \(do it\) - tips functionality is broken [\#1349](https://github.com/DoSomething/phoenix/issues/1349)
- action page \(report back\) - error message when updating report back with second image [\#1347](https://github.com/DoSomething/phoenix/issues/1347)
- auth - confirm password not recognizing identical passwords [\#1332](https://github.com/DoSomething/phoenix/issues/1332)
- pitch page \(sponsor logo\) - powered by still showing if no logo present [\#1329](https://github.com/DoSomething/phoenix/issues/1329)
- pitch page - campaign boilerplate copy changes [\#1314](https://github.com/DoSomething/phoenix/issues/1314)
- footer - weird spacing on mobile [\#1312](https://github.com/DoSomething/phoenix/issues/1312)
- /campaigns and search results headers are overlapping with nav [\#1311](https://github.com/DoSomething/phoenix/issues/1311)
- pitch page \(sponsor logo\) - need to fix the container for sponsor logos [\#1280](https://github.com/DoSomething/phoenix/issues/1280)
- campaign \(confirmation page\) - captain underpants button has whack characters [\#1265](https://github.com/DoSomething/phoenix/issues/1265)
- campaign \(pitch\) - error message signing up for campaigns as a logged in user [\#1262](https://github.com/DoSomething/phoenix/issues/1262)
- Webfonts serving with wrong mime-type; Firefox disapproves [\#1254](https://github.com/DoSomething/phoenix/issues/1254)
- action page \(do it\) - after tips are not appearing [\#1253](https://github.com/DoSomething/phoenix/issues/1253)
- auth - error notifications don't appear on campaign pages [\#1249](https://github.com/DoSomething/phoenix/issues/1249)
- campaign - header image starts below the navigation for all campaigns other than Comeback Clothes [\#1244](https://github.com/DoSomething/phoenix/issues/1244)
- Search: Fix front page search box [\#1239](https://github.com/DoSomething/phoenix/issues/1239)
- Static content - Intro section and gallery bugs [\#1232](https://github.com/DoSomething/phoenix/issues/1232)
- Reportback form cleanup [\#1231](https://github.com/DoSomething/phoenix/issues/1231)
- Search: Fix search boxes [\#1229](https://github.com/DoSomething/phoenix/issues/1229)
- action page \(do it\) - image floating in bottom left hand corner [\#1226](https://github.com/DoSomething/phoenix/issues/1226)
- Search: /campaigns fix links [\#1216](https://github.com/DoSomething/phoenix/issues/1216)
- Global - Site-specific CSS not loading correctly [\#1207](https://github.com/DoSomething/phoenix/issues/1207)
- campaign – JavaScript is not compiling on Stage [\#1179](https://github.com/DoSomething/phoenix/issues/1179)
- action page \(prove it\) - arrows around photo are not visible on mobile [\#1178](https://github.com/DoSomething/phoenix/issues/1178)
- action page \(nav\) - breaks on mobile in Do It section [\#1176](https://github.com/DoSomething/phoenix/issues/1176)
- action \(all\) – nav position below content [\#1172](https://github.com/DoSomething/phoenix/issues/1172)
- action page \(do it\) - polaroid container getting obscured by the image inside [\#1171](https://github.com/DoSomething/phoenix/issues/1171)
- Static content - Gallery bugs/updates [\#1144](https://github.com/DoSomething/phoenix/issues/1144)
- campaign \(form\) - Alt background pattern field bug [\#1134](https://github.com/DoSomething/phoenix/issues/1134)
- Webfonts aren't working correctly in Firefox [\#1133](https://github.com/DoSomething/phoenix/issues/1133)
- Campaign pitch page: Disappearing sign up button [\#1131](https://github.com/DoSomething/phoenix/issues/1131)
- action page \(zendesk\) - "Have a question" should not change color for sponsored campaigns [\#1124](https://github.com/DoSomething/phoenix/issues/1124)
- action page \(modals\) - header missing [\#1123](https://github.com/DoSomething/phoenix/issues/1123)
- action page \(plan it\) - location finder styling updates [\#1122](https://github.com/DoSomething/phoenix/issues/1122)
- action page \(prove it\) - need to use H&M specific background pattern [\#1121](https://github.com/DoSomething/phoenix/issues/1121)
- action page \(prove it\) - image not appearing \(not even broken image icon\) [\#1119](https://github.com/DoSomething/phoenix/issues/1119)
- Sticky elements break between breakpoints [\#1116](https://github.com/DoSomething/phoenix/issues/1116)
- pitch page \(all\) - styling updates [\#1115](https://github.com/DoSomething/phoenix/issues/1115)
- action page \(do it\) - can't click between tips [\#1114](https://github.com/DoSomething/phoenix/issues/1114)
- action page \(do it\) - image not showing inside polaroid container [\#1113](https://github.com/DoSomething/phoenix/issues/1113)
- Reportback log bug [\#1094](https://github.com/DoSomething/phoenix/issues/1094)
- Reportback File renaming [\#1079](https://github.com/DoSomething/phoenix/issues/1079)
- campaign \(header\) – add default header [\#1077](https://github.com/DoSomething/phoenix/issues/1077)
- Reportback confirmation page error [\#1068](https://github.com/DoSomething/phoenix/issues/1068)
- Message Broker - email value missing in $payload [\#1064](https://github.com/DoSomething/phoenix/issues/1064)
- Global - Media Query polyfill not loading correctly [\#1058](https://github.com/DoSomething/phoenix/issues/1058)
- auth - incorrect error behavior if user provides invalid email [\#1057](https://github.com/DoSomething/phoenix/issues/1057)
- Reportback: public files subdirectory error [\#1054](https://github.com/DoSomething/phoenix/issues/1054)
- staff pick campaigns - Mobile Commons id/MailChimp group subscriptions [\#1050](https://github.com/DoSomething/phoenix/issues/1050)
- Modals don't properly close on Firefox [\#1018](https://github.com/DoSomething/phoenix/issues/1018)
- Auth modal - layout messed up [\#1012](https://github.com/DoSomething/phoenix/issues/1012)
- Auth Modal - Fails on MM/DD/YY date syntax [\#1007](https://github.com/DoSomething/phoenix/issues/1007)
- auth - error messages for password and confirm password [\#1000](https://github.com/DoSomething/phoenix/issues/1000)
- auth - birthday confirmation is inaccurate [\#998](https://github.com/DoSomething/phoenix/issues/998)
- auth modal – rendering behind youtube video in ff/ie [\#985](https://github.com/DoSomething/phoenix/issues/985)
- action page \(know it\) - \<script\> not being closed somewhere [\#970](https://github.com/DoSomething/phoenix/issues/970)
- User form: Warning: Invalid argument supplied for foreach\(\) [\#968](https://github.com/DoSomething/phoenix/issues/968)
- 11 Facts - Broken Images [\#963](https://github.com/DoSomething/phoenix/issues/963)
- Video Field Collection is\_empty\_alter [\#949](https://github.com/DoSomething/phoenix/issues/949)
- Campaign tpl: Notice: Undefined variable: end\_date [\#943](https://github.com/DoSomething/phoenix/issues/943)
- DS update-files removes symlinks [\#939](https://github.com/DoSomething/phoenix/issues/939)
- Campaign: Bug in "Learn more about" link  [\#937](https://github.com/DoSomething/phoenix/issues/937)
- Partners field\_collection default value bug [\#936](https://github.com/DoSomething/phoenix/issues/936)
- Image Styles features-revert error [\#934](https://github.com/DoSomething/phoenix/issues/934)
- Campaign field\_partners [\#927](https://github.com/DoSomething/phoenix/issues/927)
- Update Cached Modal Syntax [\#925](https://github.com/DoSomething/phoenix/issues/925)
- Misc. Campaign Style Updates [\#917](https://github.com/DoSomething/phoenix/issues/917)
- Campaign Wrapper Syntax [\#908](https://github.com/DoSomething/phoenix/issues/908)
- Markdown fields aren't working on Action Guides [\#891](https://github.com/DoSomething/phoenix/issues/891)
- DS User: Undefined variable user [\#887](https://github.com/DoSomething/phoenix/issues/887)
- Campaign: user should see "confirmation" page after reporting back [\#865](https://github.com/DoSomething/phoenix/issues/865)
- Validation issue with Drupal's birthdate form markup [\#853](https://github.com/DoSomething/phoenix/issues/853)
- Admin perms: Field collection and field group [\#842](https://github.com/DoSomething/phoenix/issues/842)
- Static content - Gallery image isn't appearing correctly [\#840](https://github.com/DoSomething/phoenix/issues/840)
- Static content - Empty Youtube video always appears [\#839](https://github.com/DoSomething/phoenix/issues/839)
- Static content - intro\_image not displaying [\#836](https://github.com/DoSomething/phoenix/issues/836)
- action \(prove it\) – update pagination buttons [\#829](https://github.com/DoSomething/phoenix/issues/829)
- action \(prove it\) – gallery missing fallback elements [\#828](https://github.com/DoSomething/phoenix/issues/828)
- pitch \(header\) — scholarship always prints to the page [\#824](https://github.com/DoSomething/phoenix/issues/824)
- Fatal error: Mobilecommons not found [\#810](https://github.com/DoSomething/phoenix/issues/810)
- Grunt isn't running Browserify on watch [\#808](https://github.com/DoSomething/phoenix/issues/808)
- DS User: Update "administrator" role variable. [\#805](https://github.com/DoSomething/phoenix/issues/805)
- DS build --install: Apache Solr errors [\#794](https://github.com/DoSomething/phoenix/issues/794)
- DS build --install errors:  xmlsitemap [\#787](https://github.com/DoSomething/phoenix/issues/787)
- Drush error:  Cannot change an existing field's type [\#785](https://github.com/DoSomething/phoenix/issues/785)
- DS Build --install error: blocked\_ips not found [\#784](https://github.com/DoSomething/phoenix/issues/784)
- DS Profile: Enable mobilecommons  [\#778](https://github.com/DoSomething/phoenix/issues/778)
- Preprocess JS - User.js [\#764](https://github.com/DoSomething/phoenix/issues/764)
- Reportback: Error if you upload same image [\#756](https://github.com/DoSomething/phoenix/issues/756)
- Reportback modal needs a close button [\#755](https://github.com/DoSomething/phoenix/issues/755)
- Update EntityConnect perms [\#743](https://github.com/DoSomething/phoenix/issues/743)
- EntityConnect WSOD [\#736](https://github.com/DoSomething/phoenix/issues/736)
- Auth modals in campaign template [\#715](https://github.com/DoSomething/phoenix/issues/715)
- action page \(prove it\) – gallery images are missing [\#711](https://github.com/DoSomething/phoenix/issues/711)
- action page \(prove it\) – button styles [\#708](https://github.com/DoSomething/phoenix/issues/708)
- action page \(do it\) – last content section missing copy [\#707](https://github.com/DoSomething/phoenix/issues/707)
- action page \(do it\) – tip funcitonality [\#705](https://github.com/DoSomething/phoenix/issues/705)
- action page \(do it\) – tip styles [\#704](https://github.com/DoSomething/phoenix/issues/704)
- action page \(do it\) – header styles [\#703](https://github.com/DoSomething/phoenix/issues/703)
- action page \(know it\) – facts and their sources are missing [\#701](https://github.com/DoSomething/phoenix/issues/701)
- action page \(know it\) – "the problem" video / image placeholder is missing [\#700](https://github.com/DoSomething/phoenix/issues/700)
- action page \(know it\) – "the problem" copy is missing [\#699](https://github.com/DoSomething/phoenix/issues/699)
- action page \(navigation\) – nav. not scrolling [\#696](https://github.com/DoSomething/phoenix/issues/696)
- action page \(header\) – remove scholarship call-out [\#695](https://github.com/DoSomething/phoenix/issues/695)
- DS build: Securepages not working [\#689](https://github.com/DoSomething/phoenix/issues/689)
- JavaScript - "Drupal is not defined" [\#670](https://github.com/DoSomething/phoenix/issues/670)
- ds script assumes sandbox environment [\#564](https://github.com/DoSomething/phoenix/issues/564)
- Vagrant: apache doesn't automatically start [\#390](https://github.com/DoSomething/phoenix/issues/390)
- Vagrant: SSH key goes missing. [\#293](https://github.com/DoSomething/phoenix/issues/293)
- Contrib module subdirectory [\#181](https://github.com/DoSomething/phoenix/issues/181)
- Adding additional boost to campaign type to improve ranking [\#1451](https://github.com/DoSomething/phoenix/pull/1451) ([blisteringherb](https://github.com/blisteringherb))
- Adding a check to make sure faqs on campaigns are an array [\#1269](https://github.com/DoSomething/phoenix/pull/1269) ([blisteringherb](https://github.com/blisteringherb))
- Adding admin search permissions to administrator role [\#1268](https://github.com/DoSomething/phoenix/pull/1268) ([blisteringherb](https://github.com/blisteringherb))
- Rewriting label output and image to link to campaign [\#1228](https://github.com/DoSomething/phoenix/pull/1228) ([blisteringherb](https://github.com/blisteringherb))
- Adding more campaigns to the view to prevent pagination [\#1188](https://github.com/DoSomething/phoenix/pull/1188) ([blisteringherb](https://github.com/blisteringherb))
- Adding admin perms for Entity Connect and moving to ds\_helpers [\#1140](https://github.com/DoSomething/phoenix/pull/1140) ([blisteringherb](https://github.com/blisteringherb))
- Added missing quote in image tag [\#1048](https://github.com/DoSomething/phoenix/pull/1048) ([angaither](https://github.com/angaither))
- Deeper checking for the presence of a YouTube video [\#1040](https://github.com/DoSomething/phoenix/pull/1040) ([blisteringherb](https://github.com/blisteringherb))

**Closed issues:**

- action page \(partners\) - breaking into two lines [\#1650](https://github.com/DoSomething/phoenix/issues/1650)
- User Profile: recommended campaigns [\#1636](https://github.com/DoSomething/phoenix/issues/1636)
- QA deployment [\#1633](https://github.com/DoSomething/phoenix/issues/1633)
- campaign – refactor mobile padding [\#1629](https://github.com/DoSomething/phoenix/issues/1629)
- homepage - update placement of campaigns [\#1624](https://github.com/DoSomething/phoenix/issues/1624)
- Profile: Signup images [\#1618](https://github.com/DoSomething/phoenix/issues/1618)
- Clean up securepages module [\#1611](https://github.com/DoSomething/phoenix/issues/1611)
- Metatag: Opengraph image tag [\#1605](https://github.com/DoSomething/phoenix/issues/1605)
- Fact Page metatag keywords defaults [\#1598](https://github.com/DoSomething/phoenix/issues/1598)
- Fact Page image metatag [\#1597](https://github.com/DoSomething/phoenix/issues/1597)
- Fact Page Metatag defaults [\#1593](https://github.com/DoSomething/phoenix/issues/1593)
- Fact Page pathauto alias [\#1589](https://github.com/DoSomething/phoenix/issues/1589)
- Fact Page CTA alignment [\#1587](https://github.com/DoSomething/phoenix/issues/1587)
- Switch image gradient from Drupal image style to CSS. [\#1586](https://github.com/DoSomething/phoenix/issues/1586)
- /campaigns \(staging\) - HTTP 0; Request failed: Connection timed out [\#1585](https://github.com/DoSomething/phoenix/issues/1585)
- Fact Page - should not default to published [\#1583](https://github.com/DoSomething/phoenix/issues/1583)
- Home page hard-codes some images to http [\#1582](https://github.com/DoSomething/phoenix/issues/1582)
- Eliminate PHP short tags [\#1565](https://github.com/DoSomething/phoenix/issues/1565)
- 11 Facts: Update sources [\#1558](https://github.com/DoSomething/phoenix/issues/1558)
- Update Neue for content links on :hover [\#1555](https://github.com/DoSomething/phoenix/issues/1555)
- Enforce common cache key in Redis [\#1551](https://github.com/DoSomething/phoenix/issues/1551)
- Teens for Jeans - redirect needed [\#1550](https://github.com/DoSomething/phoenix/issues/1550)
- User: Last Name field [\#1545](https://github.com/DoSomething/phoenix/issues/1545)
- Signup Data Form: First Name and Last Name [\#1544](https://github.com/DoSomething/phoenix/issues/1544)
- Quality isn't great on header gradient image [\#1542](https://github.com/DoSomething/phoenix/issues/1542)
- Reportback: Add IP column [\#1541](https://github.com/DoSomething/phoenix/issues/1541)
- Update staff role definitions [\#1532](https://github.com/DoSomething/phoenix/issues/1532)
- Merge Paraneue into main repo [\#1529](https://github.com/DoSomething/phoenix/issues/1529)
- Cache bins should default to Redis [\#1519](https://github.com/DoSomething/phoenix/issues/1519)
- static content - link / button and misc styling [\#1515](https://github.com/DoSomething/phoenix/issues/1515)
- static content - misc spacing [\#1514](https://github.com/DoSomething/phoenix/issues/1514)
- static content - gallery [\#1513](https://github.com/DoSomething/phoenix/issues/1513)
- static content / 11 facts - sync headers with style of campaigns page [\#1512](https://github.com/DoSomething/phoenix/issues/1512)
- static content - call to action [\#1511](https://github.com/DoSomething/phoenix/issues/1511)
- Signup Data Form admin: conditional fields [\#1510](https://github.com/DoSomething/phoenix/issues/1510)
- Signup Data Form [\#1484](https://github.com/DoSomething/phoenix/issues/1484)
- Add Google Analytics tracking to auth modal [\#1473](https://github.com/DoSomething/phoenix/issues/1473)
- Add --force to fr  [\#1462](https://github.com/DoSomething/phoenix/issues/1462)
- Vector art galleries in static content pages [\#1460](https://github.com/DoSomething/phoenix/issues/1460)
- Static Content Front end tweaks  [\#1456](https://github.com/DoSomething/phoenix/issues/1456)
- action page \(prove it\) - design QA todos [\#1455](https://github.com/DoSomething/phoenix/issues/1455)
- Mailchimp Grouping ID vars [\#1454](https://github.com/DoSomething/phoenix/issues/1454)
- action guides - styling needed [\#1453](https://github.com/DoSomething/phoenix/issues/1453)
- action page \(do it\) - design QA todos [\#1452](https://github.com/DoSomething/phoenix/issues/1452)
- action page \(plan it\) - location finder one column [\#1450](https://github.com/DoSomething/phoenix/issues/1450)
- action page \(know it\) - design QA todos [\#1449](https://github.com/DoSomething/phoenix/issues/1449)
- Action page - 18px base font size? [\#1447](https://github.com/DoSomething/phoenix/issues/1447)
- Action page \(structure\) - Grid layout updates [\#1446](https://github.com/DoSomething/phoenix/issues/1446)
- Pitch page - design QA todos [\#1445](https://github.com/DoSomething/phoenix/issues/1445)
- Site background - revisit [\#1444](https://github.com/DoSomething/phoenix/issues/1444)
- Header - design QA todos [\#1443](https://github.com/DoSomething/phoenix/issues/1443)
- Footer - design QA todos [\#1442](https://github.com/DoSomething/phoenix/issues/1442)
- Auth Modal - design QA todos [\#1441](https://github.com/DoSomething/phoenix/issues/1441)
- User search view [\#1429](https://github.com/DoSomething/phoenix/issues/1429)
- Member support role [\#1428](https://github.com/DoSomething/phoenix/issues/1428)
- Foot Locker - log in takes you to a 404 [\#1424](https://github.com/DoSomething/phoenix/issues/1424)
- Image: Up file upload size [\#1421](https://github.com/DoSomething/phoenix/issues/1421)
- Campaign Hero Image meta tags [\#1420](https://github.com/DoSomething/phoenix/issues/1420)
- Data Migration [\#1419](https://github.com/DoSomething/phoenix/issues/1419)
- /campaigns - images paths point to dev.dosomething [\#1412](https://github.com/DoSomething/phoenix/issues/1412)
- auth - failed log in on pitch page takes the user to a 404 [\#1408](https://github.com/DoSomething/phoenix/issues/1408)
- Theme header / nav eats up content. [\#1403](https://github.com/DoSomething/phoenix/issues/1403)
- Zendesk - not showing users' name when questions submitted from Action Page contact us modal [\#1402](https://github.com/DoSomething/phoenix/issues/1402)
- Mind On My Money - header image not showing up on /money \("action" page\) [\#1401](https://github.com/DoSomething/phoenix/issues/1401)
- port to neue – secondary link styles [\#1398](https://github.com/DoSomething/phoenix/issues/1398)
- Sign-up email - Report back button not linked correctly  [\#1397](https://github.com/DoSomething/phoenix/issues/1397)
- Sign-up Email - First Name merge tag not working  [\#1396](https://github.com/DoSomething/phoenix/issues/1396)
- Icons and fonts on old app footer don't display because of incorrect path [\#1391](https://github.com/DoSomething/phoenix/issues/1391)
- campaigns \(confirmation page\) - images on confirmation aren't clickable [\#1389](https://github.com/DoSomething/phoenix/issues/1389)
- email - create default replacement for first name if none exists [\#1378](https://github.com/DoSomething/phoenix/issues/1378)
- nav - not aligned horizontally and partially hidden on ie [\#1368](https://github.com/DoSomething/phoenix/issues/1368)
- email - update subject line for site registration template [\#1361](https://github.com/DoSomething/phoenix/issues/1361)
- Set up Cron in Jenkins [\#1360](https://github.com/DoSomething/phoenix/issues/1360)
- FNAME var in Comeback Clothes sign up email subject and body [\#1354](https://github.com/DoSomething/phoenix/issues/1354)
- action page \(tips\) - If there's only one tip, then it shouldn't be clickable [\#1353](https://github.com/DoSomething/phoenix/issues/1353)
- campaign \(zendesk\)  - error message when submit a question [\#1352](https://github.com/DoSomething/phoenix/issues/1352)
- /campaigns: Change subtitle [\#1345](https://github.com/DoSomething/phoenix/issues/1345)
- action page \(do it\) - after tips are now appearing twice [\#1342](https://github.com/DoSomething/phoenix/issues/1342)
- email - campaign name merge tag not coming in properly on report back transacational [\#1340](https://github.com/DoSomething/phoenix/issues/1340)
- notifications \(mobile\) - logo makes them unreadable [\#1328](https://github.com/DoSomething/phoenix/issues/1328)
- Pass campaign mailchimp group id to MBP request [\#1322](https://github.com/DoSomething/phoenix/issues/1322)
- Update all static content paths to /about [\#1319](https://github.com/DoSomething/phoenix/issues/1319)
- /campaigns - Comeback clothes opens up in new tab [\#1315](https://github.com/DoSomething/phoenix/issues/1315)
- search results - not properly prioritizing results [\#1310](https://github.com/DoSomething/phoenix/issues/1310)
- campaigns - default meta tags [\#1308](https://github.com/DoSomething/phoenix/issues/1308)
- action page \(contact us\) - Contact us modal needs to be styled [\#1307](https://github.com/DoSomething/phoenix/issues/1307)
- /campaigns prioritization is off [\#1306](https://github.com/DoSomething/phoenix/issues/1306)
- static content - header of static content is interfering with nav [\#1305](https://github.com/DoSomething/phoenix/issues/1305)
- email - prove it link in email body copy not linked properly [\#1304](https://github.com/DoSomething/phoenix/issues/1304)
- action page \(plan it\) - remove underline from "Locate" button [\#1303](https://github.com/DoSomething/phoenix/issues/1303)
- campaigns \(confirmation page\) - layout updates [\#1301](https://github.com/DoSomething/phoenix/issues/1301)
- Action Guide modals [\#1297](https://github.com/DoSomething/phoenix/issues/1297)
- Static content - New link styles [\#1291](https://github.com/DoSomething/phoenix/issues/1291)
- auth - we should tell the user the password needs to be 6+ characters [\#1288](https://github.com/DoSomething/phoenix/issues/1288)
- tons of random error messages on admin side [\#1282](https://github.com/DoSomething/phoenix/issues/1282)
- Transactional Emails - not displaying main body [\#1278](https://github.com/DoSomething/phoenix/issues/1278)
- Static Content Galleries - Gallery titles not showing up [\#1276](https://github.com/DoSomething/phoenix/issues/1276)
- Static Content Galleries - alignment and spacing [\#1275](https://github.com/DoSomething/phoenix/issues/1275)
- Old world/new world nid lookup. [\#1272](https://github.com/DoSomething/phoenix/issues/1272)
- Search: Permissions [\#1264](https://github.com/DoSomething/phoenix/issues/1264)
- Signups: Data column  [\#1261](https://github.com/DoSomething/phoenix/issues/1261)
- Campaign PHP Warning [\#1260](https://github.com/DoSomething/phoenix/issues/1260)
- Simple redirects for Legacy SMS Game Campaigns [\#1259](https://github.com/DoSomething/phoenix/issues/1259)
- Import additional signup data [\#1252](https://github.com/DoSomething/phoenix/issues/1252)
- Link up all of the header/footer links [\#1251](https://github.com/DoSomething/phoenix/issues/1251)
- Campaign: Errors on signup [\#1246](https://github.com/DoSomething/phoenix/issues/1246)
- Static content - Gradient on header to match campaigns template [\#1234](https://github.com/DoSomething/phoenix/issues/1234)
- Static content - Style updates [\#1233](https://github.com/DoSomething/phoenix/issues/1233)
- SMS transactional message not delivered on sign up [\#1225](https://github.com/DoSomething/phoenix/issues/1225)
- New navigation into old ds.org [\#1221](https://github.com/DoSomething/phoenix/issues/1221)
- Stub node redirects [\#1219](https://github.com/DoSomething/phoenix/issues/1219)
- Old World URLs [\#1218](https://github.com/DoSomething/phoenix/issues/1218)
- Import Signup Data  [\#1217](https://github.com/DoSomething/phoenix/issues/1217)
- Stub Campaign Nodes on Stage [\#1215](https://github.com/DoSomething/phoenix/issues/1215)
- Legacy campaign redirects [\#1213](https://github.com/DoSomething/phoenix/issues/1213)
- Explore Campaigns page theming [\#1209](https://github.com/DoSomething/phoenix/issues/1209)
- action page \(do it\) - menu items in nav aren't active when in Do It [\#1208](https://github.com/DoSomething/phoenix/issues/1208)
- action page \(prove it\) - Tweak official rules link [\#1205](https://github.com/DoSomething/phoenix/issues/1205)
- action page \(do it\) - fix landscape \(mobile view\) version of polaroid [\#1204](https://github.com/DoSomething/phoenix/issues/1204)
- action page \(plan it\) - tighten up margin under The Solution [\#1203](https://github.com/DoSomething/phoenix/issues/1203)
- action page \(do it\) - hide tips in modal on mobile [\#1200](https://github.com/DoSomething/phoenix/issues/1200)
- action page - general style tweaks [\#1199](https://github.com/DoSomething/phoenix/issues/1199)
- Sitewide Footer - remove mobile search and ds logo [\#1198](https://github.com/DoSomething/phoenix/issues/1198)
- Sitewide Footer - bg black [\#1197](https://github.com/DoSomething/phoenix/issues/1197)
- Campaign footer - bg charcoal and update copy [\#1196](https://github.com/DoSomething/phoenix/issues/1196)
- auth - language and button enhancements [\#1194](https://github.com/DoSomething/phoenix/issues/1194)
- Campaign header images - Implement new gradient [\#1193](https://github.com/DoSomething/phoenix/issues/1193)
- Search:  Display enough results to avoid paging [\#1187](https://github.com/DoSomething/phoenix/issues/1187)
- Minor visual tweaks before design review [\#1182](https://github.com/DoSomething/phoenix/issues/1182)
- Comeback Clothes SMS tips [\#1164](https://github.com/DoSomething/phoenix/issues/1164)
- campaign \(all\) – clean up inline styles [\#1159](https://github.com/DoSomething/phoenix/issues/1159)
- Change function names that use "cell" to use "mobile" [\#1158](https://github.com/DoSomething/phoenix/issues/1158)
- SOLR: Campaign priorities [\#1155](https://github.com/DoSomething/phoenix/issues/1155)
- Rework Image, Fact node non-staff access [\#1153](https://github.com/DoSomething/phoenix/issues/1153)
- action page \(prove it\) - only show official rules if field has a file uploaded [\#1147](https://github.com/DoSomething/phoenix/issues/1147)
- White screen "set\_group\_operator" error on campaign nodes [\#1146](https://github.com/DoSomething/phoenix/issues/1146)
- Static content - Gallery titles aren't showing up [\#1145](https://github.com/DoSomething/phoenix/issues/1145)
- Markdown - bold disabled  [\#1143](https://github.com/DoSomething/phoenix/issues/1143)
- Entity connect permissions [\#1139](https://github.com/DoSomething/phoenix/issues/1139)
- SOLR: Use correct markup for search boxes [\#1135](https://github.com/DoSomething/phoenix/issues/1135)
- action page \(nav\) - navigation order needs updated [\#1130](https://github.com/DoSomething/phoenix/issues/1130)
- Signup: Remove signup functionality [\#1129](https://github.com/DoSomething/phoenix/issues/1129)
- action page \(prove it\) - gallery image isn't 16:9 [\#1126](https://github.com/DoSomething/phoenix/issues/1126)
- action page \(report back modal\) - styling needed [\#1125](https://github.com/DoSomething/phoenix/issues/1125)
- Site Registration \(campaign\) - should only display one message to the user [\#1118](https://github.com/DoSomething/phoenix/issues/1118)
- Sticky elements need to be able to differ behavior between breakpoints [\#1117](https://github.com/DoSomething/phoenix/issues/1117)
- Campaign navigation: Step highlighting [\#1112](https://github.com/DoSomething/phoenix/issues/1112)
- DS build: Add drush fra [\#1111](https://github.com/DoSomething/phoenix/issues/1111)
- Redirect module [\#1110](https://github.com/DoSomething/phoenix/issues/1110)
- site registration - notification message copy [\#1109](https://github.com/DoSomething/phoenix/issues/1109)
- action page \(zendesk\)  - help copy change [\#1107](https://github.com/DoSomething/phoenix/issues/1107)
- 11 Facts: Inline image alongside the facts [\#1104](https://github.com/DoSomething/phoenix/issues/1104)
- Static content - Style list elements [\#1103](https://github.com/DoSomething/phoenix/issues/1103)
- Static Content - Header style tweaks [\#1102](https://github.com/DoSomething/phoenix/issues/1102)
- 11 Facts: Description at the bottom [\#1101](https://github.com/DoSomething/phoenix/issues/1101)
- Campaign: Create theme.inc file [\#1099](https://github.com/DoSomething/phoenix/issues/1099)
- action page \(header\) – default hero images [\#1095](https://github.com/DoSomething/phoenix/issues/1095)
- 11 Facts: Remove sources [\#1092](https://github.com/DoSomething/phoenix/issues/1092)
- 11 Facts: Update node edit form [\#1091](https://github.com/DoSomething/phoenix/issues/1091)
- Campaign form: Display mailchimp and mobilecommons vars [\#1090](https://github.com/DoSomething/phoenix/issues/1090)
- Reportback form validation [\#1087](https://github.com/DoSomething/phoenix/issues/1087)
- SOLR: /campaigns update row styles to divs [\#1081](https://github.com/DoSomething/phoenix/issues/1081)
- Message Broker - Gather remaining merge\_var values [\#1071](https://github.com/DoSomething/phoenix/issues/1071)
- Message Broker - rename message\_broker to mbp [\#1069](https://github.com/DoSomething/phoenix/issues/1069)
- Login redirect to legacy app [\#1060](https://github.com/DoSomething/phoenix/issues/1060)
- SOLR: /campaigns tpl [\#1052](https://github.com/DoSomething/phoenix/issues/1052)
- SOLR: Create /campaigns page [\#1046](https://github.com/DoSomething/phoenix/issues/1046)
- action page \(header\) – hero image update [\#1043](https://github.com/DoSomething/phoenix/issues/1043)
- action page \(prove it\) – sponsor background pattern [\#1042](https://github.com/DoSomething/phoenix/issues/1042)
- action page – sponsor header colors [\#1041](https://github.com/DoSomething/phoenix/issues/1041)
- 11 Facts: Blank youtube video [\#1039](https://github.com/DoSomething/phoenix/issues/1039)
- action page \(know it\) – fact sources header always present [\#1037](https://github.com/DoSomething/phoenix/issues/1037)
- Users: Import user table from old world [\#1036](https://github.com/DoSomething/phoenix/issues/1036)
- Add and configure Optimizely [\#1034](https://github.com/DoSomething/phoenix/issues/1034)
- Cache clear Image URLs [\#1033](https://github.com/DoSomething/phoenix/issues/1033)
- User login: First name and birthday required [\#1031](https://github.com/DoSomething/phoenix/issues/1031)
- User mailing address [\#1026](https://github.com/DoSomething/phoenix/issues/1026)
- header - change Sign In to Log In [\#1025](https://github.com/DoSomething/phoenix/issues/1025)
- auth - after log in user is taken to /user; should reload page they started on [\#1023](https://github.com/DoSomething/phoenix/issues/1023)
- Login form broken due to \#999. [\#1021](https://github.com/DoSomething/phoenix/issues/1021)
- touch screen - pinch zoom does not work [\#1020](https://github.com/DoSomething/phoenix/issues/1020)
- Production: Make https paths work on webheads [\#1011](https://github.com/DoSomething/phoenix/issues/1011)
- Production: Fix wildcard SSL on varnish instance [\#1010](https://github.com/DoSomething/phoenix/issues/1010)
- auth - modal cut off on mobile [\#1006](https://github.com/DoSomething/phoenix/issues/1006)
- campaign - scholarship amounts should have a comma when displayed [\#997](https://github.com/DoSomething/phoenix/issues/997)
- Remove Secure Pages Module [\#994](https://github.com/DoSomething/phoenix/issues/994)
- User message request error checking [\#991](https://github.com/DoSomething/phoenix/issues/991)
- SOLR: Output subtitle/call to action [\#988](https://github.com/DoSomething/phoenix/issues/988)
- SOLR: Output highlighted text [\#983](https://github.com/DoSomething/phoenix/issues/983)
- Document validation for login/registration flow [\#982](https://github.com/DoSomething/phoenix/issues/982)
- Reportback Files [\#974](https://github.com/DoSomething/phoenix/issues/974)
- system message styles [\#971](https://github.com/DoSomething/phoenix/issues/971)
- Mobile Commons opt-in function [\#962](https://github.com/DoSomething/phoenix/issues/962)
- Campaigns path-auto [\#961](https://github.com/DoSomething/phoenix/issues/961)
- Install Global Redirect [\#960](https://github.com/DoSomething/phoenix/issues/960)
- Site Registration - Field for users under 13 [\#959](https://github.com/DoSomething/phoenix/issues/959)
- Sponsor modals: Preprocess image [\#958](https://github.com/DoSomething/phoenix/issues/958)
- Campaign header: Sponsor logos [\#957](https://github.com/DoSomething/phoenix/issues/957)
- Move the H&M campaign to a title based URL [\#955](https://github.com/DoSomething/phoenix/issues/955)
- Hosting for misc images used in themes [\#954](https://github.com/DoSomething/phoenix/issues/954)
- SOLR: Field Biasing [\#951](https://github.com/DoSomething/phoenix/issues/951)
- SOLR: Type Biasing [\#950](https://github.com/DoSomething/phoenix/issues/950)
- Updated Image styles/sizes Needed [\#948](https://github.com/DoSomething/phoenix/issues/948)
- Fatal Error: ApacheSolr [\#947](https://github.com/DoSomething/phoenix/issues/947)
- Add modules to ds.info [\#945](https://github.com/DoSomething/phoenix/issues/945)
- Errors on DS build [\#944](https://github.com/DoSomething/phoenix/issues/944)
- action page - modal styling [\#942](https://github.com/DoSomething/phoenix/issues/942)
- Port to Neue! [\#941](https://github.com/DoSomething/phoenix/issues/941)
- Staging: Drop field\_data\_field\_partners\_fc tables [\#938](https://github.com/DoSomething/phoenix/issues/938)
- Static Content - Markdown is not working [\#933](https://github.com/DoSomething/phoenix/issues/933)
- Site Registration - Under 13 should not be added to MailChimp nor MobileCommons [\#932](https://github.com/DoSomething/phoenix/issues/932)
- Site Registration - Allow Under 13 [\#931](https://github.com/DoSomething/phoenix/issues/931)
- Fact: Remove custom table [\#930](https://github.com/DoSomething/phoenix/issues/930)
- Update ds --help documentation for stage downloads [\#929](https://github.com/DoSomething/phoenix/issues/929)
- Zendesk: Ticket Groups [\#928](https://github.com/DoSomething/phoenix/issues/928)
- SCSS Compile issue on ds build [\#921](https://github.com/DoSomething/phoenix/issues/921)
- Report-back modals should be in script tags [\#919](https://github.com/DoSomething/phoenix/issues/919)
- Fact footnotes [\#918](https://github.com/DoSomething/phoenix/issues/918)
- Admin Perms [\#915](https://github.com/DoSomething/phoenix/issues/915)
- Buttons are defaulting to small size. [\#914](https://github.com/DoSomething/phoenix/issues/914)
- Images: Filter Needed on Campaign Hero Images [\#912](https://github.com/DoSomething/phoenix/issues/912)
- action page \(do it\) – layout and styles [\#906](https://github.com/DoSomething/phoenix/issues/906)
- pitch page \(all\) – mobile styles [\#905](https://github.com/DoSomething/phoenix/issues/905)
- action page \(all\) – mobile styles [\#904](https://github.com/DoSomething/phoenix/issues/904)
- Undefined Property: $mail [\#898](https://github.com/DoSomething/phoenix/issues/898)
- Campaign: sponsor color variable [\#895](https://github.com/DoSomething/phoenix/issues/895)
- SMS in-campaign transition flows [\#894](https://github.com/DoSomething/phoenix/issues/894)
- Staff Pick Campaigns: MailChimp Group Subscription [\#893](https://github.com/DoSomething/phoenix/issues/893)
- User Registration: MailChimp Subscription [\#892](https://github.com/DoSomething/phoenix/issues/892)
- Update registration modal links [\#884](https://github.com/DoSomething/phoenix/issues/884)
- Birthday client-side validation doesn't fail on incorrect months [\#883](https://github.com/DoSomething/phoenix/issues/883)
- Mobilecommons module update [\#882](https://github.com/DoSomething/phoenix/issues/882)
- Campaign: Mobile Commons opt-in non-staff pick [\#881](https://github.com/DoSomething/phoenix/issues/881)
- Campaign Template - Default Image in Prove It Gallery [\#875](https://github.com/DoSomething/phoenix/issues/875)
- Auth Flow: Google Analtyics track sign in/reg failures [\#874](https://github.com/DoSomething/phoenix/issues/874)
- Footer: Remove Scholarships [\#873](https://github.com/DoSomething/phoenix/issues/873)
- Auth - Create an Account Required Fields Needed [\#869](https://github.com/DoSomething/phoenix/issues/869)
- confirmation – build [\#863](https://github.com/DoSomething/phoenix/issues/863)
- confirmation – style [\#862](https://github.com/DoSomething/phoenix/issues/862)
- Campaign: Mobile Commons ID for Staff Picks [\#859](https://github.com/DoSomething/phoenix/issues/859)
- Campaign: On sign up or registration, update the user's Mobile Commons first name and email [\#858](https://github.com/DoSomething/phoenix/issues/858)
- New User Reg: Mobile Commons opt-in [\#857](https://github.com/DoSomething/phoenix/issues/857)
- Campaign:  FAQ and More Facts links [\#856](https://github.com/DoSomething/phoenix/issues/856)
- Campaign: Know It footnotes [\#855](https://github.com/DoSomething/phoenix/issues/855)
- campaign.scss is growing unruly [\#848](https://github.com/DoSomething/phoenix/issues/848)
- action \(know it\) – switch facts and video/placeholder [\#844](https://github.com/DoSomething/phoenix/issues/844)
- View term pages permissions [\#841](https://github.com/DoSomething/phoenix/issues/841)
- Image: PDO Exception [\#837](https://github.com/DoSomething/phoenix/issues/837)
- Form validation suggestions not "filling-in" [\#835](https://github.com/DoSomething/phoenix/issues/835)
- Campaign: Sponsors field / taxonomy changes [\#833](https://github.com/DoSomething/phoenix/issues/833)
- Hook up validation to form. [\#832](https://github.com/DoSomething/phoenix/issues/832)
- Matching field validation. [\#831](https://github.com/DoSomething/phoenix/issues/831)
- Phone Number validation [\#830](https://github.com/DoSomething/phoenix/issues/830)
- Static content CTA field preprocess notice [\#827](https://github.com/DoSomething/phoenix/issues/827)
- Static content node edit page updates  [\#826](https://github.com/DoSomething/phoenix/issues/826)
- Make file: Update ctools [\#822](https://github.com/DoSomething/phoenix/issues/822)
- Suppress "expr" warning in JSHint [\#818](https://github.com/DoSomething/phoenix/issues/818)
- Hide Drupal invisibles [\#814](https://github.com/DoSomething/phoenix/issues/814)
- HTML5Shiv in header for IE8 [\#812](https://github.com/DoSomething/phoenix/issues/812)
- Remove width and height attributes in image tag helper [\#807](https://github.com/DoSomething/phoenix/issues/807)
- action page \(footer\) – zen desk modal styles [\#803](https://github.com/DoSomething/phoenix/issues/803)
- Pitch login bug [\#801](https://github.com/DoSomething/phoenix/issues/801)
- DS build: Zendesk library [\#797](https://github.com/DoSomething/phoenix/issues/797)
- DS build: Composer package installation [\#796](https://github.com/DoSomething/phoenix/issues/796)
- 11 Facts: Move causes selection down. [\#791](https://github.com/DoSomething/phoenix/issues/791)
- Action Page - Customer coloring for sponsors [\#781](https://github.com/DoSomething/phoenix/issues/781)
- Action Page - Content changes for Sponsors [\#780](https://github.com/DoSomething/phoenix/issues/780)
- User: Staff members can have a username [\#774](https://github.com/DoSomething/phoenix/issues/774)
- User: Partner term field [\#772](https://github.com/DoSomething/phoenix/issues/772)
- ZenDesk contact form [\#770](https://github.com/DoSomething/phoenix/issues/770)
- Campaigns Template - Sponsor Fields + Modal [\#768](https://github.com/DoSomething/phoenix/issues/768)
- Message Broker: Example Code [\#752](https://github.com/DoSomething/phoenix/issues/752)
- Enhancements to Filtering for Image Search [\#729](https://github.com/DoSomething/phoenix/issues/729)
- Tags Needed for Adding Images [\#728](https://github.com/DoSomething/phoenix/issues/728)
- Message Broker and drush.make - how to include libraries with depenancies [\#716](https://github.com/DoSomething/phoenix/issues/716)
- action page \(prove it\) – section footer missing [\#710](https://github.com/DoSomething/phoenix/issues/710)
- action page \(prove it\) – rules and regulations [\#709](https://github.com/DoSomething/phoenix/issues/709)
- action page \(do it\) – photo gallery styles [\#706](https://github.com/DoSomething/phoenix/issues/706)
- action page \(plan it\) – location finder styling [\#702](https://github.com/DoSomething/phoenix/issues/702)
- action page \(navigation\) – style [\#698](https://github.com/DoSomething/phoenix/issues/698)
- action page \(navigation\) – section indicator [\#697](https://github.com/DoSomething/phoenix/issues/697)
- campaign – tighten up typography [\#693](https://github.com/DoSomething/phoenix/issues/693)
- campaign \(header\) – style sponsor logo [\#692](https://github.com/DoSomething/phoenix/issues/692)
- pitch page – campaign footer missing [\#691](https://github.com/DoSomething/phoenix/issues/691)
- Grid – Wider Container Needed [\#676](https://github.com/DoSomething/phoenix/issues/676)
- ds script – update sandbox environment with content from staging site [\#675](https://github.com/DoSomething/phoenix/issues/675)
- 11 facts – style [\#658](https://github.com/DoSomething/phoenix/issues/658)
- static content – style [\#657](https://github.com/DoSomething/phoenix/issues/657)
- DS build: Param to copy staging db [\#607](https://github.com/DoSomething/phoenix/issues/607)
- Redis Cache [\#600](https://github.com/DoSomething/phoenix/issues/600)
- Global button classes [\#525](https://github.com/DoSomething/phoenix/issues/525)
- Campaign: Use Video field instead of PSA [\#507](https://github.com/DoSomething/phoenix/issues/507)
- search results – style [\#493](https://github.com/DoSomething/phoenix/issues/493)
- Present search results [\#492](https://github.com/DoSomething/phoenix/issues/492)
- Reportback: Security [\#479](https://github.com/DoSomething/phoenix/issues/479)
- Implement neue login/registration workflow [\#420](https://github.com/DoSomething/phoenix/issues/420)
- Campaign: JS for Reportback form [\#419](https://github.com/DoSomething/phoenix/issues/419)
- Pantheon deployment from ds CLI [\#349](https://github.com/DoSomething/phoenix/issues/349)
- Vagrant: Create environment variable for Varnish secret key [\#291](https://github.com/DoSomething/phoenix/issues/291)
- Play nice with Pantheon [\#277](https://github.com/DoSomething/phoenix/issues/277)
- Client-side auth flow [\#224](https://github.com/DoSomething/phoenix/issues/224)
- SMS: migrate custom ConductorActivity plugins and ConductorWorkflows from old world to new [\#201](https://github.com/DoSomething/phoenix/issues/201)
- Stage: Share cookies between http/https [\#198](https://github.com/DoSomething/phoenix/issues/198)
- Production: Add New Relic support [\#165](https://github.com/DoSomething/phoenix/issues/165)
- SMS: migrate sms\_flow\_game and sms\_flow\_records over from old db [\#163](https://github.com/DoSomething/phoenix/issues/163)
- Method to swap out github username in make files [\#151](https://github.com/DoSomething/phoenix/issues/151)
- Coder: Sniff changes on pull requests [\#146](https://github.com/DoSomething/phoenix/issues/146)
- Internal import.sh script [\#116](https://github.com/DoSomething/phoenix/issues/116)
- Production: Upgrade Varnish to latest [\#94](https://github.com/DoSomething/phoenix/issues/94)
- SMS: consolidate dosomething\_sms amd sms\_flow modules into a single module [\#91](https://github.com/DoSomething/phoenix/issues/91)
- SMS: Purge private values from dosomething\_sms and sms\_flow code [\#90](https://github.com/DoSomething/phoenix/issues/90)
- Hubot script to deploy to production [\#80](https://github.com/DoSomething/phoenix/issues/80)
- Production environment [\#79](https://github.com/DoSomething/phoenix/issues/79)

**Merged pull requests:**

- jQuery shimming issues [\#1668](https://github.com/DoSomething/phoenix/pull/1668) ([DFurnes](https://github.com/DFurnes))
- Temporary Button Fixes [\#1666](https://github.com/DoSomething/phoenix/pull/1666) ([mmwtsn](https://github.com/mmwtsn))
- Padding Hack Refactor [\#1663](https://github.com/DoSomething/phoenix/pull/1663) ([mmwtsn](https://github.com/mmwtsn))
- Uses correct copy for Preg Text on homepage. [\#1661](https://github.com/DoSomething/phoenix/pull/1661) ([DFurnes](https://github.com/DFurnes))
- Decoding htmlentities for label field [\#1660](https://github.com/DoSomething/phoenix/pull/1660) ([blisteringherb](https://github.com/blisteringherb))
- Adds CTIA text to registration form. [\#1654](https://github.com/DoSomething/phoenix/pull/1654) ([DFurnes](https://github.com/DFurnes))
- Dynamic gradients [\#1653](https://github.com/DoSomething/phoenix/pull/1653) ([weerd](https://github.com/weerd))
- Homepage updates for April 3rd. [\#1652](https://github.com/DoSomething/phoenix/pull/1652) ([DFurnes](https://github.com/DFurnes))
- Updating missing vars fix to ONLY pass in the necessary variables for th... [\#1651](https://github.com/DoSomething/phoenix/pull/1651) ([weerd](https://github.com/weerd))
- Restores Neue Banner Styles [\#1645](https://github.com/DoSomething/phoenix/pull/1645) ([mmwtsn](https://github.com/mmwtsn))
- Campaign finder [\#1642](https://github.com/DoSomething/phoenix/pull/1642) ([DFurnes](https://github.com/DFurnes))
- Updates to pass missing vars array to theme function. [\#1640](https://github.com/DoSomething/phoenix/pull/1640) ([weerd](https://github.com/weerd))
- Add recommended campaigns to user profile [\#1637](https://github.com/DoSomething/phoenix/pull/1637) ([angaither](https://github.com/angaither))
- Adding updates to make cap deploy work through Jenkins [\#1634](https://github.com/DoSomething/phoenix/pull/1634) ([blisteringherb](https://github.com/blisteringherb))
- Reportback log fix [\#1632](https://github.com/DoSomething/phoenix/pull/1632) ([aaronschachter](https://github.com/aaronschachter))
- Removes newline from end of file. [\#1631](https://github.com/DoSomething/phoenix/pull/1631) ([DFurnes](https://github.com/DFurnes))
- Uses new layout classes from Neue 3.2.x. [\#1630](https://github.com/DoSomething/phoenix/pull/1630) ([DFurnes](https://github.com/DFurnes))
- Campaign PSA [\#1626](https://github.com/DoSomething/phoenix/pull/1626) ([mmwtsn](https://github.com/mmwtsn))
- User profile [\#1625](https://github.com/DoSomething/phoenix/pull/1625) ([weerd](https://github.com/weerd))
- Action Guide Styles [\#1623](https://github.com/DoSomething/phoenix/pull/1623) ([mmwtsn](https://github.com/mmwtsn))
- Move hook\_user\_view into dosomething\_user [\#1622](https://github.com/DoSomething/phoenix/pull/1622) ([angaither](https://github.com/angaither))
- Pitch page metatag images [\#1621](https://github.com/DoSomething/phoenix/pull/1621) ([aaronschachter](https://github.com/aaronschachter))
- Add hero image to signups block. [\#1619](https://github.com/DoSomething/phoenix/pull/1619) ([angaither](https://github.com/angaither))
- Updates to fix final misc spacing issues and cleanup a few things. [\#1616](https://github.com/DoSomething/phoenix/pull/1616) ([weerd](https://github.com/weerd))
- Removes shim now that Neue 3.2+ defines itself as AMD module. [\#1613](https://github.com/DoSomething/phoenix/pull/1613) ([DFurnes](https://github.com/DFurnes))
- Removing references to securepages module [\#1612](https://github.com/DoSomething/phoenix/pull/1612) ([blisteringherb](https://github.com/blisteringherb))
- Fact Page keywords [\#1610](https://github.com/DoSomething/phoenix/pull/1610) ([aaronschachter](https://github.com/aaronschachter))
- Updates to 11 Facts to styles the CTAs and extract all static content... [\#1609](https://github.com/DoSomething/phoenix/pull/1609) ([weerd](https://github.com/weerd))
- RequireJS dev environment [\#1608](https://github.com/DoSomething/phoenix/pull/1608) ([DFurnes](https://github.com/DFurnes))
- Neue 3.2 [\#1607](https://github.com/DoSomething/phoenix/pull/1607) ([DFurnes](https://github.com/DFurnes))
- Facebook OG Image [\#1606](https://github.com/DoSomething/phoenix/pull/1606) ([aaronschachter](https://github.com/aaronschachter))
- Fact Page metatag image [\#1604](https://github.com/DoSomething/phoenix/pull/1604) ([aaronschachter](https://github.com/aaronschachter))
- Pitch Button Width [\#1603](https://github.com/DoSomething/phoenix/pull/1603) ([mmwtsn](https://github.com/mmwtsn))
- Restores Uglify task for production build. [\#1602](https://github.com/DoSomething/phoenix/pull/1602) ([DFurnes](https://github.com/DFurnes))
- Protocol relative URLs for homepage images. [\#1601](https://github.com/DoSomething/phoenix/pull/1601) ([DFurnes](https://github.com/DFurnes))
- Fixes script loading issue. [\#1600](https://github.com/DoSomething/phoenix/pull/1600) ([DFurnes](https://github.com/DFurnes))
- Prove It QA [\#1599](https://github.com/DoSomething/phoenix/pull/1599) ([mmwtsn](https://github.com/mmwtsn))
- Fixes unintentionally relative URL on JS include. [\#1596](https://github.com/DoSomething/phoenix/pull/1596) ([DFurnes](https://github.com/DFurnes))
- Require that js [\#1595](https://github.com/DoSomething/phoenix/pull/1595) ([DFurnes](https://github.com/DFurnes))
- Fact  Page tweaks [\#1594](https://github.com/DoSomething/phoenix/pull/1594) ([aaronschachter](https://github.com/aaronschachter))
- Paraneue paranoia [\#1591](https://github.com/DoSomething/phoenix/pull/1591) ([DFurnes](https://github.com/DFurnes))
- Updated the import script again. [\#1590](https://github.com/DoSomething/phoenix/pull/1590) ([angaither](https://github.com/angaither))
- Readding previous commits to new PR for cleanliness sake. [\#1584](https://github.com/DoSomething/phoenix/pull/1584) ([weerd](https://github.com/weerd))
- Signup data form states [\#1581](https://github.com/DoSomething/phoenix/pull/1581) ([aaronschachter](https://github.com/aaronschachter))
- Zendesk Tickets: groups and priority [\#1580](https://github.com/DoSomething/phoenix/pull/1580) ([aaronschachter](https://github.com/aaronschachter))
- Action Sources Dropdown Toggle [\#1578](https://github.com/DoSomething/phoenix/pull/1578) ([mmwtsn](https://github.com/mmwtsn))
- Fixes \#893, mailchimp payload cleanup [\#1576](https://github.com/DoSomething/phoenix/pull/1576) ([DeeZone](https://github.com/DeeZone))
- Adding a check for drush when calling drupal\_goto in hook\_init [\#1574](https://github.com/DoSomething/phoenix/pull/1574) ([blisteringherb](https://github.com/blisteringherb))
- Remove reference to video field for 11 facts [\#1572](https://github.com/DoSomething/phoenix/pull/1572) ([blisteringherb](https://github.com/blisteringherb))
- Removing PHP short tags from 2 templates. [\#1570](https://github.com/DoSomething/phoenix/pull/1570) ([weerd](https://github.com/weerd))
- 11 facts  sources output [\#1569](https://github.com/DoSomething/phoenix/pull/1569) ([weerd](https://github.com/weerd))
- Action Page Alignment [\#1567](https://github.com/DoSomething/phoenix/pull/1567) ([mmwtsn](https://github.com/mmwtsn))
- Campaign video collection [\#1564](https://github.com/DoSomething/phoenix/pull/1564) ([aaronschachter](https://github.com/aaronschachter))
- Updating fact page sources to use add'l text field [\#1559](https://github.com/DoSomething/phoenix/pull/1559) ([blisteringherb](https://github.com/blisteringherb))
- Video Collection - hook\_field\_collection\_is\_empty\_alter [\#1557](https://github.com/DoSomething/phoenix/pull/1557) ([aaronschachter](https://github.com/aaronschachter))
- Zendesk error catching [\#1556](https://github.com/DoSomething/phoenix/pull/1556) ([aaronschachter](https://github.com/aaronschachter))
- Added first & last name to address collection. [\#1554](https://github.com/DoSomething/phoenix/pull/1554) ([angaither](https://github.com/angaither))
- Fixes 1551: Sets 'ds' as the Redis cache key [\#1552](https://github.com/DoSomething/phoenix/pull/1552) ([mshmsh5000](https://github.com/mshmsh5000))
- Static content  misc [\#1549](https://github.com/DoSomething/phoenix/pull/1549) ([weerd](https://github.com/weerd))
- Refactored file saving code for SMS report backs to maintain file extension [\#1548](https://github.com/DoSomething/phoenix/pull/1548) ([jonuy](https://github.com/jonuy))
- Reportback IP address [\#1547](https://github.com/DoSomething/phoenix/pull/1547) ([aaronschachter](https://github.com/aaronschachter))
- Add last name field to user profile [\#1546](https://github.com/DoSomething/phoenix/pull/1546) ([angaither](https://github.com/angaither))
- More Flexible Campaign Header Sponsor Logo Styles [\#1543](https://github.com/DoSomething/phoenix/pull/1543) ([mmwtsn](https://github.com/mmwtsn))
- Reportback security [\#1538](https://github.com/DoSomething/phoenix/pull/1538) ([aaronschachter](https://github.com/aaronschachter))
- Styles to scale image fluidly. [\#1536](https://github.com/DoSomething/phoenix/pull/1536) ([weerd](https://github.com/weerd))
- Add roles to is\_staff check [\#1534](https://github.com/DoSomething/phoenix/pull/1534) ([angaither](https://github.com/angaither))
- Collect user address in signup data form [\#1533](https://github.com/DoSomething/phoenix/pull/1533) ([aaronschachter](https://github.com/aaronschachter))
- Static Content, updating header to add purple to black gradient. [\#1531](https://github.com/DoSomething/phoenix/pull/1531) ([weerd](https://github.com/weerd))
- Sets up homepage as node. [\#1527](https://github.com/DoSomething/phoenix/pull/1527) ([DFurnes](https://github.com/DFurnes))
- Refactor meeting [\#1524](https://github.com/DoSomething/phoenix/pull/1524) ([DFurnes](https://github.com/DFurnes))
- Hide Address on Registration Form [\#1522](https://github.com/DoSomething/phoenix/pull/1522) ([angaither](https://github.com/angaither))
- Fixes \#1519: Sets Redis\_Cache as default cache class [\#1520](https://github.com/DoSomething/phoenix/pull/1520) ([mshmsh5000](https://github.com/mshmsh5000))
- Track user signup\_data\_form submissions [\#1516](https://github.com/DoSomething/phoenix/pull/1516) ([aaronschachter](https://github.com/aaronschachter))
- Removes QUnit tests temporarily. [\#1506](https://github.com/DoSomething/phoenix/pull/1506) ([DFurnes](https://github.com/DFurnes))
- 11 facts  image on mobile [\#1505](https://github.com/DoSomething/phoenix/pull/1505) ([weerd](https://github.com/weerd))
- User signup data form [\#1504](https://github.com/DoSomething/phoenix/pull/1504) ([aaronschachter](https://github.com/aaronschachter))
- Kill that drupal padding [\#1503](https://github.com/DoSomething/phoenix/pull/1503) ([DFurnes](https://github.com/DFurnes))
- Adding Optimizely to ds.info and adding default OPT project ID [\#1502](https://github.com/DoSomething/phoenix/pull/1502) ([blisteringherb](https://github.com/blisteringherb))
- Format the $cholar$hip with commma commma commmma chameleonssss [\#1501](https://github.com/DoSomething/phoenix/pull/1501) ([angaither](https://github.com/angaither))
- Set default first name for mb requests. [\#1500](https://github.com/DoSomething/phoenix/pull/1500) ([angaither](https://github.com/angaither))
- Report back clientside validation [\#1498](https://github.com/DoSomething/phoenix/pull/1498) ([DFurnes](https://github.com/DFurnes))
- Add address field to user profile. [\#1497](https://github.com/DoSomething/phoenix/pull/1497) ([angaither](https://github.com/angaither))
- New dosomething\_signup\_data\_form table [\#1496](https://github.com/DoSomething/phoenix/pull/1496) ([aaronschachter](https://github.com/aaronschachter))
- Moves mbp call to submit function [\#1495](https://github.com/DoSomething/phoenix/pull/1495) ([DeeZone](https://github.com/DeeZone))
- Fixes \#1436: Mismatched hosts break AJAX submissions [\#1494](https://github.com/DoSomething/phoenix/pull/1494) ([mshmsh5000](https://github.com/mshmsh5000))
- Removes undefined variable. [\#1493](https://github.com/DoSomething/phoenix/pull/1493) ([DFurnes](https://github.com/DFurnes))
- Fixed broken modal BG. [\#1492](https://github.com/DoSomething/phoenix/pull/1492) ([DFurnes](https://github.com/DFurnes))
- Adds dosomething\_campaign.theme.inc [\#1487](https://github.com/DoSomething/phoenix/pull/1487) ([aaronschachter](https://github.com/aaronschachter))
- Adds mobile for MailChimp submissions [\#1486](https://github.com/DoSomething/phoenix/pull/1486) ([DeeZone](https://github.com/DeeZone))
- Fixes \#1092, 11 Facts: Remove sources. [\#1482](https://github.com/DoSomething/phoenix/pull/1482) ([weerd](https://github.com/weerd))
- Mailchimp grouping\_id and group\_name vars [\#1481](https://github.com/DoSomething/phoenix/pull/1481) ([aaronschachter](https://github.com/aaronschachter))
- Do It QA [\#1479](https://github.com/DoSomething/phoenix/pull/1479) ([mmwtsn](https://github.com/mmwtsn))
- Campaign Navigation QA [\#1478](https://github.com/DoSomething/phoenix/pull/1478) ([mmwtsn](https://github.com/mmwtsn))
- Know It QA [\#1477](https://github.com/DoSomething/phoenix/pull/1477) ([mmwtsn](https://github.com/mmwtsn))
- Pitch Page Design QA [\#1475](https://github.com/DoSomething/phoenix/pull/1475) ([mmwtsn](https://github.com/mmwtsn))
- Communications Team: admin menu access [\#1474](https://github.com/DoSomething/phoenix/pull/1474) ([aaronschachter](https://github.com/aaronschachter))
- Updated build script to force revert of features. [\#1472](https://github.com/DoSomething/phoenix/pull/1472) ([angaither](https://github.com/angaither))
- Updated the other firstname and birthdate script to run faster. [\#1471](https://github.com/DoSomething/phoenix/pull/1471) ([angaither](https://github.com/angaither))
- Campaign Modal Image Widths [\#1470](https://github.com/DoSomething/phoenix/pull/1470) ([mmwtsn](https://github.com/mmwtsn))
- Displaying first name or email for Zendesk tickets [\#1469](https://github.com/DoSomething/phoenix/pull/1469) ([blisteringherb](https://github.com/blisteringherb))
- Removes tagline on homepage. [\#1468](https://github.com/DoSomething/phoenix/pull/1468) ([DFurnes](https://github.com/DFurnes))
- Lets button size itself as it pleases. [\#1467](https://github.com/DoSomething/phoenix/pull/1467) ([DFurnes](https://github.com/DFurnes))
- Paraneue DS SCSS Lint Configuration Update [\#1466](https://github.com/DoSomething/phoenix/pull/1466) ([mmwtsn](https://github.com/mmwtsn))
- Step headers bug [\#1465](https://github.com/DoSomething/phoenix/pull/1465) ([DFurnes](https://github.com/DFurnes))
- Make mobile data import go faster [\#1463](https://github.com/DoSomething/phoenix/pull/1463) ([angaither](https://github.com/angaither))
- Campaign Metatag Image [\#1461](https://github.com/DoSomething/phoenix/pull/1461) ([aaronschachter](https://github.com/aaronschachter))
- Bower non-interactive flag [\#1459](https://github.com/DoSomething/phoenix/pull/1459) ([DFurnes](https://github.com/DFurnes))
- Rename dosomething\_user\_init correctly [\#1458](https://github.com/DoSomething/phoenix/pull/1458) ([aaronschachter](https://github.com/aaronschachter))
- Updated banner class for DoSomething/ds-neue\#204. [\#1439](https://github.com/DoSomething/phoenix/pull/1439) ([DFurnes](https://github.com/DFurnes))
- Placeholder Images [\#1435](https://github.com/DoSomething/phoenix/pull/1435) ([mmwtsn](https://github.com/mmwtsn))
- High Priority Backlog [\#1434](https://github.com/DoSomething/phoenix/pull/1434) ([mmwtsn](https://github.com/mmwtsn))
- Fender Code Quality [\#1433](https://github.com/DoSomething/phoenix/pull/1433) ([mmwtsn](https://github.com/mmwtsn))
- Home content type perms [\#1432](https://github.com/DoSomething/phoenix/pull/1432) ([aaronschachter](https://github.com/aaronschachter))
- Member Support, User Search [\#1431](https://github.com/DoSomething/phoenix/pull/1431) ([aaronschachter](https://github.com/aaronschachter))
- Don't select all the things from the user table. [\#1430](https://github.com/DoSomething/phoenix/pull/1430) ([angaither](https://github.com/angaither))
- Clear dosomething\_image cache table on image updates. [\#1425](https://github.com/DoSomething/phoenix/pull/1425) ([angaither](https://github.com/angaither))
- dosomething\_metatag module [\#1423](https://github.com/DoSomething/phoenix/pull/1423) ([aaronschachter](https://github.com/aaronschachter))
- Added script to grab first name and birthday data. [\#1422](https://github.com/DoSomething/phoenix/pull/1422) ([angaither](https://github.com/angaither))
- Update action paths post login on campaigns [\#1418](https://github.com/DoSomething/phoenix/pull/1418) ([angaither](https://github.com/angaither))
- Tip Fix [\#1416](https://github.com/DoSomething/phoenix/pull/1416) ([mmwtsn](https://github.com/mmwtsn))
- Wrap the http referer in url alias call. [\#1415](https://github.com/DoSomething/phoenix/pull/1415) ([angaither](https://github.com/angaither))
- Added script to import mobile info from temp tables. [\#1414](https://github.com/DoSomething/phoenix/pull/1414) ([angaither](https://github.com/angaither))
- Properly floats images on campaigns again. [\#1413](https://github.com/DoSomething/phoenix/pull/1413) ([DFurnes](https://github.com/DFurnes))
- Homepage updates for March 18 2014. [\#1410](https://github.com/DoSomething/phoenix/pull/1410) ([DFurnes](https://github.com/DFurnes))
- Update the register validate hook. [\#1407](https://github.com/DoSomething/phoenix/pull/1407) ([angaither](https://github.com/angaither))
- Header quickfix [\#1406](https://github.com/DoSomething/phoenix/pull/1406) ([DFurnes](https://github.com/DFurnes))
- Removing \#prove anchor from campaign signup link [\#1405](https://github.com/DoSomething/phoenix/pull/1405) ([blisteringherb](https://github.com/blisteringherb))
- PEANUT BUTTER EVERYWHERE [\#1393](https://github.com/DoSomething/phoenix/pull/1393) ([DFurnes](https://github.com/DFurnes))
- Fixes minor visual issues on homepage. [\#1387](https://github.com/DoSomething/phoenix/pull/1387) ([DFurnes](https://github.com/DFurnes))
- Fixes bug where IE showed black BG on homepage. [\#1385](https://github.com/DoSomething/phoenix/pull/1385) ([DFurnes](https://github.com/DFurnes))
- wrap it up [\#1384](https://github.com/DoSomething/phoenix/pull/1384) ([DFurnes](https://github.com/DFurnes))
- PAINTS IT WHITE [\#1383](https://github.com/DoSomething/phoenix/pull/1383) ([DFurnes](https://github.com/DFurnes))
- Hacks homepage in page--front for now. [\#1382](https://github.com/DoSomething/phoenix/pull/1382) ([DFurnes](https://github.com/DFurnes))
- don't display a sponsored by on the pitch page [\#1381](https://github.com/DoSomething/phoenix/pull/1381) ([barryclark](https://github.com/barryclark))
- Fuck it all [\#1380](https://github.com/DoSomething/phoenix/pull/1380) ([aaronschachter](https://github.com/aaronschachter))
- Fixed nav color selector. [\#1379](https://github.com/DoSomething/phoenix/pull/1379) ([DFurnes](https://github.com/DFurnes))
- Exists legacy validation if user already exists [\#1377](https://github.com/DoSomething/phoenix/pull/1377) ([desmondmorris](https://github.com/desmondmorris))
- Added field to home page [\#1375](https://github.com/DoSomething/phoenix/pull/1375) ([angaither](https://github.com/angaither))
- The circle of life. [\#1374](https://github.com/DoSomething/phoenix/pull/1374) ([aaronschachter](https://github.com/aaronschachter))
- Adds legacy auth validation to stubbed function [\#1371](https://github.com/DoSomething/phoenix/pull/1371) ([desmondmorris](https://github.com/desmondmorris))
- Stubs legacy auth validation callback [\#1370](https://github.com/DoSomething/phoenix/pull/1370) ([desmondmorris](https://github.com/desmondmorris))
- Don't display anything if there's no sponsor image [\#1369](https://github.com/DoSomething/phoenix/pull/1369) ([barryclark](https://github.com/barryclark))
- Removing \_blank target [\#1367](https://github.com/DoSomething/phoenix/pull/1367) ([blisteringherb](https://github.com/blisteringherb))
- Restyle of the confirmation page [\#1365](https://github.com/DoSomething/phoenix/pull/1365) ([barryclark](https://github.com/barryclark))
- Getting the link for the campaign from the nid [\#1363](https://github.com/DoSomething/phoenix/pull/1363) ([blisteringherb](https://github.com/blisteringherb))
- Adds check to HTTP\_X\_FORWARDED\_FOR for valid mobilecommons IP addresses [\#1362](https://github.com/DoSomething/phoenix/pull/1362) ([desmondmorris](https://github.com/desmondmorris))
- Fixing error when creating ZenDesk ticket [\#1359](https://github.com/DoSomething/phoenix/pull/1359) ([blisteringherb](https://github.com/blisteringherb))
- Added stub dosomething\_home module/node type. [\#1358](https://github.com/DoSomething/phoenix/pull/1358) ([angaither](https://github.com/angaither))
- Hack together homepage in new app. [\#1355](https://github.com/DoSomething/phoenix/pull/1355) ([DFurnes](https://github.com/DFurnes))
- Tells user password must be 6+ characters long. [\#1351](https://github.com/DoSomething/phoenix/pull/1351) ([DFurnes](https://github.com/DFurnes))
- Makes admin interface look a bit nicer. [\#1350](https://github.com/DoSomething/phoenix/pull/1350) ([DFurnes](https://github.com/DFurnes))
- Auth tweaks [\#1348](https://github.com/DoSomething/phoenix/pull/1348) ([DFurnes](https://github.com/DFurnes))
- Updating /campaigns subtitle [\#1346](https://github.com/DoSomething/phoenix/pull/1346) ([blisteringherb](https://github.com/blisteringherb))
- Campaign tips fix [\#1344](https://github.com/DoSomething/phoenix/pull/1344) ([barryclark](https://github.com/barryclark))
- Contact us plz [\#1343](https://github.com/DoSomething/phoenix/pull/1343) ([DFurnes](https://github.com/DFurnes))
- Search & Explore Campaigns header overlap fixes [\#1341](https://github.com/DoSomething/phoenix/pull/1341) ([barryclark](https://github.com/barryclark))
- Campaign: fix footer boilerplate copy [\#1339](https://github.com/DoSomething/phoenix/pull/1339) ([barryclark](https://github.com/barryclark))
- Updates client-side validation attributes with new IDs [\#1338](https://github.com/DoSomething/phoenix/pull/1338) ([DFurnes](https://github.com/DFurnes))
- Updated ds\_user permissions file. [\#1337](https://github.com/DoSomething/phoenix/pull/1337) ([angaither](https://github.com/angaither))
- Adding mobile support for post action tips [\#1336](https://github.com/DoSomething/phoenix/pull/1336) ([blisteringherb](https://github.com/blisteringherb))
- Sponsor logo fallback [\#1335](https://github.com/DoSomething/phoenix/pull/1335) ([aaronschachter](https://github.com/aaronschachter))
- Adding post tips to action page [\#1334](https://github.com/DoSomething/phoenix/pull/1334) ([blisteringherb](https://github.com/blisteringherb))
- Added post step to the campaign template. [\#1333](https://github.com/DoSomething/phoenix/pull/1333) ([angaither](https://github.com/angaither))
- Adding 'q' param for apachesolr views to enable elevate queries [\#1331](https://github.com/DoSomething/phoenix/pull/1331) ([blisteringherb](https://github.com/blisteringherb))
- Mailchimp MBP vars [\#1330](https://github.com/DoSomething/phoenix/pull/1330) ([aaronschachter](https://github.com/aaronschachter))
- Issue1322-Add\_mailchimp\_group\_id [\#1327](https://github.com/DoSomething/phoenix/pull/1327) ([DeeZone](https://github.com/DeeZone))
- Issue \#1323 - add birthday to MBP payload for user\_register [\#1326](https://github.com/DoSomething/phoenix/pull/1326) ([DeeZone](https://github.com/DeeZone))
- Updated static content auto-alias to about/\[node:title\] [\#1324](https://github.com/DoSomething/phoenix/pull/1324) ([angaither](https://github.com/angaither))
- Added a variable to set the last user saved. [\#1320](https://github.com/DoSomething/phoenix/pull/1320) ([angaither](https://github.com/angaither))
- Adding install file to update vars to replace reg. success msg [\#1318](https://github.com/DoSomething/phoenix/pull/1318) ([blisteringherb](https://github.com/blisteringherb))
- Theme cleanup [\#1317](https://github.com/DoSomething/phoenix/pull/1317) ([DFurnes](https://github.com/DFurnes))
- Fixes Issue 1304, missing CAMPAIGN\_LINK merge\_var in campaign\_signup [\#1316](https://github.com/DoSomething/phoenix/pull/1316) ([DeeZone](https://github.com/DeeZone))
- Adds neue image mixin. [\#1309](https://github.com/DoSomething/phoenix/pull/1309) ([DFurnes](https://github.com/DFurnes))
- Action guide modals [\#1300](https://github.com/DoSomething/phoenix/pull/1300) ([aaronschachter](https://github.com/aaronschachter))
- Fixes padding for static content and 11 Facts pages. [\#1299](https://github.com/DoSomething/phoenix/pull/1299) ([DFurnes](https://github.com/DFurnes))
- 3 misc static content tweaks [\#1298](https://github.com/DoSomething/phoenix/pull/1298) ([barryclark](https://github.com/barryclark))
- Wmax image style [\#1296](https://github.com/DoSomething/phoenix/pull/1296) ([angaither](https://github.com/angaither))
- remove margin-top on the solution [\#1295](https://github.com/DoSomething/phoenix/pull/1295) ([barryclark](https://github.com/barryclark))
- Static content gallery [\#1294](https://github.com/DoSomething/phoenix/pull/1294) ([barryclark](https://github.com/barryclark))
- Static content grid layout + misc styles [\#1293](https://github.com/DoSomething/phoenix/pull/1293) ([barryclark](https://github.com/barryclark))
- Printing gallery title and fixing printing mult galleries [\#1292](https://github.com/DoSomething/phoenix/pull/1292) ([blisteringherb](https://github.com/blisteringherb))
- Explore campaigns page [\#1290](https://github.com/DoSomething/phoenix/pull/1290) ([barryclark](https://github.com/barryclark))
- Fixes some display issues I inadvertently caused. [\#1285](https://github.com/DoSomething/phoenix/pull/1285) ([DFurnes](https://github.com/DFurnes))
- Adds font mimetypes to vhost config in VM [\#1284](https://github.com/DoSomething/phoenix/pull/1284) ([desmondmorris](https://github.com/desmondmorris))
- Set the mind on my money nids in the settings file. [\#1283](https://github.com/DoSomething/phoenix/pull/1283) ([angaither](https://github.com/angaither))
- We do not need the old world join page. [\#1279](https://github.com/DoSomething/phoenix/pull/1279) ([angaither](https://github.com/angaither))
- This Could Be You! [\#1277](https://github.com/DoSomething/phoenix/pull/1277) ([mmwtsn](https://github.com/mmwtsn))
- Add signup data [\#1271](https://github.com/DoSomething/phoenix/pull/1271) ([angaither](https://github.com/angaither))
- Added support for legacy campaign redirects. [\#1270](https://github.com/DoSomething/phoenix/pull/1270) ([angaither](https://github.com/angaither))
- Pitch Page Footer Updates [\#1267](https://github.com/DoSomething/phoenix/pull/1267) ([mmwtsn](https://github.com/mmwtsn))
- Action Page Style Tweaks [\#1263](https://github.com/DoSomething/phoenix/pull/1263) ([mmwtsn](https://github.com/mmwtsn))
- Headless Horseman Crop Fix [\#1258](https://github.com/DoSomething/phoenix/pull/1258) ([mmwtsn](https://github.com/mmwtsn))
- Ie8 snafu [\#1257](https://github.com/DoSomething/phoenix/pull/1257) ([DFurnes](https://github.com/DFurnes))
- Show Error Messages [\#1256](https://github.com/DoSomething/phoenix/pull/1256) ([mmwtsn](https://github.com/mmwtsn))
- Official Rules Fix [\#1255](https://github.com/DoSomething/phoenix/pull/1255) ([mmwtsn](https://github.com/mmwtsn))
- Signup admin views / unsignup form [\#1250](https://github.com/DoSomething/phoenix/pull/1250) ([aaronschachter](https://github.com/aaronschachter))
- Signup error [\#1247](https://github.com/DoSomething/phoenix/pull/1247) ([aaronschachter](https://github.com/aaronschachter))
- SMS special campaign opt-ins [\#1245](https://github.com/DoSomething/phoenix/pull/1245) ([angaither](https://github.com/angaither))
- More cleanup [\#1243](https://github.com/DoSomething/phoenix/pull/1243) ([aaronschachter](https://github.com/aaronschachter))
- Sets base url protocol dynamically [\#1242](https://github.com/DoSomething/phoenix/pull/1242) ([desmondmorris](https://github.com/desmondmorris))
- Rb cleanup [\#1241](https://github.com/DoSomething/phoenix/pull/1241) ([aaronschachter](https://github.com/aaronschachter))
- Fixing missing keys on front page search box [\#1240](https://github.com/DoSomething/phoenix/pull/1240) ([blisteringherb](https://github.com/blisteringherb))
- Polaroid Style Fix [\#1238](https://github.com/DoSomething/phoenix/pull/1238) ([mmwtsn](https://github.com/mmwtsn))
- Installing redirect module [\#1237](https://github.com/DoSomething/phoenix/pull/1237) ([blisteringherb](https://github.com/blisteringherb))
- MBP Request variables [\#1236](https://github.com/DoSomething/phoenix/pull/1236) ([aaronschachter](https://github.com/aaronschachter))
- Script to import signup data to the new world. [\#1235](https://github.com/DoSomething/phoenix/pull/1235) ([angaither](https://github.com/angaither))
- Search boxes didn't have the correct form action [\#1230](https://github.com/DoSomething/phoenix/pull/1230) ([blisteringherb](https://github.com/blisteringherb))
- Reportback helper functions [\#1227](https://github.com/DoSomething/phoenix/pull/1227) ([aaronschachter](https://github.com/aaronschachter))
- Fixes YouTube embed z-index issues in some browsers. [\#1224](https://github.com/DoSomething/phoenix/pull/1224) ([DFurnes](https://github.com/DFurnes))
- Nav layering boo boo [\#1223](https://github.com/DoSomething/phoenix/pull/1223) ([DFurnes](https://github.com/DFurnes))
- Mobile Tips Modals [\#1222](https://github.com/DoSomething/phoenix/pull/1222) ([mmwtsn](https://github.com/mmwtsn))
- Search Page Styles [\#1220](https://github.com/DoSomething/phoenix/pull/1220) ([mmwtsn](https://github.com/mmwtsn))
- Removes H&M Hero Override [\#1214](https://github.com/DoSomething/phoenix/pull/1214) ([mmwtsn](https://github.com/mmwtsn))
- Allows JavaScript to Compile on Stage [\#1212](https://github.com/DoSomething/phoenix/pull/1212) ([mmwtsn](https://github.com/mmwtsn))
- Updated image masks. [\#1210](https://github.com/DoSomething/phoenix/pull/1210) ([angaither](https://github.com/angaither))
- Staff-only content types [\#1192](https://github.com/DoSomething/phoenix/pull/1192) ([aaronschachter](https://github.com/aaronschachter))
- Minor cleanup and restructure changes [\#1191](https://github.com/DoSomething/phoenix/pull/1191) ([DeeZone](https://github.com/DeeZone))
- Updating SMS transition gate with correct IDs [\#1189](https://github.com/DoSomething/phoenix/pull/1189) ([jonuy](https://github.com/jonuy))
- Implement hook\_flush\_cache for ds\_image cache [\#1186](https://github.com/DoSomething/phoenix/pull/1186) ([angaither](https://github.com/angaither))
- Zero downtime deploy & cleanup [\#1185](https://github.com/DoSomething/phoenix/pull/1185) ([desmondmorris](https://github.com/desmondmorris))
- Tweaks [\#1183](https://github.com/DoSomething/phoenix/pull/1183) ([DFurnes](https://github.com/DFurnes))
- Revert features that are overridden [\#1181](https://github.com/DoSomething/phoenix/pull/1181) ([angaither](https://github.com/angaither))
- Copy Edit [\#1175](https://github.com/DoSomething/phoenix/pull/1175) ([mmwtsn](https://github.com/mmwtsn))
- Polaroid Styles Fix [\#1174](https://github.com/DoSomething/phoenix/pull/1174) ([mmwtsn](https://github.com/mmwtsn))
- Modal sponsor bg [\#1173](https://github.com/DoSomething/phoenix/pull/1173) ([DFurnes](https://github.com/DFurnes))
- Pitch Page Button Fix [\#1170](https://github.com/DoSomething/phoenix/pull/1170) ([mmwtsn](https://github.com/mmwtsn))
- Image field directory [\#1168](https://github.com/DoSomething/phoenix/pull/1168) ([aaronschachter](https://github.com/aaronschachter))
- Reportback file directories [\#1167](https://github.com/DoSomething/phoenix/pull/1167) ([aaronschachter](https://github.com/aaronschachter))
- Renaming methods that use 'cell' to use 'mobile' [\#1166](https://github.com/DoSomething/phoenix/pull/1166) ([jonuy](https://github.com/jonuy))
- Comeback Clothes SMS Tips [\#1165](https://github.com/DoSomething/phoenix/pull/1165) ([jonuy](https://github.com/jonuy))
- Image mask patch [\#1163](https://github.com/DoSomething/phoenix/pull/1163) ([mmwtsn](https://github.com/mmwtsn))
- action page updates [\#1162](https://github.com/DoSomething/phoenix/pull/1162) ([mmwtsn](https://github.com/mmwtsn))
- Campaign form - Alt BG field fix [\#1161](https://github.com/DoSomething/phoenix/pull/1161) ([aaronschachter](https://github.com/aaronschachter))
- Pitch Revisions [\#1160](https://github.com/DoSomething/phoenix/pull/1160) ([mmwtsn](https://github.com/mmwtsn))
- Report back modals [\#1157](https://github.com/DoSomething/phoenix/pull/1157) ([DFurnes](https://github.com/DFurnes))
- Boosting queries to improve search results [\#1156](https://github.com/DoSomething/phoenix/pull/1156) ([blisteringherb](https://github.com/blisteringherb))
- Modals [\#1154](https://github.com/DoSomething/phoenix/pull/1154) ([DFurnes](https://github.com/DFurnes))
- Comeback Clothes SMS report backs [\#1152](https://github.com/DoSomething/phoenix/pull/1152) ([jonuy](https://github.com/jonuy))
- Changes "have a question?" footer text to gray [\#1151](https://github.com/DoSomething/phoenix/pull/1151) ([barryclark](https://github.com/barryclark))
- Prove It image fix [\#1150](https://github.com/DoSomething/phoenix/pull/1150) ([aaronschachter](https://github.com/aaronschachter))
- Static content style updates [\#1142](https://github.com/DoSomething/phoenix/pull/1142) ([barryclark](https://github.com/barryclark))
- Pitch \[sign up\] Fix [\#1141](https://github.com/DoSomething/phoenix/pull/1141) ([mmwtsn](https://github.com/mmwtsn))
- Fixed nav order. Fixes \#1130. [\#1138](https://github.com/DoSomething/phoenix/pull/1138) ([DFurnes](https://github.com/DFurnes))
- Location finder style [\#1137](https://github.com/DoSomething/phoenix/pull/1137) ([DFurnes](https://github.com/DFurnes))
- Adding proper theming and functionality for search boxes [\#1136](https://github.com/DoSomething/phoenix/pull/1136) ([blisteringherb](https://github.com/blisteringherb))
- Campaign Opt-in info. [\#1132](https://github.com/DoSomething/phoenix/pull/1132) ([angaither](https://github.com/angaither))
- Fixes \#1094 [\#1108](https://github.com/DoSomething/phoenix/pull/1108) ([aaronschachter](https://github.com/aaronschachter))
- Campaign Footer Styles [\#1106](https://github.com/DoSomething/phoenix/pull/1106) ([mmwtsn](https://github.com/mmwtsn))
- SEMICOLON STUFF [\#1100](https://github.com/DoSomething/phoenix/pull/1100) ([angaither](https://github.com/angaither))
- Updated campaign hero images. [\#1098](https://github.com/DoSomething/phoenix/pull/1098) ([angaither](https://github.com/angaither))
- Reportback form validation [\#1097](https://github.com/DoSomething/phoenix/pull/1097) ([aaronschachter](https://github.com/aaronschachter))
- Action Page Sponsor Updates [\#1096](https://github.com/DoSomething/phoenix/pull/1096) ([mmwtsn](https://github.com/mmwtsn))
- Updating fact page edit form [\#1093](https://github.com/DoSomething/phoenix/pull/1093) ([blisteringherb](https://github.com/blisteringherb))
- Campaign Pathauto [\#1089](https://github.com/DoSomething/phoenix/pull/1089) ([angaither](https://github.com/angaither))
- Added cache clear for dosomething\_image [\#1084](https://github.com/DoSomething/phoenix/pull/1084) ([angaither](https://github.com/angaither))
- Changing row styles for /campaigns [\#1082](https://github.com/DoSomething/phoenix/pull/1082) ([blisteringherb](https://github.com/blisteringherb))
- Adding a tpl file for theming /campaigns view [\#1075](https://github.com/DoSomething/phoenix/pull/1075) ([blisteringherb](https://github.com/blisteringherb))
- View reportback images [\#1074](https://github.com/DoSomething/phoenix/pull/1074) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#1069 - Move to mbp naming convention [\#1070](https://github.com/DoSomething/phoenix/pull/1070) ([DeeZone](https://github.com/DeeZone))
- Fixes \#1064 - missing email value in payload [\#1067](https://github.com/DoSomething/phoenix/pull/1067) ([DeeZone](https://github.com/DeeZone))
- Hotfix for reportback upload directory [\#1066](https://github.com/DoSomething/phoenix/pull/1066) ([aaronschachter](https://github.com/aaronschachter))
- Campaign custom variables [\#1065](https://github.com/DoSomething/phoenix/pull/1065) ([aaronschachter](https://github.com/aaronschachter))
- 11 Facts Theming [\#1063](https://github.com/DoSomething/phoenix/pull/1063) ([barryclark](https://github.com/barryclark))
- Adds ds pull command [\#1062](https://github.com/DoSomething/phoenix/pull/1062) ([aaronschachter](https://github.com/aaronschachter))
- Fixed menu callback, only print picks if they are there [\#1059](https://github.com/DoSomething/phoenix/pull/1059) ([angaither](https://github.com/angaither))
- Fixes \#939 [\#1056](https://github.com/DoSomething/phoenix/pull/1056) ([aaronschachter](https://github.com/aaronschachter))
- Updating type biasing [\#1053](https://github.com/DoSomething/phoenix/pull/1053) ([blisteringherb](https://github.com/blisteringherb))
- Adding a new view and neccessary fields for /campaigns [\#1051](https://github.com/DoSomething/phoenix/pull/1051) ([blisteringherb](https://github.com/blisteringherb))
- Sponsor modal images [\#1049](https://github.com/DoSomething/phoenix/pull/1049) ([aaronschachter](https://github.com/aaronschachter))
- Import user data [\#1047](https://github.com/DoSomething/phoenix/pull/1047) ([angaither](https://github.com/angaither))
- Redis ground work [\#1045](https://github.com/DoSomething/phoenix/pull/1045) ([desmondmorris](https://github.com/desmondmorris))
- Sponsor logos [\#1044](https://github.com/DoSomething/phoenix/pull/1044) ([aaronschachter](https://github.com/aaronschachter))
- Added dosomething\_sms to the info and make files [\#1038](https://github.com/DoSomething/phoenix/pull/1038) ([jonuy](https://github.com/jonuy))
- Reportback form images [\#1035](https://github.com/DoSomething/phoenix/pull/1035) ([aaronschachter](https://github.com/aaronschachter))
- Make first name & bday required on signup [\#1032](https://github.com/DoSomething/phoenix/pull/1032) ([angaither](https://github.com/angaither))
- Redirect to referer after login. [\#1030](https://github.com/DoSomething/phoenix/pull/1030) ([angaither](https://github.com/angaither))
- Fact Styles and Markup Updates [\#1029](https://github.com/DoSomething/phoenix/pull/1029) ([mmwtsn](https://github.com/mmwtsn))
- Hides asterisks on required form fields. [\#1028](https://github.com/DoSomething/phoenix/pull/1028) ([DFurnes](https://github.com/DFurnes))
- Reportback File upload [\#1027](https://github.com/DoSomething/phoenix/pull/1027) ([aaronschachter](https://github.com/aaronschachter))
- Correctly applies login form styling. [\#1022](https://github.com/DoSomething/phoenix/pull/1022) ([DFurnes](https://github.com/DFurnes))
- Static content style updates [\#1017](https://github.com/DoSomething/phoenix/pull/1017) ([barryclark](https://github.com/barryclark))
- Fixes form styling error caused by \#999. [\#1013](https://github.com/DoSomething/phoenix/pull/1013) ([DFurnes](https://github.com/DFurnes))
- Replaces robots.txt during staging deployment [\#1009](https://github.com/DoSomething/phoenix/pull/1009) ([desmondmorris](https://github.com/desmondmorris))
- Kill reportback field [\#1008](https://github.com/DoSomething/phoenix/pull/1008) ([aaronschachter](https://github.com/aaronschachter))
- Remove image field from Reportback form [\#1002](https://github.com/DoSomething/phoenix/pull/1002) ([aaronschachter](https://github.com/aaronschachter))
- Auth warning common [\#999](https://github.com/DoSomething/phoenix/pull/999) ([angaither](https://github.com/angaither))
- Removes secure pages module from info file & code. [\#996](https://github.com/DoSomething/phoenix/pull/996) ([angaither](https://github.com/angaither))
- Updating Solr biases [\#995](https://github.com/DoSomething/phoenix/pull/995) ([blisteringherb](https://github.com/blisteringherb))
- Adds subtitle and add'l fields [\#993](https://github.com/DoSomething/phoenix/pull/993) ([blisteringherb](https://github.com/blisteringherb))
- Signup message [\#992](https://github.com/DoSomething/phoenix/pull/992) ([aaronschachter](https://github.com/aaronschachter))
- Campaign footnotes [\#990](https://github.com/DoSomething/phoenix/pull/990) ([aaronschachter](https://github.com/aaronschachter))
- User Partners/Sponsors field [\#989](https://github.com/DoSomething/phoenix/pull/989) ([aaronschachter](https://github.com/aaronschachter))
- Port to Neue [\#987](https://github.com/DoSomething/phoenix/pull/987) ([mmwtsn](https://github.com/mmwtsn))
- Mobilecommons update [\#986](https://github.com/DoSomething/phoenix/pull/986) ([aaronschachter](https://github.com/aaronschachter))
- Enable modules in dosomething.info on ds build. [\#984](https://github.com/DoSomething/phoenix/pull/984) ([angaither](https://github.com/angaither))
- Initial pass at dosomething\_sms module [\#981](https://github.com/DoSomething/phoenix/pull/981) ([jonuy](https://github.com/jonuy))
- Image folder [\#979](https://github.com/DoSomething/phoenix/pull/979) ([DFurnes](https://github.com/DFurnes))
- Broken Markup Patch [\#978](https://github.com/DoSomething/phoenix/pull/978) ([mmwtsn](https://github.com/mmwtsn))
- Changes ds cli shell to bash instead of sh.  This will make it play nice... [\#977](https://github.com/DoSomething/phoenix/pull/977) ([desmondmorris](https://github.com/desmondmorris))
- Tag fixes [\#976](https://github.com/DoSomething/phoenix/pull/976) ([DFurnes](https://github.com/DFurnes))
- Updated get\_themed\_image function. [\#975](https://github.com/DoSomething/phoenix/pull/975) ([angaither](https://github.com/angaither))
- Campaign Template Checks [\#973](https://github.com/DoSomething/phoenix/pull/973) ([mmwtsn](https://github.com/mmwtsn))
- Fact Footnotes [\#972](https://github.com/DoSomething/phoenix/pull/972) ([aaronschachter](https://github.com/aaronschachter))
- Set mobile-commons title opt in to null [\#966](https://github.com/DoSomething/phoenix/pull/966) ([angaither](https://github.com/angaither))
- Fixin small bugs [\#965](https://github.com/DoSomething/phoenix/pull/965) ([aaronschachter](https://github.com/aaronschachter))
- Add under 13 bool [\#964](https://github.com/DoSomething/phoenix/pull/964) ([angaither](https://github.com/angaither))
- Partners field collection fix [\#953](https://github.com/DoSomething/phoenix/pull/953) ([aaronschachter](https://github.com/aaronschachter))
- Added function to check if user is under 13. [\#952](https://github.com/DoSomething/phoenix/pull/952) ([angaither](https://github.com/angaither))
- Add modules to info file. [\#946](https://github.com/DoSomething/phoenix/pull/946) ([angaither](https://github.com/angaither))
- Campaign hotfix [\#940](https://github.com/DoSomething/phoenix/pull/940) ([aaronschachter](https://github.com/aaronschachter))
- Misc. Campaign Style Updates [\#926](https://github.com/DoSomething/phoenix/pull/926) ([mmwtsn](https://github.com/mmwtsn))
- is\_empty is not empty FML [\#924](https://github.com/DoSomething/phoenix/pull/924) ([aaronschachter](https://github.com/aaronschachter))
- Broken campaigns [\#923](https://github.com/DoSomething/phoenix/pull/923) ([aaronschachter](https://github.com/aaronschachter))
- Update Admin Perms [\#922](https://github.com/DoSomething/phoenix/pull/922) ([angaither](https://github.com/angaither))
- Updates directory name lol [\#920](https://github.com/DoSomething/phoenix/pull/920) ([DFurnes](https://github.com/DFurnes))
- Sponsors vars - Part 2 [\#916](https://github.com/DoSomething/phoenix/pull/916) ([aaronschachter](https://github.com/aaronschachter))
- Added imagemagick rule to process images. [\#913](https://github.com/DoSomething/phoenix/pull/913) ([angaither](https://github.com/angaither))
- Authy-auth-auth. [\#911](https://github.com/DoSomething/phoenix/pull/911) ([DFurnes](https://github.com/DFurnes))
- Added fieldgroup permissions [\#910](https://github.com/DoSomething/phoenix/pull/910) ([angaither](https://github.com/angaither))
- Campaign Partials [\#909](https://github.com/DoSomething/phoenix/pull/909) ([mmwtsn](https://github.com/mmwtsn))
- Campaign Fender Updates [\#907](https://github.com/DoSomething/phoenix/pull/907) ([mmwtsn](https://github.com/mmwtsn))
- Issue716 message broker install [\#903](https://github.com/DoSomething/phoenix/pull/903) ([DeeZone](https://github.com/DeeZone))
- Adding a tpl file to facilitate theming search results [\#902](https://github.com/DoSomething/phoenix/pull/902) ([blisteringherb](https://github.com/blisteringherb))
- Added an admin form for mailchimp & mobile commons list ids. [\#901](https://github.com/DoSomething/phoenix/pull/901) ([angaither](https://github.com/angaither))
- Updating default solr settings [\#900](https://github.com/DoSomething/phoenix/pull/900) ([blisteringherb](https://github.com/blisteringherb))
- Fixes incorrect auth link on pitch page. [\#899](https://github.com/DoSomething/phoenix/pull/899) ([DFurnes](https://github.com/DFurnes))
- Hero Images [\#896](https://github.com/DoSomething/phoenix/pull/896) ([mmwtsn](https://github.com/mmwtsn))
- Fixes everything [\#890](https://github.com/DoSomething/phoenix/pull/890) ([angaither](https://github.com/angaither))
- Vocabulary permissions [\#889](https://github.com/DoSomething/phoenix/pull/889) ([aaronschachter](https://github.com/aaronschachter))
- Zendesk Test fix + additional tests [\#888](https://github.com/DoSomething/phoenix/pull/888) ([aaronschachter](https://github.com/aaronschachter))
- Signup mobile commons [\#886](https://github.com/DoSomething/phoenix/pull/886) ([angaither](https://github.com/angaither))
- Zendesk lib [\#885](https://github.com/DoSomething/phoenix/pull/885) ([aaronschachter](https://github.com/aaronschachter))
- Confirmation Page [\#880](https://github.com/DoSomething/phoenix/pull/880) ([mmwtsn](https://github.com/mmwtsn))
- It's not purple time :\( [\#878](https://github.com/DoSomething/phoenix/pull/878) ([barryclark](https://github.com/barryclark))
- Hooked in validation classes; cleaned up gross datetime formatting. [\#876](https://github.com/DoSomething/phoenix/pull/876) ([DFurnes](https://github.com/DFurnes))
- drush aliases, ssh configs and ds binary update commands [\#872](https://github.com/DoSomething/phoenix/pull/872) ([desmondmorris](https://github.com/desmondmorris))
- First pass over static content markup and styles [\#871](https://github.com/DoSomething/phoenix/pull/871) ([barryclark](https://github.com/barryclark))
- Removes files symlink before creating new symlink.  Removes unused steps [\#870](https://github.com/DoSomething/phoenix/pull/870) ([desmondmorris](https://github.com/desmondmorris))
- Added 'form action' to add campaign data funciton. [\#868](https://github.com/DoSomething/phoenix/pull/868) ([angaither](https://github.com/angaither))
- Changes ssh user and app paths.  Also does staging specific symlinking [\#867](https://github.com/DoSomething/phoenix/pull/867) ([desmondmorris](https://github.com/desmondmorris))
- Output modal links for FAQ and Facts [\#866](https://github.com/DoSomething/phoenix/pull/866) ([aaronschachter](https://github.com/aaronschachter))
- Action Fact Updates [\#864](https://github.com/DoSomething/phoenix/pull/864) ([mmwtsn](https://github.com/mmwtsn))
- Fixes \#822: Updates ctools to latest \(7.x-1.4\) [\#861](https://github.com/DoSomething/phoenix/pull/861) ([mshmsh5000](https://github.com/mshmsh5000))
- Environment aware settings [\#860](https://github.com/DoSomething/phoenix/pull/860) ([desmondmorris](https://github.com/desmondmorris))
- Making updates to static content for better usability [\#854](https://github.com/DoSomething/phoenix/pull/854) ([blisteringherb](https://github.com/blisteringherb))
- Fixing intro and hero image for static content [\#852](https://github.com/DoSomething/phoenix/pull/852) ([blisteringherb](https://github.com/blisteringherb))
- Checking for video id before generating video markup [\#851](https://github.com/DoSomething/phoenix/pull/851) ([blisteringherb](https://github.com/blisteringherb))
- Partners vocabulary [\#849](https://github.com/DoSomething/phoenix/pull/849) ([aaronschachter](https://github.com/aaronschachter))
- Fixing generation of gallery img on static content [\#847](https://github.com/DoSomething/phoenix/pull/847) ([blisteringherb](https://github.com/blisteringherb))
- Typo [\#846](https://github.com/DoSomething/phoenix/pull/846) ([mmwtsn](https://github.com/mmwtsn))
- NPM Warnings! [\#845](https://github.com/DoSomething/phoenix/pull/845) ([mmwtsn](https://github.com/mmwtsn))
- Only staff members can see term pages. [\#843](https://github.com/DoSomething/phoenix/pull/843) ([angaither](https://github.com/angaither))
- Removed 'field\_image\_sponsor\_logo' from node\_view [\#838](https://github.com/DoSomething/phoenix/pull/838) ([angaither](https://github.com/angaither))
- action \(prove it\) – gallery updates [\#834](https://github.com/DoSomething/phoenix/pull/834) ([mmwtsn](https://github.com/mmwtsn))
- Condintionally Prints Scholarship Variable [\#825](https://github.com/DoSomething/phoenix/pull/825) ([mmwtsn](https://github.com/mmwtsn))
- Mobilecommons tweaks [\#823](https://github.com/DoSomething/phoenix/pull/823) ([aaronschachter](https://github.com/aaronschachter))
- Smart settings and cap deploy to pc staging server [\#821](https://github.com/DoSomething/phoenix/pull/821) ([desmondmorris](https://github.com/desmondmorris))
- Fixes JSHint Errors [\#820](https://github.com/DoSomething/phoenix/pull/820) ([mmwtsn](https://github.com/mmwtsn))
- Adds a .jshintrc and syncs with Neue [\#819](https://github.com/DoSomething/phoenix/pull/819) ([mmwtsn](https://github.com/mmwtsn))
- Adds html5shiv for IE8. [\#817](https://github.com/DoSomething/phoenix/pull/817) ([DFurnes](https://github.com/DFurnes))
- Tip Functionality & Styles [\#816](https://github.com/DoSomething/phoenix/pull/816) ([mmwtsn](https://github.com/mmwtsn))
- Drupal invisibles [\#813](https://github.com/DoSomething/phoenix/pull/813) ([DFurnes](https://github.com/DFurnes))
- Browserify on grunt:watch! [\#811](https://github.com/DoSomething/phoenix/pull/811) ([mmwtsn](https://github.com/mmwtsn))
- Administrator role [\#809](https://github.com/DoSomething/phoenix/pull/809) ([aaronschachter](https://github.com/aaronschachter))
- Action Template Updates [\#806](https://github.com/DoSomething/phoenix/pull/806) ([mmwtsn](https://github.com/mmwtsn))
- Added image terms. [\#804](https://github.com/DoSomething/phoenix/pull/804) ([angaither](https://github.com/angaither))
- Print do it copy. [\#802](https://github.com/DoSomething/phoenix/pull/802) ([angaither](https://github.com/angaither))
- Set image & cause tags in image search to 'and' not 'or' [\#800](https://github.com/DoSomething/phoenix/pull/800) ([angaither](https://github.com/angaither))
- dosomething\_zendesk [\#798](https://github.com/DoSomething/phoenix/pull/798) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#787 by properly configuring xmlsitemap in dosomething.install [\#795](https://github.com/DoSomething/phoenix/pull/795) ([mshmsh5000](https://github.com/mshmsh5000))
- Staff Username [\#793](https://github.com/DoSomething/phoenix/pull/793) ([angaither](https://github.com/angaither))
- Moving causes down [\#790](https://github.com/DoSomething/phoenix/pull/790) ([blisteringherb](https://github.com/blisteringherb))
- Message broker call update1 [\#775](https://github.com/DoSomething/phoenix/pull/775) ([DeeZone](https://github.com/DeeZone))

## [v0.2.0](https://github.com/dosomething/phoenix/tree/v0.2.0) (2014-02-22)
**Fixed bugs:**

- DS build --install error - Missing Xmlsitemap\_18n [\#783](https://github.com/DoSomething/phoenix/issues/783)
- Campaign End Date error [\#754](https://github.com/DoSomething/phoenix/issues/754)
- Campaign: automatic revisions [\#744](https://github.com/DoSomething/phoenix/issues/744)
- Reportback: PHP Notice [\#721](https://github.com/DoSomething/phoenix/issues/721)
- User Edit: Can't update profile and save mobile number [\#720](https://github.com/DoSomething/phoenix/issues/720)
- User edit form redirect [\#719](https://github.com/DoSomething/phoenix/issues/719)
- Declare default $secure\_url value [\#714](https://github.com/DoSomething/phoenix/issues/714)
- User: PHP Notice in dosomething\_user\_form\_alter [\#713](https://github.com/DoSomething/phoenix/issues/713)
- Chrome – Style Confirmation Messages [\#678](https://github.com/DoSomething/phoenix/issues/678)
- User: Empty cell \# won't allow login [\#665](https://github.com/DoSomething/phoenix/issues/665)
- DS Profile: Mobilecommons Library directory error [\#656](https://github.com/DoSomething/phoenix/issues/656)
- Editable Content Regions + Markdown Breaking Layout [\#646](https://github.com/DoSomething/phoenix/issues/646)
- Fact:  Use title instead of body to store fact [\#626](https://github.com/DoSomething/phoenix/issues/626)
- Campaign: Error: Unknown data property [\#625](https://github.com/DoSomething/phoenix/issues/625)
- Campaign Form - Timing; start date in one year, end date in the next [\#596](https://github.com/DoSomething/phoenix/issues/596)
- Campaign Form - Timing; default value should be null [\#595](https://github.com/DoSomething/phoenix/issues/595)
- Image Module – Undefined Variables [\#581](https://github.com/DoSomething/phoenix/issues/581)
- Campaign: PHP Notice - undefined variable sponsors [\#580](https://github.com/DoSomething/phoenix/issues/580)
- Missing NPM Module "debowerify" [\#575](https://github.com/DoSomething/phoenix/issues/575)
- Reportback: PHP Notice [\#487](https://github.com/DoSomething/phoenix/issues/487)
- DS build: User permissions not set [\#446](https://github.com/DoSomething/phoenix/issues/446)
- Fact: PHP Notice [\#441](https://github.com/DoSomething/phoenix/issues/441)
- Taxonomy: Sponsor image field instance missing [\#440](https://github.com/DoSomething/phoenix/issues/440)
- User: Is Staff PHP notice [\#422](https://github.com/DoSomething/phoenix/issues/422)
- Devel generage image - PHP Warning [\#399](https://github.com/DoSomething/phoenix/issues/399)
- Devel generate campaign - PHP Notice [\#398](https://github.com/DoSomething/phoenix/issues/398)
- Campaign: Pitch tab [\#388](https://github.com/DoSomething/phoenix/issues/388)
- Fact Search: Admin toolbar [\#384](https://github.com/DoSomething/phoenix/issues/384)
- Fact Search: Format updated column [\#383](https://github.com/DoSomething/phoenix/issues/383)
- Campaign: Double field -- text formats [\#369](https://github.com/DoSomething/phoenix/issues/369)
- Vagrant: SimpleTest execution timeout [\#365](https://github.com/DoSomething/phoenix/issues/365)
- Fact Devel: Notice messages when creating Facts [\#351](https://github.com/DoSomething/phoenix/issues/351)
- QA broken: Fatal error -- varnish.cache.inc [\#307](https://github.com/DoSomething/phoenix/issues/307)
- Devel Generate - PHP Strict warning [\#297](https://github.com/DoSomething/phoenix/issues/297)
- Campaign / double\_field: PHP Notice [\#286](https://github.com/DoSomething/phoenix/issues/286)
- Fix subdir for Double Field in drupal-org.make [\#281](https://github.com/DoSomething/phoenix/issues/281)
- Campaign: PHP Notice/warnings in preprocess\_entity [\#275](https://github.com/DoSomething/phoenix/issues/275)
- Varnish errors [\#274](https://github.com/DoSomething/phoenix/issues/274)
- DoSomething WebTests fail [\#260](https://github.com/DoSomething/phoenix/issues/260)
- Vagrant up error: host\_name setting doesn't exist [\#255](https://github.com/DoSomething/phoenix/issues/255)
- Set base url & hostname [\#251](https://github.com/DoSomething/phoenix/issues/251)
- "400 Bad Request" Error when adding a node [\#248](https://github.com/DoSomething/phoenix/issues/248)
- Devel: Drush was unable to export FirePHP [\#235](https://github.com/DoSomething/phoenix/issues/235)
- Campaign: Form validation for URL fields [\#232](https://github.com/DoSomething/phoenix/issues/232)
- Errors uploading images in Campaign form [\#229](https://github.com/DoSomething/phoenix/issues/229)
- Bug in drupal-org make file: UUID Features array key [\#185](https://github.com/DoSomething/phoenix/issues/185)
- Missing paraneue theme in themes/dosomething [\#147](https://github.com/DoSomething/phoenix/issues/147)
- Fail: sh ds build --install [\#145](https://github.com/DoSomething/phoenix/issues/145)
- DS User WebTest fails for "administer mailsystem" [\#131](https://github.com/DoSomething/phoenix/issues/131)
- Installation error with build.sh [\#60](https://github.com/DoSomething/phoenix/issues/60)
- CKEditor could not be detected. [\#55](https://github.com/DoSomething/phoenix/issues/55)
- Moving ds\_search module to the new lib directory [\#604](https://github.com/DoSomething/phoenix/pull/604) ([blisteringherb](https://github.com/blisteringherb))

**Closed issues:**

- Add and configure XML Sitemap module [\#763](https://github.com/DoSomething/phoenix/issues/763)
- Facts - Help Text Updates [\#762](https://github.com/DoSomething/phoenix/issues/762)
- Action Guides: Help Text Updates [\#761](https://github.com/DoSomething/phoenix/issues/761)
- Campaign Template - Help Text Updates [\#760](https://github.com/DoSomething/phoenix/issues/760)
- Campaign: On sign up or registration, update the user's Mobile Commons DOB [\#759](https://github.com/DoSomething/phoenix/issues/759)
- Move gallery preprocess code into subfunction [\#757](https://github.com/DoSomething/phoenix/issues/757)
- DS utility doesn't have a task to compile minified assets [\#748](https://github.com/DoSomething/phoenix/issues/748)
- Image Fields: Minimum pixel size [\#745](https://github.com/DoSomething/phoenix/issues/745)
- Action Guides: Image Issues [\#735](https://github.com/DoSomething/phoenix/issues/735)
- Campaign Date Variable [\#734](https://github.com/DoSomething/phoenix/issues/734)
- User Edit: Fails if mobile is set [\#731](https://github.com/DoSomething/phoenix/issues/731)
- User Add Fails without error [\#730](https://github.com/DoSomething/phoenix/issues/730)
- Hook up report back modal [\#717](https://github.com/DoSomething/phoenix/issues/717)
- Mobilecommons auth variables [\#712](https://github.com/DoSomething/phoenix/issues/712)
- campaign – dates missing form header sections [\#694](https://github.com/DoSomething/phoenix/issues/694)
- User / Campaign: Login signup bug [\#690](https://github.com/DoSomething/phoenix/issues/690)
- Campaign: Pitch page bug [\#687](https://github.com/DoSomething/phoenix/issues/687)
- Web tests for login/registration flows [\#686](https://github.com/DoSomething/phoenix/issues/686)
- Registration form server-side validation and data sanitation [\#685](https://github.com/DoSomething/phoenix/issues/685)
- Editors: Publish / unpublish ability [\#683](https://github.com/DoSomething/phoenix/issues/683)
- Install Drush manually instead of PEAR [\#682](https://github.com/DoSomething/phoenix/issues/682)
- Login can fail with blank mobile number [\#680](https://github.com/DoSomething/phoenix/issues/680)
- Campaign: Confirmation template [\#679](https://github.com/DoSomething/phoenix/issues/679)
- Campaign – "High Season" year fields starts at year 0 [\#677](https://github.com/DoSomething/phoenix/issues/677)
- Action Guide: Preprocess / template [\#674](https://github.com/DoSomething/phoenix/issues/674)
- User: Registration/login form [\#671](https://github.com/DoSomething/phoenix/issues/671)
- Registration form shouldn't request a username [\#669](https://github.com/DoSomething/phoenix/issues/669)
- Image: node updates [\#667](https://github.com/DoSomething/phoenix/issues/667)
- Sponsors: Use an image field for the logo [\#654](https://github.com/DoSomething/phoenix/issues/654)
- Image Node Reference view alter [\#650](https://github.com/DoSomething/phoenix/issues/650)
- Image Node: Add fields [\#649](https://github.com/DoSomething/phoenix/issues/649)
- View for browsing images [\#648](https://github.com/DoSomething/phoenix/issues/648)
- Image Style name [\#647](https://github.com/DoSomething/phoenix/issues/647)
- Pathauto patterns [\#645](https://github.com/DoSomething/phoenix/issues/645)
- User: Mobile must be unique [\#644](https://github.com/DoSomething/phoenix/issues/644)
- Markdown editing for static content fields [\#641](https://github.com/DoSomething/phoenix/issues/641)
- Markdown not working within the campaigns template [\#640](https://github.com/DoSomething/phoenix/issues/640)
- Login Form: No default birthdate. [\#638](https://github.com/DoSomething/phoenix/issues/638)
- User: PHP Notice -- dosomething\_user\_node\_access [\#636](https://github.com/DoSomething/phoenix/issues/636)
- Fact: Alter title field as textarea [\#633](https://github.com/DoSomething/phoenix/issues/633)
- Video field collection: Default to YouTube provider [\#624](https://github.com/DoSomething/phoenix/issues/624)
- Campaign CSV export [\#623](https://github.com/DoSomething/phoenix/issues/623)
- Members need to be able to log in with email, cell \(username?\) [\#619](https://github.com/DoSomething/phoenix/issues/619)
- DMOZ meta tag in header [\#618](https://github.com/DoSomething/phoenix/issues/618)
- Campaign: Action Guide fields [\#616](https://github.com/DoSomething/phoenix/issues/616)
- Action Guide: Content Type [\#615](https://github.com/DoSomething/phoenix/issues/615)
- User login/registration form fields [\#614](https://github.com/DoSomething/phoenix/issues/614)
- Modal login form HTTPS issue [\#613](https://github.com/DoSomething/phoenix/issues/613)
- 11 Facts: Permissions [\#609](https://github.com/DoSomething/phoenix/issues/609)
- Static Content: Permissions [\#608](https://github.com/DoSomething/phoenix/issues/608)
- Fact: Rebuild as node [\#606](https://github.com/DoSomething/phoenix/issues/606)
- Replace Pantheon drops core with d.o core [\#602](https://github.com/DoSomething/phoenix/issues/602)
- Facts - multiple sources [\#598](https://github.com/DoSomething/phoenix/issues/598)
- 11 Facts - add cause taxonomy [\#594](https://github.com/DoSomething/phoenix/issues/594)
- User API: Disable default drupal emails [\#588](https://github.com/DoSomething/phoenix/issues/588)
- Remove WYSIWYG Module [\#584](https://github.com/DoSomething/phoenix/issues/584)
- Campaign form: solution statement open text field [\#579](https://github.com/DoSomething/phoenix/issues/579)
- Campaign form: "Show End Date on Pitch & Action Page" should be default selected [\#577](https://github.com/DoSomething/phoenix/issues/577)
- Campaign form: Location Finder fields [\#576](https://github.com/DoSomething/phoenix/issues/576)
- Remove CKEditor library [\#573](https://github.com/DoSomething/phoenix/issues/573)
- Add DMOZ meta tag. [\#571](https://github.com/DoSomething/phoenix/issues/571)
- Reportback: Update testSchema\(\) [\#569](https://github.com/DoSomething/phoenix/issues/569)
- DS Build doesn't install Neue & compile source [\#566](https://github.com/DoSomething/phoenix/issues/566)
- Facts: Add char counter to fact text area [\#563](https://github.com/DoSomething/phoenix/issues/563)
- Campaign: Editor permissions [\#561](https://github.com/DoSomething/phoenix/issues/561)
- Static content: User permissions [\#558](https://github.com/DoSomething/phoenix/issues/558)
- Reportback: Documentation [\#557](https://github.com/DoSomething/phoenix/issues/557)
- Campaign: Admin form fender work [\#555](https://github.com/DoSomething/phoenix/issues/555)
- Action – Build Out Template [\#553](https://github.com/DoSomething/phoenix/issues/553)
- Campaign: rename labels [\#552](https://github.com/DoSomething/phoenix/issues/552)
- Header – Style [\#549](https://github.com/DoSomething/phoenix/issues/549)
- Header – Build Out Template [\#548](https://github.com/DoSomething/phoenix/issues/548)
- Footer – Style [\#547](https://github.com/DoSomething/phoenix/issues/547)
- Footer – Build Out Template [\#546](https://github.com/DoSomething/phoenix/issues/546)
- Reportback: Remove num\_participants [\#545](https://github.com/DoSomething/phoenix/issues/545)
- Static Content: Add links for gallery images [\#544](https://github.com/DoSomething/phoenix/issues/544)
- Action Type taxonomy updates [\#541](https://github.com/DoSomething/phoenix/issues/541)
- Campaign: Add new fields [\#539](https://github.com/DoSomething/phoenix/issues/539)
- ƒfield displays on all drush commands [\#537](https://github.com/DoSomething/phoenix/issues/537)
- Campaign: update form helper text [\#533](https://github.com/DoSomething/phoenix/issues/533)
- Campaign: Login / Register signup [\#532](https://github.com/DoSomething/phoenix/issues/532)
- User: Account creation settings [\#531](https://github.com/DoSomething/phoenix/issues/531)
- Awesome Things module [\#530](https://github.com/DoSomething/phoenix/issues/530)
- Static Content: Add intro video field and corresponding logic [\#528](https://github.com/DoSomething/phoenix/issues/528)
- Image: create "image\_get\_image\_url" function [\#523](https://github.com/DoSomething/phoenix/issues/523)
- Add a link for CTA button [\#520](https://github.com/DoSomething/phoenix/issues/520)
- User fields [\#518](https://github.com/DoSomething/phoenix/issues/518)
- Metatag: Permissions [\#516](https://github.com/DoSomething/phoenix/issues/516)
- Reportback: Change why\_participated field type [\#515](https://github.com/DoSomething/phoenix/issues/515)
- Add drush make\_local plugin [\#513](https://github.com/DoSomething/phoenix/issues/513)
- Include Paraneue working copy in make file [\#512](https://github.com/DoSomething/phoenix/issues/512)
- Pitch – Background Image [\#511](https://github.com/DoSomething/phoenix/issues/511)
- Pitch – Style [\#510](https://github.com/DoSomething/phoenix/issues/510)
- Pitch – Build out HTML [\#509](https://github.com/DoSomething/phoenix/issues/509)
- Static content: Add Video field collection to content type [\#508](https://github.com/DoSomething/phoenix/issues/508)
- Video field collection [\#506](https://github.com/DoSomething/phoenix/issues/506)
- Image: Rename fields [\#505](https://github.com/DoSomething/phoenix/issues/505)
- Update ds binary with asset helpers [\#504](https://github.com/DoSomething/phoenix/issues/504)
- Fact: Remove ctools modal [\#501](https://github.com/DoSomething/phoenix/issues/501)
- NPM, Bower & Grunt support in Vagrant [\#498](https://github.com/DoSomething/phoenix/issues/498)
- Reportback: Log updates [\#497](https://github.com/DoSomething/phoenix/issues/497)
- Reportback: Log table schema [\#496](https://github.com/DoSomething/phoenix/issues/496)
- Create Static Content content type [\#494](https://github.com/DoSomething/phoenix/issues/494)
- Add Metatag module [\#490](https://github.com/DoSomething/phoenix/issues/490)
- Campaign: Errors when there is no sponsor [\#484](https://github.com/DoSomething/phoenix/issues/484)
- Reportback: Simplify + document dosomething\_reportback\_save [\#482](https://github.com/DoSomething/phoenix/issues/482)
- Campaign: Reportback display field [\#478](https://github.com/DoSomething/phoenix/issues/478)
- Campaign: Rename reportback fields [\#477](https://github.com/DoSomething/phoenix/issues/477)
- Reportback: User view permissions [\#475](https://github.com/DoSomething/phoenix/issues/475)
- Hard-coded base\_url borks things in non-sandbox installs [\#472](https://github.com/DoSomething/phoenix/issues/472)
- Reportback: Add additional properties [\#469](https://github.com/DoSomething/phoenix/issues/469)
- DS Image: User permissions [\#468](https://github.com/DoSomething/phoenix/issues/468)
- Campaign: Sponsors Image in tpl [\#467](https://github.com/DoSomething/phoenix/issues/467)
- DS Client-Side: App-level SCSS and JS [\#462](https://github.com/DoSomething/phoenix/issues/462)
- DS Build: Client-side build system [\#461](https://github.com/DoSomething/phoenix/issues/461)
- DS build: Dev -- generate taxonomy terms before nodes [\#460](https://github.com/DoSomething/phoenix/issues/460)
- Reportback: tpl file [\#459](https://github.com/DoSomething/phoenix/issues/459)
- Campaign: Display update reportback form [\#458](https://github.com/DoSomething/phoenix/issues/458)
- Reportback: Delete functionality [\#457](https://github.com/DoSomething/phoenix/issues/457)
- Reportback: Display confirm message upon submit [\#452](https://github.com/DoSomething/phoenix/issues/452)
- Add NOODP meta tag to head block [\#451](https://github.com/DoSomething/phoenix/issues/451)
- Campaign: Mobile Commons opt in with campaign name on sign up [\#450](https://github.com/DoSomething/phoenix/issues/450)
- Campaign: Preprocess Image vars [\#448](https://github.com/DoSomething/phoenix/issues/448)
- Pattern Library integration [\#444](https://github.com/DoSomething/phoenix/issues/444)
- JavaScript build system [\#443](https://github.com/DoSomething/phoenix/issues/443)
- Campaign: Preprocess field collection isset [\#442](https://github.com/DoSomething/phoenix/issues/442)
- Fact: Preprocess mutli-value fact fields [\#435](https://github.com/DoSomething/phoenix/issues/435)
- Youtube Link [\#433](https://github.com/DoSomething/phoenix/issues/433)
- Reportback: Save reportback function [\#432](https://github.com/DoSomething/phoenix/issues/432)
- Coder misconfigured? Possible work around with drush [\#431](https://github.com/DoSomething/phoenix/issues/431)
- Campaign: Preprocess fact vars [\#430](https://github.com/DoSomething/phoenix/issues/430)
- Fact: View fact\_search access [\#428](https://github.com/DoSomething/phoenix/issues/428)
- Fact: Test user access to Facts [\#427](https://github.com/DoSomething/phoenix/issues/427)
- On ds build 'admin' user does not have the admin role applied to the account [\#425](https://github.com/DoSomething/phoenix/issues/425)
- Campaign: Preprocess vars [\#424](https://github.com/DoSomething/phoenix/issues/424)
- Campaign: Auth user display [\#418](https://github.com/DoSomething/phoenix/issues/418)
- Campaign: Anon user display [\#417](https://github.com/DoSomething/phoenix/issues/417)
- Reportback: permissions [\#415](https://github.com/DoSomething/phoenix/issues/415)
- Signup: Expose to views [\#414](https://github.com/DoSomething/phoenix/issues/414)
- Reportback: access callback [\#413](https://github.com/DoSomething/phoenix/issues/413)
- Reportback: Expose to views [\#411](https://github.com/DoSomething/phoenix/issues/411)
- Web test for dosomething\_user\_is\_staff\(\) [\#407](https://github.com/DoSomething/phoenix/issues/407)
- Reportback: Form arguments [\#406](https://github.com/DoSomething/phoenix/issues/406)
- Reportback:User images field [\#405](https://github.com/DoSomething/phoenix/issues/405)
- Reportback: Use entity module [\#404](https://github.com/DoSomething/phoenix/issues/404)
- Core Make: Upgrade to 7.26 [\#403](https://github.com/DoSomething/phoenix/issues/403)
- Reportback: Base table and module [\#392](https://github.com/DoSomething/phoenix/issues/392)
- Fact Search: Link to fact page [\#382](https://github.com/DoSomething/phoenix/issues/382)
- Update fact search roles [\#380](https://github.com/DoSomething/phoenix/issues/380)
- Taxonomy: Permissions [\#376](https://github.com/DoSomething/phoenix/issues/376)
- Fact: Expose facts to views [\#375](https://github.com/DoSomething/phoenix/issues/375)
- Admin Content Search [\#374](https://github.com/DoSomething/phoenix/issues/374)
- DS script: Rebuild permissions [\#362](https://github.com/DoSomething/phoenix/issues/362)
- Signup: Add dosomething\_signup into dosomething.info [\#361](https://github.com/DoSomething/phoenix/issues/361)
- Settings: Add dosomething\_settings to dosomething.info [\#360](https://github.com/DoSomething/phoenix/issues/360)
- Settings: Markdown access [\#359](https://github.com/DoSomething/phoenix/issues/359)
- Settings: Markdown allowed tags [\#358](https://github.com/DoSomething/phoenix/issues/358)
- Signup: Tests [\#355](https://github.com/DoSomething/phoenix/issues/355)
- Campaign: Template Preprocess text vars [\#354](https://github.com/DoSomething/phoenix/issues/354)
- User: Test for editor role [\#352](https://github.com/DoSomething/phoenix/issues/352)
- Signup: insert, check, delete signup functions [\#346](https://github.com/DoSomething/phoenix/issues/346)
- Signup: Form API functions [\#345](https://github.com/DoSomething/phoenix/issues/345)
- Signup: Create dosomething\_signup module and schema [\#344](https://github.com/DoSomething/phoenix/issues/344)
- Editor: Permissions for revisions [\#342](https://github.com/DoSomething/phoenix/issues/342)
- Add and enable Diff module [\#338](https://github.com/DoSomething/phoenix/issues/338)
- Campaign form: Alter internal google doc field weight [\#333](https://github.com/DoSomething/phoenix/issues/333)
- Campaign: Pitch view mode [\#332](https://github.com/DoSomething/phoenix/issues/332)
- Campaign: Collapse field groups on node form [\#331](https://github.com/DoSomething/phoenix/issues/331)
- Campaign: Rename and kill modules [\#330](https://github.com/DoSomething/phoenix/issues/330)
- Campaign: Move fact modal into campaign node form [\#329](https://github.com/DoSomething/phoenix/issues/329)
- Campaign: Unset '\_none' option in 'active hours' [\#327](https://github.com/DoSomething/phoenix/issues/327)
- Campaign: Hide 'show end date' checkbox [\#326](https://github.com/DoSomething/phoenix/issues/326)
- Campaign: FAQ longer title box [\#325](https://github.com/DoSomething/phoenix/issues/325)
- Update drupal core make to 7.25 [\#324](https://github.com/DoSomething/phoenix/issues/324)
- Create Campaign Node Type [\#323](https://github.com/DoSomething/phoenix/issues/323)
- Create Campaign Node Type [\#322](https://github.com/DoSomething/phoenix/issues/322)
- DS Image:  info changes [\#319](https://github.com/DoSomething/phoenix/issues/319)
- Fact: Store user permissions [\#318](https://github.com/DoSomething/phoenix/issues/318)
- Fact: Render source url as link in buildContent [\#317](https://github.com/DoSomething/phoenix/issues/317)
- Fact: Display campaigns on fact view page [\#316](https://github.com/DoSomething/phoenix/issues/316)
- Campaign: View campaigns\_by\_fact  [\#315](https://github.com/DoSomething/phoenix/issues/315)
- dosomething\_image return [\#313](https://github.com/DoSomething/phoenix/issues/313)
- dosomething\_image return [\#312](https://github.com/DoSomething/phoenix/issues/312)
- Remove extraneous README files [\#309](https://github.com/DoSomething/phoenix/issues/309)
- DS Devel: README files [\#308](https://github.com/DoSomething/phoenix/issues/308)
- DS Devel: Drush commands [\#306](https://github.com/DoSomething/phoenix/issues/306)
- Campaigns: Metatags support [\#305](https://github.com/DoSomething/phoenix/issues/305)
- Campaigns: Pathauto support [\#304](https://github.com/DoSomething/phoenix/issues/304)
- Campaign: 404 on campaign/%id where id does not exist [\#302](https://github.com/DoSomething/phoenix/issues/302)
- Image / Media entity [\#300](https://github.com/DoSomething/phoenix/issues/300)
- Double\_field contrib module: Devel Generate issue [\#298](https://github.com/DoSomething/phoenix/issues/298)
- Fact: Dummy Fact generator [\#295](https://github.com/DoSomething/phoenix/issues/295)
- Campaign: update preprocess values. [\#290](https://github.com/DoSomething/phoenix/issues/290)
- Facts: Permissions [\#289](https://github.com/DoSomething/phoenix/issues/289)
- Campaign: Expose dosomething\_campaign entity to views [\#287](https://github.com/DoSomething/phoenix/issues/287)
- Campaign: Filter by Title on admin/campaign [\#285](https://github.com/DoSomething/phoenix/issues/285)
- Campaign: Remove dosomething\_compound from info file [\#283](https://github.com/DoSomething/phoenix/issues/283)
- Switch compound fields to double fields [\#278](https://github.com/DoSomething/phoenix/issues/278)
- DS Profile: Add contrib Entity Reference module [\#272](https://github.com/DoSomething/phoenix/issues/272)
- Vagrant SSL not functioning [\#271](https://github.com/DoSomething/phoenix/issues/271)
- Sponsors Vocab Term Creation [\#267](https://github.com/DoSomething/phoenix/issues/267)
- Campaign: Facts [\#265](https://github.com/DoSomething/phoenix/issues/265)
- Campaign: Preprocess vars to include Compound text values [\#264](https://github.com/DoSomething/phoenix/issues/264)
- Dosomething CompoundText: Change Title \#size [\#263](https://github.com/DoSomething/phoenix/issues/263)
- Test that status field is saved [\#259](https://github.com/DoSomething/phoenix/issues/259)
- Campaign: Compound Text field instances [\#250](https://github.com/DoSomething/phoenix/issues/250)
- Campaign node: Textareas as Markdown [\#247](https://github.com/DoSomething/phoenix/issues/247)
- Add contrib Markdown module to Profile and enable [\#246](https://github.com/DoSomething/phoenix/issues/246)
- Campaign: Test campaign generator [\#244](https://github.com/DoSomething/phoenix/issues/244)
- Profile: Set paraneue NEUE\_PATH upon install  [\#240](https://github.com/DoSomething/phoenix/issues/240)
- DS script: Fix / restore themes/dosomething symlink [\#238](https://github.com/DoSomething/phoenix/issues/238)
- Paraneue Subtheme [\#237](https://github.com/DoSomething/phoenix/issues/237)
- Campaign: Published checkbox [\#228](https://github.com/DoSomething/phoenix/issues/228)
- Campaign: allow editor to see all unpublished campaigns [\#227](https://github.com/DoSomething/phoenix/issues/227)
- Campaign: Test for CampaignEntityController-\>save\(\) [\#220](https://github.com/DoSomething/phoenix/issues/220)
- Campaign: Form validation for Season Date fields MM/DD [\#218](https://github.com/DoSomething/phoenix/issues/218)
- Campaign: Sponsors term field [\#217](https://github.com/DoSomething/phoenix/issues/217)
- Taxonomy: Sponsors vocabulary [\#216](https://github.com/DoSomething/phoenix/issues/216)
- Campaign: Split out Field API fields on Campaign Form [\#214](https://github.com/DoSomething/phoenix/issues/214)
- Campaign: Variable functions [\#213](https://github.com/DoSomething/phoenix/issues/213)
- Campaign: Uninstall hook should delete field data [\#212](https://github.com/DoSomething/phoenix/issues/212)
- Campaign: Tags field [\#211](https://github.com/DoSomething/phoenix/issues/211)
- Taxonomy: Tags vocabulary [\#210](https://github.com/DoSomething/phoenix/issues/210)
- Campaign: Alter "Action Type" field to be multi-value [\#209](https://github.com/DoSomething/phoenix/issues/209)
- Update dosomething.install to include "batch" in list of securepages [\#204](https://github.com/DoSomething/phoenix/issues/204)
- CRUD tests against Campaign entity [\#194](https://github.com/DoSomething/phoenix/issues/194)
- Campaign: Add properties for created, updated, uid, status [\#192](https://github.com/DoSomething/phoenix/issues/192)
- Campaign: compound text field type [\#190](https://github.com/DoSomething/phoenix/issues/190)
- Campaign: Install schema + Edit form [\#189](https://github.com/DoSomething/phoenix/issues/189)
- dosomething.info: Enable admin\_menu\_toolbar module in contrib [\#188](https://github.com/DoSomething/phoenix/issues/188)
- Editor role [\#187](https://github.com/DoSomething/phoenix/issues/187)
- Include more admin paths in securepages list of secure pages [\#182](https://github.com/DoSomething/phoenix/issues/182)
- Campaign: Taxonomy Term fields [\#180](https://github.com/DoSomething/phoenix/issues/180)
- Campaign: Image fields [\#179](https://github.com/DoSomething/phoenix/issues/179)
- Fix Varnish VCL's health check URL [\#176](https://github.com/DoSomething/phoenix/issues/176)
- Campaign: hook\_permissions [\#175](https://github.com/DoSomething/phoenix/issues/175)
- Campaign: Admin UI + Test [\#174](https://github.com/DoSomething/phoenix/issues/174)
- Campaign: Pitch and Action templates [\#173](https://github.com/DoSomething/phoenix/issues/173)
- dosomething\_taxonomy feature [\#172](https://github.com/DoSomething/phoenix/issues/172)
- Upgrade Drupal core [\#167](https://github.com/DoSomething/phoenix/issues/167)
- QA: Add New Relic support [\#164](https://github.com/DoSomething/phoenix/issues/164)
- Remove major version prefixes from the drupal-org.make file [\#162](https://github.com/DoSomething/phoenix/issues/162)
- Content staging: Stable environment for campaign content entry [\#161](https://github.com/DoSomething/phoenix/issues/161)
- Install and enable Entity API [\#159](https://github.com/DoSomething/phoenix/issues/159)
- Vagrant: Fix PECL installs: APC, uploadprogress [\#157](https://github.com/DoSomething/phoenix/issues/157)
- Add geo data to Varnish and response header [\#154](https://github.com/DoSomething/phoenix/issues/154)
- Update wiki with instructions on how to run Coder locally with vagrant [\#142](https://github.com/DoSomething/phoenix/issues/142)
- Share users/sessions tables across new and old DBs [\#140](https://github.com/DoSomething/phoenix/issues/140)
- DrupalWebTestCase setUp fails [\#128](https://github.com/DoSomething/phoenix/issues/128)
- Automatic documentation -\> GitHub pages [\#121](https://github.com/DoSomething/phoenix/issues/121)
- Document deployment strategy [\#120](https://github.com/DoSomething/phoenix/issues/120)
- Enable dosomething\_user in dosomething profile [\#118](https://github.com/DoSomething/phoenix/issues/118)
- Disable Mandrill in dosomething profile [\#117](https://github.com/DoSomething/phoenix/issues/117)
- Create new private github repo for internal dev scripts [\#115](https://github.com/DoSomething/phoenix/issues/115)
- ds script cleanup: Remove "dbup" code [\#114](https://github.com/DoSomething/phoenix/issues/114)
- ds script cleanup: commented drush commands [\#113](https://github.com/DoSomething/phoenix/issues/113)
- ds script cleanup: profile symlinks [\#112](https://github.com/DoSomething/phoenix/issues/112)
- dosomething\_user: Web test for administrator permissions [\#109](https://github.com/DoSomething/phoenix/issues/109)
- dosomething\_user: Roles for Contributor / Editor [\#108](https://github.com/DoSomething/phoenix/issues/108)
- Installation: Set features default export path [\#106](https://github.com/DoSomething/phoenix/issues/106)
- Disable Metatags module in DoSomething profile [\#105](https://github.com/DoSomething/phoenix/issues/105)
- Actual Varnish-Drupal integration [\#104](https://github.com/DoSomething/phoenix/issues/104)
- ds build: Permission denied errors [\#102](https://github.com/DoSomething/phoenix/issues/102)
- Cleanup README.md [\#101](https://github.com/DoSomething/phoenix/issues/101)
- blackangus: vagrant up on server boot [\#100](https://github.com/DoSomething/phoenix/issues/100)
- Switch to https for user login/edit/register [\#99](https://github.com/DoSomething/phoenix/issues/99)
- QA: Self-assigned SSL cert [\#98](https://github.com/DoSomething/phoenix/issues/98)
- Vagrant: Add PECL uploadprogress [\#97](https://github.com/DoSomething/phoenix/issues/97)
- QA: Explicit subdomain-based Varnish routing rules [\#96](https://github.com/DoSomething/phoenix/issues/96)
- QA: Create explicit subdomains for old and new apps [\#95](https://github.com/DoSomething/phoenix/issues/95)
- SMS: Install/enable suite of modules needed for SMS [\#92](https://github.com/DoSomething/phoenix/issues/92)
- Install PEAR on Black Angus [\#89](https://github.com/DoSomething/phoenix/issues/89)
- Add PHP CodeSniffer to Vagrant [\#88](https://github.com/DoSomething/phoenix/issues/88)
- Add Coder module to drupal-org.make [\#87](https://github.com/DoSomething/phoenix/issues/87)
- Test suite dependencies [\#86](https://github.com/DoSomething/phoenix/issues/86)
- Install Jenkins on Black Angus [\#85](https://github.com/DoSomething/phoenix/issues/85)
- QA: Full Vagrant build [\#84](https://github.com/DoSomething/phoenix/issues/84)
- QA: Vagrant implicit pool routing [\#83](https://github.com/DoSomething/phoenix/issues/83)
- dosomething\_page: user permissions [\#82](https://github.com/DoSomething/phoenix/issues/82)
- Automatic deploy to QA upon push to dev [\#81](https://github.com/DoSomething/phoenix/issues/81)
- Documentation for the DoSomething profile [\#76](https://github.com/DoSomething/phoenix/issues/76)
- Dev / QA configuration variables [\#75](https://github.com/DoSomething/phoenix/issues/75)
- Dev: Reject pull request if any DoSomething SimpleTests fail [\#72](https://github.com/DoSomething/phoenix/issues/72)
- QA: Tests should run in a separate DB [\#70](https://github.com/DoSomething/phoenix/issues/70)
- Vagrant: Configure php.ini to show all notices, errors [\#69](https://github.com/DoSomething/phoenix/issues/69)
- Behat [\#66](https://github.com/DoSomething/phoenix/issues/66)
- Automated coder review upon pull request [\#63](https://github.com/DoSomething/phoenix/issues/63)
- dosomething\_user feature: administrator role [\#48](https://github.com/DoSomething/phoenix/issues/48)
- Build Script [\#46](https://github.com/DoSomething/phoenix/issues/46)
- Set paraneue base theme as default [\#43](https://github.com/DoSomething/phoenix/issues/43)
- Create "dosomething" subdir in the themes directory [\#41](https://github.com/DoSomething/phoenix/issues/41)
- Setup SSH Agent forwarding in Vagrant [\#36](https://github.com/DoSomething/phoenix/issues/36)
- Create build job on cerebro jenkins [\#35](https://github.com/DoSomething/phoenix/issues/35)
- Start documentation for working within the Vagrant enviornment [\#30](https://github.com/DoSomething/phoenix/issues/30)
- Filtered HTML input filter [\#24](https://github.com/DoSomething/phoenix/issues/24)
- DS profile should set Admin theme to Seven [\#23](https://github.com/DoSomething/phoenix/issues/23)
- Provide stub scaffold for project specific themes and modules [\#15](https://github.com/DoSomething/phoenix/issues/15)
- Prepare wercker file for unit testing [\#12](https://github.com/DoSomething/phoenix/issues/12)
- Create a basic drupal-core-org.make file [\#8](https://github.com/DoSomething/phoenix/issues/8)
- Add contribution instructions to the readme [\#3](https://github.com/DoSomething/phoenix/issues/3)
- Add a better description in readme [\#1](https://github.com/DoSomething/phoenix/issues/1)

**Merged pull requests:**

- Fixes \#783; typo in dosomething.info [\#786](https://github.com/DoSomething/phoenix/pull/786) ([mshmsh5000](https://github.com/mshmsh5000))
- Action guide preprocess / template file [\#782](https://github.com/DoSomething/phoenix/pull/782) ([aaronschachter](https://github.com/aaronschachter))
- Exported taxonomy perms. [\#779](https://github.com/DoSomething/phoenix/pull/779) ([angaither](https://github.com/angaither))
- Sponsor image field. [\#777](https://github.com/DoSomething/phoenix/pull/777) ([angaither](https://github.com/angaither))
- Default youtube value. [\#776](https://github.com/DoSomething/phoenix/pull/776) ([angaither](https://github.com/angaither))
- Allow editors publish/unpublish [\#773](https://github.com/DoSomething/phoenix/pull/773) ([aaronschachter](https://github.com/aaronschachter))
- Help text changes [\#771](https://github.com/DoSomething/phoenix/pull/771) ([aaronschachter](https://github.com/aaronschachter))
- Fixes \#763 -- Installs XML Sitemap and related projects [\#769](https://github.com/DoSomething/phoenix/pull/769) ([mshmsh5000](https://github.com/mshmsh5000))
- Campagin end date not set. [\#767](https://github.com/DoSomething/phoenix/pull/767) ([angaither](https://github.com/angaither))
- Mobilecommons bday [\#766](https://github.com/DoSomething/phoenix/pull/766) ([aaronschachter](https://github.com/aaronschachter))
- Web Tests for login via email/cell [\#765](https://github.com/DoSomething/phoenix/pull/765) ([angaither](https://github.com/angaither))
- Campaign automatic revisions [\#758](https://github.com/DoSomething/phoenix/pull/758) ([aaronschachter](https://github.com/aaronschachter))
- Readding disapparing intro field [\#751](https://github.com/DoSomething/phoenix/pull/751) ([blisteringherb](https://github.com/blisteringherb))
- Mobilecommons signup [\#750](https://github.com/DoSomething/phoenix/pull/750) ([aaronschachter](https://github.com/aaronschachter))
- Added production Grunt build task. [\#749](https://github.com/DoSomething/phoenix/pull/749) ([DFurnes](https://github.com/DFurnes))
- Remove hero image from action guide [\#747](https://github.com/DoSomething/phoenix/pull/747) ([aaronschachter](https://github.com/aaronschachter))
- Image field mins [\#746](https://github.com/DoSomething/phoenix/pull/746) ([angaither](https://github.com/angaither))
- Switching to using apachesolr module instead of Search API [\#742](https://github.com/DoSomething/phoenix/pull/742) ([blisteringherb](https://github.com/blisteringherb))
- Confirmation Page content [\#741](https://github.com/DoSomething/phoenix/pull/741) ([aaronschachter](https://github.com/aaronschachter))
- Image style name updates [\#740](https://github.com/DoSomething/phoenix/pull/740) ([angaither](https://github.com/angaither))
- Image Terms [\#739](https://github.com/DoSomething/phoenix/pull/739) ([angaither](https://github.com/angaither))
- Image Search By [\#738](https://github.com/DoSomething/phoenix/pull/738) ([angaither](https://github.com/angaither))
- Campaign date preprocess. [\#737](https://github.com/DoSomething/phoenix/pull/737) ([angaither](https://github.com/angaither))
- Update Profile/Add Users [\#733](https://github.com/DoSomething/phoenix/pull/733) ([angaither](https://github.com/angaither))
- Report back modal classes [\#732](https://github.com/DoSomething/phoenix/pull/732) ([mmwtsn](https://github.com/mmwtsn))
- Action Page Updates [\#727](https://github.com/DoSomething/phoenix/pull/727) ([mmwtsn](https://github.com/mmwtsn))
- Blank Mobile Number Fix [\#725](https://github.com/DoSomething/phoenix/pull/725) ([angaither](https://github.com/angaither))
- Pitch Page Modals [\#724](https://github.com/DoSomething/phoenix/pull/724) ([mmwtsn](https://github.com/mmwtsn))
- Reportback fix [\#723](https://github.com/DoSomething/phoenix/pull/723) ([aaronschachter](https://github.com/aaronschachter))
- User bugs galore [\#722](https://github.com/DoSomething/phoenix/pull/722) ([angaither](https://github.com/angaither))
- Campaign confirmation template [\#718](https://github.com/DoSomething/phoenix/pull/718) ([aaronschachter](https://github.com/aaronschachter))
- Fix pitch page button [\#688](https://github.com/DoSomething/phoenix/pull/688) ([aaronschachter](https://github.com/aaronschachter))
- Changes drush install method. Fixes \#682 [\#684](https://github.com/DoSomething/phoenix/pull/684) ([desmondmorris](https://github.com/desmondmorris))
- Adding Markdown support to static content [\#681](https://github.com/DoSomething/phoenix/pull/681) ([blisteringherb](https://github.com/blisteringherb))
- Static content [\#673](https://github.com/DoSomething/phoenix/pull/673) ([barryclark](https://github.com/barryclark))
- Registration login fancy [\#672](https://github.com/DoSomething/phoenix/pull/672) ([angaither](https://github.com/angaither))
- Edit ui image node fancify. [\#668](https://github.com/DoSomething/phoenix/pull/668) ([angaither](https://github.com/angaither))
- Force secure login/registration on modal. [\#666](https://github.com/DoSomething/phoenix/pull/666) ([angaither](https://github.com/angaither))
- Update all image fields to use a view to return entity results. [\#664](https://github.com/DoSomething/phoenix/pull/664) ([angaither](https://github.com/angaither))
- Capistranos return [\#663](https://github.com/DoSomething/phoenix/pull/663) ([desmondmorris](https://github.com/desmondmorris))
- Include custom modules & themes via make [\#662](https://github.com/DoSomething/phoenix/pull/662) ([desmondmorris](https://github.com/desmondmorris))
- Action Page [\#661](https://github.com/DoSomething/phoenix/pull/661) ([mmwtsn](https://github.com/mmwtsn))
- Image node fields views and everything [\#660](https://github.com/DoSomething/phoenix/pull/660) ([angaither](https://github.com/angaither))
- Mobilecommons Opt-In [\#659](https://github.com/DoSomething/phoenix/pull/659) ([aaronschachter](https://github.com/aaronschachter))
- Adding entity connect perms for editors [\#655](https://github.com/DoSomething/phoenix/pull/655) ([blisteringherb](https://github.com/blisteringherb))
- User has unique mobile number. [\#653](https://github.com/DoSomething/phoenix/pull/653) ([angaither](https://github.com/angaither))
- Pathauto vars [\#651](https://github.com/DoSomething/phoenix/pull/651) ([aaronschachter](https://github.com/aaronschachter))
- Theming for 11 facts page [\#643](https://github.com/DoSomething/phoenix/pull/643) ([blisteringherb](https://github.com/blisteringherb))
- Campaign action guide [\#642](https://github.com/DoSomething/phoenix/pull/642) ([aaronschachter](https://github.com/aaronschachter))
- No default birthdate [\#639](https://github.com/DoSomething/phoenix/pull/639) ([angaither](https://github.com/angaither))
- Replace panteon drupal core with d.o core [\#637](https://github.com/DoSomething/phoenix/pull/637) ([angaither](https://github.com/angaither))
- Form tweaks [\#634](https://github.com/DoSomething/phoenix/pull/634) ([aaronschachter](https://github.com/aaronschachter))
- User login updates [\#632](https://github.com/DoSomething/phoenix/pull/632) ([angaither](https://github.com/angaither))
- Campaign Action Page [\#631](https://github.com/DoSomething/phoenix/pull/631) ([mmwtsn](https://github.com/mmwtsn))
- Adds helper functions to display entityref parents [\#630](https://github.com/DoSomething/phoenix/pull/630) ([aaronschachter](https://github.com/aaronschachter))
- Action Guide content type [\#629](https://github.com/DoSomething/phoenix/pull/629) ([aaronschachter](https://github.com/aaronschachter))
- Facts of life [\#628](https://github.com/DoSomething/phoenix/pull/628) ([aaronschachter](https://github.com/aaronschachter))
- Static Content: Fixing PHP notices [\#627](https://github.com/DoSomething/phoenix/pull/627) ([blisteringherb](https://github.com/blisteringherb))
- Adding editor permissions for static content [\#622](https://github.com/DoSomething/phoenix/pull/622) ([blisteringherb](https://github.com/blisteringherb))
- Fact Cleanup [\#621](https://github.com/DoSomething/phoenix/pull/621) ([aaronschachter](https://github.com/aaronschachter))
- Static content: Adding links for gallery items [\#617](https://github.com/DoSomething/phoenix/pull/617) ([blisteringherb](https://github.com/blisteringherb))
- Fact Content Type [\#612](https://github.com/DoSomething/phoenix/pull/612) ([aaronschachter](https://github.com/aaronschachter))
- 11 Facts Permissions [\#611](https://github.com/DoSomething/phoenix/pull/611) ([blisteringherb](https://github.com/blisteringherb))
- Adding Cause taxonomy to Fact Page [\#610](https://github.com/DoSomething/phoenix/pull/610) ([blisteringherb](https://github.com/blisteringherb))
- Removing ds\_search from make file to prevent build breakage [\#605](https://github.com/DoSomething/phoenix/pull/605) ([blisteringherb](https://github.com/blisteringherb))
- Neue config [\#603](https://github.com/DoSomething/phoenix/pull/603) ([DFurnes](https://github.com/DFurnes))
- Proposed: Codebase re-org [\#599](https://github.com/DoSomething/phoenix/pull/599) ([desmondmorris](https://github.com/desmondmorris))
- Solr - Basic setup for indexing nodes [\#593](https://github.com/DoSomething/phoenix/pull/593) ([blisteringherb](https://github.com/blisteringherb))
- Set up 11 Facts \(Fact Page\) Content Type [\#592](https://github.com/DoSomething/phoenix/pull/592) ([blisteringherb](https://github.com/blisteringherb))
- Reportback Tests [\#591](https://github.com/DoSomething/phoenix/pull/591) ([aaronschachter](https://github.com/aaronschachter))
- Static content issets [\#590](https://github.com/DoSomething/phoenix/pull/590) ([blisteringherb](https://github.com/blisteringherb))
- Disable automatic drupal emails to users [\#589](https://github.com/DoSomething/phoenix/pull/589) ([angaither](https://github.com/angaither))
- Resolves merge conflicts from PR 574 \(local Drupal settings\) [\#587](https://github.com/DoSomething/phoenix/pull/587) ([mshmsh5000](https://github.com/mshmsh5000))
- Campaign tweaks [\#586](https://github.com/DoSomething/phoenix/pull/586) ([aaronschachter](https://github.com/aaronschachter))
- Remove unused text format module/libs [\#585](https://github.com/DoSomething/phoenix/pull/585) ([angaither](https://github.com/angaither))
- Added char count to fact text area. [\#583](https://github.com/DoSomething/phoenix/pull/583) ([angaither](https://github.com/angaither))
- Image Module Updates [\#582](https://github.com/DoSomething/phoenix/pull/582) ([mmwtsn](https://github.com/mmwtsn))
- Local Drupal settings FTW [\#574](https://github.com/DoSomething/phoenix/pull/574) ([mshmsh5000](https://github.com/mshmsh5000))
- Reportback Schema Test [\#572](https://github.com/DoSomething/phoenix/pull/572) ([aaronschachter](https://github.com/aaronschachter))
- Pitch Page [\#568](https://github.com/DoSomething/phoenix/pull/568) ([mmwtsn](https://github.com/mmwtsn))
- Fact Search View tweaks [\#567](https://github.com/DoSomething/phoenix/pull/567) ([aaronschachter](https://github.com/aaronschachter))
- Added permissions to create/edit image nodes for editors. [\#565](https://github.com/DoSomething/phoenix/pull/565) ([angaither](https://github.com/angaither))
- Campaign: Editor permissions [\#562](https://github.com/DoSomething/phoenix/pull/562) ([aaronschachter](https://github.com/aaronschachter))
- Bower stuff [\#560](https://github.com/DoSomething/phoenix/pull/560) ([DFurnes](https://github.com/DFurnes))
- Reportback: No more num\_participants [\#559](https://github.com/DoSomething/phoenix/pull/559) ([aaronschachter](https://github.com/aaronschachter))
- Admin form fender stuff. [\#556](https://github.com/DoSomething/phoenix/pull/556) ([angaither](https://github.com/angaither))
- Campaign field labels [\#554](https://github.com/DoSomething/phoenix/pull/554) ([aaronschachter](https://github.com/aaronschachter))
- Static content cta link [\#551](https://github.com/DoSomething/phoenix/pull/551) ([blisteringherb](https://github.com/blisteringherb))
- Static content video [\#550](https://github.com/DoSomething/phoenix/pull/550) ([blisteringherb](https://github.com/blisteringherb))
- Pitch page for anon user [\#543](https://github.com/DoSomething/phoenix/pull/543) ([aaronschachter](https://github.com/aaronschachter))
- Tax action type updates [\#542](https://github.com/DoSomething/phoenix/pull/542) ([angaither](https://github.com/angaither))
- Added new fields to campaign form. [\#540](https://github.com/DoSomething/phoenix/pull/540) ([angaither](https://github.com/angaither))
- Remove ƒfield from file. [\#538](https://github.com/DoSomething/phoenix/pull/538) ([angaither](https://github.com/angaither))
- Installs make\_local drush plugin to werkcer env [\#536](https://github.com/DoSomething/phoenix/pull/536) ([desmondmorris](https://github.com/desmondmorris))
- Campaign help text copy updates. [\#535](https://github.com/DoSomething/phoenix/pull/535) ([angaither](https://github.com/angaither))
- Signup login [\#534](https://github.com/DoSomething/phoenix/pull/534) ([aaronschachter](https://github.com/aaronschachter))
- Browserify [\#529](https://github.com/DoSomething/phoenix/pull/529) ([DFurnes](https://github.com/DFurnes))
- Dosomething\_image module updates. [\#527](https://github.com/DoSomething/phoenix/pull/527) ([angaither](https://github.com/angaither))
- Rename Image Fields. [\#524](https://github.com/DoSomething/phoenix/pull/524) ([angaither](https://github.com/angaither))
- Temporary fix to include neue for early theming [\#522](https://github.com/DoSomething/phoenix/pull/522) ([mmwtsn](https://github.com/mmwtsn))
- Reportback Activity log [\#521](https://github.com/DoSomething/phoenix/pull/521) ([aaronschachter](https://github.com/aaronschachter))
- Add fields to user object/login [\#519](https://github.com/DoSomething/phoenix/pull/519) ([angaither](https://github.com/angaither))
- Metatag on [\#517](https://github.com/DoSomething/phoenix/pull/517) ([aaronschachter](https://github.com/aaronschachter))
- Paraneue working copy  [\#514](https://github.com/DoSomething/phoenix/pull/514) ([desmondmorris](https://github.com/desmondmorris))
- Adds bower install command to ds cli tool.   [\#503](https://github.com/DoSomething/phoenix/pull/503) ([desmondmorris](https://github.com/desmondmorris))
- Installs node, bower & grunt for dosomething-paraneue build. Fixes \#498 [\#502](https://github.com/DoSomething/phoenix/pull/502) ([desmondmorris](https://github.com/desmondmorris))
- Cache themed image tags. [\#499](https://github.com/DoSomething/phoenix/pull/499) ([angaither](https://github.com/angaither))
- Static content [\#495](https://github.com/DoSomething/phoenix/pull/495) ([blisteringherb](https://github.com/blisteringherb))
- Frontenders [\#491](https://github.com/DoSomething/phoenix/pull/491) ([DFurnes](https://github.com/DFurnes))
- Save Reportback sub-functions + documentation [\#489](https://github.com/DoSomething/phoenix/pull/489) ([aaronschachter](https://github.com/aaronschachter))
- Reportback Form fix [\#488](https://github.com/DoSomething/phoenix/pull/488) ([aaronschachter](https://github.com/aaronschachter))
- Display the pitch page to all users if not signed up for the campaign [\#486](https://github.com/DoSomething/phoenix/pull/486) ([angaither](https://github.com/angaither))
- Campaign sponsor term errors. [\#485](https://github.com/DoSomething/phoenix/pull/485) ([angaither](https://github.com/angaither))
- Reportback new properties [\#483](https://github.com/DoSomething/phoenix/pull/483) ([aaronschachter](https://github.com/aaronschachter))
- Campaign - Update Reportback form [\#476](https://github.com/DoSomething/phoenix/pull/476) ([aaronschachter](https://github.com/aaronschachter))
- Delete Reportback Form [\#474](https://github.com/DoSomething/phoenix/pull/474) ([aaronschachter](https://github.com/aaronschachter))
- Sponsor images [\#473](https://github.com/DoSomething/phoenix/pull/473) ([angaither](https://github.com/angaither))
- Check if images are set. [\#471](https://github.com/DoSomething/phoenix/pull/471) ([angaither](https://github.com/angaither))
- Reportback template file [\#470](https://github.com/DoSomething/phoenix/pull/470) ([aaronschachter](https://github.com/aaronschachter))
- DS Build tweaks [\#464](https://github.com/DoSomething/phoenix/pull/464) ([aaronschachter](https://github.com/aaronschachter))
- Image return [\#463](https://github.com/DoSomething/phoenix/pull/463) ([angaither](https://github.com/angaither))
- Reportback: Insert / update functions  [\#455](https://github.com/DoSomething/phoenix/pull/455) ([aaronschachter](https://github.com/aaronschachter))
- Sponsor logo-image field. [\#454](https://github.com/DoSomething/phoenix/pull/454) ([angaither](https://github.com/angaither))
- Reportback access callback [\#453](https://github.com/DoSomething/phoenix/pull/453) ([aaronschachter](https://github.com/aaronschachter))
- Campaign tpl - check if field collections vars are set [\#449](https://github.com/DoSomething/phoenix/pull/449) ([aaronschachter](https://github.com/aaronschachter))
- dosomething\_fact\_access cleanup [\#447](https://github.com/DoSomething/phoenix/pull/447) ([aaronschachter](https://github.com/aaronschachter))
- Action page preprocess [\#445](https://github.com/DoSomething/phoenix/pull/445) ([angaither](https://github.com/angaither))
- Preprocess multi-value fact fields [\#439](https://github.com/DoSomething/phoenix/pull/439) ([aaronschachter](https://github.com/aaronschachter))
- Automatically generate content on site install. [\#438](https://github.com/DoSomething/phoenix/pull/438) ([angaither](https://github.com/angaither))
- Fixes \#425 [\#437](https://github.com/DoSomething/phoenix/pull/437) ([angaither](https://github.com/angaither))
- Fixes \#433 [\#436](https://github.com/DoSomething/phoenix/pull/436) ([angaither](https://github.com/angaither))
- Preprocess Facts [\#434](https://github.com/DoSomething/phoenix/pull/434) ([aaronschachter](https://github.com/aaronschachter))
- Added GLOBAL lookup for dosomething\_fact\_access\(\) if not set [\#429](https://github.com/DoSomething/phoenix/pull/429) ([DeeZone](https://github.com/DeeZone))
- Preprocess vars for the pitch page. [\#426](https://github.com/DoSomething/phoenix/pull/426) ([angaither](https://github.com/angaither))
- Fixes php non-object notice. [\#423](https://github.com/DoSomething/phoenix/pull/423) ([angaither](https://github.com/angaither))
- Issue: \#316 - Adds views to list related campaigns for fact [\#421](https://github.com/DoSomething/phoenix/pull/421) ([DeeZone](https://github.com/DeeZone))
- Signup views [\#416](https://github.com/DoSomething/phoenix/pull/416) ([aaronschachter](https://github.com/aaronschachter))
- Rebuild of Campaigns by Fact view to avoid merge conflict [\#412](https://github.com/DoSomething/phoenix/pull/412) ([DeeZone](https://github.com/DeeZone))
- Reportback entity [\#410](https://github.com/DoSomething/phoenix/pull/410) ([aaronschachter](https://github.com/aaronschachter))
- Created a test to check if a user is a ds staff member. [\#409](https://github.com/DoSomething/phoenix/pull/409) ([angaither](https://github.com/angaither))
- Updated post-install message to reference Wiki documentation. [\#408](https://github.com/DoSomething/phoenix/pull/408) ([DFurnes](https://github.com/DFurnes))
- Campaign update all the things. [\#401](https://github.com/DoSomething/phoenix/pull/401) ([angaither](https://github.com/angaither))
- Add view/edit links to fact admin search. [\#400](https://github.com/DoSomething/phoenix/pull/400) ([angaither](https://github.com/angaither))
- Fact view date time [\#397](https://github.com/DoSomething/phoenix/pull/397) ([angaither](https://github.com/angaither))
- Only display 'pitch' link on campaign nodes. [\#396](https://github.com/DoSomething/phoenix/pull/396) ([angaither](https://github.com/angaither))
- Signup form [\#395](https://github.com/DoSomething/phoenix/pull/395) ([aaronschachter](https://github.com/aaronschachter))
- Editor test [\#394](https://github.com/DoSomething/phoenix/pull/394) ([aaronschachter](https://github.com/aaronschachter))
- dosomething\_reportback [\#393](https://github.com/DoSomething/phoenix/pull/393) ([aaronschachter](https://github.com/aaronschachter))
- Add 'facts' tab to the admin toolbar [\#391](https://github.com/DoSomething/phoenix/pull/391) ([angaither](https://github.com/angaither))
- Field collection FTW [\#389](https://github.com/DoSomething/phoenix/pull/389) ([aaronschachter](https://github.com/aaronschachter))
- Reverts back to git download type for profile [\#387](https://github.com/DoSomething/phoenix/pull/387) ([desmondmorris](https://github.com/desmondmorris))
- Initial pass at pantheon deploy script [\#386](https://github.com/DoSomething/phoenix/pull/386) ([desmondmorris](https://github.com/desmondmorris))
- chowns local drush directory to vagrant user [\#385](https://github.com/DoSomething/phoenix/pull/385) ([desmondmorris](https://github.com/desmondmorris))
- Updated content search view roles. [\#381](https://github.com/DoSomething/phoenix/pull/381) ([angaither](https://github.com/angaither))
- Created an admin node search tool. [\#379](https://github.com/DoSomething/phoenix/pull/379) ([angaither](https://github.com/angaither))
- Added views support to facts. [\#378](https://github.com/DoSomething/phoenix/pull/378) ([angaither](https://github.com/angaither))
- Double Field module patch [\#377](https://github.com/DoSomething/phoenix/pull/377) ([aaronschachter](https://github.com/aaronschachter))
- Installs composer and terminus cli tool [\#373](https://github.com/DoSomething/phoenix/pull/373) ([desmondmorris](https://github.com/desmondmorris))
- Issue \#351 - Fact devel PHP notice messages [\#371](https://github.com/DoSomething/phoenix/pull/371) ([DeeZone](https://github.com/DeeZone))
- Signup test [\#370](https://github.com/DoSomething/phoenix/pull/370) ([aaronschachter](https://github.com/aaronschachter))
- Enable text filter on all text area campaign fields. [\#368](https://github.com/DoSomething/phoenix/pull/368) ([angaither](https://github.com/angaither))
- Markdown filter perms [\#367](https://github.com/DoSomething/phoenix/pull/367) ([angaither](https://github.com/angaither))
- DS CLI clean up [\#366](https://github.com/DoSomething/phoenix/pull/366) ([desmondmorris](https://github.com/desmondmorris))
- Updated dosomething.info file. [\#364](https://github.com/DoSomething/phoenix/pull/364) ([angaither](https://github.com/angaither))
- Moves ds cli tool to bin directory [\#363](https://github.com/DoSomething/phoenix/pull/363) ([desmondmorris](https://github.com/desmondmorris))
- Markdown [\#357](https://github.com/DoSomething/phoenix/pull/357) ([angaither](https://github.com/angaither))



\* *This Change Log was automatically generated by [github_changelog_generator](https://github.com/skywinder/Github-Changelog-Generator)*

\* *This Change Log was automatically generated by [github_changelog_generator](https://github.com/skywinder/Github-Changelog-Generator)*