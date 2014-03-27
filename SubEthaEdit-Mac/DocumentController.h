//
//  DocumentController.h
//  SubEthaEdit
//
//  Created by Dominik Wagner on Thu Mar 25 2004.
//  Copyright (c) 2004-2006 TheCodingMonkeys. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class TCMMMSession;
@class EncodingPopUpButton;
@class DocumentModePopUpButton;
@class DocumentMode;
@class PlainTextWindowController;
@class MAAttachedWindow;
@class PlainTextDocument;

@interface DocumentController : NSDocumentController {    
    IBOutlet NSPanel *O_modeInstallerPanel;
    IBOutlet NSTextField *O_modeInstallerMessageTextField;
    IBOutlet NSMatrix *O_modeInstallerDomainMatrix;
    IBOutlet NSTextField *O_modeInstallerInformativeTextField;
	
    NSMutableDictionary *I_propertiesForOpenedFiles;
    NSMutableDictionary *I_suspendedSeeScriptCommands;
    NSMutableDictionary *I_refCountsOfSeeScriptCommands;
    NSMutableDictionary *I_waitingDocuments;
    NSMutableArray *I_pipingSeeScriptCommands;
    
    NSString *I_currentModeFileName;
        
    @private
    NSMutableArray *I_windowControllers;
}

@property (nonatomic, readonly, assign) NSStringEncoding encodingFromLastRunOpenPanel;
@property (nonatomic, readonly, copy) NSString *modeIdentifierFromLastRunOpenPanel;

+ (DocumentController *)sharedInstance;

- (IBAction)showDocumentListWindow:(id)sender;

- (NSMenu *)documentMenu;

- (IBAction)alwaysShowTabBar:(id)sender;

- (IBAction)changeModeInstallationDomain:(id)sender;

- (IBAction)installMode:(id)sender;
- (IBAction)cancelModeInstallation:(id)sender;
- (IBAction)openNormalDocument:(id)aSender;
- (IBAction)openAlternateDocument:(id)aSender;

- (void)addProxyDocumentWithSession:(TCMMMSession *)aSession;

- (NSArray *)documentsInMode:(DocumentMode *)aDocumentMode;

- (IBAction)menuValidationNoneAction:(id)aSender;

- (BOOL)isDocumentFromLastRunOpenPanel:(NSDocument *)aDocument;
- (NSDictionary *)propertiesForOpenedFile:(NSString *)fileName;

- (PlainTextDocument *)frontmostPlainTextDocument;

- (id)handleOpenScriptCommand:(NSScriptCommand *)command;
- (id)handlePrintScriptCommand:(NSScriptCommand *)command;
- (id)handleSeeScriptCommand:(NSScriptCommand *)command;

- (PlainTextWindowController *)activeWindowController;
- (void)addWindowController:(id)aWindowController;
- (void)removeWindowController:(id)aWindowController;

- (void)updateTabMenu;

- (void)newDocumentInTab:(id)sender;
- (void)newDocumentWithModeMenuItem:(id)aSender;
@end
