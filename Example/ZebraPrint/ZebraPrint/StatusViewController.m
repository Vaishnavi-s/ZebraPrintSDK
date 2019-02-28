//
//  status.m
//  ZebraPrint
//
//  Created by Mphasis on 2/25/19.
//  Copyright © 2019 Hariprasad. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "StatusViewController.h"
#import "ZebraPrinterConnection.h"
#import "TcpPrinterConnection.h"
#import "ZebraPrinter.h"
#import "ZebraPrinterFactory.h"
#import "PrinterStatus.h"
#import "PrinterStatusMessages.h"
#import "MfiBtPrinterConnection.h"

@implementation StatusViewController

- (void) performStatusDemo {
    
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
