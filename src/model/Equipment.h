/*
 * model/Equipment.h is part of Brewtarget, and is Copyright the following
 * authors 2009-2023
 * - Jeff Bailey <skydvr38@verizon.net>
 * - Matt Young <mfsy@yahoo.com>
 * - Mik Firestone <mikfire@gmail.com>
 * - Philip Greggory Lee <rocketman768@gmail.com>
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MODEL_EQUIPMENT_H
#define MODEL_EQUIPMENT_H
#pragma once

#include <QDomNode>
#include <QSqlRecord>

#include "model/NamedEntity.h"

//======================================================================================================================
//========================================== Start of property name constants ==========================================
// See comment in model/NamedEntity.h
#define AddPropertyName(property) namespace PropertyNames::Equipment { BtStringConst const property{#property}; }
AddPropertyName(batchSize_l          )
AddPropertyName(boilingPoint_c       )
AddPropertyName(boilSize_l           )
AddPropertyName(boilTime_min         )
AddPropertyName(calcBoilVolume       )
AddPropertyName(evapRate_lHr         )
AddPropertyName(evapRate_pctHr       )
AddPropertyName(grainAbsorption_LKg  )
AddPropertyName(hopUtilization_pct   )
AddPropertyName(lauterDeadspace_l    )
AddPropertyName(notes                )
AddPropertyName(topUpKettle_l        )
AddPropertyName(topUpWater_l         )
AddPropertyName(trubChillerLoss_l    )
AddPropertyName(tunSpecificHeat_calGC)
AddPropertyName(tunVolume_l          )
AddPropertyName(tunWeight_kg         )
#undef AddPropertyName
//=========================================== End of property name constants ===========================================
//======================================================================================================================


/*!
 * \class Equipment
 *
 * \brief Model representing a single equipment record.
 */
class Equipment : public NamedEntity {
   Q_OBJECT
   Q_CLASSINFO("signal", "equipments")

public:
   /**
    * \brief Mapping of names to types for the Qt properties of this class.  See \c NamedEntity::typeLookup for more
    *        info.
    */
   static TypeLookup const typeLookup;

   Equipment(QString t_name = "");
   Equipment(NamedParameterBundle const & namedParameterBundle);
   Equipment(Equipment const & other);

   virtual ~Equipment();

   //! \brief The boil size in liters.
   Q_PROPERTY( double boilSize_l            READ boilSize_l            WRITE setBoilSize_l            NOTIFY changedBoilSize_l )
   //! \brief The batch size in liters.
   Q_PROPERTY( double batchSize_l           READ batchSize_l           WRITE setBatchSize_l           NOTIFY changedBatchSize_l )
   //! \brief The tun volume in liters.
   Q_PROPERTY( double tunVolume_l           READ tunVolume_l           WRITE setTunVolume_l           NOTIFY changedTunVolume_l )
   //! \brief Set the tun mass in kg.
   Q_PROPERTY( double tunWeight_kg          READ tunWeight_kg          WRITE setTunWeight_kg          NOTIFY changedTunWeight_kg )
   //! \brief Set the tun specific heat in cal/(g*C)
   Q_PROPERTY( double tunSpecificHeat_calGC READ tunSpecificHeat_calGC WRITE setTunSpecificHeat_calGC NOTIFY changedTunSpecificHeat_calGC )
   //! \brief Set the top-up water in liters.
   Q_PROPERTY( double topUpWater_l          READ topUpWater_l          WRITE setTopUpWater_l          NOTIFY changedTopUpWater_l )
   //! \brief Set the loss to trub and chiller in liters.
   Q_PROPERTY( double trubChillerLoss_l     READ trubChillerLoss_l     WRITE setTrubChillerLoss_l     NOTIFY changedTrubChillerLoss_l )
   //! \brief Set the evaporation rate in percent of the boil size per hour. DO NOT USE. Only for BeerXML compatibility.
   Q_PROPERTY( double evapRate_pctHr        READ evapRate_pctHr        WRITE setEvapRate_pctHr        NOTIFY changedEvapRate_pctHr )
   //! \brief Set the evaporation rate in liters/hr.
   Q_PROPERTY( double evapRate_lHr          READ evapRate_lHr          WRITE setEvapRate_lHr          NOTIFY changedEvapRate_lHr )
   //! \brief Set the boil time in minutes.
   Q_PROPERTY( double boilTime_min          READ boilTime_min          WRITE setBoilTime_min          NOTIFY changedBoilTime_min )
   //! \brief Set whether you want the boil volume to be automatically calculated.
   Q_PROPERTY( bool   calcBoilVolume        READ calcBoilVolume        WRITE setCalcBoilVolume        NOTIFY changedCalcBoilVolume )
   //! \brief Set the lauter tun's deadspace in liters.
   Q_PROPERTY( double lauterDeadspace_l     READ lauterDeadspace_l     WRITE setLauterDeadspace_l     NOTIFY changedLauterDeadspace_l )
   //! \brief Set the kettle top up in liters.
   Q_PROPERTY( double topUpKettle_l         READ topUpKettle_l         WRITE setTopUpKettle_l         NOTIFY changedTopUpKettle_l )
   //! \brief Set the hop utilization factor. I do not believe this is used.
   Q_PROPERTY( double hopUtilization_pct    READ hopUtilization_pct    WRITE setHopUtilization_pct    NOTIFY changedHopUtilization_pct )
   //! \brief Set the notes.
   Q_PROPERTY( QString notes                READ notes                 WRITE setNotes                 NOTIFY changedNotes )
   //! \brief Set how much water the grains absorb in liters/kg.
   Q_PROPERTY( double grainAbsorption_LKg   READ grainAbsorption_LKg   WRITE setGrainAbsorption_LKg   NOTIFY changedGrainAbsorption_LKg )
   //! \brief Set the boiling point of water in Celsius.
   Q_PROPERTY( double boilingPoint_c        READ boilingPoint_c        WRITE setBoilingPoint_c        NOTIFY changedBoilingPoint_c )

   // Set
   void setBoilSize_l( double var );
   void setBatchSize_l( double var );
   void setTunVolume_l( double var );
   void setTunWeight_kg( double var );
   void setTunSpecificHeat_calGC( double var );
   void setTopUpWater_l( double var );
   void setTrubChillerLoss_l( double var );
   void setEvapRate_pctHr( double var );
   void setEvapRate_lHr( double var );
   void setBoilTime_min( double var );
   void setCalcBoilVolume( bool var );
   void setLauterDeadspace_l( double var );
   void setTopUpKettle_l( double var );
   void setHopUtilization_pct( double var );
   void setNotes( const QString &var );
   void setGrainAbsorption_LKg(double var);
   void setBoilingPoint_c(double var);

   // Get
   double  boilSize_l           () const;
   double  batchSize_l          () const;
   double  tunVolume_l          () const;
   double  tunWeight_kg         () const;
   double  tunSpecificHeat_calGC() const;
   double  topUpWater_l         () const;
   double  trubChillerLoss_l    () const;
   double  evapRate_pctHr       () const;
   double  evapRate_lHr         () const;
   double  boilTime_min         () const;
   bool    calcBoilVolume       () const;
   double  lauterDeadspace_l    () const;
   double  topUpKettle_l        () const;
   double  hopUtilization_pct   () const;
   QString notes                () const;
   double  grainAbsorption_LKg  ();
   double  boilingPoint_c       () const;

   //! \brief Calculate how much wort is left immediately at knockout.
   double wortEndOfBoil_l( double kettleWort_l ) const;

   virtual Recipe * getOwningRecipe();

signals:
   void changedBoilSize_l(double);
   void changedBatchSize_l(double);
   void changedTunVolume_l(double);
   void changedTunWeight_kg(double);
   void changedTunSpecificHeat_calGC(double);
   void changedTopUpWater_l(double);
   void changedTrubChillerLoss_l(double);
   void changedEvapRate_pctHr(double);
   void changedEvapRate_lHr(double);
   void changedBoilTime_min(double);
   void changedCalcBoilVolume(bool);
   void changedLauterDeadspace_l(double);
   void changedTopUpKettle_l(double);
   void changedHopUtilization_pct(double);
   void changedNotes(QString);
   void changedGrainAbsorption_LKg(double);
   void changedBoilingPoint_c(double);

protected:
   virtual bool isEqualTo(NamedEntity const & other) const;
   virtual ObjectStore & getObjectStoreTypedInstance() const;

private:
   double m_boilSize_l;
   double m_batchSize_l;
   double m_tunVolume_l;
   double m_tunWeight_kg;
   double m_tunSpecificHeat_calGC;
   double m_topUpWater_l;
   double m_trubChillerLoss_l;
   double m_evapRate_pctHr;
   double m_evapRate_lHr;
   double m_boilTime_min;
   bool m_calcBoilVolume;
   double m_lauterDeadspace_l;
   double m_topUpKettle_l;
   double m_hopUtilization_pct;
   QString m_notes;
   double m_grainAbsorption_LKg;
   double m_boilingPoint_c;

   // Calculate the boil size.
   void doCalculations();
};

Q_DECLARE_METATYPE( Equipment* )

#endif
