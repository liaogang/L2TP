## L2TP

###
在App里创建一个VPN　L2TP的配置

### 动机 　

iOS只提供了添加IPSec 和IKEV2的接口。L2TP和PPTP是苹果私有的。

```
If you want to connect programatically in ios 8 you can use only IPSec or IKEv2 protocols. L2TP and PPTP protocols are private for apple. It is not possible to use L2TP and PPTP APIs in your applications. Only Apple is currently using these APIs.
```


Create L2TP in iOS with NetworkExtension

Here we use the Undocumented API NEVPNProtocolL2TP and some little trick

## Test

(X)I use `mac os Server` to start a L2TP service(X)

(X)Tested in iOS9 and iOS11(X)

Although the system says is connected.  
The network traffic seems NOT go through the vpn server.  
Something must be missing,or the Apple do not realy add the L2TP Interface yet. 



## ToDo

iOS save the personal vpn configure path: 
`/Library/Preferences/com.apple.networkextension.plist`

Look into those file:
NetworkExtesion.framework　,pppd and neSessionManager.
