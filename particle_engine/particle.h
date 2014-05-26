/*
 * @Heintze, Darrell R.
 * 6544 10/10/2012
*/

#include "color.h"
#include<stdlib.h>
#include<time.h>



class Particle {
    public:
      //constructors
        Particle() {
            srand(time(NULL));
            this->active = true;
            this->lifespan = 100.0f;

            this->posX = 1;
            this->posY = 1;

            this->particle_color.r = (1.0f/255)*(rand() % 255 + 1);
            this->particle_color.g = (1.0f/255)*(rand() % 255 + 1);
            this->particle_color.b = (1.0f/255)*(rand() % 255 + 1);
            this->particle_color.alpha = 1.0f;

            this->vX = ((float)rand()/(float)RAND_MAX+1)-1; this->vY = ((float)rand()/(float)RAND_MAX+1)-1;
            this->aX = 0; this->aY = 0;
        }
      //destructor
        ~Particle () {
            delete this;
        }


      //setters & getters
        float getPosX() { return posX; }
        float getPosY() { return posY; }
        void setPosX(float x) { this->posX = x; }
        void setPosY(float y) { this->posY = y; }

        float getvX() { return vX; }
        float getvY() { return vY; }
        void setvX(float x) { this->vX = x; }
        void setvY(float y) { this->vY = y; }

        float getaX() { return aX; }
        float getaY() { return aY; }
        void setaX(float x) { this->aX = x; }
        void setaY(float y) { this->aY = y; }

        float getR() { return particle_color.r; }
        float getG() { return particle_color.g; }
        float getB() { return particle_color.b; }
        float getA() { return particle_color.alpha; }
        void setR(float r) { this->particle_color.r = r; }
        void setG(float g) { this->particle_color.g = g; }
        void setB(float b) { this->particle_color.b = b; }
        void setA(float a) { this->particle_color.alpha = a; }

    private:
        bool active;
        float lifespan;
        float posX,posY,vX,vY,aX,aY;
        Color particle_color;
};
