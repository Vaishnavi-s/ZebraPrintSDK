//
//  ZebraPrint.h
//  ZebraPrint
//
//  Created by Hariprasad on 29/01/19.
//  Copyright © 2019 Hariprasad. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <ZebraPrint/MfiBtPrinterConnection.h>
#import <ZebraPrint/DiscoveredPrinter.h
#import <ZebraPrint/DiscoveredPrinterNetwork.h>
#import <ZebraPrint/FieldDescriptionData.h>
#import <ZebraPrint/FileUtil.h>
#import <ZebraPrint/FormalUtil.h>
#import <ZebraPrint/GraphicsUtil.h>
#import <ZebraPrint/MagCardReader.h>
#import <ZebraPrint/NetworkDiscover.h>
#import <ZebraPrint/PrinterStatus.h>
#import <ZebraPrint/PrinterStatusMessages.h>
#import <ZebraPrint/ResponseValidator.h>
#import <ZebraPrint/SGD.h>
#import <ZebraPrint/SmartCardReader.h>
#import <ZebraPrint/TcpPrinterConnection.h>
#import <ZebraPrint/ToolsUtil.h>
#import <ZebraPrint/ZebraErrorCode.h>
#import <ZebraPrint/ZebraPrinter.h>
#import <ZebraPrint/ZebraPrinterConnection.h>
#import <ZebraPrint/ZebraPrinterFactory.h>
#import <ZebraPrint/StatusDemo.h>
#import <ZebraPrint/ZplPrintMode.h>
//! Project version number for ZebraPrint.
FOUNDATION_EXPORT double ZebraPrintVersionNumber;

//! Project version string for ZebraPrint.
FOUNDATION_EXPORT const unsigned char ZebraPrintVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <ZebraPrint/PublicHeader.h>
#import <Foundation/Foundation.h>

@interface ZebraPrint : NSObject{
    
}
    
+(void)performStatusDemo;
    
    @end
@implementation StatusDemo
    
+(void) performStatusDemo {
    
    id<ZebraPrinterConnection, NSObject> connection = nil;
    NSArray *printerStatusMessagesArray = nil;
    connection = [[MfiBtPrinterConnection alloc] initWithSerialNumber:@"XXQPJ162400947"] ;
    BOOL didOpen = [connection open];
    if(didOpen == YES) {
        NSError *error = nil;
        id<ZebraPrinter,NSObject> printer = [ZebraPrinterFactory getInstance:connection error:&error];
        NSLog(@"Printer:%@",printer);
        if(printer != nil) {
            //            PrinterLanguage language = [printer getPrinterControlLanguage];
            
            PrinterStatus *status = [printer getCurrentStatus:&error];
            NSLog(@"Status:%@",status);
            if (status == nil) {
                NSLog(@"Error retreiving status");
            } else {
                PrinterStatusMessages *printerStatusMessages = [[PrinterStatusMessages alloc] initWithPrinterStatus:status] ;
                NSLog(@"Message:%@",printerStatusMessages);
                printerStatusMessagesArray = [printerStatusMessages getStatusMessage];
                NSLog(@"MessageArray:%@",printerStatusMessagesArray);
                
            }
        } else {
            NSLog(@"Could not Detect Language");
        }
    } else {
        NSLog(@"Could not connect to printer");
    }
}
    @end


