//mode.h

/*
*Ce header définit des valeurs permattant
*d'utiliser facilement les variables de type mode_t
*/


#ifndef MODE_H_
#define MODE_H_

#if !defined (_WIN16) && !defined (_WIN32) && !defined (_WIN64)

#define m000 
#define m001 S_IXOTH
#define m002 S_IWOTH
#define m003 S_IXOTH | S_IWOTH
#define m004 S_IROTH
#define m005 S_IXOTH | S_IROTH
#define m006 S_IROTH | S_IWOTH
#define m007 S_IXOTH | S_IWOTH | S_IROTH
#define m010 S_IXGRP
#define m011 S_IXGRP | S_IXOTH
#define m012 S_IXGRP | S_IWOTH
#define m013 S_IXGRP | S_IXOTH | S_IWOTH
#define m014 S_IXGRP | S_IROTH
#define m015 S_IXGRP | S_IXOTH | S_IROTH
#define m016 S_IXGRP | S_IROTH | S_IWOTH
#define m017 S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m020 S_IWGRP
#define m021 S_IWGRP | S_IXOTH
#define m022 S_IWGRP | S_IWOTH
#define m023 S_IWGRP | S_IXOTH | S_IWOTH
#define m024 S_IWGRP | S_IROTH
#define m025 S_IWGRP | S_IXOTH | S_IROTH
#define m026 S_IWGRP | S_IROTH | S_IWOTH
#define m027 S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m030 S_IXGRP | S_IWGRP
#define m031 S_IXGRP | S_IWGRP | S_IXOTH
#define m032 S_IXGRP | S_IWGRP | S_IWOTH
#define m033 S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m034 S_IXGRP | S_IWGRP | S_IROTH
#define m035 S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m036 S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m037 S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m040 S_IRGRP
#define m041 S_IRGRP | S_IXOTH
#define m042 S_IRGRP | S_IWOTH
#define m043 S_IRGRP | S_IXOTH | S_IWOTH
#define m044 S_IRGRP | S_IROTH
#define m045 S_IRGRP | S_IXOTH | S_IROTH
#define m046 S_IRGRP | S_IROTH | S_IWOTH
#define m047 S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m050 S_IXGRP | S_IRGRP
#define m051 S_IXGRP | S_IRGRP | S_IXOTH
#define m052 S_IXGRP | S_IRGRP | S_IWOTH
#define m053 S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m054 S_IXGRP | S_IRGRP | S_IROTH
#define m055 S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m056 S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m057 S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m060 S_IRGRP | S_IWGRP
#define m061 S_IRGRP | S_IWGRP | S_IXOTH
#define m062 S_IRGRP | S_IWGRP | S_IWOTH
#define m063 S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m064 S_IRGRP | S_IWGRP | S_IROTH
#define m065 S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m066 S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m067 S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m070 S_IXGRP | S_IWGRP | S_IRGRP
#define m071 S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m072 S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m073 S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m074 S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m075 S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m076 S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m077 S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m100 S_IXUSR
#define m101 S_IXUSR | S_IXOTH
#define m102 S_IXUSR | S_IWOTH
#define m103 S_IXUSR | S_IXOTH | S_IWOTH
#define m104 S_IXUSR | S_IROTH
#define m105 S_IXUSR | S_IXOTH | S_IROTH
#define m106 S_IXUSR | S_IROTH | S_IWOTH
#define m107 S_IXUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m110 S_IXUSR | S_IXGRP
#define m111 S_IXUSR | S_IXGRP | S_IXOTH
#define m112 S_IXUSR | S_IXGRP | S_IWOTH
#define m113 S_IXUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m114 S_IXUSR | S_IXGRP | S_IROTH
#define m115 S_IXUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m116 S_IXUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m117 S_IXUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m120 S_IXUSR | S_IWGRP
#define m121 S_IXUSR | S_IWGRP | S_IXOTH
#define m122 S_IXUSR | S_IWGRP | S_IWOTH
#define m123 S_IXUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m124 S_IXUSR | S_IWGRP | S_IROTH
#define m125 S_IXUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m126 S_IXUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m127 S_IXUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m130 S_IXUSR | S_IXGRP | S_IWGRP
#define m131 S_IXUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m132 S_IXUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m133 S_IXUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m134 S_IXUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m135 S_IXUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m136 S_IXUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m137 S_IXUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m140 S_IXUSR | S_IRGRP
#define m141 S_IXUSR | S_IRGRP | S_IXOTH
#define m142 S_IXUSR | S_IRGRP | S_IWOTH
#define m143 S_IXUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m144 S_IXUSR | S_IRGRP | S_IROTH
#define m145 S_IXUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m146 S_IXUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m147 S_IXUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m150 S_IXUSR | S_IXGRP | S_IRGRP
#define m151 S_IXUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m152 S_IXUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m153 S_IXUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m154 S_IXUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m155 S_IXUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m156 S_IXUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m157 S_IXUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m160 S_IXUSR | S_IRGRP | S_IWGRP
#define m161 S_IXUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m162 S_IXUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m163 S_IXUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m164 S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m165 S_IXUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m166 S_IXUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m167 S_IXUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m170 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m171 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m172 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m173 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m174 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m175 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m176 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m177 S_IXUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m200 S_IWUSR
#define m201 S_IWUSR | S_IXOTH
#define m202 S_IWUSR | S_IWOTH
#define m203 S_IWUSR | S_IXOTH | S_IWOTH
#define m204 S_IWUSR | S_IROTH
#define m205 S_IWUSR | S_IXOTH | S_IROTH
#define m206 S_IWUSR | S_IROTH | S_IWOTH
#define m207 S_IWUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m210 S_IWUSR | S_IXGRP
#define m211 S_IWUSR | S_IXGRP | S_IXOTH
#define m212 S_IWUSR | S_IXGRP | S_IWOTH
#define m213 S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m214 S_IWUSR | S_IXGRP | S_IROTH
#define m215 S_IWUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m216 S_IWUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m217 S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m220 S_IWUSR | S_IWGRP
#define m221 S_IWUSR | S_IWGRP | S_IXOTH
#define m222 S_IWUSR | S_IWGRP | S_IWOTH
#define m223 S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m224 S_IWUSR | S_IWGRP | S_IROTH
#define m225 S_IWUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m226 S_IWUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m227 S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m230 S_IWUSR | S_IXGRP | S_IWGRP
#define m231 S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m232 S_IWUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m233 S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m234 S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m235 S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m236 S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m237 S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m240 S_IWUSR | S_IRGRP
#define m241 S_IWUSR | S_IRGRP | S_IXOTH
#define m242 S_IWUSR | S_IRGRP | S_IWOTH
#define m243 S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m244 S_IWUSR | S_IRGRP | S_IROTH
#define m245 S_IWUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m246 S_IWUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m247 S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m250 S_IWUSR | S_IXGRP | S_IRGRP
#define m251 S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m252 S_IWUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m253 S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m254 S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m255 S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m256 S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m257 S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m260 S_IWUSR | S_IRGRP | S_IWGRP
#define m261 S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m262 S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m263 S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m264 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m265 S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m266 S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m267 S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m270 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m271 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m272 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m273 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m274 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m275 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m276 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m277 S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m300 S_IXUSR | S_IWUSR
#define m301 S_IXUSR | S_IWUSR | S_IXOTH
#define m302 S_IXUSR | S_IWUSR | S_IWOTH
#define m303 S_IXUSR | S_IWUSR | S_IXOTH | S_IWOTH
#define m304 S_IXUSR | S_IWUSR | S_IROTH
#define m305 S_IXUSR | S_IWUSR | S_IXOTH | S_IROTH
#define m306 S_IXUSR | S_IWUSR | S_IROTH | S_IWOTH
#define m307 S_IXUSR | S_IWUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m310 S_IXUSR | S_IWUSR | S_IXGRP
#define m311 S_IXUSR | S_IWUSR | S_IXGRP | S_IXOTH
#define m312 S_IXUSR | S_IWUSR | S_IXGRP | S_IWOTH
#define m313 S_IXUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m314 S_IXUSR | S_IWUSR | S_IXGRP | S_IROTH
#define m315 S_IXUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m316 S_IXUSR | S_IWUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m317 S_IXUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m320 S_IXUSR | S_IWUSR | S_IWGRP
#define m321 S_IXUSR | S_IWUSR | S_IWGRP | S_IXOTH
#define m322 S_IXUSR | S_IWUSR | S_IWGRP | S_IWOTH
#define m323 S_IXUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m324 S_IXUSR | S_IWUSR | S_IWGRP | S_IROTH
#define m325 S_IXUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m326 S_IXUSR | S_IWUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m327 S_IXUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m330 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP
#define m331 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m332 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m333 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m334 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m335 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m336 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m337 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m340 S_IXUSR | S_IWUSR | S_IRGRP
#define m341 S_IXUSR | S_IWUSR | S_IRGRP | S_IXOTH
#define m342 S_IXUSR | S_IWUSR | S_IRGRP | S_IWOTH
#define m343 S_IXUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m344 S_IXUSR | S_IWUSR | S_IRGRP | S_IROTH
#define m345 S_IXUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m346 S_IXUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m347 S_IXUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m350 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP
#define m351 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m352 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m353 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m354 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m355 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m356 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m357 S_IXUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m360 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP
#define m361 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m362 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m363 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m364 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m365 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m366 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m367 S_IXUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m370 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m371 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m372 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m373 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m374 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m375 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m376 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m377 S_IXUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m400 S_IRUSR
#define m401 S_IRUSR | S_IXOTH
#define m402 S_IRUSR | S_IWOTH
#define m403 S_IRUSR | S_IXOTH | S_IWOTH
#define m404 S_IRUSR | S_IROTH
#define m405 S_IRUSR | S_IXOTH | S_IROTH
#define m406 S_IRUSR | S_IROTH | S_IWOTH
#define m407 S_IRUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m410 S_IRUSR | S_IXGRP
#define m411 S_IRUSR | S_IXGRP | S_IXOTH
#define m412 S_IRUSR | S_IXGRP | S_IWOTH
#define m413 S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m414 S_IRUSR | S_IXGRP | S_IROTH
#define m415 S_IRUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m416 S_IRUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m417 S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m420 S_IRUSR | S_IWGRP
#define m421 S_IRUSR | S_IWGRP | S_IXOTH
#define m422 S_IRUSR | S_IWGRP | S_IWOTH
#define m423 S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m424 S_IRUSR | S_IWGRP | S_IROTH
#define m425 S_IRUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m426 S_IRUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m427 S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m430 S_IRUSR | S_IXGRP | S_IWGRP
#define m431 S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m432 S_IRUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m433 S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m434 S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m435 S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m436 S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m437 S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m440 S_IRUSR | S_IRGRP
#define m441 S_IRUSR | S_IRGRP | S_IXOTH
#define m442 S_IRUSR | S_IRGRP | S_IWOTH
#define m443 S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m444 S_IRUSR | S_IRGRP | S_IROTH
#define m445 S_IRUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m446 S_IRUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m447 S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m450 S_IRUSR | S_IXGRP | S_IRGRP
#define m451 S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m452 S_IRUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m453 S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m454 S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m455 S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m456 S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m457 S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m460 S_IRUSR | S_IRGRP | S_IWGRP
#define m461 S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m462 S_IRUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m463 S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m464 S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m465 S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m466 S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m467 S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m470 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m471 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m472 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m473 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m474 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m475 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m476 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m477 S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m500 S_IXUSR | S_IRUSR
#define m501 S_IXUSR | S_IRUSR | S_IXOTH
#define m502 S_IXUSR | S_IRUSR | S_IWOTH
#define m503 S_IXUSR | S_IRUSR | S_IXOTH | S_IWOTH
#define m504 S_IXUSR | S_IRUSR | S_IROTH
#define m505 S_IXUSR | S_IRUSR | S_IXOTH | S_IROTH
#define m506 S_IXUSR | S_IRUSR | S_IROTH | S_IWOTH
#define m507 S_IXUSR | S_IRUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m510 S_IXUSR | S_IRUSR | S_IXGRP
#define m511 S_IXUSR | S_IRUSR | S_IXGRP | S_IXOTH
#define m512 S_IXUSR | S_IRUSR | S_IXGRP | S_IWOTH
#define m513 S_IXUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m514 S_IXUSR | S_IRUSR | S_IXGRP | S_IROTH
#define m515 S_IXUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m516 S_IXUSR | S_IRUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m517 S_IXUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m520 S_IXUSR | S_IRUSR | S_IWGRP
#define m521 S_IXUSR | S_IRUSR | S_IWGRP | S_IXOTH
#define m522 S_IXUSR | S_IRUSR | S_IWGRP | S_IWOTH
#define m523 S_IXUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m524 S_IXUSR | S_IRUSR | S_IWGRP | S_IROTH
#define m525 S_IXUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m526 S_IXUSR | S_IRUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m527 S_IXUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m530 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP
#define m531 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m532 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m533 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m534 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m535 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m536 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m537 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m540 S_IXUSR | S_IRUSR | S_IRGRP
#define m541 S_IXUSR | S_IRUSR | S_IRGRP | S_IXOTH
#define m542 S_IXUSR | S_IRUSR | S_IRGRP | S_IWOTH
#define m543 S_IXUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m544 S_IXUSR | S_IRUSR | S_IRGRP | S_IROTH
#define m545 S_IXUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m546 S_IXUSR | S_IRUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m547 S_IXUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m550 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP
#define m551 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m552 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m553 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m554 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m555 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m556 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m557 S_IXUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m560 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP
#define m561 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m562 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m563 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m564 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m565 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m566 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m567 S_IXUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m570 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m571 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m572 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m573 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m574 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m575 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m576 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m577 S_IXUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m600 S_IRUSR | S_IWUSR
#define m601 S_IRUSR | S_IWUSR | S_IXOTH
#define m602 S_IRUSR | S_IWUSR | S_IWOTH
#define m603 S_IRUSR | S_IWUSR | S_IXOTH | S_IWOTH
#define m604 S_IRUSR | S_IWUSR | S_IROTH
#define m605 S_IRUSR | S_IWUSR | S_IXOTH | S_IROTH
#define m606 S_IRUSR | S_IWUSR | S_IROTH | S_IWOTH
#define m607 S_IRUSR | S_IWUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m610 S_IRUSR | S_IWUSR | S_IXGRP
#define m611 S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH
#define m612 S_IRUSR | S_IWUSR | S_IXGRP | S_IWOTH
#define m613 S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m614 S_IRUSR | S_IWUSR | S_IXGRP | S_IROTH
#define m615 S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m616 S_IRUSR | S_IWUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m617 S_IRUSR | S_IWUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m620 S_IRUSR | S_IWUSR | S_IWGRP
#define m621 S_IRUSR | S_IWUSR | S_IWGRP | S_IXOTH
#define m622 S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH
#define m623 S_IRUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m624 S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH
#define m625 S_IRUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m626 S_IRUSR | S_IWUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m627 S_IRUSR | S_IWUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m630 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP
#define m631 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m632 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m633 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m634 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m635 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m636 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m637 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m640 S_IRUSR | S_IWUSR | S_IRGRP
#define m641 S_IRUSR | S_IWUSR | S_IRGRP | S_IXOTH
#define m642 S_IRUSR | S_IWUSR | S_IRGRP | S_IWOTH
#define m643 S_IRUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m644 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define m645 S_IRUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m646 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m647 S_IRUSR | S_IWUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m650 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP
#define m651 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m652 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m653 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m654 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m655 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m656 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m657 S_IRUSR | S_IWUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m660 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP
#define m661 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m662 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m663 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m664 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m665 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m666 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m667 S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m670 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m671 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m672 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m673 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m674 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m675 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m676 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m677 S_IRUSR | S_IWUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m700 S_IXUSR | S_IWUSR | S_IRUSR
#define m701 S_IXUSR | S_IWUSR | S_IRUSR | S_IXOTH
#define m702 S_IXUSR | S_IWUSR | S_IRUSR | S_IWOTH
#define m703 S_IXUSR | S_IWUSR | S_IRUSR | S_IXOTH | S_IWOTH
#define m704 S_IXUSR | S_IWUSR | S_IRUSR | S_IROTH
#define m705 S_IXUSR | S_IWUSR | S_IRUSR | S_IXOTH | S_IROTH
#define m706 S_IXUSR | S_IWUSR | S_IRUSR | S_IROTH | S_IWOTH
#define m707 S_IXUSR | S_IWUSR | S_IRUSR | S_IXOTH | S_IWOTH | S_IROTH
#define m710 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP
#define m711 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IXOTH
#define m712 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWOTH
#define m713 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH
#define m714 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IROTH
#define m715 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IROTH
#define m716 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IROTH | S_IWOTH
#define m717 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m720 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP
#define m721 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IXOTH
#define m722 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IWOTH
#define m723 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH
#define m724 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH
#define m725 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IROTH
#define m726 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IROTH | S_IWOTH
#define m727 S_IXUSR | S_IWUSR | S_IRUSR | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m730 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP
#define m731 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH
#define m732 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IWOTH
#define m733 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m734 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH
#define m735 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m736 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m737 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m740 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP
#define m741 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IXOTH
#define m742 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWOTH
#define m743 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH
#define m744 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH
#define m745 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IROTH
#define m746 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH | S_IWOTH
#define m747 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m750 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP
#define m751 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH
#define m752 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IWOTH
#define m753 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m754 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH
#define m755 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m756 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m757 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m760 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP
#define m761 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH
#define m762 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IWOTH
#define m763 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH
#define m764 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH
#define m765 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IROTH
#define m766 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH
#define m767 S_IXUSR | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IXOTH | S_IWOTH | S_IROTH
#define m770 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP
#define m771 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH
#define m772 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IWOTH
#define m773 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH
#define m774 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH
#define m775 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IROTH
#define m776 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IROTH | S_IWOTH
#define m777 S_IXUSR | S_IWUSR | S_IRUSR | S_IXGRP | S_IWGRP | S_IRGRP | S_IXOTH | S_IWOTH | S_IROTH

#else

#define m000 0
#define m001 0
#define m002 0
#define m003 0
#define m004 0
#define m005 0
#define m006 0
#define m007 0
#define m010 0
#define m011 0
#define m012 0
#define m013 0
#define m014 0
#define m015 0
#define m016 0
#define m017 0
#define m020 0
#define m021 0
#define m022 0
#define m023 0
#define m024 0
#define m025 0
#define m026 0
#define m027 0
#define m030 0
#define m031 0
#define m032 0
#define m033 0
#define m034 0
#define m035 0
#define m036 0
#define m037 0
#define m040 0
#define m041 0
#define m042 0
#define m043 0
#define m044 0
#define m045 0
#define m046 0
#define m047 0
#define m050 0
#define m051 0
#define m052 0
#define m053 0
#define m054 0
#define m055 0
#define m056 0
#define m057 0
#define m060 0
#define m061 0
#define m062 0
#define m063 0
#define m064 0
#define m065 0
#define m066 0
#define m067 0
#define m070 0
#define m071 0
#define m072 0
#define m073 0
#define m074 0
#define m075 0
#define m076 0
#define m077 0
#define m100 0
#define m101 0
#define m102 0
#define m103 0
#define m104 0
#define m105 0
#define m106 0
#define m107 0
#define m110 0
#define m111 0
#define m112 0
#define m113 0
#define m114 0
#define m115 0
#define m116 0
#define m117 0
#define m120 0
#define m121 0
#define m122 0
#define m123 0
#define m124 0
#define m125 0
#define m126 0
#define m127 0
#define m130 0
#define m131 0
#define m132 0
#define m133 0
#define m134 0
#define m135 0
#define m136 0
#define m137 0
#define m140 0
#define m141 0
#define m142 0
#define m143 0
#define m144 0
#define m145 0
#define m146 0
#define m147 0
#define m150 0
#define m151 0
#define m152 0
#define m153 0
#define m154 0
#define m155 0
#define m156 0
#define m157 0
#define m160 0
#define m161 0
#define m162 0
#define m163 0
#define m164 0
#define m165 0
#define m166 0
#define m167 0
#define m170 0
#define m171 0
#define m172 0
#define m173 0
#define m174 0
#define m175 0
#define m176 0
#define m177 0
#define m200 0
#define m201 0
#define m202 0
#define m203 0
#define m204 0
#define m205 0
#define m206 0
#define m207 0
#define m210 0
#define m211 0
#define m212 0
#define m213 0
#define m214 0
#define m215 0
#define m216 0
#define m217 0
#define m220 0
#define m221 0
#define m222 0
#define m223 0
#define m224 0
#define m225 0
#define m226 0
#define m227 0
#define m230 0
#define m231 0
#define m232 0
#define m233 0
#define m234 0
#define m235 0
#define m236 0
#define m237 0
#define m240 0
#define m241 0
#define m242 0
#define m243 0
#define m244 0
#define m245 0
#define m246 0
#define m247 0
#define m250 0
#define m251 0
#define m252 0
#define m253 0
#define m254 0
#define m255 0
#define m256 0
#define m257 0
#define m260 0
#define m261 0
#define m262 0
#define m263 0
#define m264 0
#define m265 0
#define m266 0
#define m267 0
#define m270 0
#define m271 0
#define m272 0
#define m273 0
#define m274 0
#define m275 0
#define m276 0
#define m277 0
#define m300 0
#define m301 0
#define m302 0
#define m303 0
#define m304 0
#define m305 0
#define m306 0
#define m307 0
#define m310 0
#define m311 0
#define m312 0
#define m313 0
#define m314 0
#define m315 0
#define m316 0
#define m317 0
#define m320 0
#define m321 0
#define m322 0
#define m323 0
#define m324 0
#define m325 0
#define m326 0
#define m327 0
#define m330 0
#define m331 0
#define m332 0
#define m333 0
#define m334 0
#define m335 0
#define m336 0
#define m337 0
#define m340 0
#define m341 0
#define m342 0
#define m343 0
#define m344 0
#define m345 0
#define m346 0
#define m347 0
#define m350 0
#define m351 0
#define m352 0
#define m353 0
#define m354 0
#define m355 0
#define m356 0
#define m357 0
#define m360 0
#define m361 0
#define m362 0
#define m363 0
#define m364 0
#define m365 0
#define m366 0
#define m367 0
#define m370 0
#define m371 0
#define m372 0
#define m373 0
#define m374 0
#define m375 0
#define m376 0
#define m377 0
#define m400 0
#define m401 0
#define m402 0
#define m403 0
#define m404 0
#define m405 0
#define m406 0
#define m407 0
#define m410 0
#define m411 0
#define m412 0
#define m413 0
#define m414 0
#define m415 0
#define m416 0
#define m417 0
#define m420 0
#define m421 0
#define m422 0
#define m423 0
#define m424 0
#define m425 0
#define m426 0
#define m427 0
#define m430 0
#define m431 0
#define m432 0
#define m433 0
#define m434 0
#define m435 0
#define m436 0
#define m437 0
#define m440 0
#define m441 0
#define m442 0
#define m443 0
#define m444 0
#define m445 0
#define m446 0
#define m447 0
#define m450 0
#define m451 0
#define m452 0
#define m453 0
#define m454 0
#define m455 0
#define m456 0
#define m457 0
#define m460 0
#define m461 0
#define m462 0
#define m463 0
#define m464 0
#define m465 0
#define m466 0
#define m467 0
#define m470 0
#define m471 0
#define m472 0
#define m473 0
#define m474 0
#define m475 0
#define m476 0
#define m477 0
#define m500 0
#define m501 0
#define m502 0
#define m503 0
#define m504 0
#define m505 0
#define m506 0
#define m507 0
#define m510 0
#define m511 0
#define m512 0
#define m513 0
#define m514 0
#define m515 0
#define m516 0
#define m517 0
#define m520 0
#define m521 0
#define m522 0
#define m523 0
#define m524 0
#define m525 0
#define m526 0
#define m527 0
#define m530 0
#define m531 0
#define m532 0
#define m533 0
#define m534 0
#define m535 0
#define m536 0
#define m537 0
#define m540 0
#define m541 0
#define m542 0
#define m543 0
#define m544 0
#define m545 0
#define m546 0
#define m547 0
#define m550 0
#define m551 0
#define m552 0
#define m553 0
#define m554 0
#define m555 0
#define m556 0
#define m557 0
#define m560 0
#define m561 0
#define m562 0
#define m563 0
#define m564 0
#define m565 0
#define m566 0
#define m567 0
#define m570 0
#define m571 0
#define m572 0
#define m573 0
#define m574 0
#define m575 0
#define m576 0
#define m577 0
#define m600 0
#define m601 0
#define m602 0
#define m603 0
#define m604 0
#define m605 0
#define m606 0
#define m607 0
#define m610 0
#define m611 0
#define m612 0
#define m613 0
#define m614 0
#define m615 0
#define m616 0
#define m617 0
#define m620 0
#define m621 0
#define m622 0
#define m623 0
#define m624 0
#define m625 0
#define m626 0
#define m627 0
#define m630 0
#define m631 0
#define m632 0
#define m633 0
#define m634 0
#define m635 0
#define m636 0
#define m637 0
#define m640 0
#define m641 0
#define m642 0
#define m643 0
#define m644 0
#define m645 0
#define m646 0
#define m647 0
#define m650 0
#define m651 0
#define m652 0
#define m653 0
#define m654 0
#define m655 0
#define m656 0
#define m657 0
#define m660 0
#define m661 0
#define m662 0
#define m663 0
#define m664 0
#define m665 0
#define m666 0
#define m667 0
#define m670 0
#define m671 0
#define m672 0
#define m673 0
#define m674 0
#define m675 0
#define m676 0
#define m677 0
#define m700 0
#define m701 0
#define m702 0
#define m703 0
#define m704 0
#define m705 0
#define m706 0
#define m707 0
#define m710 0
#define m711 0
#define m712 0
#define m713 0
#define m714 0
#define m715 0
#define m716 0
#define m717 0
#define m720 0
#define m721 0
#define m722 0
#define m723 0
#define m724 0
#define m725 0
#define m726 0
#define m727 0
#define m730 0
#define m731 0
#define m732 0
#define m733 0
#define m734 0
#define m735 0
#define m736 0
#define m737 0
#define m740 0
#define m741 0
#define m742 0
#define m743 0
#define m744 0
#define m745 0
#define m746 0
#define m747 0
#define m750 0
#define m751 0
#define m752 0
#define m753 0
#define m754 0
#define m755 0
#define m756 0
#define m757 0
#define m760 0
#define m761 0
#define m762 0
#define m763 0
#define m764 0
#define m765 0
#define m766 0
#define m767 0
#define m770 0
#define m771 0
#define m772 0
#define m773 0
#define m774 0
#define m775 0
#define m776 0
#define m777 0

#endif //(_WIN16) || defined (_WIN32) || defined (_WIN64)

#endif //MODE_H_
