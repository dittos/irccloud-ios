//
//  ColorFormatter.h
//  IRCCloud
//
//  Created by Sam Steele on 3/1/13.
//  Copyright (c) 2013 IRCCloud, Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

#define BOLD 2
#define COLOR_MIRC 3
#define COLOR_RGB 4
#define CLEAR 15
#define ITALICS 16
#define UNDERLINE 31

@interface ColorFormatter : NSObject
+(NSAttributedString *)format:(NSString *)input defaultColor:(UIColor *)color;
@end