#include "EmojiNode.hpp"

bool EmojiNode::init(std::string key)
{
    for (auto emoji : getAnimatedEmojis())
    {
        if (emoji.first == key)
        {
            return EmojiNode::initWithAnimatedSprite(key, emoji.second);
        }
    }

    return EmojiNode::initWithKey(key);
}

bool EmojiNode::initWithKey(std::string key)
{
    return CCSprite::initWithSpriteFrameName(frameForKey(key));
}

bool EmojiNode::initWithAnimatedSprite(std::string key, float rate)
{
    if (!CCSprite::init())
        return false;

    for (size_t i = 1; i < 420; i++)
    {
        auto s = fmt::format("{}{}_{}.png", ""_spr, key, i).c_str();

        if (auto frame = CCSpriteFrameCache::get()->m_pSpriteFrames->objectForKey(s))
        {
            auto f = CCSprite::createWithSpriteFrame(as<CCSpriteFrame*>(frame));
            f->setVisible(frames.size() == 0);
            f->setTag(i);
            this->setContentSize(f->getContentSize());
            f->setPosition(f->getContentSize() / 2);

            frames.push_back(f);
            this->addChild(f);
        }
        else
        {
            break;
        }
    }

    if (frames.size() > 0)
        this->schedule(schedule_selector(EmojiNode::updateFrame), rate);

    return true;
}

EmojiNode* EmojiNode::createWithKey(std::string key)
{
    auto pRet = new EmojiNode();

    if (pRet && pRet->init(key))
    {
        pRet->autorelease();
        return pRet;
    }

    CC_SAFE_DELETE(pRet);
    return nullptr;
}

void EmojiNode::updateFrame(float)
{
    currentFrame++;

    if (currentFrame >= frames.size())
        currentFrame = 0;

    int i = 0;
    for (auto frame : frames)
    {
        frames[i]->setVisible(i == currentFrame);
        i++;
    }

    //this->setDisplayFrame(frames[currentFrame]);
}

const char* EmojiNode::frameForKey(std::string key)
{
    for (auto emoji : EmojiNode::getEmojis()) {
        if (!emoji.first.starts_with("$$newline$$") && geode::utils::string::toLower(emoji.first) == geode::utils::string::toLower(key))
            return emoji.second.c_str();
    }

    return "";
}



std::pair<std::string, std::string> _Emoji(const std::string &name) {
    auto spr = std::string(""_spr);
    return {name, spr + (name + std::string(".png"))};
}
std::vector<std::pair<std::string, std::string>> emojis = {
    std::pair("auto", "diffIcon_auto_btn_001.png"),
    std::pair("na", "diffIcon_00_btn_001.png"),
    std::pair("easy", "diffIcon_01_btn_001.png"),
    std::pair("normal", "diffIcon_02_btn_001.png"),
    _Emoji("casual"),
    std::pair("hard", "diffIcon_03_btn_001.png"),
    std::pair("harder", "diffIcon_04_btn_001.png"),
    _Emoji("tough"),
    std::pair("insane", "diffIcon_05_btn_001.png"),
    _Emoji("creul"),
    std::pair("easydemon", "diffIcon_07_btn_001.png"),
    std::pair("mediumdemon", "diffIcon_08_btn_001.png"),
    std::pair("harddemon", "diffIcon_06_btn_001.png"),
    std::pair("insanedemon", "diffIcon_09_btn_001.png"),
    std::pair("extremedemon", "diffIcon_10_btn_001.png"),

    std::pair("star", "GJ_starsIcon_001.png"_spr),

    std::pair("orb", "currencyOrb_001.png"_spr),
    std::pair("orbs", "currencyOrbIcon_001.png"_spr),

    std::pair("diamond", "diamond_small01_001.png"_spr),
    std::pair("diamonds", "currencyDiamondIcon_001.png"_spr),

    std::pair("like", "GJ_likesIcon_001.png"_spr),
    std::pair("dislike", "GJ_dislikesIcon_001.png"_spr), // rob i genuinely hate you for making it this differetn size it is size size different

    std::pair("check", "GJ_completesIcon_001.png"),
    std::pair("cross", "GJ_deleteIcon_001.png"_spr),

    std::pair("locked", "GJLargeLock_001.png"_spr),
    std::pair("lockedgray", "GJ_lockGray_001.png"_spr),
    std::pair("unlocked", "GJ_lock_open_001.png"_spr),

    std::pair("goldcoin", "GJ_coinsIcon_001.png"_spr),
    std::pair("uncollectedusercoin", "GJ_coinsIcon_gray_001.png"),
    _Emoji("usercoinunverified"),
    std::pair("usercoin", "GJ_coinsIcon2_001.png"_spr),
    std::pair("points", "GJ_pointsIcon_001.png"_spr),

    std::pair("mod", "modBadge_01_001.png"_spr),
    std::pair("eldermod", "modBadge_02_001.png"_spr),
    std::pair("leaderboardmod", "modBadge_03_001.png"_spr),

    std::pair("$$newline$$CPS Server", "$$newline$$"),
    
    _Emoji("active"),
    _Emoji("Admin"),
    _Emoji("aeon_requiem"),
    _Emoji("ballcat"),
    _Emoji("berd"),
    _Emoji("bigbrain"),
    _Emoji("booba"),
    _Emoji("boykisser"),
    _Emoji("brilliant"),
    _Emoji("brown_coin"),
    _Emoji("catcry"),
    _Emoji("catfear"),
    _Emoji("catnothehe"),
    _Emoji("catpointandlaugh"),
    _Emoji("catsus"),
    _Emoji("catwhaaa"),
    _Emoji("catwink"),
    _Emoji("catwtf"),
    _Emoji("cat_angrystare"),
    _Emoji("cat_aple"),
    _Emoji("cat_floer"),
    _Emoji("cat_insane"),
    _Emoji("cat_lim"),
    _Emoji("cat_nothing"),
    _Emoji("cat_orng"),
    _Emoji("cat_sad"),
    _Emoji("cat_spon"),
    _Emoji("cat_wow"),
    _Emoji("comment"),
    _Emoji("creator_point"),
    _Emoji("CryCat"),
    _Emoji("crythumbsup"),
    _Emoji("cube_ok_hand"),
    _Emoji("cutecat"),
    _Emoji("demon"),
    _Emoji("demonlist_staff"),
    _Emoji("demon_curse"),
    _Emoji("developer"),
    _Emoji("discord_icon"),
    _Emoji("doodle_drool"),
    _Emoji("doodle_happi"),
    _Emoji("doodle_happi2"),
    _Emoji("doodle_nerd"),
    _Emoji("doodle_smile"),
    _Emoji("doodle_think"),
    _Emoji("download"),
    _Emoji("easy_curse"),
    _Emoji("easy_hapi"),
    _Emoji("elder_mod"),
    _Emoji("epic_rate"),
    _Emoji("extreme_demon"),
    _Emoji("Extreme_Demon_Think"),
    _Emoji("ex_demon_curse"),
    _Emoji("ez_demon"),
    _Emoji("ez_like"),
    _Emoji("featured"),
    _Emoji("harddemon_grr"),
    _Emoji("harder_curse"),
    _Emoji("harder_dislike"),
    _Emoji("heheehe"),
    _Emoji("info"),
    _Emoji("insane_demon"),
    _Emoji("insane_lmao"),
    _Emoji("insane_uhh"),
    _Emoji("jerryosht"),
    _Emoji("leaderboard"),
    _Emoji("leaderboard_mod"),
    _Emoji("legendary_rate"),
    _Emoji("lobotomy_like"),
    _Emoji("lowtiergod"),
    _Emoji("mcfox_sleep"),
    _Emoji("medium_demon"),
    _Emoji("moderator"),
    _Emoji("moon"),
    _Emoji("moyai_icon"),
    _Emoji("mythic_rate"),
    _Emoji("no"),
    _Emoji("normal_curse"),
    _Emoji("normal_nerd"),
    _Emoji("normal_ok"),
    _Emoji("npestapog"),
    _Emoji("ohnocringecat"),
    _Emoji("omg"),
    _Emoji("owner"),
    _Emoji("partnership_icon"),
    _Emoji("pc"),
    _Emoji("peepoaff"),
    _Emoji("peepohappy"),
    _Emoji("peepohypers"),
    _Emoji("pepe_clown"),
    _Emoji("pepe_sad"),
    _Emoji("play"),
    _Emoji("Pop_cat"),
    _Emoji("sadlol"),
    _Emoji("sadspongebob"),
    _Emoji("secret_coin"),
    _Emoji("silver_coins"),
    _Emoji("skull_hd"),
    _Emoji("spike"),
    _Emoji("staff"),
    _Emoji("star2d"),
    _Emoji("starGd"),
    _Emoji("the_rock"),
    _Emoji("think"),
    _Emoji("time"),
    _Emoji("trollface"),
    _Emoji("unmod"),
    _Emoji("vip"),
    _Emoji("watermelon"),
    _Emoji("whatdahell"),
    _Emoji("WOAH"),
    _Emoji("WOOOOW"),
    _Emoji("xD"),
    _Emoji("ybangry"),
    _Emoji("ybangry2"),
    _Emoji("ybayo"),
    _Emoji("ybsunglasses"),
    _Emoji("yb_facepalm"),
    _Emoji("yb_ohyou"),
    _Emoji("yb_point"),
    _Emoji("yb_robber"),
    _Emoji("yb_sad"),
    _Emoji("yb_sad2"),
    _Emoji("yb_sleep"),
    _Emoji("yb_smoke"),
    _Emoji("yb_stare"),
    _Emoji("yb_sunglasses2"),
    _Emoji("yb_think"),
    _Emoji("yb_usure"),
    _Emoji("yes"),
    _Emoji("youtube_icon"),
    _Emoji("babyvibez"),
    _Emoji("ballwave"),
    _Emoji("blobdance"),
    _Emoji("catbitting"),
    _Emoji("catdance"),
    _Emoji("catfalling"),
    _Emoji("catJAM"),
    _Emoji("catkiss"),
    _Emoji("catshake"),
    _Emoji("catstab"),
    _Emoji("catstuck"),
    _Emoji("cronchycat"),
    _Emoji("CubeSpeen"),
    _Emoji("cute_kitten"),
    _Emoji("happicat"),
    _Emoji("lazors"),
    _Emoji("lmao"),
    _Emoji("nocat"),
    _Emoji("normalyap"),
    _Emoji("pensivegif"),
    _Emoji("popsquire"),
    _Emoji("yb_mewing"),
    _Emoji("yb_sleep2"),
    _Emoji("yb_thumbsup"),
    _Emoji("yb_walk"),

    std::pair("$$newline$$Discord", "$$newline$$"),

    //discord
    _Emoji("100"),
    _Emoji("shushing_face"),
    _Emoji("deaf_person"),
    _Emoji("deaf_man"),
    _Emoji("deaf_woman"),
    _Emoji("bear"),
    _Emoji("broken_heart"),
    _Emoji("cat"),
    _Emoji("dog"),
    _Emoji("fox"),
    _Emoji("gun"),
    _Emoji("face_with_raised_eyebrow"),
    _Emoji("middle_finger"),
    _Emoji("moyai"),
    _Emoji("fire"),
    _Emoji("nerd"),
    _Emoji("radioactive"),
    _Emoji("shocked_face"),
    _Emoji("skull"),
    _Emoji("smiling_imp"),
    _Emoji("speaking_head"),
    _Emoji("sob"),
    _Emoji("eggplant"),
    _Emoji("clown"),
    _Emoji("tongue"),

    std::pair("$$newline$$Other", "$$newline$$"),

    //other
    _Emoji("amongus"),
    _Emoji("amogus"),
    _Emoji("bruh"),
    _Emoji("carlos"),
    _Emoji("clueless"),
    _Emoji("despair"),
    _Emoji("despair2"),
    _Emoji("ned"),
    std::pair("pusab?", "pusab.png"_spr),
    _Emoji("robsmile"),
    _Emoji("sip"),
    _Emoji("splat"),
    _Emoji("teehee"),
    _Emoji("trollface"),
    _Emoji("true"),
    _Emoji("walter"),
    _Emoji("wha"),
    _Emoji("whadahell"),
    _Emoji("youshould"),
    _Emoji("car"),
    _Emoji("zoink"),
    _Emoji("shocked"),
    _Emoji("poppinbottles"),
    _Emoji("party"),
    _Emoji("potbor"),
    _Emoji("dabmeup"),
    _Emoji("fireinthehole"),
    _Emoji("finger"),
    _Emoji("soggy"),
    _Emoji("mayo"),
    _Emoji("divine"),
    _Emoji("bueno"),
    _Emoji("rattledash"),
    _Emoji("gd"),
    std::pair("geode", "geode-icon.png"_spr),
    _Emoji("boar"),
    _Emoji("mewhen"),
    _Emoji("changetopic"),
    _Emoji("touchgrass"),
    _Emoji("gggggggg"),
    _Emoji("gdok"),
    _Emoji("hug"),
    _Emoji("angy"),
    _Emoji("lewd"),
    _Emoji("headpat"),
    _Emoji("transcat"),
    _Emoji("transcat2"),
    _Emoji("skillissue"),
    _Emoji("yes"),
    _Emoji("gunleft"),
    _Emoji("gunright"),
    _Emoji("edge"),
    _Emoji("cologne"),
    _Emoji("globed"),
    _Emoji("levelthumbnails"),
    _Emoji("oh"),
    _Emoji("holymoly"),
    _Emoji("1000yardstare"),
    _Emoji("spunchbob"),
    _Emoji("freakbob"),
    _Emoji("nuhuh"),
    _Emoji("yuhuh"),

    // players
    std::pair("$$newline$$Players", "$$newline$$"),

    _Emoji("default"),
    _Emoji("sdslayer"),
    _Emoji("evw"),
    _Emoji("tride"),
    _Emoji("colon"),
    _Emoji("robtop"),
    _Emoji("wulzy"),
    _Emoji("juniper"),
    _Emoji("riot"),
    _Emoji("cyclic"),
    _Emoji("thesillydoggo"),
    _Emoji("uproxide"),

    std::pair("$$newline$$Cube Emotes (By @cyanflower on discord)", "$$newline$$"),

    _Emoji("cubeconfused"),
    //_Emoji("cubedance"),
    _Emoji("cubestare"),
    _Emoji("cubehappy"),
    _Emoji("cubewave"),
    //_Emoji("cubehyperthink"),
    _Emoji("cubeletsgo"),
    _Emoji("cubepog"),
    _Emoji("cubescared"),
    //_Emoji("cubespeen"),
    _Emoji("cubethink"),
    _Emoji("cubecool"),
    _Emoji("cubeview"),
    _Emoji("cubewink"),
    _Emoji("defaultangry"),
    _Emoji("robtoppixel"),
    _Emoji("smugzero"),
    _Emoji("cubeballin"),
    _Emoji("eeyikes"),
    _Emoji("boshytime"),
    _Emoji("fumocube"),
    
    // cat collection, thank you c# discord. i wuv you <3
    std::pair("$$newline$$Cat Collection", "$$newline$$"),

    _Emoji("catbless"),
    _Emoji("catcash"),
    _Emoji("catcomf"),
    _Emoji("catcool"),
    _Emoji("catcop"),
    _Emoji("catcorn"),
    _Emoji("catderp"),
    _Emoji("catfacepalm"),
    _Emoji("catfine"),
    _Emoji("catgasm"),
    _Emoji("catgasp"),
    _Emoji("catgift"),
    _Emoji("catgrump"),
    _Emoji("catgun"),
    _Emoji("cathammer"),
    _Emoji("cathi"),
    _Emoji("cathype"),
    _Emoji("catlaugh"),
    _Emoji("catlick"),
    _Emoji("catloser"),
    _Emoji("catlost"),
    _Emoji("catlove"),
    _Emoji("catlul"),
    _Emoji("catlurk"),
    _Emoji("catmusik"),
    _Emoji("catok"),
    _Emoji("catpat"),
    _Emoji("catpls"),
    _Emoji("catpog"),
    _Emoji("catpout"),
    _Emoji("catree"),
    _Emoji("catshrug"),
    _Emoji("catshy"),
    _Emoji("catsimp"),
    _Emoji("catsip"),
    _Emoji("catsleep"),
    _Emoji("catsmart"),
    _Emoji("catsweat"),
    _Emoji("catthinking"),
};

std::vector<std::pair<std::string, float>> animated = {
    std::pair("$$newline$$Animated", 42069),
    std::pair("shiggy", 0.02f),
    std::pair("hype", 0.07f),
    std::pair("petmaurice", 0.05f),
    std::pair("bonk", 0.06f),
    std::pair("partying", 0.04f),
    std::pair("ned_explosion", 0.02f),
    std::pair("polarbear", 0.03f),
    std::pair("colonthreecat", 0.03f),
    std::pair("cubedance", 0.07f),
    std::pair("cubespeen", 0.04f),
    std::pair("cubehyperthink", 0.05f),
    std::pair("deltaruneexplosion", 1.0f / 17.0f),
};

std::vector<std::pair<std::string, std::string>> EmojiNode::getEmojis()
{
    return emojis;
}

std::vector<std::pair<std::string, float>> EmojiNode::getAnimatedEmojis()
{
    return animated;
}
