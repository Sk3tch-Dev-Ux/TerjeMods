# TerjeNasdara

An add-on for TerjeMedicine and TerjeSkills that supports Nasdara, the desert map added in DayZ 1.30.
Nasdara's files ship with the base game under the `DZ\*_takistan` prefix, so the mod loads on every map.
On other maps it only adds the perks and the items.

## Requirements

Load after TerjeCore, TerjeMedicine and TerjeSkills: `-mod=@TerjeCore;@TerjeMedicine;@TerjeSkills;@TerjeNasdara`.

## What it adds

### Hunting
The Nasdara animals give hunting experience and use Terje's skinning modifiers:
the Dobermann and German Shepherd, the wild sheep (`Animal_OvisGmelini`) and the monitor lizard (`Animal_VaranusGriseus`).

### Rabies in feral dogs
Dobermanns and German Shepherds can carry rabies, the same way wolves do in TerjeMedicine.
The chance is set by `Nasdara.RabiesDogInfectedChance` (default 0.1).

### Perks
| Skill | Perk | Effect |
|---|---|---|
| Survival | Heat Resistance | Hot surroundings, sun included, warm you up less. The hot-side twin of Cold Resistance. The perk switches off while any fire or other heat source is in range, so fires always warm you normally. Clothes may dry a little slower in the heat. |
| Survival | Dust Wise | Fewer silicosis and eye irritation agents from sandstorms. |
| Metabolism | Acclimatised | Overheating (vanilla thermal bias) builds up more slowly, so heat stroke comes later. Washing and medicine still cool you as normal. |
| Stealth | Dog Whisperer | Feral dogs notice you from a shorter distance. Stops working once you hurt the dog. |

New perks are stored by id. Existing saves keep working, and saves still load if the mod is removed.

### Medicine
Vanilla 1.30 added heat stroke, silicosis and irritated eyes. Vanilla has no cure for silicosis.

| Class | Use | Effect |
|---|---|---|
| `TerjeInjectorAminophylline` | Injector | Removes 400 silicosis agents (out of 1000) |
| `TerjeSalveEyeOintment` | Ointment, 5 uses | Removes 60 eye irritation agents (out of 100) per use |
| `TerjePillsElectrolytes` | Tablets, eaten | Per tablet: lowers thermal bias by 0.2 and adds water. Thermal bias then stays where it is for 60 s, neither rising nor falling (the same pause vanilla gives after washing your head). |

The pharmacology perk makes each one stronger. The stethoscope now shows heat stroke, silicosis and irritated eyes.

Modders can use the same keys on their own items:
`medSilicosisRemove`, `medEyeIrritationRemove`, `medThermalBiasRemove` and `medThermalBiasResistSec`.
They take effect instantly and store nothing on the player.

## Settings
Category `Nasdara`:
- `Nasdara.RabiesDogInfectedChance` (default 0.1)
- `Nasdara.StealthDogsVisibilityModifier` (default 1.0)

## Loot (types.xml)
These are examples. Tune nominal and min for your server.

```xml
<type name="TerjeInjectorAminophylline">
    <nominal>6</nominal><lifetime>14400</lifetime><restock>0</restock><min>3</min>
    <quantmin>-1</quantmin><quantmax>-1</quantmax><cost>100</cost>
    <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
    <category name="tools"/><usage name="Medic"/><usage name="Military"/>
</type>
<type name="TerjeSalveEyeOintment">
    <nominal>10</nominal><lifetime>14400</lifetime><restock>0</restock><min>5</min>
    <quantmin>-1</quantmin><quantmax>-1</quantmax><cost>100</cost>
    <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
    <category name="tools"/><usage name="Medic"/><usage name="Town"/>
</type>
<type name="TerjePillsElectrolytes">
    <nominal>15</nominal><lifetime>14400</lifetime><restock>0</restock><min>8</min>
    <quantmin>-1</quantmin><quantmax>-1</quantmax><cost>100</cost>
    <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/>
    <category name="tools"/><usage name="Medic"/><usage name="Town"/><usage name="Village"/>
</type>
```

## Known limits
- The new items reuse Terje's models with existing textures. They need their own art.
  The eye ointment currently looks the same as Viprosal salve.
- Perk icons reuse existing Terje icons.
- Balance numbers are starting values and have not been tuned in game.
