/* ----------------------------------------------------------------------
* I-SIMPA (http://i-simpa.ifsttar.fr). This file is part of I-SIMPA.
*
* I-SIMPA is a GUI for 3D numerical sound propagation modelling dedicated
* to scientific acoustic simulations.
* Copyright (C) 2007-2014 - IFSTTAR - Judicael Picaut, Nicolas Fortin
*
* I-SIMPA is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
* 
* I-SIMPA is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA or 
* see <http://ww.gnu.org/licenses/>
*
* For more information, please consult: <http://i-simpa.ifsttar.fr> or 
* send an email to i-simpa@ifsttar.fr
*
* To contact Ifsttar, write to Ifsttar, 14-20 Boulevard Newton
* Cite Descartes, Champs sur Marne F-77447 Marne la Vallee Cedex 2 FRANCE
* or write to scientific.computing@ifsttar.fr
* ----------------------------------------------------------------------*/

#include "first_header_include.hpp"

#include "data_manager/element.h"

/** \file e_scene_recepteursp_recepteur_proprietes.h
   \brief Element correspondant à la configuration d'un récépteur ponctuel
*/

/**
   \brief Element correspondant à la configuration d'un récépteur ponctuel
   @see E_Scene_Recepteursp_Recepteur
*/
class E_Scene_Recepteursp_Recepteur_Proprietes: public Element
{
private:
	void InitDirectivite()
	{
		
		this->AppendPropertyDecimal("u",wxTRANSLATE("Direction X"),1,false,2,false,false,0,0,true);
		this->AppendPropertyDecimal("v",wxTRANSLATE("Direction Y"),0,false,2,false,false,0,0,true);
		this->AppendPropertyDecimal("w",wxTRANSLATE("Direction Z"),0,false,2,false,false,0,0,true);
	}
	void InitProperties()
	{
		std::vector<wxString> typesrecepteursp;
		typesrecepteursp.push_back(wxTRANSLATE("Omnidirectional"));
		this->AppendPropertyList("typereception",wxTRANSLATE("Directivity"),typesrecepteursp,0);
		this->AppendPropertyText("description",wxTRANSLATE("Description"),"");
		InitDirectivite();
	}
public:
	E_Scene_Recepteursp_Recepteur_Proprietes( wxXmlNode* noeudCourant ,  Element* parent)
		:Element(parent,wxTRANSLATE("Properties"),Element::ELEMENT_TYPE_SCENE_RECEPTEURSP_RECEPTEUR_PROPRIETES,noeudCourant)
	{
		SetIcon(GRAPH_STATE_ALL,GRAPH_EL_CONFIGURATION);
		if(!this->IsPropertyExist("u")) //maj versions < 06/11/2008
		{
			InitDirectivite();
		}
		initPropLabel(this, "typereception", wxTRANSLATE("Directivity"));
	}

	E_Scene_Recepteursp_Recepteur_Proprietes( Element* parent)
		:Element(parent,"Properties",Element::ELEMENT_TYPE_SCENE_RECEPTEURSP_RECEPTEUR_PROPRIETES)
	{
		SetIcon(GRAPH_STATE_ALL,GRAPH_EL_CONFIGURATION);
		InitProperties();
	}

	
	wxXmlNode* SaveXMLDoc(wxXmlNode* NoeudParent)
	{
		wxXmlNode* thisNode = Element::SaveXMLDoc(NoeudParent);
		thisNode->SetName("prop"); // Nom de la balise xml ( pas d'espace autorise )
		return thisNode;
	}
};
