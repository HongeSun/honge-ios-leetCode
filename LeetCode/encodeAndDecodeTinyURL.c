//
//  encodeAndDecodeTinyURL.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/7.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "encodeAndDecodeTinyURL.h"

char* encode(char* longUrl) {
    char *shortUrl = NULL;
    char *hostEnd = NULL;
    char relation[5] = {0, 1, 2, 3, 4};
    
    
    while (*longUrl != '\0') {
        printf("char is %c.\n", *longUrl);
        
        if (hostEnd == NULL) {
            if (*longUrl == '.' && *(longUrl+1) == 'c' && *(longUrl+2) == 'o' && *(longUrl+3) == 'm') {
                hostEnd = longUrl+3;
            }
        }
        
        
        
        ++longUrl;
    }
    return shortUrl;
}

char* decode(char* shortUrl) {
    char relation[5] = {0, 1, 2, 3, 4};
    
    
    return shortUrl;
}
