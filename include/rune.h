#ifndef __RUNE_H__
#define __RUNE_H__

#include <string>

/*
           
VOWELS
          /  \
       2 /    \ 1
        /      \
       |
     3 |
       |
     ------------------
       |
     3 |
       |
        \       /
       4 \     / 5
          \   /
            O
            12

CONSONANTS
            7
         \  |  /
        8 \ | / 6
           \|/
            |
     ------------------
            |
           /|\
        9 / | \ 11
         /  |  \
            10

*/


const auto RUNE_REVERSE         = 0b000000000001;
const auto RUNE_VOWEL           = 0b111110000000;
const auto RUNE_CONSONANT       = 0b000001111110;
const auto RUNE_NULL            = 0b000000000000;

//                                  |||||_______
const auto RUNE_VOWEL_A         = 0b111000000000; // cat
const auto RUNE_VOWEL_O         = 0b011000000000; // on
const auto RUNE_VOWEL_I         = 0b000110000000; // ship
const auto RUNE_VOWEL_E         = 0b001110000000; // bed
const auto RUNE_VOWEL_OO_O      = 0b001100000000; // good
const auto RUNE_VOWEL_ER        = 0b110000000000; // teacher

const auto RUNE_VOWEL_EE        = 0b011110000000; // sheep
const auto RUNE_VOWEL_OO_U      = 0b111100000000; // shoot
const auto RUNE_VOWEL_IR        = 0b101110000000; // bird
const auto RUNE_VOWEL_OOR       = 0b111010000000; // door
const auto RUNE_VOWEL_AR        = 0b110110000000; // far
const auto RUNE_VOWEL_ERE       = 0b011010000000; // here

const auto RUNE_VOWEL_AI        = 0b010000000000; // wait
const auto RUNE_VOWEL_Y         = 0b100000000000; // my
const auto RUNE_VOWEL_U         = 0b000100000000; // up
const auto RUNE_VOWEL_OW_H      = 0b000010000000; // cow
const auto RUNE_VOWEL_OW_S      = 0b111110000000; // show
const auto RUNE_VOWEL_AIR       = 0b001010000000; // hair



//                                  _____||||||_
const auto RUNE_CONSONANT_M     = 0b000000001010;
const auto RUNE_CONSONANT_N     = 0b000000011010;
const auto RUNE_CONSONANT_NG    = 0b000000111110;
const auto RUNE_CONSONANT_P     = 0b000001000100;
const auto RUNE_CONSONANT_B     = 0b000000100010;
const auto RUNE_CONSONANT_T     = 0b000001010100;


const auto RUNE_CONSONANT_D     = 0b000000101010;
const auto RUNE_CONSONANT_K     = 0b000001100010;
const auto RUNE_CONSONANT_G     = 0b000001000010;
const auto RUNE_CONSONANT_J     = 0b000000101000;
const auto RUNE_CONSONANT_CH    = 0b000000010100;
const auto RUNE_CONSONANT_F     = 0b000001001100;

const auto RUNE_CONSONANT_V     = 0b000000110010;
const auto RUNE_CONSONANT_TH_Z  = 0b000000101110;
const auto RUNE_CONSONANT_TH_S  = 0b000001110100;
const auto RUNE_CONSONANT_S     = 0b000001101100;
const auto RUNE_CONSONANT_Z     = 0b000000110110;
const auto RUNE_CONSONANT_SH    = 0b000001011110;

const auto RUNE_CONSONANT_ZH    = 0b000001111010;
const auto RUNE_CONSONANT_H     = 0b000000100110;
const auto RUNE_CONSONANT_R     = 0b000001100100;
const auto RUNE_CONSONANT_Y     = 0b000000110100;
const auto RUNE_CONSONANT_W     = 0b000001010000;
const auto RUNE_CONSONANT_L     = 0b000000100100;

// VOWELS
const auto PHONETIC_EA          = "a"; //     /a/ 	a, à, e, ea 	astéroïde /as.te.ʁɔ.id/, canard /ka.naʁ/, rutabaga /ʁy.ta.ba.ɡa/, déjà /de.ʒa/, femme /fam/, évidemment /e.vi.da.mɑ̃/, orangeade /ɔ.ʁɑ̃.ʒad/
const auto PHONETIC_ALPHA       = "ɑ"; //     /ɑ/ 	â,a 	âge /ɑʒ/, pâtes /pɑt/, appât /a.pɑ/, là-bas /la.bɑ/
const auto PHONETIC_EU          = "ə"; //     /ə/ 	e, ai, on 	de /də/, genêt /ʒə.nɛ/, vendredi /vɑ̃.dʁə.di/, enveloppe /ɑ̃.və.lɔp/ ou /ɑ̃.vlɔp/[2], faisan /fə.zɑ̃/, faisable /fə.zabl/, Monsieur /mə.sjø/
const auto PHONETIC_OE          = "œ"; //     /œ/ 	eu, œ, œu, ue 	ingénieur /ɛ̃.ʒe.njœʁ/, œil /œj/, œuf /œf/, accueil /a.kœj/
const auto PHONETIC_ZERO        = "ø"; //     /ø/ 	eu, eû, œu, œufs 	euclidien /'ø.kli.djɛ̃/, feu /fø/, heureux /ø.ʁø/ (ou /œ.ʁø/), jeûne /ʒøn/, nœud /nø/, bœufs /bø/
const auto PHONETIC_EPSILON     = "ɛ"; //     /ɛ/ 	ai, aî, e, è, ê, ë, ei, et 	aimable /ɛ.mabl/, mairie /mɛ.ʁi/, maître /mɛtʁ/, lettre /lɛtʁ/, après /a.pʁɛ/, pêche /pɛʃ/, Noël /nɔ.ɛl/, peine /pɛn/, jet /ʒɛ/
const auto PHONETIC_E           = "e"; //     /e/ 	é, e, er, et, ai, æ, œ, ez 	dé /de/, mésange /me.zɑ̃ʒ/, effiler /e.fi.le/, et /e/, aigu /e.gy/, nævus /ne.vys/, fœtus /fe.tys/, nez /ne/
const auto PHONETIC_I           = "i"; //     /i/ 	i, ï, î, y, ee 	isoler /i.zɔ.le/, pi /pi/, mite /mit/, mairie /mɛ.ʁi/, haïr /a.iʁ/, île /il/, mystère /mis.tɛʁ/, week-end /wi.kɛnd/
const auto PHONETIC_AU          = "ɔ"; //     /ɔ/ 	au, eo, o, oi, u, ü 	dinosaure /di.no.zɔʁ/, Paul /pɔl/, rougeole /ʁu.ʒɔl/, octobre /ɔk.tɔbʁ/, pomme /pɔm/, oignon /ɔ.ɲɔ̃/, album /al.bɔm/, capharnaüm /ka.faʁ.na.ɔm/
const auto PHONETIC_O           = "o"; //     /o/ 	o, ô, au, eau, eô 	oser /o.ze/, rose /ʁoz/, rôti /ʁo.ti/, chevaux /ʃə.vo/, eau /o/, tonneau /tɔ.no/, geôle /ʒol/
const auto PHONETIC_Y           = "y"; //     /y/ 	u, û, ü, eu 	hurluberlu /yʁ.ly.bɛʁ.ly/, lutte /lyt/, velu /və.ly/, sûr /syʁ/, aigüe /e.gy/, gageure /ga.ʒyʁ/
const auto PHONETIC_EN          = "ɑ̃"; //     /ɑ̃/ 	am, aen, an, aon, em, en 	ampère /ɑ̃.pɛʁ/, Caen /kɑ̃/, avant /a.vɑ̃/, faon /fɑ̃/, embrouille /ɑ̃.bʁuj/, dent /dɑ̃/, parenté /pa.ʁɑ̃.te/
const auto PHONETIC_IN          = "ɛ̃"; //     /ɛ̃/ 	ain, aim, ein, eim, en, im, in, ym, yn 	pain /pɛ̃/, faim /fɛ̃/, Éteimbes /e.tɛ̃b/, feinte /fɛ̃t/, chien /ʃjɛ̃/, imbu /ɛ̃.by/, indu /ɛ̃.dy/, tympan /tɛ̃.pɑ̃/, lyncher /lɛ̃.ʃe/
const auto PHONETIC_UN          = "œ̃"; //     /œ̃/ 	un, um 	un /œ̃/, unguéal /œ̃.ɡɥe.al/, aucun /o.kœ̃/, parfum /paʁ.fœ̃/
const auto PHONETIC_ON          = "ɔ̃"; //     /ɔ̃/ 	on, om 	honte /ɔ̃t/, démonter /de.mɔ̃.te/, aviron /a.vi.ʁɔ̃/, ombrelle /ɔ̃.bʁɛl/
const auto PHONETIC_OU          = "u"; //     /u/ 	ou, où, oû, aoû, oo 	outre /utʁ/, pou /pu/, joujou / ʒu.ʒu/, où /u/, voûte /vut/, août /ut/ (ou /a.ut/), igloo /i.glu/

// SEMI-VOWELS
const auto PHONETIC_J           = "j"; //     /j/ 	i, ï, il, ll, y 	bien /bjɛ̃/, païen /pa.jɛ̃/, ail /aj/, fille /fij/, pailleter /paj.te/, yen /jɛn/
const auto PHONETIC_W           = "w"; //     /w/ 	ou, w, wh, oe, oi, oua 	oued /wɛd/, watt /wat/, whisky /wis.ki/, moelleux /mwɛlø / (ou /mwalø/), poids /pwa/, noir /nwaʁ/, ouate /wat/
const auto PHONETIC_U           = "ɥ"; //     /ɥ/ 	u 	nuage /nɥaʒ/, suer /sɥe/, duel /dɥɛl/ puits /pɥi/, duo /dɥo/ 

// CONSONANTS
//const auto PHONETIC_XXX         = " "; //     /b/ 	b, bb, bh 	banc /bɑ̃/, tabac /ta.ba/, robe /ʁɔb/, abbé /a.be/, Bhoutan /bu.tɑ̃/
//const auto PHONETIC_XXX         = " "; //     /d/ 	d, dd, dh 	dent /dɑ̃/, redorer /ʁə.dɔ.ʁe/, limonade /li.mɔ.nad/, additif /a.di.tif/, Dhuizon /dɥi.zɔ̃/
//const auto PHONETIC_XXX         = " "; //     /ʃ/ 	ch, sch, sh 	chat /ʃa/, échaudé /e.ʃo.de/, cache /kaʃ/, schéma /ʃe.ma/, shérif /ʃe.ʁif/
//const auto PHONETIC_XXX         = " "; //     /f/ 	f, ff, ph, pph 	famille /fa.mij/, effacer /e.fa.se/, graphe /ɡʁaf/, Sappho /sa.fo/
//const auto PHONETIC_XXX         = " "; //     /ɡ/ 	g, gg, gh, gu, c 	gant /ɡɑ̃/, aggraver /a.gʁa.ve/, afghan /af.gɑ̃/, aguerrir /a.gɛ.ʁiʁ/, bague /baɡ/, seconde /sə.ɡɔ̃d/
//const auto PHONETIC_XXX         = " "; //     /ʒ/ 	j, ge 	juré /ʒy.ʁe/, gens /ʒɑ̃/, végéter /ve.ʒe.te/, cage /kaʒ/
//const auto PHONETIC_XXX         = " "; //     /k/ 	c, cc, ch, ck, cu, k, kh, q, qu 	caméléon /ka.me.le.ɔ̃/, accorder /a.kɔʁ.de/, chlorophylle /klɔ.ʁɔ.fil/, Patrick /pa.tʁik/, recueil /ʁə.kœj/, kaki /ka.ki/, sikh /sik/, coq /kɔq/, chèque /ʃɛk/
//const auto PHONETIC_XXX         = " "; //     /l/ 	l, ll, lh 	Labrador /la.bʁa.dɔʁ/, cale /kal/, ville /vil/, Lhassa /la.sa/
//const auto PHONETIC_XXX         = " "; //     /m/ 	m, mm, mh 	mosquée /mɔs.ke/, comme /kɔm/, Mhère /mɛʁ/
//const auto PHONETIC_XXX         = " "; //     /n/ 	n, nn 	Nancy /nɑ̃.si/, canard /ka.naʁ/, canne /kan/
//const auto PHONETIC_XXX         = " "; //     /ɲ/ 	gn 	gnangnan /ɲɑ̃.ɲɑ̃/, vignoble /vi.ɲɔbl/, champagne /ʃɑ̃.paɲ/
//const auto PHONETIC_XXX         = " "; //     /ŋ/ 	ng 	parking /paʁ.kiŋ/
//const auto PHONETIC_XXX         = " "; //     /p/ 	p, pp 	poule /pul/, apprenti /a.pʁɑ̃.ti/, soupe /sup/
//const auto PHONETIC_XXX         = " "; //     /ʁ/ 	r, rr, rh, rrh 	rat /ʁa/, carré /kɑ.ʁe/, car /kaʁ/, rhododendron /ʁo.do.dɛ̃.dʁɔ̃/, diarrhée /djaʁe/
//const auto PHONETIC_XXX         = " "; //     /s/ 	s, ss, sc, c, ç, t, x 	série /se.ʁi/, aérostat /a.e.ʁɔs.ta/, assez /a.se/, scie /si/, cycle /sikl/, puce /pys/, façon /fa.sɔ̃/, nation /na.sjɔ̃/, soixante-dix /swa.sɑ̃t.dis/
//const auto PHONETIC_XXX         = " "; //     /t/ 	t, th, tt 	taon /tɑ̃/, retaper /ʁə.ta.pe/, thym /tɛ̃/, patte /pat/
//const auto PHONETIC_XXX         = " "; //     /v/ 	v, w 	vent /vɑ̃/, David /david/, rave /ʁav/, wagon /va.gɔ̃/, WC /ve.se/ (ou /du.blə.ve.se/)
//const auto PHONETIC_XXX         = " "; //     /z/ 	s, z, x 	zen /zɛn/, zigzag /zig.zag/, visage /vi.zaʒ/, case /kɑz/, dixième /di.zjɛm/ 


class Rune {
public:
    Rune() = default;
    Rune(unsigned long bin);
    std::string to_string() const;
private:
    std::string to_string(unsigned long bin) const;
    unsigned long m_rune;
};

#endif // __RUNE_H__