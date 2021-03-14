//
// Created by Ruben on 2/12/2021.
//

#include "VectorManipulation.h"
#include <cmath>

namespace adcs {

    vec3 getSunPosition(int julianDate) {
        double tut1 = ( julianDate - 2451545.0 )/ 36525.0;
        double meanlong = 280.460 + (36000.771285 * tut1);
        meanlong = fmod(meanlong, 360);

        double meananomaly = 357.528 + (35999.050957 * tut1);
        meananomaly = fmod(meananomaly * CONST_DEG_TO_RAD, CONST_PI * 2);

        if(meananomaly < 0)
            meananomaly = (2 * CONST_PI) + meananomaly;

        double eclplong = meanlong + (1.915 * sin(meananomaly)) + (0.020 * sin(2.0 * meananomaly));
        eclplong = fmod(eclplong, 360);

        double obliquity = 24.439 - (0.01461 * tut1);
        eclplong = eclplong * CONST_DEG_TO_RAD;
        obliquity = obliquity * CONST_DEG_TO_RAD;

        double magr = 1.00014 - (0.01671 * cos(meananomaly)) - (0.00014 * cos(2.0 * meananomaly));

        vec3 rsun = vec3(magr * cos(eclplong), magr * cos(obliquity) * sin(eclplong), magr * sin(obliquity) * sin(eclplong));

        double rtasc = atan(cos(obliquity) * tan(eclplong));

        if(eclplong < 0)
            eclplong = eclplong + (2.0 * CONST_PI);

        if(abs(eclplong - rtasc) > CONST_PI * 0.5)
            rtasc = rtasc + (0.5 * CONST_PI * round((eclplong - rtasc) / (0.5 * CONST_PI)));

        double decl = asin(sin(obliquity) * sin(eclplong));

        return rsun;
    }
    /**
     * Function that transforms a vector from the mean equator mean equinox of date (mod) to the mean equator mean eeuinox (j2000) frame.
     * @param pos - Position vector of sun
     * @param julianCenturies - Julian centuries of terrestrial time
     */
    vec3 mod2eci(vec3 pos, int julianCenturies) {
        // Square and cubes of julian centuries
        int julianCenturiesSquared = pow(julianCenturies,2);
        int julianCenturiesCubed = pow(julianCenturies, 3);

        double degToRad = CONST_DEG_TO_RAD / 3600.0;

        double zeta = ((2306.2181 * julianCenturies) + (0.30188 * julianCenturiesSquared) + (0.017998 * julianCenturiesCubed)) * degToRad;
        double theta = ((2004.3109 * julianCenturies) - (0.42665 * julianCenturiesSquared) - (0.041833 * julianCenturiesCubed)) * degToRad;
        double z    = ((2306.2181 * julianCenturies) + (1.09468 * julianCenturiesSquared) + (0.018203 * julianCenturiesCubed)) * degToRad;

        double coszeta = cos(zeta);
        double sinzeta = sin(zeta);
        double costheta = cos(theta);
        double sintheta = cos(theta);
        double cosz = cos(z);
        double sinz = sin(z);

        double row1col1 = (coszeta * costheta * cosz) - (sinzeta * sinz);
        double row1col2 = (coszeta * costheta * sinz) + (sinzeta * cosz);
        double row1col3 =  coszeta * sintheta;
        double row2col1 = (-sinzeta * costheta * cosz) - (coszeta * sinz);
        double row2col2 = (-sinzeta * costheta * sinz) + (coszeta * cosz);
        double row2col3 = -sinzeta * sintheta;
        double row3col1 = -sintheta * cosz;
        double row3col2 = -sintheta * sinz;
        double row3col3 =  costheta;

        // Transformation matrix
        mat3 prec = mat3(row1col1, row2col1, row3col1, row1col2, row2col2, row3col2,row1col3, row2col3, row3col3);
        return pos * prec;
    }

    vec3 eci2teme(vec3 pos){
        return vec3();
    }

    vec3 teme2ecef(vec3 steme, vec3 rteme, vec3 vteme, vec3 ateme, int julianCenturies, int julianDate, int lod, double xp, double yp, int eqeterms){
        double gmst = gstime(julianDate);
        double omega = 125.04452222  + (   (-6962890.5390 * julianCenturies) + (7.455 * pow(julianCenturies, 2)) + (0.008 * pow(julianCenturies, 3)) )  / 3600.0;
        omega = fmod( omega, 360.0  ) * CONST_DEG_TO_RAD;


    }
}