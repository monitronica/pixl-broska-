# Pixl Broška — A Wearable Programmable Pixel Brooch

**A project by monitronica**

> Twenty LEDs, one tiny microcontroller, and a wearable space for words, images, and motion.

Official project visuals: [finished brooch and circuit-board close-up](https://radiona.org/monika-pocrnjic-radionica-pikslbroska/) · [workshop documentation](https://kons-platforma.org/en/dogodki/pixelbrooch-6/)

The official sources do not state a reusable image license, so photographs are linked rather than copied. See [image credits and permission status](images/README.md).

## Project overview

Pixl Broška is a programmable electronic brooch with a hand-built 4×5 LED display. Its twenty large “pixels” can show scrolling words, simple drawings, symbols, and short frame-by-frame animations. Worn on clothing, the circuit becomes a small public screen: part accessory, part message board, and part introduction to creative coding.

The project is designed for experimentation. A first-time maker can solder a working object and start by changing a line of text, while a more experienced participant can draw new bitmap characters, design animation frames, or rewrite the display routine.

## Artistic concept and background

Clothing and jewelry already communicate identity, mood, and belonging. Pixl Broška makes that communication programmable. Instead of fixing one image or slogan permanently, the wearer can decide what the object says today, how it moves, and when it says nothing at all.

Its visible circuitry is part of the work. The grid of individual LEDs gives digital imagery a physical scale, while the circuit board places code, electronics, and personal expression directly on the body. The limited resolution encourages the visual economy of pixel art: every light matters.

Pixl Broška was the first workshop developed within the Maribor part of the konS platform. The first documented online edition took place in December 2020, when participants received material kits at home. Later workshops brought the project to students, children, young people, and adult beginners in Maribor, Novo Mesto, Velenje, Zagreb, and other konS partner locations.

## Inspiration & Acknowledgements

Pixl Broška was inspired by **benbrandt22** and the Instructables project [*Creating a Charlieplexed LED Grid to Run on ATTiny85*](https://www.instructables.com/Creating-a-charlieplexed-LED-grid-to-run-on-ATTiny/). Building on that generous sharing of knowledge, design, code, and inspiration, **monitronica** redesigned and created a new PCB, adapted and modified parts of the original code, and developed a distinct wearable artistic interpretation of the project.

Warm thanks to [benbrandt22](https://www.instructables.com/member/benbrandt22/) for making the original project available to fellow makers. No text, photographs, or other media from the Instructables page are reproduced here; the original material remains subject to the copyright and licensing terms of its author and source platform.

## How Pixl Broška works

The brooch uses an **ATtiny85V**, a low-power 8-bit AVR microcontroller, to control a matrix of **twenty 5 mm LEDs** arranged as four columns by five rows.

Five microcontroller pins drive the display through **charlieplexing**. Each LED sits between a different ordered pair of pins. The firmware repeatedly changes selected pins between high, low, and high-impedance input states, lighting one LED path at a time. This scanning happens quickly enough for the separate points of light to appear as a complete image.

The repository contains two display approaches:

- [`srce1.ino`](srce1.ino) stores a sequence of 4×5 bitmap frames and plays them as a short animation.
- [`PixlBroskaTekst.ino`](PixlBroskaTekst.ino) defines a compact bitmap alphabet and scrolls a programmed text string across the display.

The result is deliberately small and direct: no phone, wireless connection, or separate screen is required once the firmware has been uploaded.

## Hardware and electronics

The repository's board and bill of materials specify:

- 1 × ATtiny85V-10PU microcontroller in an 8-pin DIP package
- 1 × DIP-8 socket
- 20 × 5 mm through-hole LEDs
- 5 × 100 Ω through-hole resistors
- 1 × CR2032 3 V coin cell and through-hole holder
- 1 × SPDT slide switch for power
- 1 × six-pin ISP programming header
- a custom two-layer KiCad PCB that forms the body of the brooch

The six-pin header exposes the standard AVR programming connections: MISO, MOSI, SCK, reset, power, and ground. The CR2032 holder sits on the rear of the board, while the LED matrix and visible controls form the front-facing display.

This is **wearable electronics**, not an electronic-textile circuit: the electronics are assembled on a rigid PCB and worn on clothing rather than sewn with conductive thread or integrated into fabric.

## Programming and animation

The included sketches use Arduino-style C/C++ and can be adapted in the Arduino development environment with an ATtiny85-compatible core and an AVR ISP programmer. An Arduino configured as an ISP can also be used when set up correctly. Confirm the selected ATtiny core, clock, fuse, and programmer settings before uploading.

### Change the scrolling text

In [`PixlBroskaTekst.ino`](PixlBroskaTekst.ino), edit the message constant:

```cpp
#define PRIKAZI_BESEDILO " HELLO WORLD "
```

The sketch maps letters, digits, spaces, and a few lowercase characters to 4×5 bitmaps, then moves the message across the LED grid. The `HITROST` value controls the scrolling speed.

### Draw an animation

In [`srce1.ino`](srce1.ino), each frame is five rows of four bits:

```cpp
{ 0b0000,
  0b0110,
  0b0011,
  0b0110,
  0b0000 }
```

Each `1` represents a lit pixel. Add or replace frames, then adjust the playback loop and duration to change the movement. Simple icons, blinking patterns, faces, and abstract rhythms work especially well at this scale.

## Building your own brooch

1. Review the [BOM](pikselbroska1.csv), [PCB layout](pikselbroska.kicad_pcb), and firmware before ordering parts or boards.
2. Fabricate the PCB from the KiCad source or the archived Gerber and drill files in [`BroskaPiksL.rar`](BroskaPiksL.rar). Verify the fabrication outputs with your board manufacturer before ordering.
3. Sort and identify every component. Check LED polarity and the orientation marks for the DIP socket, ATtiny85, battery holder, switch, and ISP header.
4. Solder the lowest-profile parts first, typically the resistors and socket, followed by the LEDs, header, switch, and battery holder.
5. Inspect every joint and test for shorts before inserting the microcontroller or battery.
6. Upload a simple display test through the ISP header, then program the scrolling-text or animation sketch.
7. Fit the brooch securely to clothing so that conductive parts cannot contact skin, loose metal, or other conductive objects.

Work in a ventilated area, use eye protection when trimming leads, and keep the soldering iron in a stable stand. Coin cells are hazardous if swallowed and must be kept away from small children and stored safely. Beginners should build with an experienced facilitator.

## Project photographs

Authentic Pixl Broška images are available from the official project and workshop pages:

| View | Official source | Permission status |
| --- | --- | --- |
| Finished brooch shown on clothing | [Radiona workshop page](https://radiona.org/monika-pocrnjic-radionica-pikslbroska/) | Reuse license not stated; linked only |
| Populated board, LED display, and rear battery holder | [Radiona workshop page](https://radiona.org/monika-pocrnjic-radionica-pikslbroska/) | Reuse license not stated; linked only |
| Workshop and event documentation | [konS PixeLBrooch](https://kons-platforma.org/en/dogodki/pixelbrooch-6/) and [MKC Maribor](https://mkc.si/koledar/2020/12/16/kons-delavnica-pikslbroska) | Reuse license not established; linked only |

No photograph has been copied into this repository without confirmed permission. Candidate-image details are documented in [`images/README.md`](images/README.md).

## Workshops and educational context

Pixl Broška turns a wearable object into an approachable lesson in electronics and programming. Workshop participants encounter:

- safe soldering and component orientation
- current-limiting resistors and LED polarity
- microcontrollers and firmware
- charlieplexing and persistence of vision
- bitmap fonts, binary patterns, and animation frames
- debugging through inspection, continuity testing, and small code changes
- wearable objects as media for public and personal expression

The workshop has been presented for learners with no previous electronics experience. Documented editions include the first online konS workshop in December 2020, a two-part soldering and programming workshop for Maribor students in May and June 2021, konS workshops during 2021–2023, and a Radiona workshop in Zagreb on 12 June 2023.

## Credits and acknowledgements

- **Project and artistic direction:** monitronica
- **Original workshop development:** monitronica, with assistance from Denis Lederhas, Klemen Šali, and Marko Lük
- **Workshop development and production context:** MKC Maribor and konS – Platform for Contemporary Investigative Art
- **2023 Zagreb workshop host:** Radiona – Zagreb Makerspace
- **Radiona page portrait photography:** Gregor Salobir for konSekvence; the portrait is not reproduced in this repository
- **Participating workshop hosts and partners:** konS partner organizations and local venues credited on the linked event pages

Historical source pages may identify monitronica under an earlier/legal-name credit. This repository uses the artist's requested public name while retaining direct source links and the names of collaborators, photographers, and institutions.

## Technical resources and useful links

### Repository files

- [Scrolling-text firmware](PixlBroskaTekst.ino)
- [Frame-animation firmware](srce1.ino)
- [Bill of materials](pikselbroska1.csv)
- [KiCad PCB layout](pikselbroska.kicad_pcb)
- [Legacy KiCad project file](pikselbroska.pro)
- [Archived Gerber and drill files](BroskaPiksL.rar)

### Project and workshop sources

- [PixeLBrooch workshop, konS](https://kons-platforma.org/en/dogodki/pixelbrooch-6/)
- [Pixl Broška workshop, Radiona Zagreb](https://radiona.org/monika-pocrnjic-radionica-pikslbroska/)
- [Pixl Broška workshop overview, MKC Maribor](https://mkc.si/park-delavnice)
- [First online Pixl Broška workshop, MKC Maribor](https://mkc.si/koledar/2020/12/16/kons-delavnica-pikslbroska)
- [2021 soldering workshop announcement, Kultura Maribor](https://kultura.maribor.si/dogodek/kons-mb-x-kms-delavnica-pikslbroska-spajkanje/)
- [2021 programming workshop announcement, Kultura Maribor](https://kultura.maribor.si/dogodek/kons-mb-x-kms-delavnica-pikslbroska-programiranje/)
- [ATtiny85 product page, Microchip](https://www.microchip.com/en-us/product/attiny85)
- [monitronica on GitHub](https://github.com/monitronica)
