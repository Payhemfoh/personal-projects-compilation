"use strict";
function lerp(A, B, t) {
    return A + (B - A) * t;
}
function getIntersection(A, B, C, D) {
    /*
        Ix = Ax + (Bx-Ax)t = Cx+(Dx-Cx)u
        Iy = Ay + (By-Ay)t = Cy+(Dy-Cy)u

        Ax + (Bx-Ax)t = Cx+(Dx-Cx)u
        (Ax - Cx) + (Bx-Ax)t = (Dx-Cx)u

        Ay + (By-Ay)t = Cy+(Dy-Cy)u
        (Ay - Cy) + (By-Ay)t = (Dy-Cy)u
        ------------------
        (Dx-Cx)(Ay-Cy) + (Dx-Cx)(By-Ay)t
        = (Dy-Cy)(Dx-Cx)u
        --------------------
        (Dx-Cx)(Ay-Cy) + (Dx-Cx)(By-Ay)t
        = (Dy-Cy)(Ax-Cx)+(Dy-Cy)(Bx-Ax)t
        --------------------
        (Dx-Cx)(Ay-Cy) - (Dy-Cy)(Ax-Cx) + (Dx-Cx)(By-Ay)t
        = (Dy-Cy)(Bx-Ax)t
        ---------------
        (Dx-Cx)(Ay-Cy) - (Dy-Cy)(Ax-Cx)
        = (Dy-Cy)(Bx-Ax)t - (Dx-Cx)(By-Ay)t
        ----------------------
        (Dx-Cx)(Ay-Cy) - (Dy-Cy)(Ax-Cx)
        = t((Dy-Cy)(Bx-Ax) - (Dx-Cx)(By-Ay))
        ## t = (Dx-Cx)(Ay-Cy) - (Dy-Cy)(Ax-Cx)/
            (Dy-Cy)(Bx-Ax) - (Dx-Cx)(By-Ay)

        -----------
        (Ay - Cy) + (By-Ay)t = (Dy-Cy)u
        (By-Ay)t = (Dy-Cy)u - (Ay - Cy)
        (By-Ay)t(Bx-Ax) = (Bx-Ax)(Dy-Cy)u - (Ay - Cy)(Bx-Ax)
        ------------------
        (By-Ay)(Dx-Cx)u + (By-Ay)(Cx-Ax)
        =(Bx-Ax)(Dy-Cy)u - (Ay - Cy)(Bx-Ax)
        -----------------------
        (By-Ay)(Cx-Ax) + (Ay - Cy)(Bx-Ax)
        =(Bx-Ax)(Dy-Cy)u - (By-Ay)(Dx-Cx)u
        -------------------------
        (By-Ay)(Cx-Ax) + (Ay - Cy)(Bx-Ax)
        =u((Bx-Ax)(Dy-Cy) - (By-Ay)(Dx-Cx))
        
        ###u =
        (By-Ay)(Cx-Ax) + (Ay - Cy)(Bx-Ax) /
        (Bx-Ax)(Dy-Cy) - (By-Ay)(Dx-Cx)
        

    */
    if (A == undefined || B == undefined || C == undefined || D == undefined)
        return null;
    var tTop = ((D.x - C.x) * (A.y - C.y)) - ((D.y - C.y) * (A.x - C.x));
    var uTop = ((B.y - A.y) * (C.x - A.x)) + ((A.y - C.y) * (B.x - A.x));
    var Bottom = ((D.y - C.y) * (B.x - A.x)) - ((D.x - C.x) * (B.y - A.y));
    if (Bottom != 0) {
        var t = tTop / Bottom;
        var u = uTop / Bottom;
        if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
            return {
                x: lerp(A.x, B.x, t),
                y: lerp(A.y, B.y, t),
                offset: t
            };
        }
    }
    return null;
}
function polysIntersect(poly1, poly2) {
    for (var i = 0; i < poly1.length; ++i) {
        for (var j = 0; j < poly2.length; ++j) {
            var touch = getIntersection(poly1[i], poly1[(i + 1) % poly1.length], poly2[j], poly2[(j + 1) % poly2.length]);
            if (touch)
                return true;
        }
    }
    return false;
}
function getRGBA(value) {
    var alpha = Math.abs(value);
    var R = value < 0 ? 0 : 255;
    var G = R;
    var B = value > 0 ? 0 : 255;
    return "rgba(" + R + "," + G + "," + B + "," + alpha + ")";
}
function getInter2(A, B, C, D) {
    /*
    //form equation for line AB
    y - A.y = ((B.y-A.y)/(B.x-A.x)) (x-A.x)
    y = ((B.y-A.y)/(B.x-A.x)) (x-A.x) + A.y
    (B.y-A.y)(x-A.x)(y)/(B.x-A.x) + A.y(y) = 0
    --------------
    (B.y(x)-A.y(x) -A.x(B.x) +(A.x)(A.y))(y)/
    (B.x-A.x) + A.y(y) = 0

    (B.y(x)(y)-A.y(x)(y) -A.x(B.x)(y) +(A.x)(A.y)(y))/
    (B.x-A.x) + A.y(y) = 0
    ----------
    (B.y(x)(y)-A.y(x)(y) -A.x(B.x)(y) +(A.x)(A.y)(y) + A.y(y)(B.x-A.x))/
    (B.x-A.x)= 0
    ---------------------
    y(B.y(x)-A.y(x) -A.x(B.x) +(A.x)(A.y) + A.y(B.x-A.x)))
    /(B.x-A.x) = 0
    ---------------------
    y/(B.x-A.x) +
    (B.y(x)-A.y(x) -A.x(B.x) +(A.x)(A.y) + A.y(B.x-A.x))/(B.x-A.x)
    = 0
    ------------------------
    y/(B.x-A.x) +
    (x)(B.y-A.y)/(B.x-A.x)
    - (A.x(B.x) + A.y(B.x))/(B.x-A.x)

    -----------------
    //form equation for line CD
    y/(D.x-C.x) +
    (x)(D.y-C.y)/(D.x-C.x)
    - (C.x(D.x) + C.y(D.x))/(D.x-C.x)

    //formula for finding intersection
    ax + by +c = 0

    //cramer's rule
    Ix = b1c2-b2c1 / a1b2-a2b1
    Iy = c1a2 - c2a1 / a1b2-a2b1

    Ix = 1/(B.x-A.x) * (- (C.x(D.x) + C.y(D.x))/(D.x-C.x))
        - 1/(D.x-C.x) * (- (A.x(B.x) + A.y(B.x))/(B.x-A.x))
        /
        (B.y-A.y)/(B.x-A.x) * 1/(D.x-C.x)
        - (D.y-C.y)/(D.x-C.x) * 1/(B.x-A.x)
    -------------------------
    Ix = - (C.x(D.x) + C.y(D.x))/(D.x-C.x)(B.x-A.x))
        + (A.x(B.x) + A.y(B.x))/(B.x-A.x)(D.x-C.x))
        /
        (B.y-A.y)/(B.x-A.x)(D.x-C.x)
        - (D.y-C.y)/(D.x-C.x)(B.x-A.x)
    -------------------------
    Ix =(A.x(B.x) + A.y(B.x)) - (C.x(D.x) + C.y(D.x))/(B.x-A.x)(D.x-C.x))
        /
        ((B.y-A.y) - (D.y-C.y))/(B.x-A.x)(D.x-C.x)
    -------------------------
    Ix =(A.x(B.x) + A.y(B.x)) - (C.x(D.x) + C.y(D.x))/(B.x-A.x)(D.x-C.x))
        *
        (B.x-A.x)(D.x-C.x)/(B.y-A.y) - (D.y-C.y)
    -------------------------
    Ix =(A.x(B.x) + A.y(B.x))((B.x-A.x)(D.x-C.x)) - ((B.x-A.x)(D.x-C.x))(C.x(D.x) + C.y(D.x))
        /(B.x-A.x)(D.x-C.x)) * (B.y-A.y-D.y+C.y)
    -------------------------
    Ix =(A.x(B.x) + A.y(B.x) - (C.x(D.x) + C.y(D.x))
        / (B.y-A.y-D.y+C.y)
    */
    return null;
}
