// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  WebCamTest.cpp
 * @brief get Image in WebCamera (test code)
 *
 */
// </rtc-template>

#include "WebCamTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const webcam_spec[] =
#else
static const char* webcam_spec[] =
#endif
  {
    "implementation_id", "WebCamTest",
    "type_name",         "WebCamTest",
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
WebCamTest::WebCamTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_WebCameraImageIn("CameraImageOut", m_WebCameraImage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
WebCamTest::~WebCamTest()
{
}



RTC::ReturnCode_t WebCamTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("CameraImageOut", m_WebCameraImageIn);
  
  // Set OutPort buffer
  
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
RTC::ReturnCode_t WebCamTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t WebCamTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t WebCamTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCamTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t WebCamTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t WebCamTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t WebCamTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool WebCamTest::runTest()
{
    return true;
}


extern "C"
{
 
  void WebCamTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(webcam_spec);
    manager->registerFactory(profile,
                             RTC::Create<WebCamTest>,
                             RTC::Delete<WebCamTest>);
  }
  
}
