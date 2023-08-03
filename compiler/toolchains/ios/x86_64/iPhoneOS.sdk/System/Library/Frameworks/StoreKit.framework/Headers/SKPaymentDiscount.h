//
//  SKPaymentDiscount.h
//  StoreKit
//
//  Copyright © 2018 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKitDefines.h>

NS_ASSUME_NONNULL_BEGIN

SK_EXTERN_CLASS API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2)) NS_SWIFT_SENDABLE @interface SKPaymentDiscount : NSObject {
@private
    id _internal;
}

- (instancetype)initWithIdentifier:(NSString *)identifier
                     keyIdentifier:(NSString *)keyIdentifier
                             nonce:(NSUUID *)nonce
                         signature:(NSString *)signature
                         timestamp:(NSNumber *)timestamp API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

// Identifier agreed upon with the App Store for a discount of your choosing.
@property(nonatomic, copy, readonly) NSString *identifier API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

// The identifier of the public/private key pair agreed upon with the App Store when the keys were generated.
@property(nonatomic, copy, readonly) NSString *keyIdentifier API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

// One-time use random entropy-adding value for security.
@property(nonatomic, copy, readonly) NSUUID *nonce API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

// The cryptographic signature generated by your private key.
@property(nonatomic, copy, readonly) NSString *signature API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

// Timestamp of when the signature is created.
@property(nonatomic, copy, readonly) NSNumber *timestamp API_AVAILABLE(ios(12.2), macos(10.14.4), watchos(6.2));

@end

NS_ASSUME_NONNULL_END
