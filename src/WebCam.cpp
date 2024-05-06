// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  WebCam.cpp
 * @brief get Image in WebCamera
 *
 */
// </rtc-template>

#include "WebCam.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const webcam_spec[] =
#else
static const char* webcam_spec[] =
#endif
  {
    "implementation_id", "WebCam",
    "type_name",         "WebCam",
    "description",       "get Image in WebCamera",
    "version",           "1.0.0",
    "vendor",            "TsuchidaYuta",
    "category",          "Camera",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.height", "240",
    "conf.default.width", "320",

    // Widget
    "conf.__widget__.height", "text",
    "conf.__widget__.width", "text",
    // Constraints

    "conf.__type__.height", "int",
    "conf.__type__.width", "int",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
WebCam::WebCam(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_WebCameraImageOut("CameraImageOut", m_WebCameraImage)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
WebCam::~WebCam()
{
}



RTC::ReturnCode_t WebCam::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("CameraImageOut", m_WebCameraImageOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("height", m_height, "240");
  bindParameter("width", m_width, "320");
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t WebCam::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t WebCam::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCam::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t WebCam::onActivated(RTC::UniqueId /*ec_id*/)
{
    std::cout << "Active" << std::endl;
    //camera setup
    cap.open(0);
    if (cap.isOpened()) {
        std::cout << "USE Camera Connect" << std::endl;
    }
    else {
        std::cout << "USB Camera UnConnect" << std::endl;
    }

    //Frame size set
    cap.set(cv::CAP_PROP_FRAME_WIDTH, m_width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, m_height);

     return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCam::onDeactivated(RTC::UniqueId /*ec_id*/)
{
    std::cout << "Deactive" << std::endl;
    cap.release();
    return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCam::onExecute(RTC::UniqueId /*ec_id*/)
{
    if (cap.isOpened()) {
        if (width != m_width || height != m_height) {

        }
    }
    return RTC::RTC_OK;
}


//RTC::ReturnCode_t WebCam::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCam::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCam::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCam::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCam::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void WebCamInit(RTC::Manager* manager)
  {
    coil::Properties profile(webcam_spec);
    manager->registerFactory(profile,
                             RTC::Create<WebCam>,
                             RTC::Delete<WebCam>);
  }
  
}
