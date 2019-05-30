This Tutorial is using a setup script to make Masternode Setup as easy as possible. Please make sure you are root (not different user) or else you need to change the domo.conf path in the setup script manually to make it work properly.
(https://github.com/Utopianer/Domo-Masternode-Setup)

# Domocoin Masternode setup guide

<b>There is a chance that the 1000 coins masternode collateral will stake and split the transaction. If that happens you will have to do step 1.6 again.</b>

## 1. Initial setup
* 1.1 Download the [latest wallet](https://github.com/Utopianer/DOMO-Project/releases) for your operating system.<br>
* 1.2 Launch the wallet and allow it to synchronize <br />
* 1.3 Click on `debug console` found in `tools`
* 1.4 Type `masternode genkey` - copy the generated key and exit the console<br />
Save the private key in a text file for future use.<br>
* 1.5 Go to `receiving wallets` found in `files` - create masternode wallet, by creating a new wallet, called `masternode1` <br />
Copy the address by right-clicking and selecting "Copy Address"<br>
* 1.6 Send EXACTLY 1000 coins to `masternode1` wallet by pasting the copied address.<br>
Note that this has to be sent in **ONE transaction**. <br />
* 1.7 Go back to `debug console` and type `masternode outputs` <br />
* 1.8 Copy the transaction id and output id
Save the output in the text file for future use.

## 2. Get a VPS ( masternode server )
We recommend renting a VPS with https://www.scaleway.com/ because they are fast and cheap.

* 2.1 Create an account:<br>
* 2.2 Deploy a new server
* 2.3 Choose a location close to you to have a fast connection
* 2.4 Choose Ubuntu 16.04 (Xenial) as operating system and take the START1-XS server size. This is sufficient.<br>
* 2.5 Give your masternode VPS a name.<br>
* 2.6 Click "Create Server"<br>
The server is now being started. Please wait until the status is "online".<br />
* 2.7 Click the server name and copy the IP-address. Save it in the text file for future use.
* 2.8 If you did not setup a SSH key before, do this now, by following this guide (may vary depending on your provider):<br>
https://www.scaleway.com/docs/configure-new-ssh-key/

## 3. Configure your masternode
Depending upon which operating system you are using follow the correct section:

### 3.1 Windows - [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html)
#### 3.1.1 Install PuTTY and run it.
* You will be greeted with the following page:<br>
![Imgur](https://i.imgur.com/a3bhSBj.jpg)<br>
* Go to Auth (as shown in the image), click on Browse and locate your SSH file. (If you only use a password, skip this step)<br>
* Go back to Session.
* Fill the Host name field with the IP address you previously copied and click "Open".<br>
* You will see a popup asking you if you trust this host. Choose Yes!( this will only be asked once ).
* Login as "root". Hit ENTER
* Type the password for your ssh key or vps server.  ENTER.
* You are now logged into your server

### 3.2 Mac/Linux - Terminal ( preinstalled )
* You can find Terminal by following the steps:
* Go to Finder, Applications then click on utilities, then you'll find the terminal there.

* Type: ssh root@YourMasternodeIPaddress.  ENTER.
* You are now logged into your server.

### 3.3 General steps
Let's update our system to the latest version to make sure we are secure.
* Type: `sudo apt-get update`  ENTER
* Wait until this finishes
* Type: `sudo apt-get upgrade` ENTER

* Type "y" if the system ask for the confirmation of updating the system.
> Now we start using the power of the script made by Zoldur team member of Domocoin<br>

Remember that you can copy the text below and paste it in to the server via RIGHT-MOUSE click for PuTTY, or CMD-V for MAC<br>

* Type: `cd ~`  ENTER
* Type: `wget -N https://raw.githubusercontent.com/zoldur/Domo/master/domo_install.sh` ENTER
* Type: `bash domo_install.sh` ENTER
* Follow the Script and paste the requested informations.

## 4. Masternode config file in the LOCAL wallet
* Back to your local wallet:
* 4.1 Go to `open masternode configuration file` in the wallet - found on the 'tools' menu <br />
Here you will see the format and an example( these three lines are comments so they have no effect ) <br />
The format is like this:

```
# Masternode config file
# Format: alias IP:port masternodeprivkey collateral_output_txid collateral_output_index
# Example: MN1 127.0.0.2:52992 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
```

* 4.2. Add your own real working node details under it. <br />
* 4.3. Put the masternode wallet name, i.e - `MN1` <br />
* 4.4 Put the server IP address ( your scaleway ip or other vps/vm ip) followed by the port :52992 <br />
* 4.5 Put the private key generated in step 1.4 <br />
* 4.6 Put the transaction hash and output id from step 1.7 <br />
Example below

```
MN01 69.69.69.0:52992 119cCx5YeA5ggdYkTzun4EptddxAo3RvQXaPdkP 838328ce34cc8b1682332d138001781b77b22470c05cf2235a3284093cb0019db 0
```

* 4.7 Once complete, save the file <br />

The file will look like this:
```
# Masternode config file
# Format: alias IP:port masternodeprivkey collateral_output_txid collateral_output_index
# Example: mn1 127.0.0.2:52992 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
MN01 69.69.69.0:52992 119cCx5Y3ed19YkTzun4EptdexAo3RvQXaPdkP 838354ce57cc8b168d932d138001781b77b2353460c05cf2235a3284093cb0019db 0
```
* 4.8 Restart the wallet<br>
* 4.9 Go to your wallet and go to the masternode page.<br>
* Select the masternode and press: "Start alias".<br>
* Sometimes it helps, if you do it two times in a row.<br>

To verify that the masternode is running on the vps:
* Type: `domo-cli masternode status`  ENTER
* If you get this output you are done:<br>
![Imgur](https://i.imgur.com/tWVgO2O.png)

<br>
If you followed these steps correctly your Domocoin masternode should be running right now!<br>

> 🎉🎉🎉🎉🎉🎉 !!!!! Congratulations, begin earning rewards for supporting the DOMO network! !!!!! 🎉🎉🎉🎉🎉🎉<br>

After some time the rewards will be distributed in your wallet.

<br>

# 5. Security

## 5.1 Wallet

Encrypt your wallet! This prevents other people ( who have access to your computer or get access to your wallet.dat file ) to get in your wallet. Don't lose that password. If you lose it the wallet is locked forever and nobobdy will be able to recover your funds.

Backup your wallet! The beauty of digital files is that you can back them up and store them somewhere safe. After encrypting your wallet make sure you back it up and keep it somewhere safe ( on a usb for example).

## 5.2 VPS

For the more advanced user I advise making your VPS more secure from all kinds of attacks. We don't want other people stealing our masternode right?
Please look at this guide http://patheyman.com/masternode-secure/ for more info.

# 6. Questions?

If you have a problem or a question you can find us in the #support channel on our Discord.

# 7. Credits

Credits go to the Nodium project, for providing a wonderful Setup Layout!
