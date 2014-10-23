/***************************************************************
 * Name:      guiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Jonas Zinn (Jonas.S.Zinn@gmail.com)
 * Created:   2014-10-18
 * Copyright: Jonas Zinn ()
 * License:
 **************************************************************/

#include "guiApp.h"

#include <include/cef_app.h>
#include <include/cef_browser.h>
#include <include/cef_string_visitor.h>
#include <wx/fs_mem.h>

//(*AppHeaders
#include "MarkdownFrame.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(guiApp);

bool guiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;

	wxFileSystem::AddHandler(new wxMemoryFSHandler);

    wxInitAllImageHandlers();
	int code = 0;
	if (!wxWebViewChromium::StartUp(code))
		return false;
    if ( wxsOK )
    {
    	MarkdownFrame* Frame = new MarkdownFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}

guiApp::~guiApp()
{
	// Execute
	CefShutdown();
}
