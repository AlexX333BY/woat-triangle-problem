#include "TriangleProblemApp.h"
#include "TriangleProblemFrame.h"

bool TriangleProblemApp::OnInit()
{
    return (new TriangleProblemFrame("Triangle Problem solver"))->Show(true);
}
