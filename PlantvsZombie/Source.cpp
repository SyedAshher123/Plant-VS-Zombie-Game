#include <ctime>
#include <cstdlib>
#include <string>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;




// CARDS**
//  Base class for Plant Cards
class PlantCard
{
protected:
    Texture texture;
    Sprite sprite;

public:
    PlantCard(const string& imagePath)
    {
        if (!texture.loadFromFile(imagePath))
        {
            cerr << "Failed to load image: " << imagePath << endl;
        }
        sprite.setTexture(texture);
    }

    void setPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void draw(RenderWindow& window)
    {
        window.draw(sprite);
    }

    bool isClicked(const Vector2f& mousePos)
    {
        return sprite.getGlobalBounds().contains(mousePos);
    }
};

// Specific Plant Card classes derived from PlantCard
class PeaPlantCard : public PlantCard
{
public:
    PeaPlantCard() : PlantCard("../Images/peashootercard.png") {}
};

class RepeaterPlantCard : public PlantCard
{
public:
    RepeaterPlantCard() : PlantCard("../Images/repeatercard.png") {}
};

class SunflowerCard : public PlantCard
{
public:
    SunflowerCard() : PlantCard("../Images/sunflowercard.png") {}
};

class SnowPeaPlantCard : public PlantCard
{
public:
    SnowPeaPlantCard() : PlantCard("../Images/snowcard.png") {}
};

class WallNutCard : public PlantCard
{
public:
    WallNutCard() : PlantCard("../Images/walknutcard.png") {}
};

class CherryBombCard : public PlantCard
{
public:
    CherryBombCard() : PlantCard("../Images/cherrycard.png") {}
};

class MushroomCard : public PlantCard
{

public:
    MushroomCard() : PlantCard("../Images/mushroomcard.png") {}

};



// CARDS END**
class PlantSprite
{
protected:
    string PlantSprite;
    double Plantposx;
    double Plantposy;

public:
    virtual void setSprite() = 0;
    virtual void setPlantPosx(double) = 0;
    virtual void setPlantPosy(double) = 0;
    virtual float getPlantPosx() = 0;
    virtual float getPlantPosy() = 0;
    virtual void draw(RenderWindow& window) = 0;
    virtual bool isWalnut() = 0;
    virtual void walnutMovement() = 0;
};

class SunflowerSprite : public PlantSprite
{
private:
    Texture sunflowerTexture;
    Sprite sunflowerSprite;

public:

    SunflowerSprite()
    {
        sunflowerTexture.loadFromFile("../Images/sunflower.png");
        sunflowerSprite.setTexture(sunflowerTexture);
    }
    void setSprite()
    {
        sunflowerSprite.setTexture(sunflowerTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        sunflowerSprite.setPosition(Plantposx, Plantposy);
        window.draw(sunflowerSprite);
    }
    bool isWalnut()
    {
        return false;
    }

    void walnutMovement() {
    }

};

class PeaShooterSprite : public PlantSprite
{
private:
    Texture peaShooterTexture;
    Sprite peaShooterSprite;

public:
    PeaShooterSprite()
    {
        peaShooterTexture.loadFromFile("../Images/peashooter.png");
        peaShooterSprite.setTexture(peaShooterTexture);
    }
    void setSprite()
    {
        peaShooterSprite.setTexture(peaShooterTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        peaShooterSprite.setPosition(Plantposx, Plantposy);
        window.draw(peaShooterSprite);
    }
    bool isWalnut()
    {
        return false;
    }

    void walnutMovement() {
    }

};

class SnowPeaShooterSprite : public PlantSprite
{
private:
    Texture snowPeaShooterTexture;
    Sprite snowPeaShooterSprite;

public:
    SnowPeaShooterSprite()
    {
        snowPeaShooterTexture.loadFromFile("../Images/snow.png");
        snowPeaShooterSprite.setTexture(snowPeaShooterTexture);
    }
    void setSprite()
    {
        snowPeaShooterSprite.setTexture(snowPeaShooterTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        snowPeaShooterSprite.setPosition(Plantposx, Plantposy);
        window.draw(snowPeaShooterSprite);
    }
    bool isWalnut()
    {
        return false;
    }
    void walnutMovement() {
    }
};

class WallNutSprite : public PlantSprite
{
private:
    Texture wallNutTexture;
    Sprite wallNutSprite;

public:
    WallNutSprite()
    {
        wallNutTexture.loadFromFile("../Images/walnut.png");
        wallNutSprite.setTexture(wallNutTexture);
    }
    void setSprite()
    {
        wallNutSprite.setTexture(wallNutTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        wallNutSprite.setPosition(Plantposx, Plantposy);
        window.draw(wallNutSprite);
    }
    bool isWalnut()
    {
        return true;
    }

    void walnutMovement()
    {

        Plantposx += 5;
    }


};

class CherryBombSprite : public PlantSprite
{
private:
    Texture cherryBombTexture;
    Sprite cherryBombSprite;

public:
    CherryBombSprite()
    {
        cherryBombTexture.loadFromFile("../Images/cherry.png");
        cherryBombSprite.setTexture(cherryBombTexture);
    }
    void setSprite()
    {
        cherryBombSprite.setTexture(cherryBombTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        cherryBombSprite.setPosition(Plantposx, Plantposy);
        window.draw(cherryBombSprite);
    }

    bool isWalnut()
    {
        return false;
    }
    void walnutMovement() {
    }
};

class MushroomSprite : public PlantSprite
{

private:
    Texture mshroomTexture;
    Sprite mshroomSprite;
public:
    MushroomSprite()
    {
        mshroomTexture.loadFromFile("../Images/fumeshroom.png");
        mshroomSprite.setTexture(mshroomTexture);
    }
    void setSprite()
    {
        mshroomSprite.setTexture(mshroomTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        mshroomSprite.setPosition(Plantposx, Plantposy);
        window.draw(mshroomSprite);
    }
    bool isWalnut()
    {
        return false;
    }
    void walnutMovement() {
    }
};

class RepeaterSprite : public PlantSprite
{
private:
    Texture repeaterTexture;
    Sprite repeaterSprite;

public:
    RepeaterSprite()
    {
        repeaterTexture.loadFromFile("../Images/repeater.png");
        repeaterSprite.setTexture(repeaterTexture);
    }
    void setSprite()
    {
        repeaterSprite.setTexture(repeaterTexture);
    }
    void setPlantPosx(double x)
    {
        Plantposx = x;
    }
    void setPlantPosy(double y)
    {
        Plantposy = y;
    }
    float getPlantPosx()
    {
        return Plantposx;
    }
    float getPlantPosy()
    {
        return Plantposy;
    }
    void draw(RenderWindow& window)
    {
        repeaterSprite.setPosition(Plantposx, Plantposy);
        window.draw(repeaterSprite);
    }

    bool isWalnut()
    {
        return false;
    }

    void walnutMovement() {
    }
};

class Plantdata
{
protected:
    int Health;
    int Damage;
    bool zombieInLane;



public:
    bool plantExist;
    bool posSet;
    bool isCherryBomb;
    bool isMushroom;
    bool isSunflower;
    virtual void killPlant() = 0;
    virtual bool checkPlant() = 0;
    virtual void setHealthPoint(int) = 0;
    virtual void setDamagePoint(int) = 0;
    virtual int getHealthPoint() = 0;
    virtual int getDamagepoint() = 0;
    virtual bool isZombia_Activate(int) = 0;
};

class PeaShooterData : public Plantdata
{

public:
    PeaShooterData()
    {
        Health = 3;
        Damage = 20;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = false;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class SunflowerData : public Plantdata
{
public:
    SunflowerData()
    {
        Health = 3;
        Damage = 0;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = false;
        isSunflower = true;

    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class SnowPeaShooterData : public Plantdata
{
public:
    SnowPeaShooterData()
    {
        Health = 3;
        Damage = 30;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = false;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class WallNutData : public Plantdata
{
public:
    WallNutData()
    {
        Health = 12;
        Damage = 0;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = false;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class CherryBombData : public Plantdata
{
public:
    CherryBombData()
    {
        Health = 3;
        Damage = 100;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = true;
        isMushroom = false;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class MushroomData : public Plantdata
{

public:
    MushroomData()
    {
        Health = 3;
        Damage = 0;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = true;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class RepeaterData : public Plantdata
{
public:
    RepeaterData()
    {
        Health = 3;
        Damage = 40;
        zombieInLane = false;
        plantExist = false;
        posSet = false;
        isCherryBomb = false;
        isMushroom = false;
        isSunflower = false;
    }
    void killPlant()
    {
        Health = 0;
    }
    bool checkPlant()
    {
        return plantExist;
    }
    void setHealthPoint(int health)
    {
        Health += health;
    }
    void setDamagePoint(int damage)
    {
        Damage = damage;
    }
    int getHealthPoint()
    {
        return Health;
    }
    int getDamagepoint()
    {
        return Damage;
    }
    bool isZombia_Activate(int zombia)
    {
        if (zombia == 1)
        {
            zombieInLane = true;
            return true;
        }
        else
        {
            zombieInLane = false;
            return false;
        }
    }
};

class Plantier
{
public:
    virtual PlantSprite* makePlantSprite() = 0;
    virtual Plantdata* makePlantData() = 0;
};

class SunflowerFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new SunflowerSprite();
    }
    Plantdata* makePlantData()
    {
        return new SunflowerData();
    }
};

class PeaShooterFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new PeaShooterSprite();
    }
    Plantdata* makePlantData()
    {
        return new PeaShooterData();
    }
};

class SnowPeaShooterFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new SnowPeaShooterSprite();
    }
    Plantdata* makePlantData()
    {
        return new SnowPeaShooterData();
    }
};

class WallNutFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new WallNutSprite();
    }
    Plantdata* makePlantData()
    {
        return new WallNutData();
    }
};

class CherryBombFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new CherryBombSprite();
    }
    Plantdata* makePlantData()
    {
        return new CherryBombData();
    }
};

class MushroomFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new MushroomSprite();
    }
    Plantdata* makePlantData()
    {
        return new MushroomData();
    }

};

class RepeaterFactory : public Plantier
{

public:
    PlantSprite* makePlantSprite()
    {
        return new RepeaterSprite();
    }
    Plantdata* makePlantData()
    {
        return new RepeaterData();
    }
};

class PlantBiology
{

public:
    PlantSprite* pSprite;
    Plantdata* pData;

    PlantBiology()
    {
        pSprite = nullptr;
        pData = nullptr;
    }
};

class ThePlant
{
public:
    PlantBiology* BirthPlant(Plantier& babyPlant)
    {
        PlantBiology* p = new PlantBiology;
        p->pSprite = babyPlant.makePlantSprite();
        p->pData = babyPlant.makePlantData();
        return p;
    }
};

// Zombie**
class ZombieSprite
{

protected:
    string ZombiePNG;
    float ZombiePosX;
    float ZombiePosY;
    float ZombieSpeed;

public:
    virtual void setZombiePNG(string PNG) = 0;
    virtual string getZombiePNG() = 0;

    virtual void setZombiePosX(float PosX) = 0;
    virtual void setZombiePosY(float PosY) = 0;
    virtual void setZombieSpeed(float Speed) = 0;
    virtual float getZombiePosX() = 0;
    virtual float getZombiePosY() = 0;
    virtual void drawZombie(RenderWindow& window) = 0;
    virtual void zombieMovement(Clock& clock) = 0;
};

class SimpleZombieSprite : public ZombieSprite
{

public:
    SimpleZombieSprite()
    {

        ZombiePNG = "../Images/SimpleZombie.png";
        ZombiePosX = 1900 + 200;

        int random = rand() % 5;

        switch (random)
        {

        case 0:
            ZombiePosY = 150;
            break;

        case 1:
            ZombiePosY = 300;
            break;
        case 2:
            ZombiePosY = 470;
            break;
        case 3:
            ZombiePosY = 620;
            break;
        case 4:
            ZombiePosY = 770;
            break;
        }

        ZombieSpeed = 20;
    }

    void setZombiePNG(string PNG)
    {
        ZombiePNG = PNG;
    }

    string getZombiePNG()
    {
        return ZombiePNG;
    }

    void setZombiePosX(float PosX)
    {
        ZombiePosX = PosX;
    }

    void setZombiePosY(float PosY)
    {
        ZombiePosY = PosY;
    }

    void setZombieSpeed(float Speed)
    {
        ZombieSpeed = Speed;
    }

    float getZombiePosX()
    {
        return ZombiePosX;
    }

    float getZombiePosY()
    {

        return ZombiePosY;
    }

    void drawZombie(RenderWindow& window)
    {

        Image zombie_image;
        zombie_image.loadFromFile(ZombiePNG);
        if (!zombie_image.loadFromFile(ZombiePNG))
        {
            // Error handling: Failed to load image
            cerr << "Failed to load simple zombie image: " << ZombiePNG << endl;
            return; // Return without drawing anything
        }
        Texture zombie;
        if (!zombie.loadFromImage(zombie_image))
        {
            // Error handling: Failed to create texture from image
            cerr << "Failed to create texture from simple zombie image" << endl;
            return; // Return without drawing anything
        }
        zombie.loadFromImage(zombie_image);
        Sprite s_zombie;
        s_zombie.setTexture(zombie);
        s_zombie.setPosition(ZombiePosX, ZombiePosY);
        window.draw(s_zombie);
    }

    void zombieMovement(Clock& clock)
    {
        sf::Time elapsed = clock.restart();
        float distance = ZombieSpeed * elapsed.asSeconds();
        ZombiePosX -= distance;
    }
};

class FlyingZombieSprite : public ZombieSprite
{

public:
    FlyingZombieSprite()
    {

        ZombiePNG = "../Images/FlyingZombie.png";

        ZombiePosX = 1900 + 200;

        int random = rand() % 5;

        switch (random)
        {

        case 0:
            ZombiePosY = 150;
            break;

        case 1:
            ZombiePosY = 300;
            break;
        case 2:
            ZombiePosY = 470;
            break;
        case 3:
            ZombiePosY = 620;
            break;
        case 4:
            ZombiePosY = 770;
            break;
        }

        ZombieSpeed = 25;
    }

    string getZombiePNG()
    {
        return ZombiePNG;
    }

    void setZombiePNG(string PNG)
    {
        ZombiePNG = PNG;
    }

    void setZombiePosX(float PosX)
    {
        ZombiePosX = PosX;
    }

    void setZombiePosY(float PosY)
    {
        ZombiePosY = PosY;
    }

    void setZombieSpeed(float Speed)
    {
        ZombieSpeed = Speed;
    }

    float getZombiePosX()
    {
        return ZombiePosX;
    }

    float getZombiePosY()
    {

        return ZombiePosY;
    }

    void drawZombie(RenderWindow& window)
    {

        Image zombie_image;
        zombie_image.loadFromFile(ZombiePNG);
        if (!zombie_image.loadFromFile(ZombiePNG))
        {
            // Error handling: Failed to load image
            cerr << "Failed to load flying zombie image: " << ZombiePNG << endl;
            return; // Return without drawing anything
        }
        Texture zombie;
        if (!zombie.loadFromImage(zombie_image))
        {
            // Error handling: Failed to create texture from image
            cerr << "Failed to create texture from flying zombie image" << endl;
            return; // Return without drawing anything
        }
        zombie.loadFromImage(zombie_image);
        Sprite s_zombie;
        s_zombie.setTexture(zombie);
        s_zombie.setPosition(ZombiePosX, ZombiePosY);
        window.draw(s_zombie);
    }

    void zombieMovement(Clock& clock)
    {
        sf::Time elapsed = clock.restart();
        float distance = ZombieSpeed * elapsed.asSeconds();
        ZombiePosX -= distance;
    }
};

class FootballZombieSprite : public ZombieSprite
{

public:
    FootballZombieSprite()
    {

        ZombiePNG = "../Images/FootballZombie.png";
        ZombiePosX = 1900 + 200;

        int random = rand() % 5;

        switch (random)
        {

        case 0:
            ZombiePosY = 150;
            break;

        case 1:
            ZombiePosY = 300;
            break;
        case 2:
            ZombiePosY = 470;
            break;
        case 3:
            ZombiePosY = 620;
            break;
        case 4:
            ZombiePosY = 770;
            break;
        }

        ZombieSpeed = 30;
    }

    string getZombiePNG()
    {
        return ZombiePNG;
    }
    void setZombiePNG(string PNG)
    {
        ZombiePNG = PNG;
    }

    void setZombiePosX(float PosX)
    {
        ZombiePosX = PosX;
    }

    void setZombiePosY(float PosY)
    {
        ZombiePosY = PosY;
    }

    void setZombieSpeed(float Speed)
    {
        ZombieSpeed = Speed;
    }

    float getZombiePosX()
    {
        return ZombiePosX;
    }

    float getZombiePosY()
    {

        return ZombiePosY;
    }

    void drawZombie(RenderWindow& window)
    {

        Image zombie_image;
        zombie_image.loadFromFile(ZombiePNG);
        if (!zombie_image.loadFromFile(ZombiePNG))
        {
            // Error handling: Failed to load image
            cerr << "Failed to load football zombie image: " << ZombiePNG << endl;
            return; // Return without drawing anything
        }
        Texture zombie;
        if (!zombie.loadFromImage(zombie_image))
        {
            // Error handling: Failed to create texture from image
            cerr << "Failed to create texture from football zombie image" << endl;
            return; // Return without drawing anything
        }
        zombie.loadFromImage(zombie_image);
        Sprite s_zombie;
        s_zombie.setTexture(zombie);
        s_zombie.setPosition(ZombiePosX, ZombiePosY);
        window.draw(s_zombie);
    }

    void zombieMovement(Clock& clock)
    {
        sf::Time elapsed = clock.restart();
        float distance = ZombieSpeed * elapsed.asSeconds();
        ZombiePosX -= distance;
    }
};

class DancingZombieSprite : public ZombieSprite
{
private:
    float spawnlvl;
    bool direction;
public:
    DancingZombieSprite()
    {

        ZombiePNG = "../Images/DancingZombie.png";
        ZombiePosX = 1900 + 200;

        int random = rand() % 4;

        switch (random)
        {

        case 0:
            ZombiePosY = 150;
            spawnlvl = 150;
            break;

        case 1:
            ZombiePosY = 300;
            spawnlvl = 300;
            break;
        case 2:
            ZombiePosY = 470;
            spawnlvl = 470;
            break;
        case 3:
            ZombiePosY = 620;
            spawnlvl = 620;
            break;
        }

        //ZombiePosY = 470;

        ZombieSpeed = 40;
        direction = true;
    }

    string getZombiePNG()
    {
        return ZombiePNG;
    }

    void setZombiePNG(string PNG)
    {
        ZombiePNG = PNG;
    }

    void setZombiePosX(float PosX)
    {
        ZombiePosX = PosX;
    }

    void setZombiePosY(float PosY)
    {
        ZombiePosY = PosY;
    }

    void setZombieSpeed(float Speed)
    {
        ZombieSpeed = Speed;
    }

    float getZombiePosX()
    {
        return ZombiePosX;
    }

    float getZombiePosY()
    {

        return ZombiePosY;
    }

    void drawZombie(RenderWindow& window)
    {

        Image zombie_image;
        zombie_image.loadFromFile(ZombiePNG);
        if (!zombie_image.loadFromFile(ZombiePNG))
        {
            // Error handling: Failed to load image
            cerr << "Failed to load dancing zombie image: " << ZombiePNG << endl;
            return; // Return without drawing anything
        }
        Texture zombie;
        if (!zombie.loadFromImage(zombie_image))
        {
            // Error handling: Failed to create texture from image
            cerr << "Failed to create texture from dancing zombie image" << endl;
            return; // Return without drawing anything
        }
        zombie.loadFromImage(zombie_image);
        Sprite s_zombie;
        s_zombie.setTexture(zombie);
        s_zombie.setPosition(ZombiePosX, ZombiePosY);
        window.draw(s_zombie);
    }

    void zombieMovement(Clock& clock)
    {

        ZombiePosX -= 1;



        if (spawnlvl == 150) {
            if (direction) {


                ZombiePosY += 2;
            }
            else {

                ZombiePosY -= 2;
            }





            if (ZombiePosY <= 150 || ZombiePosY >= 300) {

                direction = !direction;

            }
        }





        if (spawnlvl == 300) {
            if (direction) {


                ZombiePosY += 2;
            }
            else {

                ZombiePosY -= 2;
            }





            if (ZombiePosY <= 300 || ZombiePosY >= 470) {

                direction = !direction;

            }



        }


        if (spawnlvl == 470) {
            if (direction) {


                ZombiePosY += 2;
            }
            else {

                ZombiePosY -= 2;
            }





            if (ZombiePosY <= 470 || ZombiePosY >= 620) {

                direction = !direction;

            }
        }





        if (spawnlvl == 620) {
            if (direction) {


                ZombiePosY += 2;
            }
            else {

                ZombiePosY -= 2;
            }





            if (ZombiePosY <= 620 || ZombiePosY >= 770) {

                direction = !direction;

            }
        }





    }
};

class DolphinZombieSprite : public ZombieSprite
{

public:
    DolphinZombieSprite()
    {

        ZombiePNG = "../Images/DolphinZombie.png";
        ZombiePosX = 1900 + 200;

        int random = rand() % 5;

        switch (random)
        {

        case 0:
            ZombiePosY = 150;
            break;

        case 1:
            ZombiePosY = 300;
            break;
        case 2:
            ZombiePosY = 470;
            break;
        case 3:
            ZombiePosY = 620;
            break;
        case 4:
            ZombiePosY = 770;
            break;
        }

        ZombieSpeed = 15;
    }

    void setZombiePNG(string PNG)
    {
        ZombiePNG = PNG;
    }
    string getZombiePNG()
    {
        return ZombiePNG;
    }

    void setZombiePosX(float PosX)
    {
        ZombiePosX = PosX;
    }

    void setZombiePosY(float PosY)
    {
        ZombiePosY = PosY;
    }

    void setZombieSpeed(float Speed)
    {
        ZombieSpeed = Speed;
    }

    float getZombiePosX()
    {
        return ZombiePosX;
    }

    float getZombiePosY()
    {

        return ZombiePosY;
    }

    void drawZombie(RenderWindow& window)
    {

        Image zombie_image;
        zombie_image.loadFromFile(ZombiePNG);
        if (!zombie_image.loadFromFile(ZombiePNG))
        {
            // Error handling: Failed to load image
            cerr << "Failed to load dolphin zombie image: " << ZombiePNG << endl;
            return; // Return without drawing anything
        }
        Texture zombie;
        if (!zombie.loadFromImage(zombie_image))
        {
            // Error handling: Failed to create texture from image
            cerr << "Failed to create texture from dolphin zombie image" << endl;
            return; // Return without drawing anything
        }
        zombie.loadFromImage(zombie_image);
        Sprite s_zombie;
        s_zombie.setTexture(zombie);
        s_zombie.setPosition(ZombiePosX, ZombiePosY);
        window.draw(s_zombie);
    }

    void zombieMovement(Clock& clock)
    {
        sf::Time elapsed = clock.restart();
        float distance = ZombieSpeed * elapsed.asSeconds();
        ZombiePosX -= distance;
    }
};

class ZombieData
{

protected:
    float ZombieHealth;
    float ZombieDamage;
    float ZombieSpeedX;
    float ZombieSpeedY;

    //  int timesBulletHit = 0;

public:
    // virtual void BulletHitZombie(Bullet& bullet) = 0;
    // virtual void ZombieHitPlant(PlantBio& plant) = 0;
    // virtual void CarHitZombie(Car& car) = 0;
    // virtual void ZombieMovement() = 0;
    bool isFrozen = false;
    bool ZombieTouchPlant = false;
    bool ZombieTouchWalnut = false;
    int timesBulletHit = 0;
    bool isZombieAlive = true;
    virtual bool DoesZombieExist() = 0;
    virtual void KillZombie() = 0;
    virtual void SetZombieSpeedX() = 0;
    virtual void SetZombieSpeedY() = 0;
    virtual void SetZombieHealth() = 0;
    virtual void SetZombieDamage() = 0;
    virtual float GetZombieHealth() = 0;
    virtual float GetZombieDamage() = 0;
    virtual float GetZombieSpeedX() = 0;
    virtual float GetZombieSpeedY() = 0;
};

class SimpleZombieData : public ZombieData
{

public:
    /*  void BulletHitZombie(Bullet& bullet) {
      ZombieHealth -= bullet.GetBulletDamage();
  }

      void ZombieHitPlant(PlantBio& plant) {
      plant.setHealth(plant.getHealth() - zombieDamage);
  }

      void CarHitZombie(Car& car) {
      ZombieHealth -= car.GetCarDamage();
  }

    / void ZombieMovement() {
      ZombieSpeedX = 0.1;
  }
  */

    bool DoesZombieExist()
    {
        if (ZombieHealth <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void KillZombie()
    {
        ZombieHealth = 0;
    }

    void SetZombieSpeedX()
    {
        ZombieSpeedX = 0.1;
    }

    void SetZombieSpeedY()
    {
        ZombieSpeedY = 0.1;
    }

    void SetZombieHealth()
    {
        ZombieHealth = 100;
    }

    void SetZombieDamage()
    {
        timesBulletHit++;
    }

    float GetZombieHealth()
    {
        return ZombieHealth;
    }

    float GetZombieDamage()
    {
        return timesBulletHit;
    }

    float GetZombieSpeedX()
    {
        return ZombieSpeedX;
    }

    float GetZombieSpeedY()
    {
        return ZombieSpeedY;
    }
};

class FlyingZombieData : public ZombieData
{

public:
    /*
    void BulletHitZombie(Bullet& bullet) {
    ZombieHealth -= bullet.GetBulletDamage();
}

    void ZombiHitPlant(PlantBio& plant) {
    ZombieDamage = plant.GetPlantDamage();
}

    void CarHitZombie(Car& car) {
    ZombieHealth -= car.GetCarDamage();
}

    void ZombieMovement() {
    ZombieSpeedX = 0.1;
*/

    bool DoesZombieExist()
    {
        if (ZombieHealth <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void KillZombie()
    {
        ZombieHealth = 0;
    }

    void SetZombieSpeedX()
    {
        ZombieSpeedX = 0.1;
    }

    void SetZombieSpeedY()
    {
        ZombieSpeedY = 0.1;
    }

    void SetZombieHealth()
    {
        ZombieHealth = 100;
    }

    void SetZombieDamage()
    {
        ZombieDamage = 20;
    }

    float GetZombieHealth()
    {
        return ZombieHealth;
    }

    float GetZombieDamage()
    {
        return ZombieDamage;
    }

    float GetZombieSpeedX()
    {
        return ZombieSpeedX;
    }

    float GetZombieSpeedY()
    {
        return ZombieSpeedY;
    }
};

class FootballZombieData : public ZombieData
{

public:
    /*
    void BulletHitZombie(Bullet& bullet) {
    ZombieHealth -= bullet.GetBulletDamage();
}

    void ZombiHitPlant(PlantBio& plant) {
    ZombieDamage = plant.GetPlantDamage();
}

    void CarHitZombie(Car& car) {
    ZombieHealth -= car.GetCarDamage();
}


    void ZombieMovement() {
    ZombieSpeedX = 0.1;
}
*/
    bool DoesZombieExist()
    {
        if (ZombieHealth <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void KillZombie()
    {
        ZombieHealth = 0;
    }

    void SetZombieSpeedX()
    {
        ZombieSpeedX = 0.1;
    }

    void SetZombieSpeedY()
    {
        ZombieSpeedY = 0.1;
    }

    void SetZombieHealth()
    {
        ZombieHealth = 200;
    }

    void SetZombieDamage()
    {
        ZombieDamage = 30;
    }

    float GetZombieHealth()
    {
        return ZombieHealth;
    }

    float GetZombieDamage()
    {
        return ZombieDamage;
    }

    float GetZombieSpeedX()
    {
        return ZombieSpeedX;
    }

    float GetZombieSpeedY()
    {
        return ZombieSpeedY;
    }
};

class DancingZombieData : public ZombieData
{

public:
    /*
    void BulletHitZombie(Bullet& bullet) {
    ZombieHealth -= bullet.GetBulletDamage();
}

    void ZombiHitPlant(PlantBio& plant) {
    ZombieDamage = plant.GetPlantDamage();
}

    void CarHitZombie(Car& car) {
    ZombieHealth -= car.GetCarDamage();
}

    void ZombieMovement() {
    ZombieSpeedX = 0.1;
}*/

    bool DoesZombieExist()
    {
        if (ZombieHealth <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void KillZombie()
    {
        ZombieHealth = 0;
    }

    void SetZombieSpeedX()
    {
        ZombieSpeedX = 0.1;
    }

    void SetZombieSpeedY()
    {
        ZombieSpeedY = 0.1;
    }

    void SetZombieHealth()
    {
        ZombieHealth = 150;
    }

    void SetZombieDamage()
    {
        ZombieDamage = 40;
    }

    float GetZombieHealth()
    {
        return ZombieHealth;
    }

    float GetZombieDamage()
    {
        return ZombieDamage;
    }

    float GetZombieSpeedX()
    {
        return ZombieSpeedX;
    }

    float GetZombieSpeedY()
    {
        return ZombieSpeedY;
    }
};

class DolphinZombieData : public ZombieData
{

public:
    /*
    void BulletHitZombie(Bullet& bullet) {
    ZombieHealth -= bullet.GetBulletDamage();
}

    void ZombiHitPlant(PlantBio& plant) {
    ZombieDamage = plant.GetPlantDamage();
}

    void CarHitZombie(Car& car) {
    ZombieHealth -= car.GetCarDamage();
}


    void ZombieMovement() {
    ZombieSpeedX = 0.1;
}
*/

    bool DoesZombieExist()
    {
        if (ZombieHealth <= 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    void KillZombie()
    {
        ZombieHealth = 0;
    }

    void SetZombieSpeedX()
    {
        ZombieSpeedX = 0.1;
    }

    void SetZombieSpeedY()
    {
        ZombieSpeedY = 0.1;
    }

    void SetZombieHealth()
    {
        ZombieHealth = 100;
    }

    void SetZombieDamage()
    {
        ZombieDamage = 50;
    }

    float GetZombieHealth()
    {
        return ZombieHealth;
    }

    float GetZombieDamage()
    {
        return ZombieDamage;
    }

    float GetZombieSpeedX()
    {
        return ZombieSpeedX;
    }

    float GetZombieSpeedY()
    {
        return ZombieSpeedY;
    }
};

class ZombieBiology
{
public:
    ZombieSprite* zSprite;
    ZombieData* zData;
    sf::Clock movementClock; // Add a clock for each zombie



    // Constructor
    ZombieBiology() : zSprite(nullptr), zData(nullptr) {}
};

class Zombifier
{

public:
    virtual ZombieSprite* createZombieSprite() = 0;
    virtual ZombieData* createZombieData() = 0;
};

class SimpleZombifier : public Zombifier
{

public:
    ZombieSprite* createZombieSprite()
    {
        return new SimpleZombieSprite();
    }

    ZombieData* createZombieData()
    {
        return new SimpleZombieData();
    }
};

class FlyingZombifier : public Zombifier
{

public:
    ZombieSprite* createZombieSprite()
    {
        return new FlyingZombieSprite();
    }

    ZombieData* createZombieData()
    {
        return new FlyingZombieData();
    }
};

class FootballZombifier : public Zombifier
{

public:
    ZombieSprite* createZombieSprite()
    {
        return new FootballZombieSprite();
    }

    ZombieData* createZombieData()
    {
        return new FootballZombieData();
    }
};

class DancingZombifier : public Zombifier
{

public:
    ZombieSprite* createZombieSprite()
    {
        return new DancingZombieSprite();
    }

    ZombieData* createZombieData()
    {
        return new DancingZombieData();
    }
};

class DolphinZombifier : public Zombifier
{

public:
    ZombieSprite* createZombieSprite()
    {
        return new DolphinZombieSprite();
    }

    ZombieData* createZombieData()
    {
        return new DolphinZombieData();
    }
};

class TheZombie
{

public:
    ZombieBiology* BirthZombie(Zombifier& babyZombie)
    {

        ZombieBiology* zombie = new ZombieBiology();
        zombie->zSprite = babyZombie.createZombieSprite();
        zombie->zData = babyZombie.createZombieData();
        return zombie;
    }
};

class Car
{

private:
    string CarPNG;
    float CarPosX;
    float CarPosY;
    float CarSpeed;
    int CarNumber;
    bool CarExists = true;

public:
    // bool isMoving;

    sf::Clock CarMoveClock;

    Car()
    {

        CarPNG = "../Images/Car.png";

        CarPosX = 300;

        CarSpeed = 100;
    }

    void setCarExists(bool exists)
    {

        CarExists = exists;
    }

    bool getCarExists()
    {

        return CarExists;
    }

    void setCarNumber(int Number)
    {

        CarNumber = Number;
    }

    int getCarNumber()
    {

        return CarNumber;
    }
    void setCarPosX(float PosX)
    {
        CarPosX = PosX;
    }

    void setCarPosY(float PosY)
    {
        CarPosY = PosY;
    }

    void setCarSpeed(float Speed)
    {
        CarSpeed = Speed;
    }

    float getCarPosX()
    {
        return CarPosX;
    }

    float getCarPosY()
    {
        return CarPosY;
    }

    float getCarSpeed()
    {

        return CarSpeed;
    }

    void drawCar(RenderWindow& window)
    {

        if (CarExists)
        {

            Image car_image;
            car_image.loadFromFile(CarPNG);

            Texture car;
            car.loadFromImage(car_image);

            Sprite s_car;
            s_car.setTexture(car);

            s_car.setPosition(CarPosX, CarPosY);

            window.draw(s_car);
        }
    }

    void carMovement(Clock& clock)
    {

        /*sf::Time elapsed = clock.restart();
        float distance = CarSpeed * elapsed.asSeconds();
        CarPosX = CarPosX +  distance;
        cout << "Car is moving..." << endl;*/

        CarPosX += 40;
    }
};
class GameOverSprite
{

protected:
    float GameOverPosX;
    float GameOverPosY;

public:
    GameOverSprite()
    {

        GameOverPosX = 0;
        GameOverPosY = 0;
    }

    void drawGameOver(RenderWindow& window)
    {

        Image gameover_image;
        gameover_image.loadFromFile("../Images/ZombieAte.jpg");

        Texture gameover;
        gameover.loadFromImage(gameover_image);

        Sprite s_gameover;
        s_gameover.setTexture(gameover);

        s_gameover.setPosition(GameOverPosX, GameOverPosY);

        window.draw(s_gameover);
    }
};
// Bullets**
class Bullet
{

protected:
    string BulletPNG;
    float BulletPosX;
    float BulletPosY;
    float BulletSpeed;


public:
    // These two variables are used to return bullet back to its original position after any collision
    float FixBulletPosX;
    float FixBulletPosY;
    bool BulletExists = false;
    int plantsBullet = -1;

    virtual void setBulletPosX(float PosX) = 0;

    virtual void setBulletPosY(float PosY) = 0;

    virtual void setBulletSpeed(float Speed) = 0;

    virtual float getBulletPosX() = 0;

    virtual float getBulletPosY() = 0;

    virtual float getBulletSpeed() = 0;

    virtual void drawBullet(RenderWindow& window) = 0;

    virtual void bulletMovement() = 0;

    virtual string getBulletPNG() = 0;
};

class PeaBullet : public Bullet
{

public:
    PeaBullet()
    {

        BulletPNG = "../Images/peabullet.png";
    }

    void setBulletPosX(float PosX)
    {
        BulletPosX = PosX;
    }

    void setBulletPosY(float PosY)
    {
        BulletPosY = PosY;
    }

    string getBulletPNG()
    {
        return BulletPNG;
    }

    void setBulletSpeed(float Speed)
    {
        BulletSpeed = Speed;
    }

    float getBulletPosX()
    {
        return BulletPosX;
    }

    float getBulletPosY()
    {
        return BulletPosY;
    }

    float getBulletSpeed()
    {
        return BulletSpeed;
    }

    void drawBullet(RenderWindow& window)
    {

        Image bullet_image;
        bullet_image.loadFromFile(BulletPNG);

        Texture bullet;
        bullet.loadFromImage(bullet_image);

        Sprite s_bullet;
        s_bullet.setTexture(bullet);

        s_bullet.setPosition(BulletPosX, BulletPosY);

        window.draw(s_bullet);
    }

    void bulletMovement()
    {

        /*sf::Time elapsed = clock.restart();
        float distance = BulletSpeed * elapsed.asSeconds();
        BulletPosX = BulletPosX + distance;*/
        BulletPosX += 10;
    }
};

class SnowPeaBullet : public Bullet
{

public:
    SnowPeaBullet()
    {

        BulletPNG = "../Images/snowbullet.png";
    }

    void setBulletPosX(float PosX)
    {
        BulletPosX = PosX;
    }

    void setBulletPosY(float PosY)
    {
        BulletPosY = PosY;
    }

    string getBulletPNG()
    {
        return BulletPNG;
    }

    void setBulletSpeed(float Speed)
    {
        BulletSpeed = Speed;
    }

    float getBulletPosX()
    {
        return BulletPosX;
    }

    float getBulletPosY()
    {
        return BulletPosY;
    }

    float getBulletSpeed()
    {
        return BulletSpeed;
    }

    void drawBullet(RenderWindow& window)
    {

        Image bullet_image;
        bullet_image.loadFromFile(BulletPNG);

        Texture bullet;
        bullet.loadFromImage(bullet_image);

        Sprite s_bullet;
        s_bullet.setTexture(bullet);

        s_bullet.setPosition(BulletPosX, BulletPosY);

        window.draw(s_bullet);
    }

    void bulletMovement()
    {

        /*  sf::Time elapsed = clock.restart();
          float distance = BulletSpeed * elapsed.asSeconds();
          BulletPosX = BulletPosX + distance;*/
        BulletPosX += 10;
    }
};

class repeaterBullet : public Bullet
{
public:
    repeaterBullet()
    {

        BulletPNG = "../Images/repeaterbullet.png";
    }

    void setBulletPosX(float PosX)
    {
        BulletPosX = PosX;
    }

    void setBulletPosY(float PosY)
    {
        BulletPosY = PosY;
    }

    void setBulletSpeed(float Speed)
    {
        BulletSpeed = Speed;
    }

    string getBulletPNG()
    {
        return BulletPNG;
    }

    float getBulletPosX()
    {
        return BulletPosX;
    }

    float getBulletPosY()
    {
        return BulletPosY;
    }

    float getBulletSpeed()
    {
        return BulletSpeed;
    }

    void drawBullet(RenderWindow& window)
    {

        Image bullet_image;
        bullet_image.loadFromFile(BulletPNG);

        Texture bullet;
        bullet.loadFromImage(bullet_image);

        Sprite s_bullet;
        s_bullet.setTexture(bullet);

        s_bullet.setPosition(BulletPosX, BulletPosY);

        window.draw(s_bullet);
    }

    void bulletMovement()
    {

        /* sf::Time elapsed = clock.restart();
         float distance = BulletSpeed * elapsed.asSeconds();
         BulletPosX = BulletPosX + distance;*/

        BulletPosX += 10;
    }
};

void createBack(RenderWindow& window)
{
    Image map_image;
    map_image.loadFromFile("../Images/backwindow.jpg");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);
    window.draw(s_map);
}

void createMap(RenderWindow& window)
{
    Image map_image;
    map_image.loadFromFile("../Images/FrontPZ.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);
    window.draw(s_map);
}

void createMenu(RenderWindow& window)
{
    Image menu_image;
    menu_image.loadFromFile("../Images/MenuHD.png");
    Texture menu;
    menu.loadFromImage(menu_image);
    Sprite s_menu;
    s_menu.setTexture(menu);
    s_menu.setPosition(0, 0);
    window.draw(s_menu);
}

void createPause(RenderWindow& window)
{
    Image pause_image;
    pause_image.loadFromFile("../Images/PauseMenu.png");
    Texture pause;
    pause.loadFromImage(pause_image);
    Sprite s_pause;
    s_pause.setTexture(pause);
    s_pause.setPosition(0, 0);
    window.draw(s_pause);
}

void createInstructions(RenderWindow& window)
{
    Image instructions_image;
    instructions_image.loadFromFile("../Images/InstructionsScreen.png");
    Texture instructions;
    instructions.loadFromImage(instructions_image);
    Sprite s_instructions;
    s_instructions.setTexture(instructions);
    s_instructions.setPosition(0, 0);
    window.draw(s_instructions);
}





class ZombieSpawner
{
private:
    Clock* spawnClock;
    float spawnInterval;
    float timeSinceLastSpawn;
    int maxZombies;
    int currentZombies;

public:


    ZombieSpawner(float interval, int maxZombies, Clock& SpawnClock) : spawnInterval(interval), maxZombies(maxZombies)
    {
        srand(time(0)); // Seed random number generator
        spawnClock = &SpawnClock;
        timeSinceLastSpawn = 0.0f;

    }

    bool shouldSpawn()
    {
        timeSinceLastSpawn += spawnClock->restart().asSeconds();
        return (timeSinceLastSpawn >= spawnInterval && currentZombies < maxZombies);
    }

    void resetTimer()
    {
        timeSinceLastSpawn = 0.0f;
    }

    void increaseZombieCount()
    {
        currentZombies++;
    }

    int getCurrentZombies()
    {
        return currentZombies;
    }

    void decreaseZombieCount()
    {
        currentZombies--;
    }
};

class Buttons
{
protected:
    Texture texture;
    Sprite sprite;

public:
    Buttons(const string& imgPath)
    {
        if (!texture.loadFromFile(imgPath))
        {
            cerr << "Failed to load image: " << imgPath << endl;
        }
        sprite.setTexture(texture);
    }

    void setPosition(float x, float y)
    {
        sprite.setPosition(x, y);
    }

    void draw(RenderWindow& window)
    {
        window.draw(sprite);
    }

    bool isClicked(const Vector2f& mousePos)
    {
        return sprite.getGlobalBounds().contains(mousePos);
    }
};

class MenuButton : public Buttons
{
public:
    MenuButton() : Buttons("../Images/MenuButton.png") {}
};

class InstructionsButton : public Buttons
{
public:
    InstructionsButton() : Buttons("../Images/InstructionsButton.png") {}
};

class PauseButton : public Buttons
{
public:
    PauseButton() : Buttons("../Images/PauseButton.png") {}
};

class PlayButton : public Buttons
{

public:
    PlayButton() : Buttons("../Images/playButtonPNG.png") {}
};

class ResumeButtonOfPauseScreen : public Buttons
{

public:
    ResumeButtonOfPauseScreen() : Buttons("../Images/resumemenubutton.png") {}
};
class ResumeButtonOfinstructionScreen : public Buttons
{

public:
    ResumeButtonOfinstructionScreen() : Buttons("../Images/resumemenubutton.png") {}
};
class MenuButtonOfPauseScreen : public Buttons
{

public:
    MenuButtonOfPauseScreen() : Buttons("../Images/menumenubutton.png") {}
};

class PlayButtonOfMenuScreen : public Buttons
{

public:
    PlayButtonOfMenuScreen() : Buttons("../Images/playmenubutton.png") {}
};

class HelpButtonOfMenuScreen : public Buttons {

public: HelpButtonOfMenuScreen() : Buttons("../Images/Help.png") {}
};

class HighScoresButtonOfMenuScreen : public Buttons
{
public: HighScoresButtonOfMenuScreen() : Buttons("../Images/High.png") {}

};


class LevelOneButtonOfMenuScreen : public Buttons
{
public:
    LevelOneButtonOfMenuScreen() : Buttons("../Images/Level1.png") {}

};

class LevelTwoButtonOfMenuScreen : public Buttons
{

public:
    LevelTwoButtonOfMenuScreen() : Buttons("../Images/Level2.png") {}

};

class LevelThreeButtonOfMenuScreen : public Buttons
{

public:
    LevelThreeButtonOfMenuScreen() : Buttons("../Images/Level3.png") {}
};

class LevelFourButtonOfMenuScreen : public Buttons
{

public:
    LevelFourButtonOfMenuScreen() : Buttons("../Images/Level4.png") {}
};


class LevelFiveButtonOfMenuScreen : public Buttons
{

public:
    LevelFiveButtonOfMenuScreen() : Buttons("../Images/Level5.png") {}
};

class LevelSixButtonOfMenuScreen : public Buttons
{

public:
    LevelSixButtonOfMenuScreen() : Buttons("../Images/Level6.png") {}
};

//class Screens
//{
//protected:
//    Texture texture;
//    Sprite sprite;
//
//public:
//    Screens(const string& imgPath)
//    {
//        if (!texture.loadFromFile(imgPath))
//        {
//            cerr << "Failed to load image: " << imgPath << endl;
//        }
//        sprite.setTexture(texture);
//    }
//
//    void setPosition(float x, float y)
//    {
//        sprite.setPosition(x, y);
//    }
//
//    void draw(RenderWindow& window)
//    {
//        window.draw(sprite);
//    }
//
//    bool isClicked(const Vector2f& mousePos)
//    {
//        return sprite.getGlobalBounds().contains(mousePos);
//    }
//};
//
//class MenuScreen : public Screens
//{
//public:
//    MenuScreen() : Screens("../Images/MenuScreen.png") {}
//};
//
//class InstructionsScreen : public Screens
//{
//public:
//    InstructionsScreen() : Screens("../Images/InstructionsScreen.png") {}
//};
//
//class PauseScreen : public Screens
//{
//public:
//    PauseScreen() : Screens("../Images/PauseScreen.png") {}
//};
//
//class HighScoresScreen : public Screens
//{
//public:
//    HighScoresScreen() : Screens("../Images/MenuScreen.png") {}
//};

class SkySuns {

private:

    int SunPosX;
    int SunPosY;
    bool SunExists;
    Clock SunClock;
    Texture SunTexture;
    Sprite SunSprite;




public:
    SkySuns() {

        SunExists = false;
        SunPosX = rand() % 1900 + 200;
        SunPosY = -10;

        SunTexture.loadFromFile("../Images/SkySun.png");
        //Throw an error if the texture is not loaded
        if (!SunTexture.loadFromFile("../Images/SkySun.png")) {

            std::cerr << "Error loading texture" << std::endl;
        }
        SunSprite.setTexture(SunTexture);



    }

    bool SunClicked(RenderWindow& window) {

        Vector2i mousePos = Mouse::getPosition(window);
        Vector2f newPos = window.mapPixelToCoords(mousePos);
        if (SunSprite.getGlobalBounds().contains(newPos)) {
            return true;
        }
        return false;
    }

    void setPosX(int x) {
        SunPosX = x;
    }


    void setPosY(int y) {
        SunPosY = y;
    }

    void setSunExists(bool exists) {
        SunExists = exists;
    }

    int getPosX() {
        return SunPosX;
    }

    int getPosY() {
        return SunPosY;
    }

    bool getSunExists() {
        return SunExists;
    }

    void drawSun(RenderWindow& window) {

        SunSprite.setPosition(SunPosX, SunPosY);
        window.draw(SunSprite);


    }

    void sunMovement() {

        if (SunPosY < 1000) {
            SunPosY += 3;
        }
        else {
            SunExists = false;
        }

    }

};

class SunflowerSun {


private:

    int SunFPosX;
    int SunFPosY;
    bool SunFExists;
    Clock SunFClock;
    Texture SunFTexture;
    Sprite SunFSprite;

public:

    SunflowerSun() {

        SunFExists = false;
        SunFPosX = -100;
        SunFPosY = -100;

        SunFTexture.loadFromFile("../Images/SkySun.png");
        //Throw an error if the texture is not loaded
        if (!SunFTexture.loadFromFile("../Images/SkySun.png")) {

            std::cerr << "Error loading texture" << std::endl;
        }
        SunFSprite.setTexture(SunFTexture);
    }

    bool SunFClicked(RenderWindow& window) {

        Vector2i mousePos = Mouse::getPosition(window);
        Vector2f newPos = window.mapPixelToCoords(mousePos);
        if (SunFSprite.getGlobalBounds().contains(newPos)) {
            return true;
        }
        return false;
    }

    void setPosX(int x) {
        SunFPosX = x;
    }


    void setPosY(int y) {
        SunFPosY = y;
    }
    void setSunFExists(bool exists) {
        SunFExists = exists;
    }

    int getPosX() {
        return SunFPosX;
    }

    int getPosY() {
        return SunFPosY;
    }

    bool getSunFExists() {
        return SunFExists;
    }

    void drawSunF(RenderWindow& window) {

        SunFSprite.setPosition(SunFPosX, SunFPosY);
        window.draw(SunFSprite);
    }



};

class Scoring {
private:
    sf::Font font;
    sf::Text scoringText;
    static int score;

public:
    Scoring() {
        font.loadFromFile("../Fonts/Fixedsys500c.ttf");
        //Throw an error if the font is not loaded
        if (!font.loadFromFile("../Fonts/Fixedsys500c.ttf")) {
            std::cerr << "Error loading font" << std::endl;
        }


        scoringText.setFont(font);
        scoringText.setCharacterSize(40);
        scoringText.setFillColor(sf::Color::Yellow);

        scoringText.setPosition(79, 240);
        updateText();
    }

    void increaseScore(int value) {
        score += value;
        updateText();
    }

    void updateText() {
        scoringText.setString(std::to_string(score));
    }

    void setScore(int value) {
        score = value;
        updateText();
    }

    void draw(sf::RenderWindow& window) {
        window.draw(scoringText);
    }

    Text getScoringText() {
        return scoringText;
    }

    int getScore() {
        return score;
    }
};

int Scoring::score = 25;

class SunSystemPNG {

public:
    Sprite SunSystemSprite;
    Texture SunSystemTexture;

    SunSystemPNG() {
        SunSystemTexture.loadFromFile("../Images/SunSystemPNG.png");
        //Throw an error if the texture is not loaded
        if (!SunSystemTexture.loadFromFile("../Images/SunSystemPNG.png")) {

            std::cerr << "Error loading texture" << std::endl;
        }

        SunSystemSprite.setTexture(SunSystemTexture);
        SunSystemSprite.setPosition(0, 100);
    }

    void drawSunSystem(RenderWindow& window) {


        window.draw(SunSystemSprite);
    }




};

class FireBlast {

public:

    int PosXFire;
    int PosYFire;
    bool FireExists;
    Clock FireClock;
    Texture FireTexture;
    Sprite FireSprite;

    FireBlast() {

        FireExists = false;
        PosXFire = 0;
        PosYFire = 0;

        FireTexture.loadFromFile("../Images/FireBlast.png");
        //Throw an error if the texture is not loaded
        if (!FireTexture.loadFromFile("../Images/FireBlast.png")) {

            std::cerr << "Error loading texture" << std::endl;
        }
        FireSprite.setTexture(FireTexture);
    }


    void drawFire(RenderWindow& window) {

        FireSprite.setPosition(PosXFire, PosYFire);
        window.draw(FireSprite);
    }


    void setPos(int x, int y) {

        PosXFire = x;
        PosYFire = y;
    }




};


class CherryBlast {

public:

    int PosXBlast;
    int PosYBlast;
    bool BlastExists;
    Clock BlastClock;
    Texture BlastTexture;
    Sprite BlastSprite;

    CherryBlast() {

        BlastExists = false;
        PosXBlast = 0;
        PosYBlast = 0;

        BlastTexture.loadFromFile("../Images/boomboom.png");
        //Throw an error if the texture is not loaded
        if (!BlastTexture.loadFromFile("../Images/boomboom.png")) {

            std::cerr << "Error loading texture" << std::endl;
        }
        BlastSprite.setTexture(BlastTexture);
    }


    void drawBlast(RenderWindow& window) {

        BlastSprite.setPosition(PosXBlast, PosYBlast);
        window.draw(BlastSprite);
    }


    void setPos(int x, int y) {

        PosXBlast = x;
        PosYBlast = y;
    }




};




class Fog {

    Image fog_image;
    Texture fog;
    Sprite s_fog;

public:
    Fog() {

        fog_image.loadFromFile("../Images/foggy.png");
        fog.loadFromImage(fog_image);
        s_fog.setTexture(fog);
        s_fog.setPosition(1000, 0);
    }

    void drawFog(RenderWindow& window) {

        window.draw(s_fog);
    }



};

class ScoreManager {
private:
    std::string fileName;

public:
    ScoreManager(const std::string& fileName) : fileName(fileName) {}

    void saveScore(int score) {
        std::ofstream file(fileName, std::ios::app);
        if (file.is_open()) {
            file << score << std::endl;
            file.close();
        }
        else {
            std::cerr << "Error opening file for saving scores." << std::endl;
        }
    }

    void sortScores() {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            std::vector<int> scores;
            while (std::getline(file, line)) {
                scores.push_back(std::stoi(line));
            }
            file.close();

            std::sort(scores.begin(), scores.end(), std::greater<int>());

            std::ofstream outFile(fileName);
            if (outFile.is_open()) {
                for (int score : scores) {
                    outFile << score << std::endl;
                }
                outFile.close();
            }
            else {
                std::cerr << "Error opening file for sorting scores." << std::endl;
            }
        }
        else {
            std::cerr << "Error opening file for reading scores." << std::endl;
        }
    }

    void displayHighScores(int numScores) {
        std::ifstream file(fileName);
        if (file.is_open()) {
            std::string line;
            int count = 0;
            while (std::getline(file, line) && count < numScores) {
                std::cout << line << std::endl;
                count++;
            }
            file.close();
        }
        else {
            std::cerr << "Error opening file for reading high scores." << std::endl;
        }
    }
};

class Level
{
protected:
    int MAX_ZOMBIES;
    int MAX_PLANTS;

    Texture MAP;
    //Clock FREEZE_DELAY;
    int FREEZE_DEALY_INTERVAL = 5;
    int WALNUT_DELAY_INTERVAL = 5;

    int BULLETS_TO_KILL_ZOMBIE;


    int zombieCount = 0;

    ZombieBiology** zomBio = nullptr;
    Zombifier** zombifier = nullptr;
    ZombieSpawner* spawner; // Spawn a zombie every 6 seconds, max 30 zombies
    Clock FreezeDelay;
    Clock WalnutDelay;


    int plantierCount = 0;
    Plantier** plantier = nullptr;
    PlantBiology** PlantBio = nullptr;

    Car** cars = new Car * [5];

    Bullet** bullet = new Bullet * [100];
    int bulletCount = 0;

    Image map_image;


    bool flag = false;

    bool detect1 = false;
    bool detect2 = false;
    bool detect3 = false;
    bool detect4 = false;
    bool detect5 = false;

    int zombiesKilled = 0;

    GameOverSprite gameover;



    FireBlast* fireBlast[100];
    int fireCount;

    CherryBlast* cherryBlast[100];
    int cherryCount;





    void AddPlant(Plantier* plant, Bullet* blt)
    {
        // Create a new instance of PeaShooter plant and add it to the array
        plantier[plantierCount] = plant;
        ThePlant* newPlant = new ThePlant();
        PlantBio[plantierCount] = newPlant->BirthPlant(*plantier[plantierCount]);
        PlantBio[plantierCount]->pSprite->setPlantPosx(-1500); // Off-screen initially
        PlantBio[plantierCount]->pSprite->setPlantPosy(-1500);

        if (blt)
        {
            bullet[bulletCount] = blt;
            bullet[bulletCount]->setBulletPosX(-1500);
            bullet[bulletCount]->setBulletPosY(-1500);
            bullet[bulletCount]->setBulletSpeed(0);
            bulletCount++;
        }
    }

    void placePlant(bool& isFirstClick, bool& bulletDraw, Vector2f mousePos)
    {
        int gridX = (mousePos.x - 244) / 106;
        int gridY = (mousePos.y - 180) / 160;

        if (gridX >= 2 && gridX < 10 && gridY >= 0 && gridY < 5)
        {                              // Check if within grid bounds
            bool canPlacePlant = true; // Flag to check if a plant can be placed

            // Check if there is any previous plant at the same position
            if (gridY == 0)
            {
                for (int i = 0; i < plantierCount - 1; i++)
                {
                    if (PlantBio[i]->pData->posSet && PlantBio[i]->pSprite->getPlantPosx() == (244 + gridX * 106) && PlantBio[i]->pSprite->getPlantPosy() == 150)
                    {
                        canPlacePlant = false; // Another plant exists at the same position
                        break;
                    }
                }
            }
            if (gridY == 1)
            {
                for (int i = 0; i < plantierCount - 1; i++)
                {
                    if (PlantBio[i]->pData->posSet && PlantBio[i]->pSprite->getPlantPosx() == (244 + gridX * 106) && PlantBio[i]->pSprite->getPlantPosy() == 300)
                    {
                        canPlacePlant = false; // Another plant exists at the same position
                        break;
                    }
                }
            }

            if (gridY == 2)
            {
                for (int i = 0; i < plantierCount - 1; i++)
                {
                    if (PlantBio[i]->pData->posSet && PlantBio[i]->pSprite->getPlantPosx() == (244 + gridX * 106) && PlantBio[i]->pSprite->getPlantPosy() == 470)
                    {
                        canPlacePlant = false; // Another plant exists at the same position
                        break;
                    }
                }
            }

            if (gridY == 3)
            {
                for (int i = 0; i < plantierCount - 1; i++)
                {
                    if (PlantBio[i]->pData->posSet && PlantBio[i]->pSprite->getPlantPosx() == (244 + gridX * 106) && PlantBio[i]->pSprite->getPlantPosy() == 620)
                    {
                        canPlacePlant = false; // Another plant exists at the same position
                        break;
                    }
                }
            }

            if (gridY == 4)
            {
                for (int i = 0; i < plantierCount - 1; i++)
                {
                    if (PlantBio[i]->pData->posSet && PlantBio[i]->pSprite->getPlantPosx() == (244 + gridX * 106) && PlantBio[i]->pSprite->getPlantPosy() == 770)
                    {
                        canPlacePlant = false; // Another plant exists at the same position
                        break;
                    }
                }
            }

            if (canPlacePlant == true)
            {
                if (PlantBio[plantierCount - 1]->pData->posSet == false)
                {
                    // Update position of the selected plant based on the grid position
                    PlantBio[plantierCount - 1]->pSprite->setPlantPosx(244 + gridX * 106);
                    if (gridY == 0)
                    {
                        PlantBio[plantierCount - 1]->pSprite->setPlantPosy(150);
                    }
                    if (gridY == 1)
                    {
                        PlantBio[plantierCount - 1]->pSprite->setPlantPosy(300);
                    }
                    if (gridY == 2)
                    {
                        PlantBio[plantierCount - 1]->pSprite->setPlantPosy(470);
                    }
                    if (gridY == 3)
                    {
                        PlantBio[plantierCount - 1]->pSprite->setPlantPosy(620);
                    }
                    if (gridY == 4)
                    {
                        PlantBio[plantierCount - 1]->pSprite->setPlantPosy(770);
                    }

                    PlantBio[plantierCount - 1]->pData->posSet = true;
                    PlantBio[plantierCount - 1]->pData->plantExist = true;

                    if (bulletDraw == true)
                    {
                        bullet[bulletCount - 1]->setBulletPosX(244 + gridX * 106);
                        bullet[bulletCount - 1]->FixBulletPosX = 244 + gridX * 106;
                        if (gridY == 0)
                        {
                            bullet[bulletCount - 1]->setBulletPosY(150);
                            bullet[bulletCount - 1]->FixBulletPosY = 150;
                        }
                        if (gridY == 1)
                        {
                            bullet[bulletCount - 1]->setBulletPosY(300);
                            bullet[bulletCount - 1]->FixBulletPosY = 300;
                        }
                        if (gridY == 2)
                        {
                            bullet[bulletCount - 1]->setBulletPosY(470);
                            bullet[bulletCount - 1]->FixBulletPosY = 470;
                        }
                        if (gridY == 3)
                        {
                            bullet[bulletCount - 1]->setBulletPosY(620);
                            bullet[bulletCount - 1]->FixBulletPosY = 620;
                        }
                        if (gridY == 4)
                        {
                            bullet[bulletCount - 1]->setBulletPosY(770);
                            bullet[bulletCount - 1]->FixBulletPosY = 770;
                        }

                        bullet[bulletCount - 1]->setBulletSpeed(100);
                        bullet[bulletCount - 1]->BulletExists = true;
                        bullet[bulletCount - 1]->plantsBullet = plantierCount - 1;

                        bulletDraw = false;
                    }

                    isFirstClick = true; // Reset for next selection
                    // selectedPlantIndex = -1; // Reset selected plant index
                    cout << "Plant spawned at position (" << gridX << ", " << gridY << ")" << endl;
                }
            }
        }
    }

    void initPlants()
    {
        plantier = new Plantier * [100];
        PlantBio = new PlantBiology * [100];

        for (int i = 0; i < MAX_PLANTS; i++)
        {
            PlantBio[MAX_PLANTS] = { nullptr };
        }
    }

    void initCars()
    {
        for (int i = 0; i < 5; i++)
        {
            cars[i] = new Car();
        }

        for (int i = 0; i < 5; i++)
        {
            cars[i]->setCarNumber(i + 1);
        }

        for (int i = 0; i < 5; i++)
        {
            if (cars[i]->getCarNumber() == 1)
            {
                cars[i]->setCarPosY(150);
            }
            else if (cars[i]->getCarNumber() == 2)
            {
                cars[i]->setCarPosY(300); // Adjust Y position accordingly
            }
            else if (cars[i]->getCarNumber() == 3)
            {
                cars[i]->setCarPosY(470);
            }
            else if (cars[i]->getCarNumber() == 4)
            {
                cars[i]->setCarPosY(620);
            }
            else if (cars[i]->getCarNumber() == 5)
            {
                cars[i]->setCarPosY(770); // Adjust Y position accordingly
            }
        }
    }

    void createMap(RenderWindow& window)
    {
        Texture map;
        map.loadFromImage(map_image);
        Sprite s_map;
        s_map.setTexture(map);
        s_map.setPosition(0, 0);
        window.draw(s_map);
    }

public:
    Level()
    {
    }

    Clock SunSpawnClock;

    Clock SunflowerSunSpawnClock;


    SkySuns sunfall;

    SunflowerSun sunflower;


    Scoring Currency;



    SunSystemPNG sunSystem;

    virtual void initZombies() = 0;
    virtual void initGui() = 0;
    virtual void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw) = 0;
    virtual void drawLevelGui(RenderWindow& window) = 0;

    bool isLevelComplete()
    {
        return zombiesKilled >= MAX_ZOMBIES;
    }

    bool ishighScore() {
        return flag;
    }

    virtual void updateZombies(RenderWindow& window)
    {
        if (spawner->shouldSpawn())
        {
            cout << "Spawning zombie..." << endl;
            int TheSpawnNumber = rand() % 4;
            for (int i = 0; i < TheSpawnNumber; i++)
            {
                if (zombieCount < MAX_ZOMBIES)
                {
                    cout << "SPAWNED ZOMBIE" << endl;
                    TheZombie* newZombie = new TheZombie();
                    zomBio[zombieCount] = newZombie->BirthZombie(*zombifier[i]);
                    zombieCount++;
                    spawner->increaseZombieCount();
                }
                else
                {
                    break;
                }
            }
            spawner->resetTimer();
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true)
            {
                if (zomBio[i]->zSprite->getZombiePosX() <= 400)
                {

                    if (zomBio[i]->zSprite->getZombiePosY() == 150 && detect1 == false)
                    {
                        detect1 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 300 && detect2 == false)
                    {
                        detect2 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 470 && detect3 == false)
                    {
                        detect3 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 620 && detect4 == false)
                    {
                        detect4 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 770 && detect5 == false)
                    {
                        detect5 = true;
                    }
                }
            }
        }

        for (int i = 0; i < bulletCount; i++)
        {
            for (int j = 0; j < zombieCount; j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (bullet[i]->FixBulletPosX < zomBio[j]->zSprite->getZombiePosX())
                    {
                        if (bullet[i]->getBulletPosX() >= zomBio[j]->zSprite->getZombiePosX() && bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY())
                        {

                            std::cout << "Bullet hit zombie" << endl;
                            if (bullet[i]->getBulletPNG() == "../Images/snowbullet.png")
                            {
                                zomBio[j]->zData->isFrozen = true;
                                std::cout << "Zombie is frozen" << endl;

                                if (bullet[i]->getBulletPosX() >= zomBio[j]->zSprite->getZombiePosX() && bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY())
                                {

                                    FreezeDelay.restart();
                                }
                            }

                            bullet[i]->setBulletPosX(bullet[i]->FixBulletPosX);
                            bullet[i]->setBulletPosY(bullet[i]->FixBulletPosY);


                            if (bullet[i]->getBulletPNG() == "../Images/repeaterbullet.png") {
                                zomBio[j]->zData->timesBulletHit += 2;

                            }
                            else
                            {
                                zomBio[j]->zData->timesBulletHit += 1;
                            }

                            // cout << "Times bullet hit zombie: " << zomBio[j]->zData->timesBulletHit << endl;
                            if (zomBio[j]->zData->timesBulletHit >= BULLETS_TO_KILL_ZOMBIE)
                            {
                                zomBio[j]->zData->isZombieAlive = false;
                                zombiesKilled++;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->isFrozen == true)
            {

                // zomBio[i]->zSprite->setZombiePNG("../Images/FrozenZombie.png");
                zomBio[i]->zSprite->drawZombie(window);
                cout << FreezeDelay.getElapsedTime().asSeconds() << endl;

                if (FreezeDelay.getElapsedTime().asSeconds() >= FREEZE_DEALY_INTERVAL)
                {

                    zomBio[i]->zData->isFrozen = false;
                    cout << "Zombie is no longer frozen" << endl;
                    // zomBio[i]->zSprite->setZombiePNG("../Images/SimpleZombie.png");

                    FreezeDelay.restart();
                }
            }
        }


        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->ZombieTouchWalnut == true)
            {

                if (WalnutDelay.getElapsedTime().asSeconds() >= WALNUT_DELAY_INTERVAL)
                {

                    zomBio[i]->zData->ZombieTouchWalnut = false;
                    cout << "Zombie is no longer walnut toucher" << endl;

                    WalnutDelay.restart();
                }
            }
        }






        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (zomBio[j]->zData->isZombieAlive == true) {
                    if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                        if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 70) {

                            if (zomBio[j]->zSprite->getZombiePosX() + 20 >= PlantBio[i]->pSprite->getPlantPosx() + 70) {
                                PlantBio[i]->pData->setHealthPoint(-1);
                                zomBio[j]->zSprite->setZombiePosX(zomBio[j]->zSprite->getZombiePosX() + 25);
                            }

                        }
                        // cout << "Plant health: " << PlantBio[i]->pData->getHealthPoint() << endl;
                        if (PlantBio[i]->pData->getHealthPoint() == 0) {

                            PlantBio[i]->pData->plantExist = false;
                            PlantBio[i]->pSprite->setPlantPosx(-1500);
                            PlantBio[i]->pSprite->setPlantPosy(-1500);
                            PlantBio[i]->pData->posSet = false;


                            for (int k = 0; k < bulletCount; k++) {
                                if (bullet[k]->plantsBullet == i) {
                                    bullet[k]->BulletExists = false;
                                    bullet[k]->setBulletPosX(-1500);
                                    bullet[k]->setBulletPosY(-1500);
                                }
                            }



                        }
                    }
                }



            }

        }











        // Update and render zombies
        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->isFrozen == false && zomBio[i]->zData->ZombieTouchWalnut == false)
            {
                zomBio[i]->zSprite->zombieMovement(zomBio[i]->movementClock);
                // Render zombie
                //zomBio[i]->zSprite->drawZombie(window);
            }
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true)
            {

                zomBio[i]->zSprite->drawZombie(window);


            }
        }






        // bullet movement and reapper after moving out of bounds
        for (int i = 0; i < bulletCount; i++)
        {
            if (bullet[i]->getBulletPosX() > 1900)
            {

                bullet[i]->setBulletPosX(bullet[i]->FixBulletPosX);
                bullet[i]->setBulletPosY(bullet[i]->FixBulletPosY);
                // bullet[i]->setBulletSpeed(0);
            }
        }

        for (int i = 0; i < bulletCount; i++)
        {
            for (int j = 0; j < zombieCount; j++)
            {
                if (bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY() && zomBio[j]->zSprite->getZombiePosX() <= 1850)
                {
                    if (zomBio[j]->zData->isZombieAlive == true)
                    {
                        if (bullet[i]->BulletExists == true) {

                            bullet[i]->drawBullet(window);
                            bullet[i]->bulletMovement();
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < plantierCount; i++)
        {
            PlantBio[i]->pSprite->draw(window);

            if (PlantBio[i]->pSprite->isWalnut()) {
                PlantBio[i]->pSprite->walnutMovement();


            }
        }


        for (int i = 0; i < fireCount; i++) {

            if (fireBlast[i]->FireExists == true && fireBlast[i]->FireClock.getElapsedTime().asSeconds() < 1.5) {

                fireBlast[i]->drawFire(window);

            }
        }

        for (int i = 0; i < fireCount; i++) {

            if (fireBlast[i]->FireExists == true && fireBlast[i]->FireClock.getElapsedTime().asSeconds() >= 1.5) {

                fireBlast[i]->FireExists = false;
            }
        }

        ////////////////

        for (int i = 0; i < cherryCount; i++) {

            if (cherryBlast[i]->BlastExists == true && cherryBlast[i]->BlastClock.getElapsedTime().asSeconds() < 1.5) {

                cherryBlast[i]->drawBlast(window);

            }
        }

        for (int i = 0; i < cherryCount; i++) {

            if (cherryBlast[i]->BlastExists == true && cherryBlast[i]->BlastClock.getElapsedTime().asSeconds() >= 1.5) {

                cherryBlast[i]->BlastExists = false;
            }
        }




        for (int i = 0; i < 5; i++)
        {

            cars[i]->drawCar(window);
        }

        if (detect1 == true)
        {

            cars[0]->carMovement(cars[0]->CarMoveClock);
            cars[0]->drawCar(window);
            for (int j = 0; j < zombieCount; j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {

                    if (zomBio[j]->zSprite->getZombiePosY() == 150)
                    {
                        if (cars[0]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[0]->getCarExists() == true)
                        {

                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect2 == true)
        {
            cars[1]->carMovement(cars[1]->CarMoveClock);
            cars[1]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 300)
                    {
                        if (cars[1]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[1]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect3 == true)
        {

            cars[2]->carMovement(cars[2]->CarMoveClock);
            cars[2]->drawCar(window);
            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 470)
                    {
                        if (cars[2]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[2]->getCarExists() == true)
                        {

                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect4 == true)
        {

            cars[3]->carMovement(cars[3]->CarMoveClock);
            cars[3]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 620)
                    {
                        if (cars[3]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[3]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect5 == true)
        {

            cars[4]->carMovement(cars[4]->CarMoveClock);
            cars[4]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 770)
                    {
                        if (cars[4]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[4]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {

            if (cars[i]->getCarPosX() > 1800)
            {
                cars[i]->setCarExists(false);
                cars[i]->setCarPosX(-1500);
            }
        }

        for (int i = 0; i < zombieCount; i++)
        {

            if (zomBio[i]->zSprite->getZombiePosX() <= 300)
            {

                flag = true;
            }
        }

        if (flag)
        {
            gameover.drawGameOver(window);
        }


        window.display();
    }

    virtual void chwerryExplosion() {

        cout << "Base Class" << endl;
    }
    virtual void MushroomSpray() {

        cout << "Base Class" << endl;
    }
    virtual void StopTheZombie() {

        cout << "Base Class" << endl;
    }





};

class BeginnersGarden : public Level
{
private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    Clock ZombieSpawnClock;



public:
    int checkdeleteSun;
    bool checkSun;
    BeginnersGarden()
    {
        MAX_ZOMBIES = 7;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/FrontPZ.png");

        initGui();
        initCars();
        initPlants();
        initZombies();

        spawner = new ZombieSpawner(5.0f, MAX_ZOMBIES, ZombieSpawnClock);
        Currency.setScore(25);
    }

    ~BeginnersGarden()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;


    }

    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];

        // Only Simple zombies in first level
        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            zombifier[i] = new SimpleZombifier();
        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100)
                {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }



            }
            else if (sunflowerCard.isClicked(mousePos))
            {

                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }

            }
        }
        else
        { // Second click logic
            // Calculate grid position based on mouse position
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }
    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);

        sunSystem.drawSunSystem(window);

        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }



        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];



            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 7 && sunflower.getSunFExists() == false)
            {
                if (PlantBio[randomIndex]->pData->plantExist == true)
                {
                    sunflower.setSunFExists(true);
                    sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                    sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                    checkdeleteSun = randomIndex;
                    checkSun == true;
                }

            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);

            }

        }
        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    // cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }


        if (SunSpawnClock.getElapsedTime().asSeconds() >= 8 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);





    }
};


class ZombieOutskirts : public Level
{
private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    WallNutCard wallNutCard;

    Clock ZombieSpawnClock;


public:
    int checkdeleteSun;
    bool checkSun;
    ZombieOutskirts()
    {
        MAX_ZOMBIES = 10;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/ZombieOutskirts.png");

        initGui();
        initCars();
        initPlants();
        initZombies();



        spawner = new ZombieSpawner(6.0f, MAX_ZOMBIES, ZombieSpawnClock);
    }

    ~ZombieOutskirts()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;
    }

    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];

        // Only Simple zombies & football
        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            int random = rand() % 4;
            switch (random)
            {
            case 0:
                zombifier[i] = new SimpleZombifier();
                break;
            case 1:
                zombifier[i] = new FootballZombifier();
                break;
            case 2:
                zombifier[i] = new FlyingZombifier();
                break;
            case 3:
                zombifier[i] = new DolphinZombifier();
                break;
            }

        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
        wallNutCard.setPosition(230.0f, 10.0f);
        //cherryBombCard.setPosition(560.0f, 10.0f);
        //repeaterPlantCard.setPosition(560.0f, 10.0f);

    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100) {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }

            }
            else if (sunflowerCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }


            }
            else if (wallNutCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 50) {
                    Currency.increaseScore(-50);
                    this->AddPlant(new WallNutFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Wall Nut Plant Card clicked!" << endl;
                }

            }
        }
        else
        { // Second click logic
            // Calculate grid position based on mouse position
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }
    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);
        wallNutCard.draw(window);


        sunSystem.drawSunSystem(window);

        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }


        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];
            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 6 && sunflower.getSunFExists() == false)
            {
                sunflower.setSunFExists(true);
                sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                checkdeleteSun = randomIndex;
                checkSun = true;

            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);
            }

        }

        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }

        if (SunSpawnClock.getElapsedTime().asSeconds() >= 6 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);




    }





    void StopTheZombie() {

        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (PlantBio[i]->pData->plantExist == true && PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY() && PlantBio[i]->pSprite->getPlantPosx() + 50 >= zomBio[j]->zSprite->getZombiePosX() && PlantBio[i]->pSprite->isWalnut() == true) {
                    zomBio[j]->zData->ZombieTouchWalnut = true;
                    WalnutDelay.restart();
                    cout << "Zombie Touch Walnut" << endl;
                }
            }
        }

    }

};
class SunFlowerFields : public Level
{

private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    WallNutCard wallNutCard;
    RepeaterPlantCard repeaterPlantCard;
    Clock ZombieSpawnClock;


public:
    int checkdeleteSun;
    bool checkSun;
    SunFlowerFields()
    {
        MAX_ZOMBIES = 14;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/SunFlowerFields.jpg");

        initGui();
        initCars();
        initPlants();
        initZombies();



        spawner = new ZombieSpawner(6.0f, MAX_ZOMBIES, ZombieSpawnClock);
    }

    ~SunFlowerFields()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;
    }

    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];


        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            int random = rand() % 4;
            switch (random)
            {
            case 0:
                zombifier[i] = new SimpleZombifier();
                break;
            case 1:
                zombifier[i] = new FootballZombifier();
                break;

            case 2:
                zombifier[i] = new FlyingZombifier();
                break;
            case 3:
                zombifier[i] = new DolphinZombifier();
                break;

            }


        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
        wallNutCard.setPosition(230.0f, 10.0f);
        repeaterPlantCard.setPosition(340.0f, 10.0f);



        //  wallNutCard.setPosition(230.0f, 10.0f);
          //repeaterPlantCard.setPosition(560.0f, 10.0f);
    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100) {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }
            }
            else if (sunflowerCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }

            }

            else if (wallNutCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 50)
                {
                    Currency.increaseScore(-50);
                    this->AddPlant(new WallNutFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Wall Nut Plant Card clicked!" << endl;
                }

            }

            else if (repeaterPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 200) {
                    Currency.increaseScore(-200);
                    this->AddPlant(new RepeaterFactory, new repeaterBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Repeater Plant Card clicked!" << endl;
                }

            }




        }
        else
        { // Second click logic
            // Calculate grid position based on mouse position
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }

    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);

        wallNutCard.draw(window);
        repeaterPlantCard.draw(window);



        sunSystem.drawSunSystem(window);

        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }


        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];
            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 5 && sunflower.getSunFExists() == false)
            {
                sunflower.setSunFExists(true);
                sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                checkdeleteSun = randomIndex;
                checkSun = true;
            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);
            }

        }

        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    // cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }

        if (SunSpawnClock.getElapsedTime().asSeconds() >= 7 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);





    }



    void StopTheZombie() {

        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY() && PlantBio[i]->pSprite->getPlantPosx() + 10 == zomBio[j]->zSprite->getZombiePosX() && PlantBio[i]->pSprite->isWalnut() == true) {
                    zomBio[j]->zData->ZombieTouchWalnut = true;
                    WalnutDelay.restart();
                    cout << "Zombie Touch Walnut" << endl;


                }
            }
        }

    }

};


class FoggyForest : public Level
{

private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    WallNutCard wallNutCard;
    RepeaterPlantCard repeaterPlantCard;

    MushroomCard mushroomCard;
    CherryBombCard cherryBombCard;
    Clock ZombieSpawnClock;

    Fog foggy;


public:
    int checkdeleteSun;
    bool checkSun;
    FoggyForest()
    {
        MAX_ZOMBIES = 14;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/Nightfrontyard.png");

        initGui();
        initCars();
        initPlants();
        initZombies();



        spawner = new ZombieSpawner(6.0f, MAX_ZOMBIES, ZombieSpawnClock);
    }

    ~FoggyForest()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;
    }
    void updateZombies(RenderWindow& window)
    {
        if (spawner->shouldSpawn())
        {
            cout << "Spawning zombie..." << endl;
            int TheSpawnNumber = rand() % 4;
            for (int i = 0; i < TheSpawnNumber; i++)
            {
                if (zombieCount < MAX_ZOMBIES)
                {
                    cout << "SPAWNED ZOMBIE" << endl;
                    TheZombie* newZombie = new TheZombie();
                    zomBio[zombieCount] = newZombie->BirthZombie(*zombifier[i]);
                    zombieCount++;
                    spawner->increaseZombieCount();
                }
                else
                {
                    break;
                }
            }
            spawner->resetTimer();
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true)
            {
                if (zomBio[i]->zSprite->getZombiePosX() <= 400)
                {

                    if (zomBio[i]->zSprite->getZombiePosY() == 150 && detect1 == false)
                    {
                        detect1 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 300 && detect2 == false)
                    {
                        detect2 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 470 && detect3 == false)
                    {
                        detect3 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 620 && detect4 == false)
                    {
                        detect4 = true;
                    }
                    if (zomBio[i]->zSprite->getZombiePosY() == 770 && detect5 == false)
                    {
                        detect5 = true;
                    }
                }
            }
        }

        for (int i = 0; i < bulletCount; i++)
        {
            for (int j = 0; j < zombieCount; j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (bullet[i]->FixBulletPosX < zomBio[j]->zSprite->getZombiePosX())
                    {
                        if (bullet[i]->getBulletPosX() >= zomBio[j]->zSprite->getZombiePosX() && bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY())
                        {

                            std::cout << "Bullet hit zombie" << endl;
                            if (bullet[i]->getBulletPNG() == "../Images/snowbullet.png")
                            {
                                zomBio[j]->zData->isFrozen = true;
                                std::cout << "Zombie is frozen" << endl;

                                if (bullet[i]->getBulletPosX() >= zomBio[j]->zSprite->getZombiePosX() && bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY())
                                {

                                    FreezeDelay.restart();
                                }
                            }

                            bullet[i]->setBulletPosX(bullet[i]->FixBulletPosX);
                            bullet[i]->setBulletPosY(bullet[i]->FixBulletPosY);


                            if (bullet[i]->getBulletPNG() == "../Images/repeaterbullet.png") {
                                zomBio[j]->zData->timesBulletHit += 2;

                            }
                            else
                            {
                                zomBio[j]->zData->timesBulletHit += 1;
                            }

                            // cout << "Times bullet hit zombie: " << zomBio[j]->zData->timesBulletHit << endl;
                            if (zomBio[j]->zData->timesBulletHit >= BULLETS_TO_KILL_ZOMBIE)
                            {
                                zomBio[j]->zData->isZombieAlive = false;
                                zombiesKilled++;
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->isFrozen == true)
            {

                // zomBio[i]->zSprite->setZombiePNG("../Images/FrozenZombie.png");
                zomBio[i]->zSprite->drawZombie(window);
                cout << FreezeDelay.getElapsedTime().asSeconds() << endl;

                if (FreezeDelay.getElapsedTime().asSeconds() >= FREEZE_DEALY_INTERVAL)
                {

                    zomBio[i]->zData->isFrozen = false;
                    cout << "Zombie is no longer frozen" << endl;
                    // zomBio[i]->zSprite->setZombiePNG("../Images/SimpleZombie.png");

                    FreezeDelay.restart();
                }
            }
        }


        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->ZombieTouchWalnut == true)
            {

                if (WalnutDelay.getElapsedTime().asSeconds() >= WALNUT_DELAY_INTERVAL)
                {

                    zomBio[i]->zData->ZombieTouchWalnut = false;
                    cout << "Zombie is no longer walnut toucher" << endl;

                    WalnutDelay.restart();
                }
            }
        }






        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (zomBio[j]->zData->isZombieAlive == true) {
                    if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                        if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 70) {

                            if (zomBio[j]->zSprite->getZombiePosX() + 20 >= PlantBio[i]->pSprite->getPlantPosx() + 70) {
                                PlantBio[i]->pData->setHealthPoint(-1);
                                zomBio[j]->zSprite->setZombiePosX(zomBio[j]->zSprite->getZombiePosX() + 25);
                            }

                        }
                        // cout << "Plant health: " << PlantBio[i]->pData->getHealthPoint() << endl;
                        if (PlantBio[i]->pData->getHealthPoint() == 0) {

                            PlantBio[i]->pData->plantExist = false;
                            PlantBio[i]->pSprite->setPlantPosx(-1500);
                            PlantBio[i]->pSprite->setPlantPosy(-1500);
                            PlantBio[i]->pData->posSet = false;


                            for (int k = 0; k < bulletCount; k++) {
                                if (bullet[k]->plantsBullet == i) {
                                    bullet[k]->BulletExists = false;
                                    bullet[k]->setBulletPosX(-1500);
                                    bullet[k]->setBulletPosY(-1500);
                                }
                            }



                        }
                    }
                }



            }

        }











        // Update and render zombies
        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true && zomBio[i]->zData->isFrozen == false && zomBio[i]->zData->ZombieTouchWalnut == false)
            {
                zomBio[i]->zSprite->zombieMovement(zomBio[i]->movementClock);
                // Render zombie
                //zomBio[i]->zSprite->drawZombie(window);
            }
        }

        for (int i = 0; i < zombieCount; i++)
        {
            if (zomBio[i]->zData->isZombieAlive == true)
            {

                zomBio[i]->zSprite->drawZombie(window);


            }
        }






        // bullet movement and reapper after moving out of bounds
        for (int i = 0; i < bulletCount; i++)
        {
            if (bullet[i]->getBulletPosX() > 1900)
            {

                bullet[i]->setBulletPosX(bullet[i]->FixBulletPosX);
                bullet[i]->setBulletPosY(bullet[i]->FixBulletPosY);
                // bullet[i]->setBulletSpeed(0);
            }
        }

        for (int i = 0; i < bulletCount; i++)
        {
            for (int j = 0; j < zombieCount; j++)
            {
                if (bullet[i]->FixBulletPosY == zomBio[j]->zSprite->getZombiePosY() && zomBio[j]->zSprite->getZombiePosX() <= 1850)
                {
                    if (zomBio[j]->zData->isZombieAlive == true)
                    {
                        if (bullet[i]->BulletExists == true) {

                            bullet[i]->drawBullet(window);
                            bullet[i]->bulletMovement();
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < plantierCount; i++)
        {
            PlantBio[i]->pSprite->draw(window);

            if (PlantBio[i]->pSprite->isWalnut()) {
                PlantBio[i]->pSprite->walnutMovement();


            }
        }


        for (int i = 0; i < fireCount; i++) {

            if (fireBlast[i]->FireExists == true && fireBlast[i]->FireClock.getElapsedTime().asSeconds() < 1.5) {

                fireBlast[i]->drawFire(window);

            }
        }

        for (int i = 0; i < fireCount; i++) {

            if (fireBlast[i]->FireExists == true && fireBlast[i]->FireClock.getElapsedTime().asSeconds() >= 1.5) {

                fireBlast[i]->FireExists = false;
            }
        }

        ////////////////

        for (int i = 0; i < cherryCount; i++) {

            if (cherryBlast[i]->BlastExists == true && cherryBlast[i]->BlastClock.getElapsedTime().asSeconds() < 1.5) {

                cherryBlast[i]->drawBlast(window);

            }
        }

        for (int i = 0; i < cherryCount; i++) {

            if (cherryBlast[i]->BlastExists == true && cherryBlast[i]->BlastClock.getElapsedTime().asSeconds() >= 1.5) {

                cherryBlast[i]->BlastExists = false;
            }
        }




        for (int i = 0; i < 5; i++)
        {

            cars[i]->drawCar(window);
        }

        if (detect1 == true)
        {

            cars[0]->carMovement(cars[0]->CarMoveClock);
            cars[0]->drawCar(window);
            for (int j = 0; j < zombieCount; j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {

                    if (zomBio[j]->zSprite->getZombiePosY() == 150)
                    {
                        if (cars[0]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[0]->getCarExists() == true)
                        {

                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect2 == true)
        {
            cars[1]->carMovement(cars[1]->CarMoveClock);
            cars[1]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 300)
                    {
                        if (cars[1]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[1]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect3 == true)
        {

            cars[2]->carMovement(cars[2]->CarMoveClock);
            cars[2]->drawCar(window);
            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 470)
                    {
                        if (cars[2]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[2]->getCarExists() == true)
                        {

                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect4 == true)
        {

            cars[3]->carMovement(cars[3]->CarMoveClock);
            cars[3]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 620)
                    {
                        if (cars[3]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[3]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }
        if (detect5 == true)
        {

            cars[4]->carMovement(cars[4]->CarMoveClock);
            cars[4]->drawCar(window);

            for (int j = 0; j < spawner->getCurrentZombies(); j++)
            {

                if (zomBio[j]->zData->isZombieAlive == true)
                {
                    if (zomBio[j]->zSprite->getZombiePosY() == 770)
                    {
                        if (cars[4]->getCarPosX() >= zomBio[j]->zSprite->getZombiePosX() && cars[4]->getCarExists() == true)
                        {
                            zomBio[j]->zData->isZombieAlive = false;
                            zombiesKilled++;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++)
        {

            if (cars[i]->getCarPosX() > 1800)
            {
                cars[i]->setCarExists(false);
                cars[i]->setCarPosX(-1500);
            }
        }


        for (int i = 0; i < zombieCount; i++)
        {

            if (zomBio[i]->zSprite->getZombiePosX() <= 300)
            {

                flag = true;
            }
        }

        if (flag)
        {
            gameover.drawGameOver(window);


        }

        foggy.drawFog(window);
        window.display();
    }




    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];


        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            int random = rand() % 4;
            switch (random)
            {
            case 0:
                zombifier[i] = new SimpleZombifier();
                break;
            case 1:
                zombifier[i] = new FootballZombifier();
                break;

            case 2:
                zombifier[i] = new FlyingZombifier();
                break;
            case 3:
                zombifier[i] = new DolphinZombifier();
                break;


            }


        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
        wallNutCard.setPosition(230.0f, 10.0f);
        repeaterPlantCard.setPosition(340.0f, 10.0f);
        cherryBombCard.setPosition(450.0f, 10.0f);
        mushroomCard.setPosition(560.0f, 10.0f);


        //  wallNutCard.setPosition(230.0f, 10.0f);
          //repeaterPlantCard.setPosition(560.0f, 10.0f);
    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100) {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }
            }
            else if (sunflowerCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }

            }
            else if (cherryBombCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 150) {
                    Currency.increaseScore(-150);
                    this->AddPlant(new CherryBombFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Cherry Bomb Plant Card clicked!" << endl;
                }

            }
            else if (wallNutCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 50)
                {
                    Currency.increaseScore(-50);
                    this->AddPlant(new WallNutFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Wall Nut Plant Card clicked!" << endl;
                }

            }

            else if (repeaterPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 200) {
                    Currency.increaseScore(-200);
                    this->AddPlant(new RepeaterFactory, new repeaterBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Repeater Plant Card clicked!" << endl;
                }

            }
            //else if (snowPeaPlantCard.isClicked(mousePos))
            //{
            //    if (Currency.getScore() >= 175) {
            //        Currency.increaseScore(-175);
            //        this->AddPlant(new SnowPeaShooterFactory, new SnowPeaBullet);
            //        plantierCount++;
            //        bulletDraw = true;
            //        isFirstClick = false; // Set flag for second click
            //        // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

            //        cout << "Snow Pea Plant Card clicked!" << endl;
            //    }

            //}
            else if (mushroomCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 75) {
                    Currency.increaseScore(-75);
                    this->AddPlant(new MushroomFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Mushroom Plant Card clicked!" << endl;
                }
            }


        }
        else
        {
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }

    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);
        cherryBombCard.draw(window);
        wallNutCard.draw(window);
        repeaterPlantCard.draw(window);
        // snowPeaPlantCard.draw(window);
        mushroomCard.draw(window);

        sunSystem.drawSunSystem(window);




        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }


        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];
            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 5 && sunflower.getSunFExists() == false)
            {
                sunflower.setSunFExists(true);
                sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                checkdeleteSun = randomIndex;
                checkSun = true;
            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);
            }

        }


        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    // cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }

        if (SunSpawnClock.getElapsedTime().asSeconds() >= 7 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);





    }

    void chwerryExplosion() {


        for (int i = 0; i < plantierCount; i++) {
            //cout << "Allah" << endl;
            if (PlantBio[i]->pData->isCherryBomb == true) {
                // cout << "ALLAH" << endl;
                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 200) {
                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 10) {

                                    cherryBlast[cherryCount] = new CherryBlast();
                                    cherryBlast[cherryCount]->BlastExists = true;
                                    cherryBlast[cherryCount]->BlastClock.restart();
                                    cherryBlast[cherryCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() + 10, PlantBio[i]->pSprite->getPlantPosy() + 10);
                                    cherryCount++;




                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                    PlantBio[i]->pData->plantExist = false;
                                    PlantBio[i]->pSprite->setPlantPosx(-1500);
                                    PlantBio[i]->pSprite->setPlantPosy(-1500);


                                }
                            }
                        }
                    }
                }
            }

        }
    }

    void MushroomSpray() {


        for (int i = 0; i < plantierCount; i++) {

            if (PlantBio[i]->pData->isMushroom == true) {

                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 100) { /////////////////////////////FIREBLAST

                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 20) {
                                    fireBlast[fireCount] = new FireBlast();
                                    fireBlast[fireCount]->FireExists = true;
                                    fireBlast[fireCount]->FireClock.restart();

                                    fireBlast[fireCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() - 60, PlantBio[i]->pSprite->getPlantPosy() - 30);
                                    fireCount++;

                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                }

                            }
                        }
                    }
                }
            }

        }
    }
    void StopTheZombie() {

        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY() && PlantBio[i]->pSprite->getPlantPosx() + 10 == zomBio[j]->zSprite->getZombiePosX() && PlantBio[i]->pSprite->isWalnut() == true) {
                    zomBio[j]->zData->ZombieTouchWalnut = true;
                    WalnutDelay.restart();
                    cout << "Zombie Touch Walnut" << endl;


                }
            }
        }

    }





};


class NightTimeSiege : public Level
{

private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    WallNutCard wallNutCard;
    RepeaterPlantCard repeaterPlantCard;
    SnowPeaPlantCard snowPeaPlantCard;
    MushroomCard mushroomCard;
    CherryBombCard cherryBombCard;
    Clock ZombieSpawnClock;


public:
    int checkdeleteSun;
    bool checkSun;
    NightTimeSiege()
    {
        MAX_ZOMBIES = 14;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/Nightfrontyard.png");

        initGui();
        initCars();
        initPlants();
        initZombies();



        spawner = new ZombieSpawner(6.0f, MAX_ZOMBIES, ZombieSpawnClock);
    }

    ~NightTimeSiege()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;
    }

    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];


        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            int random = rand() % 4;
            switch (random)
            {
            case 0:
                zombifier[i] = new SimpleZombifier();
                break;
            case 1:
                zombifier[i] = new FootballZombifier();
                break;

            case 2:
                zombifier[i] = new FlyingZombifier();
                break;
            case 3:
                zombifier[i] = new DolphinZombifier();
                break;


            }


        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
        wallNutCard.setPosition(230.0f, 10.0f);
        repeaterPlantCard.setPosition(340.0f, 10.0f);
        snowPeaPlantCard.setPosition(450.0f, 10.0f);
        cherryBombCard.setPosition(560.0f, 10.0f);
        mushroomCard.setPosition(670.0f, 10.0f);



        //  wallNutCard.setPosition(230.0f, 10.0f);
          //repeaterPlantCard.setPosition(560.0f, 10.0f);
    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100) {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }
            }
            else if (sunflowerCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }

            }
            else if (cherryBombCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 150) {
                    Currency.increaseScore(-150);
                    this->AddPlant(new CherryBombFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Cherry Bomb Plant Card clicked!" << endl;
                }

            }
            else if (wallNutCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 50)
                {
                    Currency.increaseScore(-50);
                    this->AddPlant(new WallNutFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Wall Nut Plant Card clicked!" << endl;
                }

            }

            else if (repeaterPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 200) {
                    Currency.increaseScore(-200);
                    this->AddPlant(new RepeaterFactory, new repeaterBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Repeater Plant Card clicked!" << endl;
                }

            }
            else if (snowPeaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 175) {
                    Currency.increaseScore(-175);
                    this->AddPlant(new SnowPeaShooterFactory, new SnowPeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Snow Pea Plant Card clicked!" << endl;
                }

            }
            else if (mushroomCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 75) {
                    Currency.increaseScore(-75);
                    this->AddPlant(new MushroomFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Mushroom Plant Card clicked!" << endl;
                }
            }




        }
        else
        { // Second click logic
            // Calculate grid position based on mouse position
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }

    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);
        cherryBombCard.draw(window);
        wallNutCard.draw(window);
        repeaterPlantCard.draw(window);
        snowPeaPlantCard.draw(window);
        mushroomCard.draw(window);


        sunSystem.drawSunSystem(window);

        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }


        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];
            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 5 && sunflower.getSunFExists() == false)
            {
                sunflower.setSunFExists(true);
                sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                checkdeleteSun = randomIndex;
                checkSun = true;
            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);
            }

        }


        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    // cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }

        if (SunSpawnClock.getElapsedTime().asSeconds() >= 7 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);





    }

    void chwerryExplosion() {


        for (int i = 0; i < plantierCount; i++) {
            //cout << "Allah" << endl;
            if (PlantBio[i]->pData->isCherryBomb == true) {
                // cout << "ALLAH" << endl;
                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 200) {
                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 10) {





                                    cherryBlast[cherryCount] = new CherryBlast();
                                    cherryBlast[cherryCount]->BlastExists = true;
                                    cherryBlast[cherryCount]->BlastClock.restart();
                                    cherryBlast[cherryCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() + 10, PlantBio[i]->pSprite->getPlantPosy() + 10);
                                    cherryCount++;





                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                    PlantBio[i]->pData->plantExist = false;
                                    PlantBio[i]->pSprite->setPlantPosx(-1500);
                                    PlantBio[i]->pSprite->setPlantPosy(-1500);


                                }
                            }
                        }
                    }
                }
            }

        }
    }

    void MushroomSpray() {


        for (int i = 0; i < plantierCount; i++) {

            if (PlantBio[i]->pData->isMushroom == true) {

                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 400) { /////////////////////////////FIREBLAST

                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 20) {
                                    fireBlast[fireCount] = new FireBlast();
                                    fireBlast[fireCount]->FireExists = true;
                                    fireBlast[fireCount]->FireClock.restart();
                                    fireBlast[fireCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() - 60, PlantBio[i]->pSprite->getPlantPosy() - 30);
                                    fireCount++;

                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                }

                            }
                        }
                    }
                }
            }

        }
    }

    void StopTheZombie() {

        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY() && PlantBio[i]->pSprite->getPlantPosx() + 10 == zomBio[j]->zSprite->getZombiePosX() && PlantBio[i]->pSprite->isWalnut() == true) {
                    zomBio[j]->zData->ZombieTouchWalnut = true;
                    WalnutDelay.restart();
                    cout << "Zombie Touch Walnut" << endl;


                }
            }
        }

    }

};


class RooftopRampage : public Level
{

private:
    // Create plant cards
    PeaPlantCard peaPlantCard;
    SunflowerCard sunflowerCard;
    WallNutCard wallNutCard;
    RepeaterPlantCard repeaterPlantCard;
    SnowPeaPlantCard snowPeaPlantCard;
    MushroomCard mushroomCard;
    CherryBombCard cherryBombCard;
    Clock ZombieSpawnClock;


public:
    int checkdeleteSun;
    bool checkSun;
    RooftopRampage()
    {
        MAX_ZOMBIES = 30;
        MAX_PLANTS = 45;

        BULLETS_TO_KILL_ZOMBIE = 3;

        map_image.loadFromFile("../Images/roof.png");

        initGui();
        initCars();
        initPlants();
        initZombies();



        spawner = new ZombieSpawner(6.0f, MAX_ZOMBIES, ZombieSpawnClock);
    }

    ~RooftopRampage()
    {
        delete zomBio;
        delete zombifier;

        delete plantier;
        delete PlantBio;

        delete spawner;
    }

    void initZombies()
    {
        // Init zombie arrays
        zomBio = new ZombieBiology * [MAX_ZOMBIES];
        zombifier = new Zombifier * [MAX_ZOMBIES];


        for (int i = 0; i < MAX_ZOMBIES; i++)
        {
            int random = rand() % 5;
            switch (random)
            {
            case 0:
                zombifier[i] = new SimpleZombifier();
                break;
            case 1:
                zombifier[i] = new FootballZombifier();
                break;

            case 2:
                zombifier[i] = new FlyingZombifier();
                break;
            case 3:
                zombifier[i] = new DolphinZombifier();
                break;
            case 4:
                zombifier[i] = new DancingZombifier();
                break;


            }


        }
    }

    void initGui()
    {
        // Set positions for each card
        peaPlantCard.setPosition(10.0f, 10.0f);
        sunflowerCard.setPosition(120.0f, 10.0f);
        wallNutCard.setPosition(230.0f, 10.0f);
        repeaterPlantCard.setPosition(340.0f, 10.0f);
        snowPeaPlantCard.setPosition(450.0f, 10.0f);
        cherryBombCard.setPosition(560.0f, 10.0f);
        mushroomCard.setPosition(670.0f, 10.0f);


        //  wallNutCard.setPosition(230.0f, 10.0f);
          //repeaterPlantCard.setPosition(560.0f, 10.0f);
    }

    void updatePlants(RenderWindow& window, bool& isFirstClick, bool& bulletDraw)
    {
        Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        if (isFirstClick)
        { // First click logic
            if (peaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 100) {
                    Currency.increaseScore(-100);
                    this->AddPlant(new PeaShooterFactory, new PeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Pea Plant Card clicked!" << endl;
                }
            }
            else if (sunflowerCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 25) {
                    Currency.increaseScore(-25);
                    // Create a new instance of Sunflower plant and add it to the array
                    this->AddPlant(new SunflowerFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Sunflower Card clicked!" << endl;
                }

            }
            else if (cherryBombCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 150) {
                    Currency.increaseScore(-150);
                    this->AddPlant(new CherryBombFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Cherry Bomb Plant Card clicked!" << endl;
                }

            }
            else if (wallNutCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 50)
                {
                    Currency.increaseScore(-50);
                    this->AddPlant(new WallNutFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Wall Nut Plant Card clicked!" << endl;
                }

            }

            else if (repeaterPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 200) {
                    Currency.increaseScore(-200);
                    this->AddPlant(new RepeaterFactory, new repeaterBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Repeater Plant Card clicked!" << endl;
                }

            }
            else if (snowPeaPlantCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 175) {
                    Currency.increaseScore(-175);
                    this->AddPlant(new SnowPeaShooterFactory, new SnowPeaBullet);
                    plantierCount++;
                    bulletDraw = true;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Snow Pea Plant Card clicked!" << endl;
                }

            }
            else if (mushroomCard.isClicked(mousePos))
            {
                if (Currency.getScore() >= 75) {
                    Currency.increaseScore(-75);
                    this->AddPlant(new MushroomFactory, nullptr);
                    plantierCount++;
                    isFirstClick = false; // Set flag for second click
                    // selectedPlantIndex = plantierCount - 1; // Index of the newly added plant

                    cout << "Mushroom Plant Card clicked!" << endl;
                }
            }



        }
        else
        { // Second click logic
            // Calculate grid position based on mouse position
            this->placePlant(isFirstClick, bulletDraw, mousePos);
        }

    }

    void drawLevelGui(RenderWindow& window)
    {
        window.clear();
        window.clear();

        createBack(window);
        this->createMap(window);

        // Draw plant cards
        peaPlantCard.draw(window);
        sunflowerCard.draw(window);
        cherryBombCard.draw(window);
        wallNutCard.draw(window);
        repeaterPlantCard.draw(window);
        snowPeaPlantCard.draw(window);
        mushroomCard.draw(window);



        sunSystem.drawSunSystem(window);

        // Count the number of sunflowers and store their indices
        int numSunflowers = 0;
        int sunflowerIndices[45];
        for (int i = 0; i < plantierCount; i++) {
            if (PlantBio[i]->pData->plantExist && PlantBio[i]->pData->isSunflower) {
                sunflowerIndices[numSunflowers++] = i;
            }
        }


        if (numSunflowers > 0) {
            int randomIndex = sunflowerIndices[rand() % numSunflowers];
            if (SunflowerSunSpawnClock.getElapsedTime().asSeconds() >= 5 && sunflower.getSunFExists() == false)
            {
                sunflower.setSunFExists(true);
                sunflower.setPosX(PlantBio[randomIndex]->pSprite->getPlantPosx() + 55);
                sunflower.setPosY(PlantBio[randomIndex]->pSprite->getPlantPosy() + 2);
                checkdeleteSun = randomIndex;
                checkSun = true;
            }

            if (sunflower.getSunFExists())
            {
                sunflower.drawSunF(window);
            }

        }

        if (numSunflowers > 0) {
            if (PlantBio[checkdeleteSun]->pData->plantExist == false) {
                if (checkSun == true) {
                    sunflower.setSunFExists(false);
                    SunflowerSunSpawnClock.restart();
                    // cout << "i am restating time for sunflower this is bug" << endl;
                    checkSun = false;
                }
            }
        }


        if (SunSpawnClock.getElapsedTime().asSeconds() >= 7 && sunfall.getSunExists() == false)
        {
            sunfall.setSunExists(true);
            sunfall.setPosX(rand() % 1800);
            sunfall.setPosY(-10);
        }

        if (sunfall.getSunExists())
        {
            sunfall.sunMovement();
            sunfall.drawSun(window);
        }

        Currency.draw(window);





    }

    void chwerryExplosion() {


        for (int i = 0; i < plantierCount; i++) {
            //cout << "Allah" << endl;
            if (PlantBio[i]->pData->isCherryBomb == true) {
                // cout << "ALLAH" << endl;
                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 200) {
                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 10) {





                                    cherryBlast[cherryCount] = new CherryBlast();
                                    cherryBlast[cherryCount]->BlastExists = true;
                                    cherryBlast[cherryCount]->BlastClock.restart();
                                    cherryBlast[cherryCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() + 10, PlantBio[i]->pSprite->getPlantPosy() + 10);
                                    cherryCount++;





                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                    PlantBio[i]->pData->plantExist = false;
                                    PlantBio[i]->pSprite->setPlantPosx(-100);
                                    PlantBio[i]->pSprite->setPlantPosy(-100);


                                }
                            }
                        }
                    }
                }
            }

        }
    }


    void MushroomSpray() {


        for (int i = 0; i < plantierCount; i++) {

            if (PlantBio[i]->pData->isMushroom == true) {

                for (int j = 0; j < zombieCount; j++) {
                    if (zomBio[j]->zData->isZombieAlive == true) {
                        if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY()) {
                            if (zomBio[j]->zSprite->getZombiePosX() <= PlantBio[i]->pSprite->getPlantPosx() + 400) { /////////////////////////////FIREBLAST

                                if (zomBio[j]->zSprite->getZombiePosX() >= PlantBio[i]->pSprite->getPlantPosx() + 20) {
                                    fireBlast[fireCount] = new FireBlast();
                                    fireBlast[fireCount]->FireExists = true;
                                    fireBlast[fireCount]->FireClock.restart();
                                    fireBlast[fireCount]->setPos(PlantBio[i]->pSprite->getPlantPosx() - 60, PlantBio[i]->pSprite->getPlantPosy() - 30);
                                    fireCount++;

                                    zomBio[j]->zData->isZombieAlive = false;
                                    zombiesKilled++;
                                }

                            }
                        }
                    }
                }
            }

        }
    }

    void StopTheZombie() {

        for (int i = 0; i < plantierCount; i++) {
            for (int j = 0; j < zombieCount; j++) {
                if (PlantBio[i]->pSprite->getPlantPosy() == zomBio[j]->zSprite->getZombiePosY() && PlantBio[i]->pSprite->getPlantPosx() + 10 == zomBio[j]->zSprite->getZombiePosX() && PlantBio[i]->pSprite->isWalnut() == true) {
                    zomBio[j]->zData->ZombieTouchWalnut = true;
                    WalnutDelay.restart();
                    cout << "Zombie Touch Walnut" << endl;


                }
            }
        }

    }

};
class Game {

private:

    RenderWindow window;



    MenuButton menuButton;
    InstructionsButton instructionsButton;
    PauseButton pauseButton;

    ResumeButtonOfPauseScreen resumeButtonOfPauseScreen;
    MenuButtonOfPauseScreen menuButtonOfPauseScreen;
    ResumeButtonOfinstructionScreen resumeButtonOfinstructionScreen;




    PlayButtonOfMenuScreen playButtonOfMenuScreen;
    HelpButtonOfMenuScreen helpButtonOfMenuScreen;
    HighScoresButtonOfMenuScreen highScoresButtonOfMenuScreen;




    LevelOneButtonOfMenuScreen levelOneButtonOfMenuScreen;
    LevelTwoButtonOfMenuScreen levelTwoButtonOfMenuScreen;
    LevelThreeButtonOfMenuScreen levelThreeButtonOfMenuScreen;
    LevelFourButtonOfMenuScreen levelFourButtonOfMenuScreen;
    LevelFiveButtonOfMenuScreen levelFiveButtonOfMenuScreen;
    LevelSixButtonOfMenuScreen levelSixButtonOfMenuScreen;








    Clock clock;
    bool isFirstClick; // Flag to track first click
    bool bulletDraw;
    bool tohighscore = true;

    GameOverSprite gameover;


    static bool onPause;
    static bool gameIsPlaying;
    static bool onMenu;
    static bool onHelp;

    Level* lvl;
    ScoreManager scoreManager;

public:

    Game() : scoreManager("../Images/handle.txt") {
        window.create(sf::VideoMode(1900, 1000), "PlantsVsZombies", sf::Style::Close | sf::Style::Titlebar);
        window.setSize(sf::Vector2u(1400, 700));
        window.setPosition(sf::Vector2i(0, 0));

        // Game icon

        //window.setIcon(32, 32, icon.getPixelsPtr());


        // set positions for buttons of pause screen
        resumeButtonOfPauseScreen.setPosition(750, 300);
        menuButtonOfPauseScreen.setPosition(750, 500);
        resumeButtonOfinstructionScreen.setPosition(750, 500);


        // set positions for buttons of menu screen
        playButtonOfMenuScreen.setPosition(750, 700);
        helpButtonOfMenuScreen.setPosition(790, 635);
        highScoresButtonOfMenuScreen.setPosition(950, 640);



        // set positions for buttons of game screen

        menuButton.setPosition(1510.0f, 10.0f);
        instructionsButton.setPosition(1610.0f, 10.0f);
        pauseButton.setPosition(1710.0f, 10.0f);

        isFirstClick = true; // Flag to track first click
        bulletDraw = false;




        lvl = new BeginnersGarden();

        while (window.isOpen())
        {
            if (onPause == true && gameIsPlaying == false && onMenu == false && onHelp == false  /*START / END */)
            {

                window.clear();
                createPause(window);

                resumeButtonOfPauseScreen.draw(window);
                menuButtonOfPauseScreen.draw(window);

                resumeButtonOfPauseScreen.setPosition(770, 650);
                menuButtonOfPauseScreen.setPosition(770, 800);

                Event eventPause;

                while (window.pollEvent(eventPause))
                {

                    if (eventPause.type == Event::Closed)
                        window.close();
                    else if (eventPause.type == Event::MouseButtonPressed)
                    {
                        if (eventPause.mouseButton.button == Mouse::Left)
                        {
                            Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (resumeButtonOfPauseScreen.isClicked(mousePos))
                            {
                                onPause = false;
                                gameIsPlaying = true;
                                onMenu = false;
                            }
                            else if (menuButtonOfPauseScreen.isClicked(mousePos))
                            {
                                onMenu = true;
                                onPause = false;
                                gameIsPlaying = false;
                            }
                        }
                    }
                }

                window.display();
            }
            else if (onPause == false && gameIsPlaying == false && onMenu == true && onHelp == false    /*START / END */)
            {

                window.clear();
                createMenu(window);

                //START


                menuButton.setPosition(1510.0f, 10.0f);
                instructionsButton.setPosition(1610.0f, 10.0f);
                pauseButton.setPosition(1710.0f, 10.0f);

                //setting positions for levels button
                levelOneButtonOfMenuScreen.setPosition(1700, 300);
                levelTwoButtonOfMenuScreen.setPosition(1700, 400);
                levelThreeButtonOfMenuScreen.setPosition(1700, 500);
                levelFourButtonOfMenuScreen.setPosition(1700, 600);
                levelFiveButtonOfMenuScreen.setPosition(1700, 700);
                levelSixButtonOfMenuScreen.setPosition(1700, 800);

                //drawing levels button
                levelOneButtonOfMenuScreen.draw(window);
                levelTwoButtonOfMenuScreen.draw(window);
                levelThreeButtonOfMenuScreen.draw(window);
                levelFourButtonOfMenuScreen.draw(window);
                levelFiveButtonOfMenuScreen.draw(window);
                levelSixButtonOfMenuScreen.draw(window);



                //END

                playButtonOfMenuScreen.draw(window);

                highScoresButtonOfMenuScreen.draw(window);//START/END
                helpButtonOfMenuScreen.draw(window);//START/END

                Event eventMenu;

                while (window.pollEvent(eventMenu))
                {

                    if (eventMenu.type == Event::Closed)
                        window.close();
                    else if (eventMenu.type == Event::MouseButtonPressed)
                    {
                        if (eventMenu.mouseButton.button == Mouse::Left)
                        {
                            Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (playButtonOfMenuScreen.isClicked(mousePos))
                            {
                                lvl = new BeginnersGarden();
                                //  lvl = new SunFlowerFields();

                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;//START/END
                            }
                            if (helpButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = false;
                                onPause = false;
                                onHelp = true;//START/END



                            }

                            //////////////////////////////////////////START (KEEP THIS PART COMMENTED)
                            /*if (highScoresButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = false;
                                onPause = false;
                                onHighScores = true;
                            }*/
                            //////////////////////////////////////////END
                            if (levelOneButtonOfMenuScreen.isClicked(mousePos))
                            {

                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new BeginnersGarden();
                            }
                            if (levelTwoButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new ZombieOutskirts();
                            }
                            if (levelThreeButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new SunFlowerFields();
                            }
                            if (levelFourButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new FoggyForest();
                            }
                            if (levelFiveButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new NightTimeSiege();
                            }
                            if (levelSixButtonOfMenuScreen.isClicked(mousePos))
                            {
                                onMenu = false;
                                gameIsPlaying = true;
                                onPause = false;
                                onHelp = false;
                                lvl = new RooftopRampage();
                            }


                        }
                    }




                }

                window.display();
            }
            else if (onPause == false && gameIsPlaying == false && onMenu == false && onHelp == true  /*START / END */)
            {
                window.clear();
                createInstructions(window);

                Event eventHelp;

                resumeButtonOfinstructionScreen.setPosition(1000, 820);
                resumeButtonOfinstructionScreen.draw(window);
                menuButton.setPosition(850, 850);
                menuButton.draw(window);

                while (window.pollEvent(eventHelp))
                {

                    if (eventHelp.type == Event::Closed)
                        window.close();
                    else if (eventHelp.type == Event::MouseButtonPressed)
                    {
                        if (eventHelp.mouseButton.button == Mouse::Left)
                        {
                            Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (menuButton.isClicked(mousePos))
                            {
                                onMenu = true;
                                gameIsPlaying = false;
                                onPause = false;
                                onHelp = false;
                            }
                            if (resumeButtonOfinstructionScreen.isClicked(mousePos))
                            {
                                onPause = false;
                                gameIsPlaying = true;
                                onMenu = false;
                                onHelp = false;
                            }
                        }
                    }
                }

                window.display();
            }
            else if (onPause == false && gameIsPlaying == true && onMenu == false && onHelp == false   /*START / END */)
            {
                bool makepea = false;
                bool makesun = false;
                bool makesnow = false;
                bool makewall = false;
                bool makecherry = false;
                bool makerepeater = false;
                bool drawer = false;
                bool chekerforfrozen = false;
                menuButton.setPosition(1510.0f, 10.0f);

                if (lvl->ishighScore()) {
                    if (tohighscore == true) {
                        scoreManager.saveScore(lvl->Currency.getScore());
                        scoreManager.sortScores();
                        /*   onMenu = false;
                           gameIsPlaying = false;
                           onPause = true;
                           onHelp = false;*/
                        tohighscore = false;
                    }
                }


                // Check if level is complete and lvl is first level
                if (lvl->isLevelComplete() && dynamic_cast<BeginnersGarden*>(lvl))
                {

                    cout << "Level 1 complete!" << endl;
                    lvl = new ZombieOutskirts();

                }

                // Check if level is complete and lvl is second level
                if (lvl->isLevelComplete() && dynamic_cast<ZombieOutskirts*>(lvl))
                {

                    //lvl->Currency.setScore(0);//START/END
                    lvl = new SunFlowerFields();
                }


                // Check if level is complete and lvl is third level
                if (lvl->isLevelComplete() && dynamic_cast<SunFlowerFields*>(lvl))
                {

                    //lvl->Currency.setScore(0);//START/END
                    lvl = new FoggyForest();
                }

                // Check if level is complete and lvl is fourth level
                if (lvl->isLevelComplete() && dynamic_cast<FoggyForest*>(lvl))
                {

                    //lvl->Currency.setScore(0);//START/END
                    lvl = new NightTimeSiege();
                }

                // Check if level is complete and lvl is fifth level
                if (lvl->isLevelComplete() && dynamic_cast<NightTimeSiege*>(lvl))
                {

                    //lvl->Currency.setScore(0);//START/END
                    lvl = new RooftopRampage();
                }

                if (lvl->isLevelComplete() && dynamic_cast<RooftopRampage*>(lvl))
                {
                    //lvl->Currency.setScore(0);//START/END
                    scoreManager.saveScore(lvl->Currency.getScore());
                    scoreManager.sortScores();
                    //lvl = new ZombieAte();

                }





                Event event;

                while (window.pollEvent(event))
                {

                    if (event.type == Event::Closed)
                        window.close();
                    else if (event.type == Event::MouseButtonPressed)
                    {
                        if (event.mouseButton.button == Mouse::Left)
                        {
                            lvl->updatePlants(window, isFirstClick, bulletDraw);
                        }
                    }

                    if (event.type == Event::MouseButtonPressed)
                    {
                        if (event.key.code == Mouse::Left)
                        {
                            Vector2f mousePos2 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (pauseButton.isClicked(mousePos2))
                            {

                                cout << "Pause button button clicked!" << endl;

                                onPause = true;
                                gameIsPlaying = false;
                                onMenu = false;
                            }
                        }
                    }

                    if (event.type == Event::MouseButtonPressed)
                    {
                        if (event.key.code == Mouse::Left)
                        {
                            Vector2f mousePos3 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (instructionsButton.isClicked(mousePos3))
                            {
                                cout << "Instructions button clicked!" << endl;
                                onMenu = false;
                                gameIsPlaying = false;
                                onPause = false;
                                onHelp = true;

                            }
                        }
                    }
                    if (event.type == Event::MouseButtonPressed)
                    {
                        if (event.key.code == Mouse::Left)
                        {
                            Vector2f mousePos3 = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                            if (menuButton.isClicked(mousePos3))
                            {
                                cout << "Menu button clicked!" << endl;
                                onMenu = true;
                                gameIsPlaying = false;
                                onPause = false;
                                //onHelp = false;

                            }
                        }
                    }



                    //Ashher Majid 

                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                        if (lvl->sunfall.SunClicked(window)) {

                            if (lvl->sunfall.getSunExists() == true) {
                                lvl->sunfall.setSunExists(false);
                                lvl->Currency.increaseScore(25);
                                lvl->SunSpawnClock.restart();


                            }
                        }
                    }
                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                        if (lvl->sunflower.SunFClicked(window)) {

                            if (lvl->sunflower.getSunFExists() == true) {
                                lvl->sunflower.setSunFExists(false);
                                lvl->Currency.increaseScore(25);
                                lvl->SunflowerSunSpawnClock.restart();
                            }
                        }
                    }


                }


                //// UPDATE replace with createMap
                lvl->drawLevelGui(window);
                // Draw buttons
                menuButton.draw(window);
                instructionsButton.draw(window);
                pauseButton.draw(window);

                lvl->updateZombies(window);



                if (dynamic_cast<FoggyForest*>(lvl)) {

                    lvl->chwerryExplosion();
                    lvl->MushroomSpray();
                }
                if (dynamic_cast<NightTimeSiege*>(lvl)) {

                    lvl->chwerryExplosion();
                    lvl->MushroomSpray();
                }
                if (dynamic_cast<RooftopRampage*>(lvl)) {

                    lvl->chwerryExplosion();
                    lvl->MushroomSpray();
                }







            }
        }










    }
    void displayHighScores(int numScoresToShow) {
        std::cout << "High Scores:" << std::endl;
        scoreManager.displayHighScores(numScoresToShow);
    }






};


bool Game::onPause = false;
bool Game::gameIsPlaying = false;
bool Game::onMenu = true;
bool Game::onHelp = false;


int main()
{
    Game* game = new Game();
    game->displayHighScores(3);

    delete game;
    return 0;

}