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

    std::pair("active", "active.png"),
    std::pair("Admin", "Admin.png"),
    std::pair("aeon_requiem", "aeon_requiem.png"),
    std::pair("ballcat", "ballcat.png"),
    std::pair("berd", "berd.png"),
    std::pair("bigbrain", "bigbrain.png"),
    std::pair("booba", "booba.png"),
    std::pair("boykisser", "boykisser.png"),
    std::pair("brilliant", "brilliant.png"),
    std::pair("brown_coin", "brown_coin.png"),
    std::pair("catcry", "catcry.png"),
    std::pair("catfear", "catfear.png"),
    std::pair("catnothehe", "catnothehe.png"),
    std::pair("catpointandlaugh", "catpointandlaugh.png"),
    std::pair("catsus", "catsus.png"),
    std::pair("catwhaaa", "catwhaaa.png"),
    std::pair("catwink", "catwink.png"),
    std::pair("catwtf", "catwtf.png"),
    std::pair("cat_angrystare", "cat_angrystare.png"),
    std::pair("cat_aple", "cat_aple.png"),
    std::pair("cat_floer", "cat_floer.png"),
    std::pair("cat_insane", "cat_insane.png"),
    std::pair("cat_lim", "cat_lim.png"),
    std::pair("cat_nothing", "cat_nothing.png"),
    std::pair("cat_orng", "cat_orng.png"),
    std::pair("cat_sad", "cat_sad.png"),
    std::pair("cat_spon", "cat_spon.png"),
    std::pair("cat_wow", "cat_wow.png"),
    std::pair("comment", "comment.png"),
    std::pair("creator_point", "creator_point.png"),
    std::pair("CryCat", "CryCat.png"),
    std::pair("crythumbsup", "crythumbsup.png"),
    std::pair("cube_ok_hand", "cube_ok_hand.png"),
    std::pair("cutecat", "cutecat.png"),
    std::pair("demon", "demon.png"),
    std::pair("demonlist_staff", "demonlist_staff.png"),
    std::pair("demon_curse", "demon_curse.png"),
    std::pair("developer", "developer.png"),
    std::pair("diamond", "diamond.png"),
    std::pair("discord_icon", "discord_icon.png"),
    std::pair("dislike", "dislike.png"),
    std::pair("doodle_drool", "doodle_drool.png"),
    std::pair("doodle_happi", "doodle_happi.png"),
    std::pair("doodle_happi2", "doodle_happi2.png"),
    std::pair("doodle_nerd", "doodle_nerd.png"),
    std::pair("doodle_smile", "doodle_smile.png"),
    std::pair("doodle_think", "doodle_think.png"),
    std::pair("download", "download.png"),
    std::pair("easy", "easy.png"),
    std::pair("easy_curse", "easy_curse.png"),
    std::pair("easy_hapi", "easy_hapi.png"),
    std::pair("elder_mod", "elder_mod.png"),
    std::pair("epic_rate", "epic_rate.png"),
    std::pair("extreme_demon", "extreme_demon.png"),
    std::pair("Extreme_Demon_Think", "Extreme_Demon_Think.png"),
    std::pair("ex_demon_curse", "ex_demon_curse.png"),
    std::pair("ez_demon", "ez_demon.png"),
    std::pair("ez_like", "ez_like.png"),
    std::pair("featured", "featured.png"),
    std::pair("file_list.txt", "file_list.txt.png"),
    std::pair("hard", "hard.png"),
    std::pair("harddemon_grr", "harddemon_grr.png"),
    std::pair("harder", "harder.png"),
    std::pair("harder_curse", "harder_curse.png"),
    std::pair("harder_dislike", "harder_dislike.png"),
    std::pair("heheehe", "heheehe.png"),
    std::pair("info", "info.png"),
    std::pair("insane", "insane.png"),
    std::pair("insane_demon", "insane_demon.png"),
    std::pair("insane_lmao", "insane_lmao.png"),
    std::pair("insane_uhh", "insane_uhh.png"),
    std::pair("jerryosht", "jerryosht.png"),
    std::pair("leaderboard", "leaderboard.png"),
    std::pair("leaderboard_mod", "leaderboard_mod.png"),
    std::pair("legendary_rate", "legendary_rate.png"),
    std::pair("like", "like.png"),
    std::pair("lobotomy_like", "lobotomy_like.png"),
    std::pair("lowtiergod", "lowtiergod.png"),
    std::pair("mcfox_sleep", "mcfox_sleep.png"),
    std::pair("medium_demon", "medium_demon.png"),
    std::pair("mod", "mod.png"),
    std::pair("moderator", "moderator.png"),
    std::pair("moon", "moon.png"),
    std::pair("moyai_icon", "moyai_icon.png"),
    std::pair("mythic_rate", "mythic_rate.png"),
    std::pair("na", "na.png"),
    std::pair("no", "no.png"),
    std::pair("normal", "normal.png"),
    std::pair("normal_curse", "normal_curse.png"),
    std::pair("normal_nerd", "normal_nerd.png"),
    std::pair("normal_ok", "normal_ok.png"),
    std::pair("npestapog", "npestapog.png"),
    std::pair("ohnocringecat", "ohnocringecat.png"),
    std::pair("omg", "omg.png"),
    std::pair("owner", "owner.png"),
    std::pair("partnership_icon", "partnership_icon.png"),
    std::pair("pc", "pc.png"),
    std::pair("peepoaff", "peepoaff.png"),
    std::pair("peepohappy", "peepohappy.png"),
    std::pair("peepohypers", "peepohypers.png"),
    std::pair("pepe_clown", "pepe_clown.png"),
    std::pair("pepe_sad", "pepe_sad.png"),
    std::pair("play", "play.png"),
    std::pair("Pop_cat", "Pop_cat.png"),
    std::pair("sadlol", "sadlol.png"),
    std::pair("sadspongebob", "sadspongebob.png"),
    std::pair("secret_coin", "secret_coin.png"),
    std::pair("silver_coins", "silver_coins.png"),
    std::pair("skull_hd", "skull_hd.png"),
    std::pair("spike", "spike.png"),
    std::pair("staff", "staff.png"),
    std::pair("star2d", "star2d.png"),
    std::pair("starGd", "starGd.png"),
    std::pair("the_rock", "the_rock.png"),
    std::pair("think", "think.png"),
    std::pair("time", "time.png"),
    std::pair("trollface", "trollface.png"),
    std::pair("unmod", "unmod.png"),
    std::pair("vip", "vip.png"),
    std::pair("watermelon", "watermelon.png"),
    std::pair("whatdahell", "whatdahell.png"),
    std::pair("WOAH", "WOAH.png"),
    std::pair("WOOOOW", "WOOOOW.png"),
    std::pair("xD", "xD.png"),
    std::pair("ybangry", "ybangry.png"),
    std::pair("ybangry2", "ybangry2.png"),
    std::pair("ybayo", "ybayo.png"),
    std::pair("ybsunglasses", "ybsunglasses.png"),
    std::pair("yb_facepalm", "yb_facepalm.png"),
    std::pair("yb_ohyou", "yb_ohyou.png"),
    std::pair("yb_point", "yb_point.png"),
    std::pair("yb_robber", "yb_robber.png"),
    std::pair("yb_sad", "yb_sad.png"),
    std::pair("yb_sad2", "yb_sad2.png"),
    std::pair("yb_sleep", "yb_sleep.png"),
    std::pair("yb_smoke", "yb_smoke.png"),
    std::pair("yb_stare", "yb_stare.png"),
    std::pair("yb_sunglasses2", "yb_sunglasses2.png"),
    std::pair("yb_think", "yb_think.png"),
    std::pair("yb_usure", "yb_usure.png"),
    std::pair("yes", "yes.png"),
    std::pair("youtube_icon", "youtube_icon.png"),

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
