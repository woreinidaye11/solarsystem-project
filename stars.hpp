class Star {
public:
    // means the radius of the planet
    GLfloat radius;
    // means the speed of a planet's revolution
    GLfloat speed, selfSpeed;
    // the distance between the center of the planet 
    //and the center of the parent planet
    GLfloat distance;
    // the color of the planet
    GLfloat rgbaColor[4];
 
    // Parent planet
    Star* parentStar;
 
    // constructor information
    // Rotation radius, rotation speed, rotation speed, orbit (parent node) star
    Star(GLfloat radius, GLfloat distance,
         GLfloat speed,  GLfloat selfSpeed,
         Star* parentStar);
    // General planetary movement, rotation and other activities are mapped
    void drawStar();
    // invoke drawStar()
    virtual void draw() { drawStar(); }
    // The parameter is the time span for each refresh of the screen
    virtual void update(long timeSpan);
protected:
    GLfloat alphaSelf, alpha;
};
class Planet : public Star {
public:
    //constructor for planet
    Planet(GLfloat radius, GLfloat distance,
           GLfloat speed,  GLfloat selfSpeed,
           Star* parentStar, GLfloat rgbColor[3]);
    void drawPlanet();
    virtual void draw() { drawPlanet(); drawStar(); }
};
class LightPlanet : public Planet {
public:
    LightPlanet(GLfloat Radius, GLfloat Distance,
                GLfloat Speed,  GLfloat SelfSpeed,
                Star* ParentStar, GLfloat rgbColor[]);
    // Increased rendering of light to stars that provide light
    void drawLight();
    virtual void draw() { drawLight(); drawPlanet(); drawStar(); }
};
`