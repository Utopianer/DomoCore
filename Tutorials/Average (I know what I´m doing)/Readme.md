This tutorial is intended for people, who already setup Masternodes, know how to navigate through the Server and only need the minimal informations to start the masternode.

In the following Tutorial "Main Wallet" is referred to your local wallet where your 1000 Domocoins are stored. "Masternode Server" is the virtual private server (VPS).

# Domocoin Masternode setup guide - Debian package

<b>There is a chance that the 1000 coins masternode collateral will stake and split the transaction. If that happens you will have to do step 1.6 again.</b>

## 1. Requirements
* Virtual Private Server - Ubuntu 16 (Xenial), 64bit, 1GB RAM (minimum) <br />
* 25 GB of storage (default, may be less as Blockchain is still small) <br />
* 1000 DOMO (Masternode collateral) <br />
* A main computer (containing the main wallet where your coins are stored)  <br />

## 2. Main wallet setup
* 2.1 Download the [latest wallet](https://github.com/Utopianer/DOMO-Project/releases) for your operating system.<br>
* 2.2 Launch the wallet and allow it to synchronize <br />
* 2.3 Click on `debug console` found in `tools`
* 2.4 Type `masternode genkey` - copy the generated key and exit the console<br />
Save the private key in a text file for future use.<br>
* 2.5 Go to `receiving wallets` found in `files` - create masternode wallet, by creating a new wallet, called `masternode1` <br />
Copy the address by right-clicking and selecting "Copy Address"<br>
* 2.6 Send EXACTLY 1000 coins to `masternode1` wallet by pasting the copied address.<br>
Note that this has to be sent in **ONE transaction**. <br />
* 2.7 Go back to `debug console` and type `masternode outputs` <br />
* 2.8 Copy the transaction id and output id
Save the output in the text file for future use.
* 2.9 Go to `open masternode configuration file` in the wallet - found on the 'tools' menu <br />
Here you will see the format and an example (these three lines are comments so they have no effect) <br />
The format is like this:

```
# Masternode config file
# Format: alias IP:port masternodeprivkey collateral_output_txid collateral_output_index
# Example: MN1 127.0.0.2:52992 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
```

* 2.10 Add your own real working node details under it. <br />
* 2.11 Put the masternode wallet name, i.e - `MN1` <br />
* 2.12 Put the server IP address (IP you use to login to the server) followed by the port :52992 <br />
* 2.13 Put the private key generated in step 2.4 <br />
* 2.14 Put the transaction hash and output id from step 2.7 <br />
Example below

```
MN01 69.69.69.0:52992 119cCx5YeA5ggdYkTzun4EptddxAo3RvQXaPdkP 838328ce34cc8b1682332d138001781b77b22470c05cf2235a3284093cb0019db 0
```

* 2.15 Once complete, save the file <br />

* 2.16 Restart the wallet<br>

## 3. Configure your masternode (VPS)
* 3.1 Download the Debian package here:
https://github.com/Utopianer/DomoCore/releases/download/DomoCore-v3.0.0.1/Domo-setup_3.0.0.1.deb

(The Debian package only contains Daemon and Client no QT.)

* 3.2 Install the package with:
`sudo dpkg --install ./Debian-wallet_3.0.0.1.deb`

* 3.3 Run the Client with:
`domod`

* 3.3.1 Exit with CTRL + C

* 3.4 A .domocoin folder will be created in the Home directory, add this code at the bottom of the domo.conf file:

```
rpcallowip=127.0.0.1
listen=1
server=1
daemon=1
externalip=(your server IP)
masternode=1
masternodeprivkey=(your masternode genkey)
txindex=1
```

* 3.5 If you have a firewall, you need to open the 52992 and 52993 ports:
```
sudo ufw allow 52992/tcp

sudo ufw allow 52993/tcp
```
* 3.6 Now start your masternode:
`domod -reindex`

* 3.7 Wait ~10 mins for your wallet to download the blockchain. You can check the progress with the following command:
`domo-cli getinfo`

## 4 Back to your local wallet - Activate the Masternode
* 4.1 Go to your wallet and go to the masternode page.<br>
* 4.2 Select the masternode and press: "Start alias".<br>
* Sometimes it helps, if you do it two times in a row.<br>
* 4.3 To verify that the masternode is running on the vps:
* Type: `domo-cli masternode status`  ENTER
* If you get this output you are done:<br>
![Imgur](https://i.imgur.com/tWVgO2O.png)

<br>
If you followed these steps correctly your Domocoin masternode should be running right now!<br>

> 🎉🎉🎉🎉🎉🎉 !!!!! Congratulations, begin earning rewards for supporting the DOMO network! !!!!! 🎉🎉🎉🎉🎉🎉<br>

After some time the rewards will be distributed in your wallet.

<br>

# 6. Security

## 6.1 Wallet

Encrypt your wallet! This prevents other people ( who have access to your computer or get access to your wallet.dat file ) to get in your wallet. Don't lose that password. If you lose it the wallet is locked forever and nobobdy will be able to recover your funds.

Backup your wallet! The beauty of digital files is that you can back them up and store them somewhere safe. After encrypting your wallet make sure you back it up and keep it somewhere safe ( on a usb for example).

## 6.2 VPS

For the more advanced user I advise making your VPS more secure from all kinds of attacks. We don't want other people stealing our masternode right?
Please look at this guide http://patheyman.com/masternode-secure/ for more info.

# 7. Questions?

If you have a problem or a question you can find us in the #support channel on our Discord.

# 8. Credits

Credits go to the Nodium project, for providing a wonderful Setup Layout!
