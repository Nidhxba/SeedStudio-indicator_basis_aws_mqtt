# AWS MQTT Connection Issues and Sensor Reading Problem

Hi... I am encountered with a error while connecting an ESP32 device to the AWS IoT MQTT broker and reading sensor values. The primary issues encountered are outlined below:

1. mbedtls_ssl_setup returned -0x7F00:

```
E (47613) esp-tls-mbedtls: mbedtls_ssl_setup returned -0x7F00
E (47613) esp-tls: create_ssl_handle failed
E (47613) esp-tls: Failed to open new connection
E (47618) city: Connection failed...
```

2. Default value subscription:
 There is an issue with subscribing to the correct topics or reading the actual sensor values.

```
I (46805) aws_iot: Subscribe callback Test: test_topic/esp32    Temperature : 179.0, Humidity : 180.0
I (46908) aws_iot: Subscribe callback Test: test_topic/esp32    Temperature : 179.0, Humidity : 180.0
```

## Brief:

> main/model/indicator_sensor.c

The sensor data is received as _**packet serial**_ and in line **_625_** data parsing and handling is is configured.
The data need to be declared as a function, so, we can call that to the 

> main/model/indicator_sensor.h

file, and in the 

> main/model/aws_iot.c

file, add the function name in line _**203**_ and subscribe to the mqtt.


# Structure :

1. Add your AWS IoT core - certificates:
> AmazonRootCA1

> private.key

> device_cert.pem

To the 
>/main/certs 

folder and replace the values **(NOTE :- Do not change the file name, just change the value)**

2. In the menuconfig -> config the aws endpoint to your personal endpoint.

3. Build and flash the project.


# Additional Resources

[AWS IoT MQTT](https://docs.aws.amazon.com/iot/latest/developerguide/mqtt.html#mqtt-sdk)

[ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/v5.2/esp32s3/get-started/index.html)


# Using the example of 
[SeeedStudio](https://github.com/Seeed-Solution/SenseCAP_Indicator_ESP32.git)
> examples/indicator_basis
> 
and 

[MQTT](https://github.com/kevinudemy/udemy_esp32/tree/master)
> 


# Connect with me on disocrd - [dingan6537](https://discordapp.com/users/756011395174105168)
