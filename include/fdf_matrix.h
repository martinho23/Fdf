/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarinha <jfarinha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:40:38 by jfarinha          #+#    #+#             */
/*   Updated: 2025/03/18 21:40:29 by jfarinha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATRIX_H
#define FDF_MATRIX_H

#include <math.h>

#define MATRIX_ROT_Y(angle)  {{{{cos(angle),    0,  sin(angle), 0},\
                                {0,             1,  0,          0},\
                                {-sin(angle),   0,  cos(angle), 0},\
                                {0,             0,  0,          1}}}}

#define MATRIX_ROT_Z(angle)  {{{{cos(angle),    -sin(angle), 0, 0},\
                                {sin(angle),    cos(angle), 0, 0},\
                                {0,             0,          1, 0},\
                                {0,             0,          0, 1}}}}

#define MATRIX_ROT_X(angle)  {{{{1, 0,          0,              0},\
                                {0, cos(angle), -sin(angle),    0},\
                                {0, sin(angle), cos(angle),     0},\
                                {0, 0,          0,              1}}}}

#define MATRIX_TRANSLATE(pos) {{{{1,     0,     0,      0},\
                                 {0,     1,     0,      0},\
                                 {0,     0,     1,      0},\
                                 {pos.x, pos.y, pos.z,  1}}}}



#define INDENTITY_MATRIX(angle)  {{{{1, 0, 0, 0},\
                                    {0, 1, 0, 0},\
                                    {0, 0, 1, 0},\
                                    {0, 0, 0, 1}}}}

#define MATRIX_ZERO   {{{{0, 0, 0, 0},\
                         {0, 0, 0, 0},\
                         {0, 0, 0, 0},\
                         {0, 0, 0, 0}}}}

#endif
