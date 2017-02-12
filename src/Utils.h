#ifndef Utils_H
#define Utils_H

class Utils {
    public:
        static double random(); // between 0 and 1 [0,1)
        static int randomInt(int min, int max); // between min and max [min,max)
        static int getInt();
};

#endif
