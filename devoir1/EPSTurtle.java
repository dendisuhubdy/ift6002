/*
 * Copyright (c) 2017, Mikl&oacute;s Cs&#369;r&ouml;s
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
package lindenmayer;

import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.io.PrintStream;
import java.util.Iterator;

/**
 *
 * Encapsulated PostScript output following 
 * a "ghost turtle".  
 * 
 * 
 * 
 * @author Mikl&oacute;s Cs&#369;r&ouml;s
 */
public class EPSTurtle implements Turtle 
{
    private final Turtle ghost;
    private final PrintStream out;
    
    /**
     * Writes to standard output. 
     * 
     * @param ghost turtle following coordinates 
     */
    public EPSTurtle(Turtle ghost)
    {
        this(ghost, System.out);
    }
    
    /**
     * Instantiation, also prints EPS header.
     * 
     * @param ghost turtle for following coordinates and drawing
     * @param out where to write the PostScript output
     */
    public EPSTurtle(Turtle ghost, PrintStream out)
    {
        this.ghost = ghost;
        this.out=out;
        
        this.printPSHeader();
    }
    
    public void plot(LSystem lsystem, int n_iter)
    {
        ghost.push(); // save its position for computing BoundingBox
        Iterator<Symbol> axiom = lsystem.getAxiom();
        while (axiom.hasNext())
        {
            Symbol s = axiom.next();
            lsystem.tell(this, s, n_iter);
        }
        out.println("stroke");

        lsystem.resetRandomGenerator(); // to get the same random drawing for BoundingBox calculations
        ghost.pop();
        Rectangle2D bbox = lsystem.getBoundingBox(ghost, lsystem.getAxiom(), n_iter); //getBoundingBox(n_iter) ;

        out.println("%%Trailer");
        out.println("%%BoundingBox: "
            +Integer.toString((int)bbox.getMinX())
                    +" "+Integer.toString((int)bbox.getMinY())
                    +" "+Integer.toString((int)bbox.getMaxX())
                    +" "+Integer.toString((int)bbox.getMaxY()));
        out.println("%%EOF");
    }
    
    /**
     * Called at initialization.
     */
    private void printPSHeader()
    {
        out.println("%!PS-Adobe-3.0 EPSF-3.0");
        out.println("%%Title: L-system");
        out.println("%%Creator: "+getClass().getName());
        out.println("%%BoundingBox: (atend)"); // on va avoir un appel final à 
        out.println("%%EndComments");
        //out.println("/x { currentpoint stroke moveto } bind def % stroke + restart in same pos");
        out.println("/M {moveto} bind def"); // synonyme 
        out.println("/L {lineto} bind def"); // synonyme 
        out.println("0.5 setlinewidth"); // plus jolie
    }
    
    private static final String POSITION_FORMAT = "%.1f %.1f";
    
    /**
     * Prints the {@link #ghost}'s current position on the PS output. 
     */
    private void printPos()
    {
        Point2D current_pos = ghost.getPosition();
        out.printf(POSITION_FORMAT,current_pos.getX(),current_pos.getY());
    }
    
    @Override
    public void draw() 
    {
        ghost.draw();
        printPos();
        out.println(" L ");
    }

    @Override
    public void move() 
    {
        ghost.draw();
        printPos();
        out.println(" M ");
    }

    @Override
    public void turnR() 
    {
        ghost.turnR();
    }

    @Override
    public void turnL() 
    {
        ghost.turnL();
    }

    @Override
    public void push() 
    {
        out.println("stroke ");
        ghost.push();
        printPos();
        out.println(" newpath M ");
    }

    @Override
    public void pop() 
    {
        out.println("stroke ");
        ghost.pop();
        printPos();
        out.println(" newpath M ");
    }

    @Override
    public void stay() 
    {
        ghost.stay();
    }

    @Override
    public void init(Point2D pos, double angle_deg) 
    {
        ghost.init(pos, angle_deg);
        printPos();
        out.println(" newpath moveto "); //% INIT "+ghost.getPosition()+", "+ghost.getAngle());
    }
    
    @Override
    public Point2D getPosition() 
    {
        return ghost.getPosition();
    }

    @Override
    public double getAngle() 
    {
        return ghost.getAngle();
    }

    @Override
    public void setUnits(double step, double delta) 
    {
        ghost.setUnits(step, delta);
        
    }
}
