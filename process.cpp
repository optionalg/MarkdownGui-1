#include "process.h"
#include <wx/txtstrm.h>
#include <wx/fs_mem.h>
#include <wx/msgdlg.h>
// ----------------------------------------------------------------------------
// MarkdownProcess
// ----------------------------------------------------------------------------

bool MarkdownProcess::HasInput()
{
    bool hasInput = false;

    if ( IsInputAvailable() )
    {
        wxTextInputStream tis(*GetInputStream());

        // this assumes that the output is always line buffered
		m_file << tis.ReadLine() << wxT("\n");

//        m_parent->GetLogListBox()->Append(msg);

        hasInput = true;
    }

    if ( IsErrorAvailable() )
    {
        wxTextInputStream tis(*GetErrorStream());

        // this assumes that the output is always line buffered
		wxMessageBox(tis.ReadLine());
        hasInput = true;
    }

    return hasInput;
}


void MarkdownProcess::OnTerminate(int pid, int status)
{
    // show the rest of the output
    while ( HasInput() )
        ;
	//wxMemoryFSHandler::AddFile("temp.html", m_file);

	m_parent->DoIt();

    delete this;
}
