///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "MarkdownFrame.h"
#include "process.h"

#include <wx/fs_mem.h>
#include <wx/webviewfshandler.h>
#include <wx/file.h>

///////////////////////////////////////////////////////////////////////////

MarkdownFrame::MarkdownFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	m_scintilla1 = new wxStyledTextCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, wxEmptyString );
	m_scintilla1->SetUseTabs( true );
	m_scintilla1->SetTabWidth( 4 );
	m_scintilla1->SetIndent( 4 );
	m_scintilla1->SetTabIndents( true );
	m_scintilla1->SetBackSpaceUnIndents( true );
	m_scintilla1->SetViewEOL( false );
	m_scintilla1->SetViewWhiteSpace( false );
	m_scintilla1->SetMarginWidth( 2, 0 );
	m_scintilla1->SetIndentationGuides( true );
	m_scintilla1->SetMarginType( 1, wxSTC_MARGIN_SYMBOL );
	m_scintilla1->SetMarginMask( 1, wxSTC_MASK_FOLDERS );
	m_scintilla1->SetMarginWidth( 1, 16);
	m_scintilla1->SetMarginSensitive( 1, true );
	m_scintilla1->SetProperty( wxT("fold"), wxT("1") );
	m_scintilla1->SetFoldFlags( wxSTC_FOLDFLAG_LINEBEFORE_CONTRACTED | wxSTC_FOLDFLAG_LINEAFTER_CONTRACTED );
	m_scintilla1->SetMarginType( 0, wxSTC_MARGIN_NUMBER );
	m_scintilla1->SetMarginWidth( 0, m_scintilla1->TextWidth( wxSTC_STYLE_LINENUMBER, wxT("_99999") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDER, wxSTC_MARK_BOXPLUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDER, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEROPEN, wxSTC_MARK_BOXMINUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPEN, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERSUB, wxSTC_MARK_EMPTY );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEREND, wxSTC_MARK_BOXPLUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEREND, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_BOXMINUS );
	m_scintilla1->MarkerSetBackground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("BLACK") ) );
	m_scintilla1->MarkerSetForeground( wxSTC_MARKNUM_FOLDEROPENMID, wxColour( wxT("WHITE") ) );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY );
	m_scintilla1->MarkerDefine( wxSTC_MARKNUM_FOLDERTAIL, wxSTC_MARK_EMPTY );
	m_scintilla1->SetSelBackground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_scintilla1->SetSelForeground( true, wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	bSizer1->Add( m_scintilla1, 1, wxEXPAND | wxALL, 5 );
	
	wxWebView::RegisterFactory(wxWebViewBackendChromium, wxSharedPtr<wxWebViewFactory>
	(new wxWebViewFactoryChromium));
	

	m_webview = wxWebView::New(this, wxID_ANY, "file:///D:/Dokumente/Programming/cpp/gui/Gui/temp.html", wxDefaultPosition, wxDefaultSize, wxWebViewBackendChromium);
	bSizer1->Add( m_webview, 1, wxALL|wxEXPAND, 5 );
	m_webview->Layout();
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_scintilla1->Connect( wxEVT_KEY_UP, wxKeyEventHandler( MarkdownFrame::OnInput ), NULL, this );
}

MarkdownFrame::~MarkdownFrame()
{
	// Disconnect Events
	m_scintilla1->Disconnect( wxEVT_CHAR, wxKeyEventHandler( MarkdownFrame::OnInput ), NULL, this );
	
}

void MarkdownFrame::OnInput(wxKeyEvent& event)
{
	wxFile* f = new wxFile("temp.md", wxFile::write);
	f->Write(m_scintilla1->GetText());
	f->Close();
	wxString cmd = "markdown -5G -i template.html -o temp.html temp.md";
	MarkdownProcess* process = new MarkdownProcess(this);
	wxExecute(cmd, wxEXEC_ASYNC | wxEXEC_HIDE_CONSOLE, process);
	event.Skip();
}

void MarkdownFrame::DoIt()
{
	//m_webview->LoadURL("file:///D:/Dokumente/Programming/cpp/gui/Gui/temp.html");
	m_webview->Reload();
}
