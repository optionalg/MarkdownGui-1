#ifndef MARKDOWN_PROCESS_H_
#define MARKDOWN_PROCESS_H_

#include <wx/process.h>
#include <wx/cmdline.h>

#include "MarkdownFrame.h"

class MarkdownFrame;

class MarkdownProcess : public wxProcess
{
public:
	MarkdownProcess(MarkdownFrame* parent) : wxProcess(parent)
	{
		m_parent = parent;
		m_file = "";
		Redirect();
	}

	virtual void OnTerminate(int pid, int status);

	virtual bool HasInput();

private:
	MarkdownFrame* m_parent;
	wxString m_file;
};

#endif // MARKDOWN_PROCESS_H_

