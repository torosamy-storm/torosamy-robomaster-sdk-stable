bin_directory=$(pwd)

sudo rm -rf /opt/torosamy_robomaster_sdk
sudo rm -rf /opt/torosamy_rm_sdk
sudo rm -rf /etc/udev/rules.d/60-u3v-drv.rules
sudo rm -rf /etc/udev/rules.d/88-mvusb.rules
sudo rm -rf /etc/udev/rules.d/99-mvusb.rules
sudo rm -rf /etc/ld.so.conf.d/torosamy-robomaster-core.conf
sudo rm -rf /etc/ld.so.conf.d/torosamy-rm-core.conf
sudo rm -rf /opt/DahuaTech/
sudo rm -rf /etc/ld.so.conf/MV_SDK.conf
sudo rm -rf /usr/include/CameraApi.h
sudo rm -rf /usr/include/CameraDefine.h
sudo rm -rf /usr/include/CameraStatus.h
sudo rm -rf /lib/libMVSDK.so
sudo rm -rf /etc/ld.so.conf/dahua-ld.conf

sudo apt update
sudo apt install libyaml-cpp-dev -y
sudo apt-get install curl -y

# 拷贝相机识别规则
sudo cp $bin_directory/rules/60-u3v-drv.rules /etc/udev/rules.d
sudo cp $bin_directory/rules/88-mvusb.rules /etc/udev/rules.d
sudo cp $bin_directory/rules/99-mvusb.rules /etc/udev/rules.d




# 检查大华的ld规则文件是否存在，如果存在则删除
if [ -f torosamy-robomaster-core.conf ]; then
    rm torosamy-robomaster-core.conf
fi
if [ -f torosamy-rm-core.conf ]; then
    rm torosamy-rm-core.conf
fi


sudo mkdir /opt/torosamy_robomaster_sdk
sudo cp -rf $bin_directory/lib /opt/torosamy_robomaster_sdk
sudo cp -rf $bin_directory/include /opt/torosamy_robomaster_sdk
sudo cp -rf $bin_directory/config /opt/torosamy_robomaster_sdk
sudo cp -rf $bin_directory/resource /opt/torosamy_robomaster_sdk


# 创建文件并写入内容
echo "/opt/torosamy_robomaster_sdk/lib/DahuaCamera" >> torosamy-robomaster-core.conf
echo "/opt/torosamy_robomaster_sdk/lib/DahuaCamera/GenICam/bin/Linux64_x64" >> torosamy-robomaster-core.conf
echo "/opt/torosamy_robomaster_sdk/lib/MindCamera/amd64" >> torosamy-robomaster-core.conf


sudo mv torosamy-robomaster-core.conf /etc/ld.so.conf.d


sudo ldconfig

echo 'Done! If this is your first installation, please restart your computer!'
