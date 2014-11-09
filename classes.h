#ifndef __GRAVITY_SIMULATOR_CLASSES__
#define __GRAVITY_SIMULATOR_CLASSES__

//----------------------------------------------------------------------------
//{ Constants
//----------------------------------------------------------------------------

    int WIDTH = 1200, HEIGHT = 800;

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Classes
//----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Vector
    //----------------------------------------------------------------------------


        class Vector
        {
            public:
                // Constructor & destructor:

                     Vector (double x, double y, double x1, double y1);
                    ~Vector ();

                // Getters & setters:

                    double  getX () const;
                    Vector& setX (double x);

                    double  getY () const;
                    Vector& setY (double y);

                    double  getX1 () const;
                    Vector& setX1 (double x1);

                    double  getY1 () const;
                    Vector& setY1 (double y1);

                // Other functions:

                    bool ok () const;
                    // Checks correctness of this class (correct - true, else - false)

                    void addVector (Vector vector);
                    // Adds to this vector the vector of the parameters

                    void subtractVector (Vector vector);
                    // Deducts the vector of the parameters from this vector

                    double length () const;
                    // Returns vector length

                    void normalize ();
                    // Normalizes this vector

                    void multiplyBy (double factor);
                    // Multiplies vector length by entered factor

                    void render () const;
                    // Renders this vector

            private:
                double x_, y_, x1_, y1_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Vector::Vector (double x, double y, double x1, double y1) :

                x_  (x ),
                y_  (y ),
                x1_ (x1),
                y1_ (y1)
                {}

            Vector::~Vector ()
            {}

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ X
            //----------------------------------------------------------------------------

                double Vector::getX () const
                {
                    assert (ok ());
                    return x_;
                }

                Vector& Vector::setX (double x)
                {
                    assert (ok ());
                    x_ = x;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Y
            //----------------------------------------------------------------------------

                double Vector::getY () const
                {
                    assert (ok ());
                    return y_;
                }

                Vector& Vector::setY (double y)
                {
                    assert (ok ());
                    y_ = y;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ X1
            //----------------------------------------------------------------------------

                double Vector::getX1 () const
                {
                    assert (ok ());
                    return x1_;
                }

                Vector& Vector::setX1 (double x1)
                {
                    assert (ok ());
                    x1_ = x1;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Y1
            //----------------------------------------------------------------------------

                double Vector::getY1 () const
                {
                    assert (ok ());
                    return y1_;
                }

                Vector& Vector::setY1 (double y1)
                {
                    assert (ok ());
                    y1_ = y1;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Vector::ok () const
            {
                bool everythingOk = true;

                if (!this) everythingOk = false;

                return everythingOk;
            }

            void Vector::addVector (Vector vector)
            {
                assert (ok ());
                assert (vector.ok ());

                x1_ = x1_ + vector.getX1 () - vector.getX ();
                y1_ = y1_ + vector.getY1 () - vector.getY ();

                assert (ok ());
                assert (vector.ok ());
            }

            void Vector::subtractVector (Vector vector)
            {
                assert (ok ());
                assert (vector.ok ());

                x1_ = x1_ - (vector.getX1 () - vector.getX ());
                y1_ = y1_ - (vector.getY1 () - vector.getY ());

                assert (ok ());
                assert (vector.ok ());
            }

            double Vector::length () const
            {
                assert (ok ());
                return sqrt ((x1_ - x_) * (x1_ - x_) + (y1_ - y_) * (y1_ - y_));
            }

            void Vector::normalize ()
            {
                assert (ok ());

                double vectorLength = length ();
                x1_ = x_ + (x1_ - x_)/vectorLength;
                y1_ = y_ + (y1_ - y_)/vectorLength;

                assert (ok ());
            }

            void Vector::multiplyBy (double factor)
            {
                assert (ok ());

                x1_ = x_ + (x1_ - x_) * factor;
                y1_ = y_ + (y1_ - y_) * factor;

                assert (ok ());
            }

            void Vector::render () const
            {
                assert (ok ());
                txLine (x_, y_, x1_, y1_);
                assert (ok ());
            }

        //}
        //----------------------------------------------------------------------------


    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Object
    //----------------------------------------------------------------------------

        class Object
        {
            public:
                // Constructor & destructor

                     Object (Vector coords, Vector velocity, double radius, double mass, bool Nstatic, string name);
                    ~Object ();

                // Getters & setters

                    Vector  getCoords () const;
                    Object& setCoords (Vector coords);

                    Vector  getVelocity () const;
                    Object& setVelocity (Vector velocity);

                    double  getRadius () const;
                    Object& setRadius (double radius);

                    double  getMass () const;
                    Object& setMass (double mass);

                    bool getStatic () const;

                    string getName () const;

                // Functions

                    bool ok () const;
                    // Checks correctness of class Object (correct - true, else - false)

                    void move ();
                    // Moves object on it's velocity

                    void gravitateTo (Object object);
                    // Makes our object gravitate to the parameter object.

                    void render () const;
                    // Renders an object

            private:
                Vector coords_, velocity_;
                double radius_, mass_;
                bool static_;
                string name_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Object::Object (Vector coords, Vector velocity, double radius, double mass, bool objStatic, string name) :
                  coords_ (coords   ),
                velocity_ (velocity ),
                  radius_ (radius   ),
                    mass_ (mass     ),
                  static_ (objStatic),
                    name_ (name     )
                {}

            Object::~Object ()
            {}

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Coordinates
            //----------------------------------------------------------------------------
                Vector Object::getCoords () const
                {
                    assert (ok ());
                    return coords_;
                }

                Object& Object::setCoords (Vector coords)
                {
                    assert (ok ());

                    coords_ = coords;

                    assert (ok ());
                    return *this;
                }
            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Velocity
            //----------------------------------------------------------------------------

                Vector Object::getVelocity () const
                {
                    assert (ok ());
                    return velocity_;
                }

                Object& Object::setVelocity (Vector velocity)
                {
                    assert (ok ());

                    velocity_ = velocity;

                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Radius
            //----------------------------------------------------------------------------

            double Object::getRadius () const
            {
                assert (ok ());
                return radius_;
            }

            Object& Object::setRadius (double radius)
            {
                assert (ok ());

                radius_ = radius;

                assert (ok ());
                return *this;
            }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Mass
            //----------------------------------------------------------------------------

            double Object::getMass () const
            {
                assert (ok ());
                return mass_;
            }

            Object& Object::setMass (double mass)
            {
                assert (ok ());

                mass_ = mass;

                assert (ok ());
                return *this;
            }


            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Static
            //----------------------------------------------------------------------------

            bool Object::getStatic () const
            {
                assert (ok ());
                return static_;
            }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Name
            //----------------------------------------------------------------------------

            string Object::getName () const
            {
                assert (ok ());
                return name_;
            }

            //}
            //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

        bool Object::ok () const
        {
            bool everythingOk = true;

            if (!this) everythingOk = false;

            if (  !coords_.ok ()) everythingOk = false;
            if (!velocity_.ok ()) everythingOk = false;

            if (0 > radius_) everythingOk = false;

            if (0 > mass_) everythingOk = false;

            return everythingOk;
        }

        void Object::move ()
        {
            assert (ok ());

            coords_.addVector (velocity_);

            if (0 >= coords_.getX1 () - radius_)
            {
                velocity_.setX1 (velocity_.getX () - (velocity_.getX1 () - velocity_.getX ())/2);
                coords_.setX1 (radius_);
            }

            if (coords_.getX1 () + radius_ >= WIDTH)
            {
                velocity_.setX1 (velocity_.getX () - (velocity_.getX1 () - velocity_.getX ())/2);
                coords_.setX1 (WIDTH - radius_);
            }

            if (0 >= coords_.getY1 () - radius_)
            {
                velocity_.setY1 (velocity_.getY () - (velocity_.getY1 () - velocity_.getY ())/2);
                coords_.setY1 (radius_);
            }

            if (coords_.getY1 () + radius_ >= HEIGHT)
            {
                velocity_.setY1 (velocity_.getX () - (velocity_.getY1 () - velocity_.getY ())/2);
                coords_.setY1 (HEIGHT - radius_);
            }

            assert (ok ());
        }

        void Object::gravitateTo (Object object)
        {
            assert (ok ());

            if (!static_)
            {
                Vector acceleration = coords_;
                acceleration.subtractVector (object.getCoords ());

                double distance = acceleration.length ();

                printf ("%f\n", acceleration.length ());

                acceleration.normalize ();

                txSetColor (TX_RED);
                acceleration.render ();

                acceleration.multiplyBy (6.6 * (10^(-11)) * (object.getMass ())/(distance * distance + 1));

                velocity_.addVector (acceleration);

                acceleration.~Vector ();
            }

            assert (ok ());
        }

        void Object::render () const
        {
            txSetFillColor (TX_YELLOW);
            txSetColor (TX_BLACK);
            txCircle (coords_.getX1 (), coords_.getY1 (), radius_);

            txSetColor (TX_GREEN);
            txLine (coords_.getX1 () + velocity_.getX  (), coords_.getY1 () + velocity_.getY  (),
                    coords_.getX1 () + velocity_.getX1 (), coords_.getY1 () + velocity_.getY1 ());
        }

        //}
        //----------------------------------------------------------------------------


    //}
    //----------------------------------------------------------------------------

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Prototypes
//----------------------------------------------------------------------------

//}
//----------------------------------------------------------------------------

#endif

