# Music_Visualization_RealTime
RealTimeEmbedded_Project

https://github.com/WiringPi/WiringPi/tree/master/wiringPi
wiringpi元件驱动



reference:
* https://github.com/albanjoseph/Signapse
* https://twitter.com/BerndPorr/status/1516897303923204096
* https://www.hackster.io/fhdm-dev/use-arduino-libraries-with-the-rasperry-pi-pico-c-c-sdk-eff55c

reference(markdown):
* https://www.jianshu.com/p/335db5716248
---
task one；声音传感器的接收与控制
          
task two: 超声波传感器
          检测距离，一定距离内，
          print("There is a target approaching")
          alert;
          led灯亮；

linux_github  https://blog.csdn.net/sasafa/article/details/125699014
版本检测  git --version
git clone + ssh路径/https路径   #拷贝一份远程仓库代码到本地

sudo apt-get install g++
g++ test.cpp -o test
sudo ./test


## qt
[qt项目的创建](https://blog.csdn.net/weixin_53312997/article/details/128631504?ops_request_misc=&request_id=&biz_id=102&utm_term=qt%E9%A1%B9%E7%9B%AE&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-7-128631504.142^v73^control,201^v4^add_ask,239^v2^insert_chatgpt&spm=1018.2226.3001.4187)  
qt项目一般也是c++项目或者c++/QML项目


---
## audio
[tutorial](https://blog.csdn.net/Tang_Chuanlin/article/details/84567395)  
[USB Audio Capture Card Grabber](https://www.amazon.co.uk/gp/buy/thankyou/handlers/display.html?purchaseId=204-7367631-7223508&ref_=chk_typ_browserRefresh&isRefresh=1)

## git
[git](https://blog.csdn.net/m0_64448813/article/details/128470202)
---
<!-- PROJECT LOGO -->
<br />
<div align="center">
   <h1 align="center">Signapse</h1>
 <img src="https://github.com/ShenJuncheng/Music_Visualization_RealTime/blob/master/images/logo.png" alt="logo" width="400" div al ign=center />
 </br>
 Signapse is here to help you learn and practice sign language on an embedded device you can take anywhere!
 </br>
 📰 🤩 As featured on: 
    <a href="https://www.hackster.io/news/signapse-aims-to-turn-a-raspberry-pi-into-an-artificially-intelligent-tutor-for-sign-language-ec1a08d0fc36"> Hackster.io</a> ,
    <a href="https://channel969.com/signapse-goals-to-flip-a-raspberry-pi-into-an-artificially-clever-tutor-for-signal-language/"> Channel 969</a> 
   and <a href="https://hackaday.com/2022/04/30/learn-sign-language-using-machine-vision/#comments"> Hackaday</a>!! 🤩 📰
 </br>
 </br>

![Contributors](https://img.shields.io/github/contributors/albanjoseph/Signapse?style=for-the-badge)
![GitHub Repo stars](https://img.shields.io/github/stars/albanjoseph/Signapse?style=for-the-badge)
![Issues](https://img.shields.io/github/issues-raw/albanjoseph/Signapse?style=for-the-badge)
[![License](https://img.shields.io/github/license/albanjoseph/Signapse?style=for-the-badge)](https://github.com/albanjoseph/Signapse/blob/main/LICENSE)
<br />
<a href="https://github.com/albanjoseph/Signapse/issues">Report Bug</a>
.
<a href="https://github.com/albanjoseph/Signapse/issues">Request Feature</a>
<br />

![Build and Test](https://github.com/albanjoseph/Signapse/actions/workflows/cmake_build.yml/badge.svg?branch=dev&event=push)
![Docs](https://github.com/albanjoseph/Signapse/actions/workflows/docs.yml/badge.svg)

  <p align="center">
    🎥 Check out our product
    <a href="https://www.youtube.com/watch?v=wkhXxTbKkyo&ab_channel=Signapse"> Demo Video</a>!!
    <br />
    📜 Explore our 
    <a href="https://github.com/albanjoseph/Signapse/wiki"> Wiki</a> to learn more!!
    <br />
    🖇️ Browse the 
    <a href="https://albanjoseph.github.io/Signapse/html/annotated.html"> Developer Documentation</a>!! 
  </p>
</p>
</div>
<h3 align="left"></h3>



# In a Nutshell 🌰

**Signapse is free open source software that helps everyday people learn sign language for free!​**

Our deep learning enhanced video pipeline is able to detect when users are making the correct input sign, this is used to challenge users to make example signs shown on-screen. At present Signapse is configured to teach the American Sign Language character alphabet; we hope to add support for more complex and varied hand signs in the future.

For installation information check out our [installation guide](https://github.com/albanjoseph/Signapse/wiki/2.-Installation-Guide). For a demo on how to use the application, check out our demo video below. For best results using Signapse, we reccomend keeping your hand witin the green box shown on screen and signing in a well lit environment with a plain background - this helps our AI system easily detect your hand signs. Happy Signapsing! 🥳


# Demo Video
[![Demo Video](https://github.com/albanjoseph/Signapse/blob/main/images/thumbnail_compress.gif)](https://youtu.be/wkhXxTbKkyo "Signapse - Demo Video!")

# Embedded video
[![Embedded video](https://github.com/ShenJuncheng/Music_Visualization_RealTime/blob/master/draft/Embedded-video.gif)]

# Social Media 🌐
Keep up to date with Signapse! Find us on all our social channels:
</br>

<p align="center">
<a href="https://twitter.com/GU_Signapse" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="signups" height="150" width="100" /></a>·
<a href="https://www.facebook.com/Signapse-125793226671815" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" alt="signapse" height="150" width="100" /></a> ·
<!-- <a href="https://instagram.com/insta" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/instagram.svg" alt="insta" height="30" width="40" /></a> -->
<a href="https://www.youtube.com/channel/UCh2uG2pYoSloEU0IFeqDQMA" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/youtube.svg" alt="youtube" height="150" width="100"  /></a>·
<a href="https://www.tiktok.com/@GU_signapse" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/en/a/a9/TikTok_logo.svg" alt="tiktok" height="150" width="150" /></a> ·
   <a href="https://www.instagram.com/gu_signapse" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e7/Instagram_logo_2016.svg/1024px-Instagram_logo_2016.svg.png" alt="instagram" height="100" width="100" /></a> 

</p>

# Technologies ⚙️
Signapse is built using:
- [C++ Programming Language](https://www.cplusplus.com/)
- [Debian/Ubuntu Linux](https://www.linux.org/)
- [Raspberry Pi](https://www.raspberrypi.org)
- [Tensorflow](https://www.tensorflow.org/)
- [OpenCV](https://opencv.org/)
- [Google Test](https://github.com/google/googletest)
- [Doxygen](https://www.doxygen.nl/index.html)
- [Qt](https://www.qt.io/)

<!-- LICENSE -->

# License 📰

Distributed under the MIT License. See [`LICENSE`](https://github.com/ShenJuncheng/Music_Visualization_RealTime/blob/master/LICENSE) for more information.




# Contact Us 📞
- 🔭This project is being completed by a team of students at the University of Glasgow :
    * [Juncheng Shen](https://github.com/ShenJuncheng)
    * [Jinfeng Lyu](https://github.com/Jinfeng-Lyu)
    * [Chengkun Yang](https://github.com/YANGCHENGKUN-designer)
    * [Yiwei Zhang](https://github.com/testingforforrwhat)
- 📫 Email: **signapse.glasgow@gmail.com**
