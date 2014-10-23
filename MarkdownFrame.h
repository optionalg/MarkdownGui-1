///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __MARKDOWNFRAME_H__
#define __MARKDOWNFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/stc/stc.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/webview.h>
#include <webview_chromium.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MarkdownFrame
///////////////////////////////////////////////////////////////////////////////
class MarkdownFrame : public wxFrame 
{
	private:
	
	protected:
		wxStyledTextCtrl* m_scintilla1;
		wxWebView* m_webview;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInput(wxKeyEvent& event);
		
	
	public:
		
		MarkdownFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MarkdownFrame();

		void DoIt();
	
};

#endif //__MARKDOWNFRAME_H__
