In the following Tutorial "Main Wallet" is referred to your local wallet where your 1000 Domocoins are stored.
"Masternode Server" is the virtual private server (VPS) you have to compile the Sourcecode on.

# Domocoin Masternode setup guide - Compiling from Source

<b>There is a chance that the 1000 coins masternode collateral will stake and split the transaction. If that happens you will have to do step 1.6 again.</b>

## 1. Requirements
* Virtual Private Server - Ubuntu 16 (Xenial), 64bit, 1GB RAM (minimum) <br />
* Make sure you can create a swapfile of at least 4gb size for compiling Sourcecode (some VPS providers have limitations) <br />
* 25 GB of storage (default, may be less as Blockchain is still small) <br />
* 1000 DOMO (Masternode collateral) <br />
* A main computer (containing the main wallet where your coins are stored)  <br />

## 2. Create a Swapfile
Login to your VPS via SSH (using normal password is very dangerous!)

* 2.1 Type: `sudo fallocate -l 4G /swapfile`  ENTER (This will prepare a 4GB swapfile)
* 2.2 Change permissions, Type: `sudo chmod 600 /swapfile`  ENTER
* 2.3 Create the swapfile, Type: `sudo mkswap /swapfile`  ENTER
* 2.4 Enable the swapfile, Type: `sudo swapon /swapfile`  ENTER <br>
* 2.5 We have our swap file enabled, but it´s not permanent. We can change that though by modifying the fstab file, <br>
Type: `sudo nano /etc/fstab`  ENTER <br />
* 2.6 At the bottom of the file, you need to add a line that will tell the operating system to automatically use the file you created, <br>
Type: `/swapfile   none    swap    sw    0   0`  Press CTRL + X to finish, confirm with Y and ENTER <br />

## 3. Configure your masternode
* 3.1 First we are going to install the dependencies, copy paste one line at a time and press ENTER (confirm with Y): <br>
(Install package maintainers version, if asked) <br />

```
sudo apt-get update

sudo apt-get upgrade

sudo apt-get install build-essential libtool automake autoconf

sudo apt-get install autotools-dev autoconf pkg-config libssl-dev

sudo apt-get install libgmp3-dev libevent-dev bsdmainutils libboost-all-dev

sudo add-apt-repository ppa:bitcoin/bitcoin

sudo apt-get update

sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libminiupnpc-dev
```

### 3.2 Compile the Sourcecode
* 3.2.1 Clone the Github DOMO repository:<br>
```
sudo apt-get install git

git clone https://github.com/Utopianer/DomoCore
```
* 3.2.2 Now execute the following lines :<br>
```
cd DomoCore

./autogen.sh

./configure --without-gui

sudo make
```
* 3.2.3 Get some tea, this will take at least 20-30 minutes <br>

* 3.3 Finished? Great! Let´s start the headless client:
```
cd src

domod -reindex
```
* 3.4 A new file has been created containing the configuration files you need to edit later. Press CTRL + C to quit the daemon <br>

## 4. Main wallet setup
* 4.1 Download the [latest wallet](https://github.com/Utopianer/DOMO-Project/releases) for your operating system.<br>
* 4.2 Launch the wallet and allow it to synchronize <br />
* 4.3 Click on `debug console` found in `tools`
* 4.4 Type `masternode genkey` - copy the generated key and exit the console<br />
Save the private key in a text file for future use.<br>
* 4.5 Go to `receiving wallets` found in `files` - create masternode wallet, by creating a new wallet, called `masternode1` <br />
Copy the address by right-clicking and selecting "Copy Address"<br>
* 4.6 Send EXACTLY 1000 coins to `masternode1` wallet by pasting the copied address.<br>
Note that this has to be sent in **ONE transaction**. <br />
* 4.7 Go back to `debug console` and type `masternode outputs` <br />
* 4.8 Copy the transaction id and output id
Save the output in the text file for future use.
* 4.9 Go to `open masternode configuration file` in the wallet - found on the 'tools' menu <br />
Here you will see the format and an example (these three lines are comments so they have no effect) <br />
The format is like this:

```
# Masternode config file
# Format: alias IP:port masternodeprivkey collateral_output_txid collateral_output_index
# Example: MN1 127.0.0.2:52992 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
```

* 4.10 Add your own real working node details under it. <br />
* 4.11 Put the masternode wallet name, i.e - `MN1` <br />
* 4.12 Put the server IP address (IP you use to login to the server) followed by the port :52992 <br />
* 4.13 Put the private key generated in step 4.4 <br />
* 4.14 Put the transaction hash and output id from step 4.7 <br />
Example below

```
MN01 69.69.69.0:52992 119cCx5YeA5ggdYkTzun4EptddxAo3RvQXaPdkP 838328ce34cc8b1682332d138001781b77b22470c05cf2235a3284093cb0019db 0
```

* 4.15 Once complete, save the file <br />

The file will look like this:
```
# Masternode config file
# Format: alias IP:port masternodeprivkey collateral_output_txid collateral_output_index
# Example: mn1 127.0.0.2:52992 93HaYBVUCYjEMeeH1Y4sBGLALQZE1Yc1K64xiqgX37tGBDQL8Xg 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
MN01 69.69.69.0:52992 119cCx5Y3ed19YkTzun4EptdexAo3RvQXaPdkP 838354ce57cc8b168d932d138001781b77b2353460c05cf2235a3284093cb0019db 0
```
* 4.16 Restart the wallet<br>

## 5 Back to the Masternode wallet
* 5.1 Navigate to the configuration file:
```
cd

cd ./.domo
(try cd ./.domocoin if you can´t find the folder)

nano domo.conf
```
* Although we are using nano here, it´s recommended to use a different text editor to not run into formatting issues.
* 5.2 Now copy paste the following configuration below the existing code: (if you see a empty configuration file, you probably made a typing error)

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
* If you have a firewall, you need to open the 52992 and 52993 ports:
```
sudo ufw allow 52992/tcp

sudo ufw allow 52993/tcp
```
* 5.3 Now start you masternode by navigating through your DOMO folder:
```
cd

cd DomoCore/src/

domod -reindex
```
* 5.4 Wait ~10 mins for your wallet to download the blockchain. You can check the progress with the following command:
`./domo-cli getinfo`

## 6 Back to your local wallet - Activate the Masternode
* 6.1 Go to your wallet and go to the masternode page.<br>
* 6.2 Select the masternode and press: "Start alias".<br>
* Sometimes it helps, if you do it two times in a row.<br>
* 6.3 To verify that the masternode is running on the vps:
* 6.4 Type: `domo-cli masternode status`  ENTER
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
