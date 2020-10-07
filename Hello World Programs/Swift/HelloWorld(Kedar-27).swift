//
//  HelloWorld.swift
//  GeometryReader
//
//  Created by Kedar-27 on 07/10/20.
//
import SwiftUI

struct ContentView: View {
    var body: some View {
        GeometryReader{
            metrics in
            HStack{
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: metrics.size.height * 0.2)
                    .background(Color.black)
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: metrics.size.height* 0.2)
                    .background(Color.yellow)
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: metrics.size.height * 0.2)
                    .background(Color.pink)
            }
        }
    }
}

#if DEBUG
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
#
