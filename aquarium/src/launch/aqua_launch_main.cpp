#include "launch\aqua_launch_main.h"
#include "calling\aqua_calling_renderer.h"
#include "calling\aqua_calling_browser.h"
#include <functional>
#include "utils\aqua_conv.h"

using namespace AquaLaunch;

///
//	�������ݽ��洢�ڴ����ϵ�λ�á�����ǿյĻ�������������û������ڵġ�����ģʽ���´���
//	���ڴ洢����û�����ݱ����浽���̡�HTML5�����ݿ� localStorageֻ���ڻ���·������
//	������³��������ڻỰ��ָ����
///
AQUAENTRY(void, InitCachePathA)(LPVOID conf, LPCSTR path) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->cache_path) = conv.from_bytes(path);
}

///
//	�������ݽ��洢�ڴ����ϵ�λ�á�����ǿյĻ�������������û������ڵġ�����ģʽ���´���
//	���ڴ洢����û�����ݱ����浽���̡�HTML5�����ݿ� localStorageֻ���ڻ���·������
//	������³��������ڻỰ��ָ����
///
AQUAENTRY(void, InitCachePathW)(LPVOID conf, LPCWSTR path) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->cache_path) = path;
}

///
//	ƴд����ֵ��ļ����û��������ڵ�λ�ô洢�ڴ����ϡ� ���Ϊ�գ���ΪĬ��ƽ̨�ض����û�����
//	��ʹ��Ŀ¼��Linux�ϵ�"~/.cef_user_data"Ŀ¼��Mac OS X�ϵ�"~/Library/Application
//	Support/CEF/User Data"Ŀ¼��Windows �ϵ�"Local Settings\Application Data\CEF
//	\User Data"�����ļ�Ŀ¼��
///
AQUAENTRY(void, InitUserDataA)(LPVOID conf, LPCSTR path) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->user_data_path) = conv.from_bytes(path);
}

///
//	ƴд����ֵ��ļ����û��������ڵ�λ�ô洢�ڴ����ϡ� ���Ϊ�գ���ΪĬ��ƽ̨�ض����û�����
//	��ʹ��Ŀ¼��Linux�ϵ�"~/.cef_user_data"Ŀ¼��Mac OS X�ϵ�"~/Library/Application
//	Support/CEF/User Data"Ŀ¼��Windows �ϵ�"Local Settings\Application Data\CEF
//	\User Data"�����ļ�Ŀ¼��
///
AQUAENTRY(void, InitUserDataW)(LPVOID conf, LPCWSTR path) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->cache_path) = path;
}

///
//	����ΪTRUE,�������޴��ڣ���������Ⱦ֧�֡����Ӧ�ó���ʹ���޴�����Ⱦ�����ô�ֵ
//	�����ܻή��ĳЩϵͳ����Ⱦ���ܡ�
///
AQUAENTRY(void, InitWindowlessRenderingEnabled)(LPVOID conf, BOOL enabled) {
	reinterpret_cast<CefSettings*>(conf)->windowless_rendering_enabled = enabled;
}

///
//	���ֻỰcookie��û�е����ջ���Ч�ڵ�cookie�����Ĭ�������ʹ��ȫ��cookie������
//	����ֵ����ΪTRUE,�Ựcookieͨ���Ƕ��ݵģ����Ҵ󲿷ֶ���Web���������������ǡ�
//	��|cache_path|��Ҳ������ָ�����ô˹��ܡ� Ҳ����ʹ�á�persist-session-cookies�������п��ء�
//	�������á�
///
AQUAENTRY(void, InitPersistSessionCookies)(LPVOID conf, BOOL enabled) {
	reinterpret_cast<CefSettings*>(conf)->persist_session_cookies = enabled;
}

///
//	�������ΪTRUE,���û���ѡ���Ϊ����·��Ŀ¼���е�JSON�ļ�,��ʹ������|cache_path|
//	Ҳ������ָ�����ô˹��ܡ�Ҳ����ʹ��"persist-user-preferences"�����п��ء��������á�
///
AQUAENTRY(void, InitPersistUserPreferences)(LPVOID conf, BOOL enabled) {
	reinterpret_cast<CefSettings*>(conf)->persist_user_preferences = enabled;
}

///
//	����ΪUser-Agent HTTP��ͷ���ص�ֵ���������˽�ʹ��Ĭ�ϵ�User-Agent�ַ�����
//	Ҳ����ʹ��"user-agent"�����п���,�������á�
///
AQUAENTRY(void, InitUserAgentA)(LPVOID conf, LPCSTR value) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->user_agent) = conv.from_bytes(value);
}

///
//	����ΪUser-Agent HTTP��ͷ���ص�ֵ���������˽�ʹ��Ĭ�ϵ�User-Agent�ַ�����
//	Ҳ����ʹ��"user-agent"�����п���,�������á�
///
AQUAENTRY(void, InitUserAgentW)(LPVOID conf, LPCWSTR value) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->user_agent) = value;
}

///
//	����ΪĬ�ϲ�Ʒ���ֲ����ֵUser-Agent�ַ������ַ��������Ϊ�գ���ʹ��Chromium��Ʒ�汾��
//	���| userAgent |ָ����ֵ�������ԡ�Ҳ������"product-version"�����п��ء�
///
AQUAENTRY(void, InitProductVersionA)(LPVOID conf, LPCSTR value) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->product_version) = conv.from_bytes(value);
}


///
//	����ΪĬ�ϲ�Ʒ���ֲ����ֵUser-Agent�ַ������ַ��������Ϊ�գ���ʹ��Chromium��Ʒ�汾��
//	���| userAgent |ָ����ֵ�������ԡ�Ҳ������"product-version"�����п��ء�
///
AQUAENTRY(void, InitProductVersionW)(LPVOID conf, LPCWSTR value) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->product_version) = value;
}

///
//	�����ݸ�WebKit�����Ի����ַ�����������Ĭ��ֵ��ʹ�á�en-US�������Ի����� 
//	�����Ի�����Linux�ϣ���ֵ��������ʹ������˳��ʹ�û�������������ȷ����
//	LANGUAGE��LC_ALL��LC_MESSAGES��LANG��������ʹ��"lang"���������л���
///
AQUAENTRY(void, InitLocaleA)(LPVOID conf, LPCSTR value) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->locale) = conv.from_bytes(value);
}

///
//	�����ݸ�WebKit�����Ի����ַ�����������Ĭ��ֵ��ʹ�á�en-US�������Ի����� 
//	�����Ի�����Linux�ϣ���ֵ��������ʹ������˳��ʹ�û�������������ȷ����
//	LANGUAGE��LC_ALL��LC_MESSAGES��LANG��������ʹ��"lang"���������л���
///
AQUAENTRY(void, InitLocaleW)(LPVOID conf, LPCWSTR value) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->locale) = value;
}

///
//	��ʼ��V8 JavaScript����ʱ��ʹ�õ��Զ����־��ʹ���Զ����־�ĺ������û��
//	�õ��ܺõĲ��ԡ�ʹ�á�js-flags�������п��ؽ������á�
///
AQUAENTRY(void, InitJavascriptFlagsA)(LPVOID conf, LPCSTR value) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->javascript_flags) = conv.from_bytes(value);
}

///
//	��ʼ��V8 JavaScript����ʱ��ʹ�õ��Զ����־��ʹ���Զ����־�ĺ������û��
//	�õ��ܺõĲ��ԡ�ʹ�á�js-flags�������п��ؽ������á�
///
AQUAENTRY(void, InitJavascriptFlagsW)(LPVOID conf, LPCWSTR value) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->locale) = value;
}

///
//	����Ϊtrue,����Ϊ��Դ���������ü��ذ��ļ�������Ϊ���������Ⱦ�ṩ��Դ����������
//	������ذ��ļ�����ͨ��CefApp :: GetResourceBundleHandler�������д���
//	�����á� Ҳ����ʹ�á�disable-pack-loading���������������·�л���
///
AQUAENTRY(void, InitPackloadingDisabled)(LPVOID conf, BOOL enabled) {
	reinterpret_cast<CefSettings*>(conf)->pack_loading_disabled = enabled;
}

///
//	����Ϊ1024��65535֮���ֵ������Զ�̵���ָ���Ķ˿ڡ� ���磬���8080��ָ��ΪԶ�̵���URL
//	����http//localhost:8080��CEF���Դ��κ�CEF����Զ�̵���Chrome��������ڡ� 
//	Ҳ����ʹ��"remote-debugging-port"�����п��ؽ������á�
///
AQUAENTRY(void, InitRemoteDebuggingPort)(LPVOID conf, int value) {
	reinterpret_cast<CefSettings*>(conf)->remote_debugging_port = value;
}

///
//	Ϊδ������쳣����Ķ�ջ����֡��������ָ��һ����ֵ������CefRenderProcessHandler::OnUncaughtException()
//	�ص�������ָ��0��Ĭ��ֵ���� OnUncaughtException�������ᱻ���á� Ҳ����ʹ��
//	"uncaught-exception-stack-size"�����п��ؽ������á�
///
AQUAENTRY(void, InitUncaughtExceptionStackSize)(LPVOID conf, int value) {
	reinterpret_cast<CefSettings*>(conf)->uncaught_exception_stack_size = value;
}

///
//	����Ϊtrue��1����������ЧSSL֤����صĴ������ô����ÿ��ܻᵼ��Ǳ�ڵİ�ȫ©��
//	��"man in the middle"����,�ӻ������������ݵ�Ӧ�ó���Ӧ���ô����á�
//	Ҳ����ʹ��"ignore-certificate-errors"�����п��ؽ������á�
//	����ͨ��CefRequestContextSettings.ignore_certificate_errorsֵΪ����CefRequestContextʵ�����ǡ�
///
AQUAENTRY(void, InitIgnoreCertificateErrors)(LPVOID conf, BOOL enabled) {
	reinterpret_cast<CefSettings*>(conf)->ignore_certificate_errors = enabled;
}

///
//	����Ϊtrue��1���������������簲ȫ��Ϣ����֤��͸������־��HSTSԤ���غ�������Ϣ���Ļ������ڵĵ��ڡ�
//	���ô�ѡ���������簲ȫ�ԣ�����ʹ�ù�ȥ10���ڹ�����CEF�������ļ�ʱ���ܻᵼ��HTTPS����ʧ�ܡ�
//	����� https://www.certificate-transparency.org/ �� https://www.chromium.org/hsts �˽����顣
///
AQUAENTRY(void, InitEnableNetSecurityExpiration)(LPVOID conf, BOOL enabled) {
#ifndef _AQUA_CEF2623_ADAPTER
	reinterpret_cast<CefSettings*>(conf)->enable_net_security_expiration = enabled;
#endif
}

///
//	�����ĵ�֮ǰ�Լ�δָ���ĵ���ɫʱ����������ı�����ɫ��alpha����������ȫ��͸����0xFF������ȫ͸����0x00����
//	���alpha������ȫ��͸������ôRGB����������������ɫ��alpha������ڴ��ڻ����������ȫ͸���ģ�Ȼ��ʹ�ò�͸����ɫ��Ĭ��ֵ��
//	���alpha��������޴��ڣ��������������ȫ͸������͸���滭�������á�
///
AQUAENTRY(void, InitBackgroundColor)(LPVOID conf, int value) {
	reinterpret_cast<CefSettings*>(conf)->background_color = value;
}

///
//	�ö��ŷָ�����������Դ����б���û���κν��ڡ�Accept-Language��HTTP��ͷ��ʹ�õĿո�
//	����ʹ��CefBrowserSettings.accept_language_listֵ��ÿ���������������д��
//	�������ֵ��Ϊ�գ���ʹ�á�en-US,en����
//	����ͨ��CefRequestContextSettings.accept_language_listֵΪ����CefRequestContextʵ�����ǡ�
///
AQUAENTRY(void, InitAcceptLanguageListA)(LPVOID conf, LPCSTR value) {
	aqua_convert conv;
	CefString(&reinterpret_cast<CefSettings*>(conf)->accept_language_list) = conv.from_bytes(value);
}

///
//	�ö��ŷָ�����������Դ����б���û���κν��ڡ�Accept-Language��HTTP��ͷ��ʹ�õĿո�
//	����ʹ��CefBrowserSettings.accept_language_listֵ��ÿ���������������д��
//	�������ֵ��Ϊ�գ���ʹ�á�en-US,en����
//	����ͨ��CefRequestContextSettings.accept_language_listֵΪ����CefRequestContextʵ�����ǡ�
///
AQUAENTRY(void, InitAcceptLanguageListW)(LPVOID conf, LPCWSTR value) {
	CefString(&reinterpret_cast<CefSettings*>(conf)->accept_language_list) = value;
}

///
//	��ʼ������,һ����"main"�������߳�ʼ�����������ȱ�����,
//	��|init|�ص������п��Խ���һЩ��ʼ�����á�
///
AQUAENTRY(int, DoWinMain)(AquaInitCallback init,LPVOID params) {
	CefMainArgs mainArgvs(GetModuleHandle(NULL));
	CefRefPtr<AquaCallRenderer> render = new AquaCallRenderer;
	int exitCode = CefExecuteProcess(mainArgvs,render,NULL);
	if (exitCode >= 0) return exitCode;
	CefSettings conf;
	if (init) init(&conf);
	conf.single_process = TRUE;
	conf.multi_threaded_message_loop = true;
	conf.log_severity = LOGSEVERITY_DISABLE;
	CefString(&conf.locale) = L"zh-CN";
	conf.persist_session_cookies = true;
	conf.persist_user_preferences = true;
	CefString(&conf.browser_subprocess_path) = L".\\Pepper.exe";
	CefInitialize(mainArgvs, conf, render, NULL);
	return 1;
}

///
//	��Ϣѭ��
///
AQUAENTRY(int, DoMessageLoop)() {
	MSG msg = { 0 };
	while (GetMessage(&msg,NULL,NULL,NULL))
	{
		if (msg.message == WM_QUIT) {
			break;
		}
		else {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}