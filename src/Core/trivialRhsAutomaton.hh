/*

    This file is part of the Maude 2 interpreter.

    Copyright 1997-2003 SRI International, Menlo Park, CA 94025, USA.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.

*/

//
//	Class for trivial right hand side automata which just does a construct
//	or replace using an already bound (pseudo)-variable.
//
#ifndef _trivialRhsAutomaton_hh_
#define _trvialRhsAutomaton_hh_
#include "rhsAutomaton.hh"

class TrivialRhsAutomaton : public RhsAutomaton
{
  NO_COPYING(TrivialRhsAutomaton);

public:
  TrivialRhsAutomaton(int index);

  void remapIndices(VariableInfo& variableInfo);
  DagNode* construct(Substitution& matcher);
  void replace(DagNode* old, Substitution& matcher);

  bool recordInfo(StackMachineRhsCompiler& compiler);

#ifdef DUMP
  void dump(ostream& s, const VariableInfo& variableInfo, int indentLevel);
#endif

private:
  int index;
};

#endif
