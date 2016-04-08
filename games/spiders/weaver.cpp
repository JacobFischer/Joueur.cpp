// Generated by Creer at 11:41PM on April 07, 2016 UTC, git hash: 'e7ec4e35c89d7556b9e07d4331ac34052ac011bd'
// A Spiderling that can alter existing Webs by weaving to add or remove silk from the Webs, thus altering its strength.

#include "weaver.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Weaver::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::Spiderling::deltaUpdateField(fieldName, delta);

    if (fieldName == "strengtheningWeb")
    {
        this->strengtheningWeb = (Spiders::Web*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "weakeningWeb")
    {
        this->weakeningWeb = (Spiders::Web*)this->gameManager->unserializeGameObject(delta);
    }
}



bool Spiders::Weaver::strengthen(Spiders::Web* web)
{
    boost::property_tree::ptree args;
    args.put_child("web", *this->gameManager->serialize(web));

    auto returned = this->gameManager->runOnServer(*this, "strengthen", args);
    return this->gameManager->unserializeBool(*returned);
}

bool Spiders::Weaver::weaken(Spiders::Web* web)
{
    boost::property_tree::ptree args;
    args.put_child("web", *this->gameManager->serialize(web));

    auto returned = this->gameManager->runOnServer(*this, "weaken", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Weaver then you can code them here.
// <<-- /Creer-Merge: methods -->>