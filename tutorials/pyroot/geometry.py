## \file
## \ingroup tutorial_pyroot
## \notebook -nodraw
## Geometry
##
## \macro_code
##
## \author Wim Lavrijsen

import os
import ROOT

macrodir = os.path.join(ROOT.gROOT.GetTutorialsDir().Data(), 'pyroot')

# the na49.C file was generated, so no python conversion is provided
ROOT.gROOT.Macro( ROOT.gSystem.UnixPathName( os.path.join( macrodir, os.pardir, 'geom', 'na49.C' ) ) )

exec(open(os.path.join( macrodir, 'na49visible.py')).read())
exec(open(os.path.join( macrodir, 'na49geomfile.py')).read())
