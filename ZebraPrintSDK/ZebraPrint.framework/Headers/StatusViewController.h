//
//  status.h
//  ZebraPrint
//
//  Created by Mphasis on 2/25/19.
//  Copyright © 2019 Hariprasad. All rights reserved.
//

#ifndef status_h
#define status_h
#import <QuartzCore/QuartzCore.h>
#import "ZebraPrinterConnection.h"
#import "TcpPrinterConnection.h"
#import "ZebraPrinter.h"
#import "ZebraPrinterFactory.h"
#import "PrinterStatus.h"
#import "PrinterStatusMessages.h"
#import "MfiBtPrinterConnection.h"
@interface StatusViewController : NSObject

-(void) performStatusDemo;

@end
#endif /* status_h */
