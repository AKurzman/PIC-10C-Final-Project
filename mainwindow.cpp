#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <time.h>
#include <vector>
#include <string>

int counter=0;
int attempt=0;
double a=0;
double b=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->study,SIGNAL(toggled(bool)),this,SLOT(setup()));
    connect(ui->takeQuiz,SIGNAL(toggled(bool)),this,SLOT(setup()));
    connect(ui->Flashcard,SIGNAL(clicked(bool)),this,SLOT(flip()));
    connect(ui->nextCard,SIGNAL(clicked(bool)),this,SLOT(next()));
    connect(ui->prevCard,SIGNAL(clicked(bool)),this,SLOT(prev()));
    connect(ui->nextCard,SIGNAL(clicked(bool)),this,SLOT(setup()));
    connect(ui->prevCard,SIGNAL(clicked(bool)),this,SLOT(setup()));
    connect(ui->study,SIGNAL(toggled(bool)),this,SLOT(reset()));
    connect(ui->takeQuiz,SIGNAL(toggled(bool)),this,SLOT(reset()));
    connect(ui->A,SIGNAL(toggled(bool)),this,SLOT(checkAnswer()));
    connect(ui->B,SIGNAL(toggled(bool)),this,SLOT(checkAnswer()));
    connect(ui->C,SIGNAL(toggled(bool)),this,SLOT(checkAnswer()));
    connect(ui->D,SIGNAL(toggled(bool)),this,SLOT(checkAnswer()));
    ui->Flashcard->setEnabled(false);
    ui->nextCard->setEnabled(false);
    ui->prevCard->setEnabled(false);
    ui->yourAnswer->setEnabled(false);

    study.append("The use of irrigation systems in the Hohokam \nregion and Mesopotamia encouraged ______________ in each area");
    studya.push_back("Long Term Sedentism");
    study.append("In many places around the globe round houses were \nreplaced by houses composed of rectangular rooms after the adoption of agriculture. \nThis shift has been argued to be linked to:");
    studya.append("The origins of social inequality in farming societies");
    study.append("Çatalhöyük is usually not considered a city by\narchaeologists because:");
    studya.append("Lacks internal spatial differentiation");
    study.append("The Hydraulic Hypothesis model of Karl Wittfogel \nproposes that the adoption of irrigation triggered early state development \nbecause irrigation systems require ___________");
    studya.append("Management");
    study.append("Most hunting and gathering societies organize their \nsocial, political, and economic lives at what level?");
    studya.append("The family");
    study.append("Complex societies developed in response to practical \nchallenges like");
    studya.append("The need to increase agricultural output, an external\n threat like a powerful and aggressive neighboring group,\n water control");
    study.append("In rank societies Big Men attain their rank through");
    studya.append("Their competence at performing necessary tasks");
    study.append("The culture that produced Stonehenge was most likely at \nwhat level of sociopolitical complexity?");
    studya.append("Chiefdom");
    study.append("At the heart of the development of complex societies is \na group’s ability to");
    studya.append("Produce food surplus");
    study.append("In the view of anthropologist Elman Service, it is the \n“institutionalization of power” that produces");
    studya.append("Chiefdoms and rank societies");
    study.append("In all likelihood, complex societies developed at \nfirst in order for people to");
    studya.append("Organize the labor of large groups of people in \nresponse to practical challenges");
    study.append("In ancient societies, the ruling class ruled by");
    studya.append("Coercion and force");
    study.append("In ancient societies, the ruling class had the power to");
    studya.append("Tax, conscript an army, command the labor of people");
    study.append("In ancient Mesopotamia, power was first invested \nin which organization");
    studya.append("The Temple");
    study.append("The oldest city in the world is found in");
    studya.append("Mesopotamia");
    study.append("The earliest Mesopotamian City – and likely \nthe first in the world – was");
    studya.append("Uruk");
    study.append("Clay tokens found in Mesopotamia, some dating \nback as much as 10,000 years had what purpose?");
    studya.append("They were used in communication and date storage");
    study.append("After 6,000 years ago, the standardized \nimpressions placed on clay tokens in ancient Mesopotamia");
    studya.append("Became the world’s first writing system");
    study.append("Mound/pyramid building is interpreted by \narchaeologists as an indicator of _______ in ancient societies");
    studya.append("Control/coordination of labor");
    study.append("Which of the following was an independent \ncenter of plant domestication");
    studya.append("North America");
    study.append("Caral in the Andean region and Eridu in \nMesopotamia are both probable examples of");
    studya.append("The early importance of cult/pilgrimage centers\n during archaic state development");
    study.append("Which of the following is a trait found \nin nearly ALL archaic states discussed in this course?");
    studya.append("Cities");
    study.append("Which of the following statements is false?");
    studya.append("State formation in every part of the globe can \nbe explained by a single, primary factor.");
    study.append("The most common organizational form of archaic states\n during initial state formation around the globe is a(n) ___________");
    studya.append("Territorial State");
    study.append("The earliest cities in Mesopotamia date to the \n___________ period");
    studya.append("Uruk");
    study.append("Most early writing in _________ is on stone monuments \ndevoted to the glorification of leaders and \nrecording their histories");
    studya.append("Mesoamerica");
    study.append("The control of cult centers by the Inkan empire\n is an example of the importance of __________ power");
    studya.append("Ideological");
    study.append("Which of the following statements about archaic\n states is true?");
    studya.append("All archaic states formed in areas where riverine\n irrigation was necessary for agriculture");
    study.append("Animal bones covered in writing found at \nAnyang were used for");
    studya.append("Prophecy and communicating with the dead");
    study.append("Banderkeramik long houses in Europe are markers of");
    studya.append(" socioeconomic units composed of multiple\n smaller households");
    study.append("Uruk period states in Mesopotamia and Tiwanaku\n and Wari states in the Andes both utilized\n __________ to exert control over trade");
    studya.append("Colonies");
    study.append("There is no evidence that ancient Egyptian and \nMesopotamian states interacted with one another. \nThis statement is");
    studya.append("False");
    study.append("The control of _________ was important in the \ndevelopment of an archaic state centered \nat Great Zimbabwe");
    studya.append("Trade of ivory and metals");
    study.append("The geographic location of the earliest cities\n of the Xia, Shang, and Zhou dynasties");
    studya.append("Enabled control over trade between highland/lowland areas");
    study.append("Bronze objects produced by specialists associated\n with leaders in ancient Chinese states were primarily used");
    studya.append("As feasting vessels and weapons");
    study.append("__________ at the late Neolithic Chinese site of \nTaosi is/are evidence for pre-state social complexity");
    studya.append("Elaborate burials");
    study.append("Robert Carneiro’s warfare model of state formation \nproposes that archaic states arose through violent competition over");
    studya.append("Limited agricultural land");
    study.append("_______ and ______ are some of the most widespread \nelements of ancient Mesoamerican culture");
    studya.append("Temple/pyramid complexes, sacrificial rituals");
    study.append("Some archaeologists argue the Olmec were the “Mother\n Culture” of Mesoamerican societies because");
    studya.append("some of the widespread iconography and religious \npractices in Mesoamerica originate in the Olmec area");
    study.append("Control of __________ was a major source of \npower for the Teotihuacán state");
    studya.append("The Pachuca obsidian source");
    study.append("Some of the strongest evidence for the importance\n of Teotihuacán in ancient Mesoamerica comes from");
    studya.append("Elaborate writing on the walls of Teotihuacán tombs");
    study.append("The lack of depiction of individual leaders \nat Teotihuacán has been argued to be evidence that\n state power was");
    studya.append("Corporate based");
    study.append("The lack of _______ has been cited as one of \nthe most important differences between Mesopotamian \nand Mesoamerican archaic states");
    studya.append("Writing in Mesoamerica");
    study.append("The Andean site of Caral is considered \nexceptional because of");
    studya.append("Preceramic monument construction and \na reliance on maritime food resources");
    study.append("The emergence of the Moche state is marked\n by the expansion of political control _______");
    studya.append("Across multiple coastal valleys");
    study.append("Which of the following was NOT an important \npart of Andean statecraft?");
    studya.append("Trade with Mesoamerica");
    study.append("If you placed these three regions in order from\n earliest to latest based on when states first appeared\n in each area, a correct sequence would include");
    studya.append("Mesopotamia, China, Mesoamerica");
    study.append("Paintings on Moche vessels best fit the expectations\n of _______ model of state formation");
    studya.append("The trade");
    study.append("Which of the following statements is true?");
    studya.append("Most of the independent centers of state formation were also in or\n near independent centers of domestication of plants and animals");
    study.append("Which of the following is NOT a necessary \ntrait used to identify ancient cities?");
    studya.append("City-hinterland interdependency");
    study.append("Archaeological cases in North America suggest large\n communal projects such as the construction of earthen\n mounds can occur");
    studya.append("Without states and before agriculture develops");
    study.append("Among the Preclassic Hohokam, \nevidence for ________ is common");
    studya.append("Economic specialization");
    study.append("Cahokia has all of the following characteristics \nof state organization except");
    studya.append("Evidence for writing");
    study.append("______ and ______ are indicative of social \ncomplexity at Poverty Point in Louisiana");
    studya.append("Large mounds, extensive trade networks");
    study.append("The Hohokam case raises questions about simple \nmodels of the origins of social inequality because the \nstrongest evidence for leadership in the region dates to");
    studya.append("After the regional economic system decreased in size and complexity");
    study.append("_______ is the international organization that has \nhad the most influence protecting archaeological sites and \nprohibiting artifact trafficking");
    studya.append("UNESCO");
    study.append("Most archaeological work in the United States today \noccurs because of the");
    studya.append("Research interests of archaeologists at universities");
    study.append("Which of the following is the largest employer of \narchaeologists in the United States");
    studya.append("Universities");
    study.append("Preservation-oriented archaeologists attempt to");
    studya.append("Minimize the physical impact of their research on archaeological sites");
    study.append("According to the Society of American Archaeology’s (SAA)\n Principles of Archaeological Ethics, the commercialization\n of archaeological objects (their use as commodities to be exploited\n for personal enjoyment or profit) should be discouraged\n and avoided by archaeologists because");
    studya.append("It contributes to the destruction of archaeological sites,\nit promotes looting in and illicit excavations of ancient sites,\nand it promotes the selling of ancient artifacts in illicit markets");
    study.append("According to the SAA’s ethical principle of \naccountability, archaeologists should");
    studya.append("Make every reasonable effort to consult actively,\n and establish a working relationship with,\n group(s) that have a stake in archaeological research");
    study.append("According to the SAA’s ethical principles, what is NOT\n a way for archaeologists to effectively promote\n public education and outreach");
    studya.append("Encouraging schools to show blockbuster films with fictional\n archaeologists like Lara Croft and Indiana Jones");
    study.append("According to the SAA’s ethical principle on public reporting and publication,\n what is NOT expected of archaeologists");
    studya.append("Local news stations and other local media should be granted access to all\n areas of an archaeological site whenever an excavation is taking place.");
    study.append("According to the Native American Graves Protection and Repatriation Act (NAGPRA)\n of 1990, Federal agencies and museums receiving Federal funds MUST");
    studya.append("Inventory holdings of Native American human remains and funerary objects \nand provide written summaries of other cultural items, consult with Indian Tribes \nand Native Hawaiian organizations to attempt to reach agreements on the repatriation\n or other disposition of Native remains and objects, and allow Native American lineal\n descendants, affiliated Indian Tribes, or affiliated Native Hawaiian organizations to \nmake the final determination about the disposition of cultural items (such as reburial, \nlong-term curation, etc.) nonce lineal descent or cultural affiliation has been \nestablished");
    study.append("Archaeological evidence indicates that hunter-gatherer societies\n categorically lack specialized craft production");
    studya.append("False");
    study.append("Southern Californian Chumash social complexity was\n enabled at least in part by");
    studya.append("Non-agricultural surpluses");
    study.append("Arguments for specialized shell bead production during Southern California’s\n Late Period are based on the spatial distribution of\n ________, found ________");
    studya.append("Stone tool production waste; only in certain parts of the Chumash culture area,\n shell bead production waste; only in certain parts of the Chumash culture area,\nfinished shell beads; all over the Chumash culture area");
    study.append("“Complexity” is a term used by archaeologists to measure the way\n that societies are organized");
    studya.append("False");
    study.append("“Complexity” is a term used by archaeologists to measure how difficult it \nwould have been to develop the technologies that a society used");
    studya.append("False");
    study.append("The early Mogollon lived in");
    studya.append("Pit-houses");
    study.append("Southwestern kivas were (and are) used for");
    studya.append("Religious Ceremonies");
    study.append("Mound 72 in Cahokia was");
    studya.append("The burial of Cahokia’s elite");
    study.append("What characteristics did Cahokia possess that warrant its inclusion in the \nranks of complex chiefdom and early state societies?");
    studya.append("Monumental works, elite burials");
    study.append("The site of Cahokia was");
    studya.append("The geographical focal point of a powerful Native American chiefdom");
    study.append("The Hohokam homeland is best described as a");
    studya.append("Desert");
    study.append("SHORT ANSWER:\nFertile Crescent");
    studya.append("Arc shaped land area from Egypt to Syria that supported a flourishing \nfarming community; critical area in Mesopotamian \nagricultural advancement");
    study.append("SHORT ANSWER:\nIndianization");
    studya.append("Influence of Indian culture, art, Hinduism, and Buddhism on Southeast Asia;\n helped create early states \nEX: ANGKOR WAT TEMPLES");
    study.append("SHORT ANSWER:\nChinampas");
    studya.append("Raised fields constructed along lake shores in Mesoamerica;\n increased agricultural yields; used by Aztecs");
    study.append("SHORT ANSWER:\nInca");
    studya.append("Mesoamerican civilization in the Andes Mountains in present-day Bolivia, \nPeru, Ecuador, and Chile; one of largest empires in the Americas");
    study.append("SHORT ANSWER:\nSedentism");
    studya.append("Permanent, year-round settlement; structured settlement that \ndeveloped with hunting and gathering, and agriculture");
    study.append("SHORT ANSWER:\nSociopolitical");
    studya.append("Anything that structures the relations between groups in society;\n four types: Band, Chiefdom, Tribe, State\nEX: CHIEFDOM TAHITI");
    study.append("SHORT ANSWER:\nÇatal Höyük");
    studya.append("Neolithic town in Turkey with agriculture and domestication, a \nlarge population, and perhaps egalitarian social organization;\n one of oldest cities in world");
    study.append("SHORT ANSWER:\nMegalith");
    studya.append("Large stones used in Europe about 4000 to 1500 BC to create monuments\nEX: STONEHENGE");
    study.append("SHORT ANSWER:\nStonehenge");
    studya.append("Archaeological site in England that was begun during Neolithic Age and\n completed during Bronze Age; most architecturally sophisticated prehistoric\n stone circle in world");
    study.append("SHORT ANSWER:\nCahokia");
    studya.append("Ancient settlement of Native Americans near present-day St. Louis;\n trading center for 40,000 people at its peak in 1200 AD");
    study.append("SHORT ANSWER:\nAngkor Wat");
    studya.append("Hindu temple built in Angkor, Cambodia for King Suryavarman II to be \npart of his capital city; still a religious center today but Buddhist now instead of Hindu");
    study.append("SHORT ANSWER:\nHeterarchy");
    studya.append("System of organization where elements are unranked or ranked in \ndifferent ways, such as skills you can specialize in");
    study.append("SHORT ANSWER:\nMonumental architecture");
    studya.append("Large structures, like pyramids temples, and statues, that are \nusually where powerful leaders emerge\nEX: EGYPTIAN PYRAMIDS");
    study.append("SHORT ANSWER:\nCuneiform");
    studya.append("Writing system where wedge-shaped symbols represented words or syllables;\n developed by Sumerians in Mesopotamia");
    study.append("SHORT ANSWER:\nZimbabwe");
    studya.append("City, now in ruins, in present-day Zimbabwe, Africa with many stone\n structures built between about 1250 and 1450;\n trading center and capital of large state");
    study.append("SHORT ANSWER:\nBaray");
    studya.append("One of largest reservoirs in Cambodian Angkor Wats for transportation and irrigation;\n network of canals connected the reservoirs");

    for (int i=0;i<study.length();++i){
        visited.append(0);
    }

    quizc.append("A. Extreme levels of political inequality\nB. Frequent residential mobility\nC. Long-term sedentism\nD. The domestication of animals");
    quiza.append('C');
    quizc.append("A. Greater sedentism in farming societies\nB. Adoption of new religions\nC. Decline in the availability of wood\nD. The origins of social inequality in farming societies\n");
    quiza.append('D');
    quizc.append("A. Had a very small population\nB. Was occupied prior to the adoption of agriculture\nC. Lacks internal spatial differentiation\nD. Was occupied for only a few years\n");
    quiza.append('C');
    quizc.append("A. Cities\nB. Supporting armies to defend irrigation networks \nC. Domestication of draft animals for traction power\nD. Management");
    quiza.append('D');
    quizc.append("A. The state\nB. The region\nC. The fraternal organization\nD. The family");
    quiza.append('D');
    quizc.append("A. The need to increase agricultural output\nB. An external threat like a powerful and aggressive neighboring group\nC. Water control\nD. All of the above");
    quiza.append('D');
    quizc.append("A. Heredity\nB. A primitive electoral process\nC. Force\nD. Their competence at performing necessary tasks");
    quiza.append('D');
    quizc.append("A. Chiefdom\nB. Primitive\nC. State\nD. Nation");
    quiza.append('A');
    quizc.append("A. Trade over great distances\nB. Organize labor to build great monuments\nC. Keep accurate records as a result of the invention of writing\nD. Produce food surplus");
    quiza.append('D');
    quizc.append("A. Chiefdoms and rank societies\nB. Civilizations from chiefdoms\nC. Nation states from city-states\nD. All of the above");
    quiza.append('A');
    quizc.append("A. Build great monuments like Stonehenge\nB. Organize the labor of large groups of people in response to practical challenges\nC. Respond to the threat posed by militarily powerful complex societies in their region\nD. All of the above");
    quiza.append('B');
    quizc.append("A. Coercion and force\nB. Consensus\nC. Democratic election\nD. Peer pressure");
    quiza.append('A');
    quizc.append("A. tax\nB. Conscript an army\nC. Command the labor of people\nD. All of the above");
    quiza.append('D');
    quizc.append("A. The army\nB. The university\nC. The temple\nD. The police");
    quiza.append('C');
    quizc.append("A. Mesopotamia\nB. Egypt\nC. The Indus River Valley\nD. China");
    quiza.append('A');
    quizc.append("A. Uruk\nB. Ubaid\nC. Hierakonpolis\nD. Nagada");
    quiza.append('A');
    quizc.append("A. They served as ancient money used in economic exchanges\nB. They were used in communication and date storage\nC. They were used as symbols of social ranking\nD. They served to demarcate private propert");
    quiza.append('B');
    quizc.append("A. Became the world’s first writing system\nB. Became the world’s first alphabet\nC. Became hieroglyphs\nD. Became the misnamed “Roman” numerals");
    quiza.append('A');
    quizc.append("A. Control/coordination of labor\nB. Sedentism\nC. The central role of elite burial\nD. Incremental construction efforts");
    quiza.append('A');
    quizc.append("A. North America\nB. Australia\nC. Europe\nD. Hawaii");
    quiza.append('A');
    quizc.append("A. Densely populated cities without agriculture\nB. The early importance of cult/pilgrimage centers during archaic state development\nC. Colonies founded by traders\nD. Cities sacked during warfare");
    quiza.append('B');
    quizc.append("A. Early writing first occurs on public monuments glorifying leaders\nB. Maritime trade\nC. Cities\nD. Longhouses");
    quiza.append('C');
    quizc.append("a. Archaic states originated independently in multiple regions of the world\nB. State formation in every part of the globe can be explained by a single, primary factor\nC. Warfare was common among ancient city-states around the globe\nD. Archaic states were fragile and frequently collapsed");
    quiza.append('B');
    quizc.append("A. Territorial state\nB. City-state\nC. Empire\nD. Nation state");
    quiza.append('A');
    quizc.append("a. Halaf\nB. Natufian\nC. Akkadian\nD. Uruk");
    quiza.append('D');
    quizc.append("A. Mesopotamia\nB. Mesoamerica\nC. Ancient China\nD. The Mississippi Valley");
    quiza.append('B');
    quizc.append("A. Geographic\nB. Ideological\nC. Agriculture\nD. Hydraulic");
    quiza.append('B');
    quizc.append("A. Archaic states were stable political formations that usually lasted for 1000s of years\nB. All archaic states used hieroglyphic writing systems to glorify leaders\nC. Periods of political consolidation were often\n followed by the collapse of archaic state polities\nD. All archaic states formed in areas where riverine irrigation was necessary for agriculture");
    quiza.append('D');
    quizc.append("A. Prophecy and communicating with the dead\nB. Recording business transactions\nC. Public displays in temple plazas\nD. Sending messages to Mesopotamia");
    quiza.append('A');
    quizc.append("A. Interaction with Mesopotamian populations\nB. The prosperity of farmers\nC. Iron smeltin\nD. Socioeconomic units composed of multiple smaller households");
    quiza.append('D');
    quizc.append("A. Written accounting on clay tablets\nB. Colonies\nC. Ocean-going ships\nD. B and C");
    quiza.append('B');
    quizc.append("A. True\nB. False");
    quiza.append('B');
    quizc.append("A. Trade of ivory and metals\nB. Irrigation networks\nC. A large army\nD. A pilgrimage center on the Zambezi River");
    quiza.append('A');
    quizc.append("A. Provided an ideal spot for maize agriculture\nB. Enabled control over trade between highland/lowland areas\nC. Was ideal for rice agriculture\nD. Enabled control over oceanic trade");
    quiza.append('B');
    quizc.append("A. For digging irrigation canals and sewing clothing\nB. As feasting vessels and weapons\nC. To communicate with the dead\nD. As money");
    quiza.append('B');
    quizc.append("A. Giant carved stone heads\nB. Shell from the Indian Ocean\nC. Massive bronzesmithing workshops\nD. Elaborate burials");
    quiza.append('D');
    quizc.append("A. Cult centers\nB. Limited agricultural land\nC. Mineral sources\nD. Trade routes");
    quiza.append('B');
    quizc.append("A. Temple/pyramid complexes, sacrificial rituals\nB. Writing on clay tablets, maize agriculture\nC. Ball courts, sheep herding\nD. Ball courts, oracle bones");
    quiza.append('A');
    quizc.append("A. They conquered Mayan kingdoms\nB.	Some of the widespread iconography and religious\n practices in Mesoamerica originate in the Olmec area\nC. They controlled obsidian trade in the region\nD. They arose out of a migration of farmers bringing maize from the Andean region");
    quiza.append('B');
    quizc.append("A. Trade with the Mississippi Valley\nB. The cult center at Tula\nC. The Pachuca obsidian source\nD. Bronze vessel production");
    quiza.append('C');
    quizc.append("A. Monumental stone heads\nB. Accounts of Spanish explorers who visited Teotihuacán at the height of its power\nC. Writing on stelae in the Maya area\nD. Elaborate writing on the walls of Teotihuacán tombs");
    quiza.append('D');
    quizc.append("A. Limited only to the city itself\nB. Corporate-based\nC. Network-based\nD. Short-lived");
    quiza.append('B');
    quizc.append("A. Writing in Mesoamerica\nB. Gold in the Mesopotamia\nC. A diverse set of large domesticated animals in Mesoamerica\nD. Divine kings in Mesopotamia");
    quiza.append('A');
    quizc.append("A. Llama herding and access to the Amazon Basin\nB. Preceramic monument construction\nC. A reliance on maritime food resources\nD. B and C");
    quiza.append('D');
    quizc.append("A. Across multiple coastal valleys\nB. From the highlands to the coast\nC. From the highlands to the rainforest\nD. Prior to the beginnings of agriculture");
    quiza.append('A');
    quizc.append("A. Trade between different ecological zones\nB. Warfare\nC. Trade with Mesoamerica\nD. Control of pilgrimage centers");
    quiza.append('C');
    quizc.append("A. Mesopotamia, Mesoamerica, China\nB. China, Mesopotamia, Mesoamerica\nC. Mesopotamia, China, Mesoamerica\nD. Mesopotamia, Andes, China");
    quiza.append('C');
    quizc.append("A. Childe’s Urban Revolution\nB. Carneiro’s warfare\nC. Wittfogel’s irrigation\nD. The trade");
    quiza.append('D');
    quizc.append("A. Most of the independent centers of state formation were also in or near\n independent centers of domestication of plants and animals\nB. State-level political organization was only invented once in world history\n in ancient China and then spread to the rest of the globe\nC. State formation did not occur in the Americas prior\n to colonization by Europeans in the A.D. 1500s\nD. No states were present anywhere in the world prior to 1000 B.C.");
    quiza.append('A');
    quizc.append("A. Large population\nB. Internal spatial differentiation\nC. City-hinterland interdependency\nD. Irrigation");
    quiza.append('C');
    quizc.append("A. Without states\nB. Before agriculture develops\nC. Only after sedentary villages are established\nD. A and B");
    quiza.append('D');
    quizc.append("A. Long distance trade with the Northwest Coast of North America\nB. Economic specialization\nC. Divine kingship\nD. Ritual use of wheat-based beverages");
    quiza.append('B');
    quizc.append("A. A large population\nB. A multi-tier settlement hierarchy\nC. Evidence for writing\nD. Evidence for control of large labor pools");
    quiza.append('C');
    quizc.append("A. Ballcourts, extensive trade networks\nB. Elaborate burials, oceangoing canoes\nC. Large mounds, extensive trade networks\nD. Writing, tell construction");
    quiza.append('C');
    quizc.append("A. When the irrigation networks reached their maximum extent\nB. When economic specialization was most widespread\nC. After the regional economic system decreased in size and complexity\nD. The period before agriculture was adopted");
    quiza.append('C');
    quizc.append("A. The World Bank\nB. UNESCO\nC. Interpol\nD. The International Monetary Fund");
    quiza.append('B');
    quizc.append("A. Research interests of archaeologists at universities\nB. Need to comply with the National Historic Preservation Act\nC. Need for museum exhibits\nD. Desire to locate lost treasure");
    quiza.append('A');
    quizc.append("A. The state of California\nB. Universities\nC. Museums\nD. Private consulting companies");
    quiza.append('B');
    quizc.append("A. Never excavate sites\nB. Minimize the physical impact of their research on archaeological sites\nC. Only excavate sites that will be developed for tourism\nD. Hide their findings from the public");
    quiza.append('B');
    quizc.append("A. It contributes to the destruction of archaeological sites\nB. It promotes looting in and illicit excavations of ancient sites\nC. It promotes the selling of ancient artifacts in illicit markets\nD. All of the above");
    quiza.append('D');
    quizc.append("A. Obtain all of the necessary permits and legal clearances to conduct archaeological excavations\nB. Ensure that their excavations and other field work activities are financially sustainable\nC. Make every reasonable effort to consult actively, and establish a working relationship\n with, group(s) that have a stake in archaeological research\nD. Avoid as much interaction as possible with the local community where excavations are occurring");
    quiza.append('C');
    quizc.append("A. Explaining and promoting the use of archaeological methods\n and techniques in understanding human behavior and culture\nB. Encouraging schools to show blockbuster films with fictional archaeologists\n like Lara Croft and Indiana Jones\nC. Enlisting public support for the stewardship of the archaeological record\nD. Communicating archaeological interpretations of the past");
    quiza.append('B');
    quizc.append("A. Within a reasonable time, the knowledge that archaeologists gain from investigation of the\n archaeological record must be presented in accessible form (through publication or other\n means) to as wide a range of interested publics as possible.\nB. The documents and materials on which publication and other forms of public reporting\n are based should be deposited in a suitable place for permanent safekeeping.\nC. An interest in preserving and protecting in situ archaeological sites must be taken in to\n account when publishing and distributing information about their nature and location.\nD. Local news stations and other local media should be granted access to all\n areas of an archaeological site whenever an excavation is taking place.\n");
    quiza.append('D');
    quizc.append("A. Inventory holdings of Native American human remains and funerary objects\n and provide written summaries of other cultural items\nB. Consult with Indian Tribes and Native Hawaiian organizations to attempt to reach \nagreements on the repatriation or other disposition of Native remains and objects\nC. Allow Native American lineal descendants, affiliated Indian Tribes, or affiliated\n Native Hawaiian organizations to make the final determination about the disposition of cultural items\n (such as reburial, long-term curation, etc.) once lineal descent or cultural affiliation\n has been established\nD. All of the above");
    quiza.append('D');
    quizc.append("A. True\nB. False");
    quiza.append('B');
    quizc.append("A. The high prevalence of indigenous warfare\nB. The development of agriculture\nC. Non-agricultural surpluses\nD. All of the above");
    quiza.append('C');
    quizc.append("A. Stone tool production waste; only in certain parts of the Chumash culture area\nB. Shell bead production waste; only in certain parts of the Chumash culture area\nC. Finished shell beads; all over the Chumash culture area\nD. All of the Above");
    quiza.append('D');
    quizc.append("A. True\nB. False");
    quiza.append('B');
    quizc.append("A. True\nB. False");
    quiza.append('B');
    quizc.append("A. Cliff dwelling\nB. Pit-houses\nC. Multiple sets of separate courtyard groups\nD. All of the above");
    quiza.append('B');
    quizc.append("A. Food storage facilities\nB.	Dwellings\nC.	Care for the elderly\nD.	Religious ceremonies");
    quiza.append('D');
    quizc.append("A. A platform mound on top of which a great temple once stood\nB. An effigy mound in the shape of a snake\nC. The burial of Cahokia’s elite\nD. The oldest Adena burial mound");
    quiza.append('C');
    quizc.append("A. Monumental works, elite burials\nB. Writing, mathematics\nC. Military rulers, urbanization\nD. All of the above");
    quiza.append('A');
    quizc.append("A. An ancient, prehistoric, Native American City\nB. An outpost of ancient Maya traders just east of the modern city of St. Louis\nC. A Native American ceremonial center with a very small population\nD. The geographical focal point of a powerful Native American chiefdom");
    quiza.append('D');
    quizc.append("A. Tropical rainforest\nB. Desert\nC. Mountainous region\nD. Tundra");
    quiza.append('B');
    quizc.append("A. Arc shaped land area from Egypt to Syria that supported a flourishing \nfarming community; critical area in Mesopotamian \nagricultural advancement\nB. Influence of Indian culture, art, Hinduism, and Buddhism on Southeast Asia;\n helped create early states\nC. Raised fields constructed along lake shores in Mesoamerica;\n increased agricultural yields; used by Aztecs\nD. Mesoamerican civilization in the Andes Mountains in present-day Bolivia, \nPeru, Ecuador, and Chile; one of largest empires in the Americas");
    quiza.append('A');
    quizc.append("A. Influence of Indian culture, art, Hinduism, and Buddhism on Southeast Asia;\n helped create early states\nB. Raised fields constructed along lake shores in Mesoamerica;\n increased agricultural yields; used by Aztecs\nC. Mesoamerican civilization in the Andes Mountains in present-day Bolivia, \nPeru, Ecuador, and Chile; one of largest empires in the Americas\nD. Permanent, year-round settlement; structured settlement that \ndeveloped with hunting and gathering, and agriculture");
    quiza.append('A');
    quizc.append("A. Raised fields constructed along lake shores in Mesoamerica;\n increased agricultural yields; used by Aztecs\nB. Mesoamerican civilization in the Andes Mountains in present-day Bolivia, \nPeru, Ecuador, and Chile; one of largest empires in the Americas\nC. Permanent, year-round settlement; structured settlement that \ndeveloped with hunting and gathering, and agriculture\nD. Anything that structures the relations between groups in society;\n four types: Band, Chiefdom, Tribe, State");
    quiza.append('A');
    quizc.append("A. Mesoamerican civilization in the Andes Mountains in present-day Bolivia, \nPeru, Ecuador, and Chile; one of largest empires in the Americas\nB. Permanent, year-round settlement; structured settlement that \ndeveloped with hunting and gathering, and agriculture\nC. Anything that structures the relations between groups in society;\n four types: Band, Chiefdom, Tribe, State\nD. Neolithic town in Turkey with agriculture and domestication, a \nlarge population, and perhaps egalitarian social organization;\n one of oldest cities in world");
    quiza.append('A');
    quizc.append("A. Permanent, year-round settlement; structured settlement that \ndeveloped with hunting and gathering, and agriculture\nB. Anything that structures the relations between groups in society;\n four types: Band, Chiefdom, Tribe, State\nC. Neolithic town in Turkey with agriculture and domestication, a \nlarge population, and perhaps egalitarian social organization;\n one of oldest cities in world\nD. Large stones used in Europe about 4000 to 1500 BC to create monuments");
    quiza.append('A');
    quizc.append("A. Anything that structures the relations between groups in society;\n four types: Band, Chiefdom, Tribe, State\nB. Neolithic town in Turkey with agriculture and domestication, a \nlarge population, and perhaps egalitarian social organization;\n one of oldest cities in world\nC. Large stones used in Europe about 4000 to 1500 BC to create monuments\nD. Archaeological site in England that was begun during Neolithic Age and\n completed during Bronze Age; most architecturally sophisticated prehistoric\n stone circle in world");
    quiza.append('A');
    quizc.append("A. Neolithic town in Turkey with agriculture and domestication, a \nlarge population, and perhaps egalitarian social organization;\n one of oldest cities in world\nB. Large stones used in Europe about 4000 to 1500 BC to create monuments\nC. Archaeological site in England that was begun during Neolithic Age and\n completed during Bronze Age; most architecturally sophisticated prehistoric\n stone circle in world\nD. Ancient settlement of Native Americans near present-day St. Louis;\n trading center for 40,000 people at its peak in 1200 AD");
    quiza.append('A');
    quizc.append("A. Large stones used in Europe about 4000 to 1500 BC to create monuments\nB. Archaeological site in England that was begun during Neolithic Age and\n completed during Bronze Age; most architecturally sophisticated prehistoric\n stone circle in world\nC. Ancient settlement of Native Americans near present-day St. Louis;\n trading center for 40,000 people at its peak in 1200 AD\nD. Hindu temple built in Angkor, Cambodia for King Suryavarman II to be \npart of his capital city; still a religious center today but Buddhist now instead of Hindu");
    quiza.append('A');
    quizc.append("A. Archaeological site in England that was begun during Neolithic Age and\n completed during Bronze Age; most architecturally sophisticated prehistoric\n stone circle in world\nB. Ancient settlement of Native Americans near present-day St. Louis;\n trading center for 40,000 people at its peak in 1200 AD\nC. Hindu temple built in Angkor, Cambodia for King Suryavarman II to be \npart of his capital city; still a religious center today but Buddhist now instead of Hindu\nD. System of organization where elements are unranked or ranked in \ndifferent ways, such as skills you can specialize in");
    quiza.append('A');
    quizc.append("A. Ancient settlement of Native Americans near present-day St. Louis;\n trading center for 40,000 people at its peak in 1200 AD\nB. Hindu temple built in Angkor, Cambodia for King Suryavarman II to be \npart of his capital city; still a religious center today but Buddhist now instead of Hindu\nC. System of organization where elements are unranked or ranked in \ndifferent ways, such as skills you can specialize in\nD. Large structures, like pyramids temples, and statues, that are \nusually where powerful leaders emerge");
    quiza.append('A');
    quizc.append("A. Hindu temple built in Angkor, Cambodia for King Suryavarman II to be \npart of his capital city; still a religious center today but Buddhist now instead of Hindu\nB. System of organization where elements are unranked or ranked in \ndifferent ways, such as skills you can specialize in\nC. Large structures, like pyramids temples, and statues, that are \nusually where powerful leaders emerge\nD. Writing system where wedge-shaped symbols represented words or syllables;\n developed by Sumerians in Mesopotamia");
    quiza.append('A');
    quizc.append("A. System of organization where elements are unranked or ranked in \ndifferent ways, such as skills you can specialize in\nB. Large structures, like pyramids temples, and statues, that are \nusually where powerful leaders emerge\nC. Writing system where wedge-shaped symbols represented words or syllables;\n developed by Sumerians in Mesopotamia\nD. City, now in ruins, in present-day Zimbabwe, Africa with many stone\n structures built between about 1250 and 1450;\n trading center and capital of large state");
    quiza.append('A');
    quizc.append("A. Large structures, like pyramids temples, and statues, that are \nusually where powerful leaders emerge\nB. Writing system where wedge-shaped symbols represented words or syllables;\n developed by Sumerians in Mesopotamia\nC. City, now in ruins, in present-day Zimbabwe, Africa with many stone\n structures built between about 1250 and 1450;\n trading center and capital of large state\nD. One of largest reservoirs in Cambodian Angkor Wats for transportation and irrigation;\n network of canals connected the reservoirs");
    quiza.append('A');
    quizc.append("A. Writing system where wedge-shaped symbols represented words or syllables;\n developed by Sumerians in Mesopotamia\nB. City, now in ruins, in present-day Zimbabwe, Africa with many stone\n structures built between about 1250 and 1450;\n trading center and capital of large state\nC. One of largest reservoirs in Cambodian Angkor Wats for transportation and irrigation;\n network of canals connected the reservoirs\nD. Arc shaped land area from Egypt to Syria that supported a flourishing \nfarming community; critical area in Mesopotamian \nagricultural advancement");
    quiza.append('A');
    quizc.append("A. City, now in ruins, in present-day Zimbabwe, Africa with many stone\n structures built between about 1250 and 1450;\n trading center and capital of large state\nB. One of largest reservoirs in Cambodian Angkor Wats for transportation and irrigation;\n network of canals connected the reservoirs\nC. Arc shaped land area from Egypt to Syria that supported a flourishing \nfarming community; critical area in Mesopotamian \nagricultural advancement\nD. Influence of Indian culture, art, Hinduism, and Buddhism on Southeast Asia;\n helped create early states");
    quiza.append('A');
    quizc.append("A. One of largest reservoirs in Cambodian Angkor Wats for transportation and irrigation;\n network of canals connected the reservoirs\nB. Arc shaped land area from Egypt to Syria that supported a flourishing \nfarming community; critical area in Mesopotamian \nagricultural advancement\nC. Influence of Indian culture, art, Hinduism, and Buddhism on Southeast Asia;\n helped create early states\nD. Raised fields constructed along lake shores in Mesoamerica;\n increased agricultural yields; used by Aztecs");
    quiza.append('A');

    for (int i=0;i<study.length();++i){
        indexes.append(i);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setup(){

    if (ui->Flashcard->text()!=study[counter] && ui->Flashcard->text()!=studya[counter] && ui->Flashcard->text()!=quizc[counter] && counter==0){
        ui->Flashcard->setText("Click To Begin");
    }

    if (ui->study->isChecked()){
        ui->Flashcard->setEnabled(true);
        if (ui->Flashcard->text()=="Click To Begin"){
            ui->nextCard->setEnabled(false);
            ui->prevCard->setEnabled(false);
        }
        else{
            ui->nextCard->setEnabled(true);
            ui->prevCard->setEnabled(true);
        }
        ui->yourAnswer->setEnabled(false);
        ui->percent->setText("");
        ui->scorebox->setText("Card " + QString::number(counter) + " / " + QString::number(study.length()-1));



    }
    else if (ui->takeQuiz->isChecked()){
        ui->yourAnswer->setEnabled(true);
        ui->Flashcard->setEnabled(true);
        if (counter==0 && b!=study.length()){
            ui->prevCard->setEnabled(false);
        }
        else{
            ui->prevCard->setEnabled(true);
        }
        if (visited[counter]==0){
            ui->nextCard->setEnabled(false);
        }
        else{
            ui->nextCard->setEnabled(true);
        }
        if (b==0){
            ui->percent->setText("Score: 0/0 (0%)");
        }
        ui->scorebox->setText("Card " + QString::number(counter) + " / " + QString::number(study.length()-1));

    }
    else
        return;

}

void MainWindow::flip(){

    if (ui->study->isChecked()){
        if (ui->Flashcard->text()!=study[counter] && ui->Flashcard->text()!=studya[counter]){
            ui->Flashcard->setText(study[counter]);
            ui->flash_instruction->setText("Click Card to Flip");
            ui->nextCard->setEnabled(true);
            ui->prevCard->setEnabled(true);
                    return;
        }

        if (ui->Flashcard->text()==study[counter]){
            ui->Flashcard->setText(studya[counter]);
        }
        else{
            ui->Flashcard->setText(study[counter]);
        }
    }

    if (ui->takeQuiz->isChecked()){
        if (ui->Flashcard->text()!=study[counter] && ui->Flashcard->text()!=quizc[counter]){
            ui->Flashcard->setText(study[counter]);
            ui->flash_instruction->setText("Click Card to Reveal Choices");
                    return;
        }
        if (ui->Flashcard->text()==study[counter]){
            ui->Flashcard->setText(quizc[counter]);
        }
        else{
            ui->Flashcard->setText(study[counter]);
        }


    }

}

void MainWindow::next(){
    ui->result->setText("");
    visited[counter]=1;
    if (ui->study->isChecked()){
        if (counter==study.length()-1){
            counter=0;
        }
        else if(counter<study.length()-1){
            counter++;
        }
        ui->Flashcard->setText(study[counter]);
    }
    if (ui->takeQuiz->isChecked()){
        if (counter==study.length()-1){
            counter=0;
        }
        else if(counter<study.length()-1){
            counter++;
        }
        ui->Flashcard->setText(study[counter]);
        ui->A->setAutoExclusive(false);
        ui->A->setChecked(false);
        ui->A->setAutoExclusive(true);
        ui->B->setAutoExclusive(false);
        ui->B->setChecked(false);
        ui->B->setAutoExclusive(true);
        ui->C->setAutoExclusive(false);
        ui->C->setChecked(false);
        ui->C->setAutoExclusive(true);
        ui->D->setAutoExclusive(false);
        ui->D->setChecked(false);
        ui->D->setAutoExclusive(true);
        attempt=0;
        if (visited[counter]==1){
            attempt++;
        }
    }
}

void MainWindow::prev(){
    ui->result->setText("");
    if (ui->study->isChecked()){

        if (counter==0){
            counter=study.length()-1;
        }
        else if (counter>0){
            counter--;
        }
        ui->Flashcard->setText(study[counter]);
    }
    if (ui->takeQuiz->isChecked()){

        if (counter==0){
            counter=study.length()-1;
        }
        else if (counter>0){
            counter--;
        }
        ui->Flashcard->setText(study[counter]);
        ui->A->setAutoExclusive(false);
        ui->A->setChecked(false);
        ui->A->setAutoExclusive(true);
        ui->B->setAutoExclusive(false);
        ui->B->setChecked(false);
        ui->B->setAutoExclusive(true);
        ui->C->setAutoExclusive(false);
        ui->C->setChecked(false);
        ui->C->setAutoExclusive(true);
        ui->D->setAutoExclusive(false);
        ui->D->setChecked(false);
        ui->D->setAutoExclusive(true);
        attempt++;
    }
}

void MainWindow::reset(){
    counter=0;
    attempt=0;
    a=0.0;
    b=0.0;
    ui->flash_instruction->setText("");
    for (int i=0;i<study.length();++i){
        visited[i]=0;
    }
    ui->scorebox->setText("Card " + QString::number(counter) + " / " + QString::number(study.length()-1));
    ui->Flashcard->setText("Click To Begin");
    ui->result->setText("");
    ui->A->setAutoExclusive(false);
    ui->A->setChecked(false);
    ui->A->setAutoExclusive(true);
    ui->B->setAutoExclusive(false);
    ui->B->setChecked(false);
    ui->B->setAutoExclusive(true);
    ui->C->setAutoExclusive(false);
    ui->C->setChecked(false);
    ui->C->setAutoExclusive(true);
    ui->D->setAutoExclusive(false);
    ui->D->setChecked(false);
    ui->D->setAutoExclusive(true);

    std::srand(time(0));
    std::random_shuffle(indexes.begin(), indexes.end());
    int j=0;
    for (auto i = study.begin(); i != study.end(); ++i){
        swap(*i,study[indexes[j]]);
        j++;
    }
    int k=0;
    for (auto i = studya.begin(); i != studya.end(); ++i){
        swap(*i,studya[indexes[k]]);
        k++;
    }
    int l=0;
    for (auto i = quizc.begin(); i != quizc.end(); ++i){
        swap(*i,quizc[indexes[l]]);
        l++;
    }
    int m=0;
    for (auto i = quiza.begin(); i != quiza.end(); ++i){
        cswap(*i,quiza[indexes[m]]);
        m++;
    }
}

void MainWindow::checkAnswer(){

    if (ui->A->isChecked()){
        if (quiza[counter]=="A"){
            ui->result->setText("Correct!");
            ui->nextCard->setEnabled(true);
        }
        else{
            ui->result->setText("Incorrect!");
        }
    }
    if (ui->B->isChecked()){
        if (quiza[counter]=="B"){
            ui->result->setText("Correct!");
            ui->nextCard->setEnabled(true);
        }
        else{
            ui->result->setText("Incorrect!");
        }
    }
    if (ui->C->isChecked()){
        if (quiza[counter]=="C"){
            ui->result->setText("Correct!");
            ui->nextCard->setEnabled(true);
        }
        else{
            ui->result->setText("Incorrect!");
        }
    }
    if (ui->D->isChecked()){
        if (quiza[counter]=="D"){
            ui->result->setText("Correct!");
            ui->nextCard->setEnabled(true);
        }
        else{
            ui->result->setText("Incorrect!");
        }
    }
    if (attempt==0){
        if (ui->result->text()=="Correct!"){
            a++;
            b++;
            double c=(a/b)*100;
            ui->percent->setText("Score: " + QString::number(a) + "/" + QString::number(b) + " ("+QString::number(c,'f',2) + "%)");
        }
        else{
            b++;
            double c=(a/b)*100;
            ui->percent->setText("Score: " + QString::number(a) + "/" + QString::number(b) + " ("+QString::number(c,'f',2) + "%)");
        }
    }
    attempt++;
}

void MainWindow::cswap(QChar& a, QChar& b){
    QChar temp;
    temp = a;
    a=b;
    b=temp;
    return;
}
